#include "gameScene.h"
#include "util.h"
#include "entityTemplates.h"

const uint8_t ROOM_TRANSITION_VELOCITY = 2;
const uint8_t ROOM_WIDTH = WIDTH - 16;
const uint8_t ROOM_HEIGHT = HEIGHT;

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

void GameScene::detectEntityCollisions(void) {
    for (uint8_t ge = 0; ge < numEntitiesInCurrentRoom; ++ge) {
        if (entities[ge].type == UNSET) {
            continue;
        }

        if (entities[ge].overlaps(&player)) {
            if (entities[ge].type == OVERWORLD_DOOR) {
                map = dungeons_map;
                entityDefs = dungeons_entities;
                tiles = dungeon_tiles;
                tileRoom.map = map;
                tileRoom.tiles = tiles;

                tileRoom.x = entities[ge].prevX;
                tileRoom.y = entities[ge].prevY;
                setEntitiesInRoom(tileRoom.x, tileRoom.y);
            }

            player.onCollide(&entities[ge]);
        }

        for (uint8_t pe = 0; pe < MAX_PLAYER_ENTITIES; ++pe) {
            if (player.entities[pe].type == UNSET) {
                continue;
            }

            if (entities[ge].overlaps(&player.entities[pe])) {
                entities[ge].onCollide(&player.entities[pe]);
            }
        }
    }
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

    int8_t i = 0;
    for (; i < numEntitiesInCurrentRoom; ++i) {
        uint8_t rawEntityType = pgm_read_byte(roomPtr++);
        EntityType type = rawEntityType & ENTITY_MASK;

        loadEntity(entities[i], type);
        entities[i].x = pgm_read_byte(roomPtr++);
        entities[i].y = pgm_read_byte(roomPtr++);

        if (type == OVERWORLD_DOOR) {
            uint8_t doorId = (rawEntityType >> 4) & DOOR_ID_MASK;

            // reuse prevX/Y for destX/Y for doors
            entities[i].prevX = overworld_doors[doorId * 2];
            entities[i].prevY = overworld_doors[doorId * 2 + 1];
        } else {
            entities[i].prevX = x;
            entities[i].prevY = y;
        }
    }

    for (; i < MAX_ENTITIES; ++i) {
        entities[i].type = UNSET;
    }
}


void GameScene::updatePlay(uint8_t frame) {
    player.update(&player, arduboy, frame);

    int8_t e = 0;
    for (; e < MAX_PLAYER_ENTITIES; ++e) {
        Entity& entity = player.entities[e];

        if (entity.type != UNSET) {
            entity.update(&player, arduboy, frame);
        }
    }

    for (e = 0; e < MAX_ENTITIES; ++e) {
        Entity& entity = entities[e];

        if (entity.type != UNSET) {
            entity.update(&player, arduboy, frame);
        }
    }

    if (isOffscreen(player.x, player.y)) {
        goToNextRoom(player.x, player.y);
    } else {
        detectTileCollisions();
        detectEntityCollisions();
    }

    /* if (player.health <= 0) { */
    /*     LOG("player lost all health, exiting game scene"); */
    /*     return TITLE; */
    /* } else { */
    /*     return GAME; */
    /* } */
}

void GameScene::renderPlay(uint8_t frame) {
    tileRoom.render(renderer, frame);

    int8_t e = 0;
    for(; e < MAX_ENTITIES; ++e) {
        Entity& entity = entities[e];

        if (entity.type != UNSET) {
            entity.render(renderer, frame);
        }
    }

    for (e = 0; e < MAX_PLAYER_ENTITIES; ++e) {
        Entity& entity = player.entities[e];

        if (entity.type != UNSET) {
            entity.render(renderer, frame);
        }
    }

    player.render(renderer, frame);


    renderer->translateX = WIDTH - 16;
    renderer->translateY = 0;
    Hud::render(renderer, frame, player, tileRoom.x, tileRoom.y);
}

void GameScene::updateMenu(uint8_t frame) {
    menu.update(arduboy, frame);
}

void GameScene::renderMenu(uint8_t frame) {
    menu.render(renderer, frame);
}

void GameScene::updateRoomTransition(uint8_t frame) {
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

        // for example, if the player had a flying boomerang,
        // this causes it to go away, easier than trying to deal
        // with items that can span across rooms O_o
        player.entities[0].type = UNSET;
        player.entities[1].type = UNSET;

        pop();
    }
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
    Hud::render(renderer, frame, player, tileRoom.x, tileRoom.y);
}

void GameScene::update(uint8_t frame) {
    if (paused) {
        if (arduboy->justPressed(B_BUTTON)) {
            paused = false;
        } else {
            return;
        }
    }

    if (arduboy->pressed(A_BUTTON) && arduboy->pressed(B_BUTTON)) {
        if (currentUpdate != &updateMenu) {
            if (player.bButtonEntityType != UNSET) {
                menu.decision = player.bButtonEntityType;
                menu.column = 1;
                menu.row = player.bButtonEntityType - 4;
            } else {
                menu.column = 1;
                menu.row = 0;
            }
            push(&GameScene::updateMenu, &GameScene::renderMenu);
        }
    } else {
        if (currentUpdate == &updateMenu) {
            if (menu.decision == Pause) {
                paused = true;
            } else if (menu.decision >= BOOMERANG && menu.decision <= CANDLE) {
                player.bButtonEntityType = menu.decision;
            }
            pop();
        }
    }

    (this->*currentUpdate)(frame);

    if (nextUpdate != NULL) {
        prevUpdate = currentUpdate;
        currentUpdate = nextUpdate;
        nextUpdate = NULL;
    }
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
