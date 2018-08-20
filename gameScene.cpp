#include "gameScene.h"
#include "util.h"

const uint8_t ROOM_TRANSITION_VELOCITY = 2;
const uint8_t ROOM_WIDTH = TILES_PER_ROW * TILE_SIZE;
const uint8_t ROOM_HEIGHT = TILES_PER_COLUMN * TILE_SIZE;

void GameScene::push(UpdatePtr newUpdate, RenderPtr newRender) {
    nextUpdate = newUpdate;
    nextRender = newRender;
}

void GameScene::pop() {
    nextUpdate = prevUpdate;
    nextRender = prevRender;
}

bool isOffscreen(int16_t x, int16_t y) {
    return x < 0 || y < 0 || x > ROOM_WIDTH || y > HEIGHT;
}

void GameScene::detectTileCollisions(void) {
    uint8_t tile = tileRoom.getTileAt(player.x, player.y);
    player.onCollide(tile);
}

void GameScene::goToNextRoom(int16_t x, int16_t y) {
    if (x < 0) {
        nextRoomX = tileRoom.x - 1;
        nextRoomY = tileRoom.y;
        roomTransitionCount = ROOM_WIDTH;

    } else if (x > ROOM_WIDTH) {
        nextRoomX = tileRoom.x + 1;
        nextRoomY = tileRoom.y;
        roomTransitionCount = ROOM_WIDTH;

    } else if (y < 0) {
        nextRoomX = tileRoom.x;
        nextRoomY = tileRoom.y - 1;
        roomTransitionCount = ROOM_HEIGHT;
 
    } else if (y > HEIGHT) {
        nextRoomX = tileRoom.x;
        nextRoomY = tileRoom.y + 1;
        roomTransitionCount = ROOM_HEIGHT;
    }

    push(&GameScene::updateRoomTransition, &GameScene::renderRoomTransition);
}

void GameScene::setEntitiesInRoom(uint8_t x, uint8_t y) {
    uint8_t** rowPtr = pgm_read_word(&(entityDefs[y]));
    uint8_t* roomPtr = pgm_read_word(&(rowPtr[x]));

    numEntitiesInCurrentRoom = pgm_read_byte(roomPtr++);

    uint8_t i = 0;
    for (i = 0; i < numEntitiesInCurrentRoom; ++i) {
        entities[i].type = (EntityType)pgm_read_byte(roomPtr++);
        entities[i].x = pgm_read_byte(roomPtr++);
        entities[i].y = pgm_read_byte(roomPtr++);
        entities[i].tiles = blob_tiles;
        entities[i].maskTiles = blob_mask_tiles;
    }
}


Scene GameScene::updatePlay(uint8_t frame) {
    player.update(arduboy, frame);

    if (isOffscreen(player.x, player.y)) {
        goToNextRoom(player.x, player.y);
    } else {
        detectTileCollisions();
    }

    return GAME;
}

void GameScene::renderPlay(uint8_t frame) {
    tileRoom.render(renderer, frame);

    for(uint8_t e = 0; e < numEntitiesInCurrentRoom; ++e) {
        entities[e].render(renderer, frame);
    }

    player.render(renderer, frame);

    renderer->translateX = WIDTH - 16;
    renderer->translateY = 0;
    hud.render(renderer, frame, player, tileRoom.x, tileRoom.y);
}

Scene GameScene::updateMenu(uint8_t frame) {
    menu.update(arduboy, frame);
    return GAME;
}

void GameScene::renderMenu(uint8_t frame) {
    menu.render(renderer, frame);
}

Scene GameScene::updateRoomTransition(uint8_t frame) {
    roomTransitionCount -= ROOM_TRANSITION_VELOCITY;

    if (roomTransitionCount == 0) {

        if (nextRoomX < tileRoom.x) {
            player.moveTo(ROOM_WIDTH - 1, player.y);
        } else if (nextRoomX > tileRoom.x) {
            player.moveTo(1, player.y);
        } else if (nextRoomY < tileRoom.y) {
            player.moveTo(player.x, ROOM_HEIGHT - 1);
        } else {
            player.moveTo(player.x, 1);
        }

        tileRoom.x = nextRoomX;
        tileRoom.y = nextRoomY;

        setEntitiesInRoom(nextRoomX, nextRoomY);

        pop();
    }

    return GAME;
}

void GameScene::renderRoomTransition(uint8_t frame) {
    int16_t translateX = 0, translateY = 0;

    // draw current room translated
    if (nextRoomX < tileRoom.x) {
        translateX = ROOM_WIDTH - roomTransitionCount;
    } else if (nextRoomX > tileRoom.x) {
        translateX = roomTransitionCount - ROOM_WIDTH;
    } else if (nextRoomY < tileRoom.y) {
        translateY = ROOM_HEIGHT - roomTransitionCount;
    } else if (nextRoomY > tileRoom.y) {
        translateY = roomTransitionCount - ROOM_HEIGHT;
    }

    renderer->translateX = translateX;
    renderer->translateY = translateY;
    tileRoom.render(renderer, frame);

    // draw next room translated
    int16_t s = (translateX < 0 || translateY < 0) ? 1 : -1;

    renderer->translateX = translateX != 0 ? translateX + (ROOM_WIDTH * s) : 0;
    renderer->translateY = translateY != 0 ? translateY + (ROOM_HEIGHT * s) : 0;
    tileRoom.render(renderer, frame, nextRoomX, nextRoomY);
    
    // draw player translated
    renderer->translateX = translateX;
    renderer->translateY = translateY;
    player.render(renderer, frame);

    renderer->translateX = WIDTH - 16;
    renderer->translateY = 0;
    hud.render(renderer, frame, player, tileRoom.x, tileRoom.y);
}

Scene GameScene::update(uint8_t frame) {
    if (paused) {
        if (arduboy->justPressed(B_BUTTON)) {
            paused = false;
        } else {
            return GAME;
        }
    }

    if (arduboy->pressed(A_BUTTON) && arduboy->pressed(B_BUTTON)) {
        if (currentUpdate != &GameScene::updateMenu) {
            push(&GameScene::updateMenu, &GameScene::renderMenu);
        }
    } else {
        if (currentUpdate == &GameScene::updateMenu) {
            if (menu.decision == QUIT) {
                return TITLE;
            }
            if (menu.decision == PAUSE) {
                paused = true;
            }
            pop();
        }
    }

    Scene nextScene = (this->*currentUpdate)(frame);

    if (nextUpdate != NULL) {
        prevUpdate = currentUpdate;
        currentUpdate = nextUpdate;
        nextUpdate = NULL;
    }

    return nextScene;
}

void GameScene::render(uint8_t frame) {
    renderer->translateX = 0;
    renderer->translateY = 0;

    (this->*currentRender)(frame);

    renderer->translateX = 0;
    renderer->translateY = 0;

    if (paused) {
        renderer->print(32, 30, F(" paused "));
    }

    if (nextRender != NULL) {
        prevRender = currentRender;
        currentRender = nextRender;
        nextRender = NULL;
    }
}
