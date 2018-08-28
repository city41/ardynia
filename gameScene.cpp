#include "gameScene.h"
#include "util.h"
#include "entityTemplates.h"

const uint8_t ROOM_TRANSITION_VELOCITY = 2;
const uint8_t ROOM_WIDTH_PX = WIDTH - 16;
const uint8_t ROOM_HEIGHT_PX = HEIGHT;

void GameScene::push(UpdatePtr newUpdate, RenderPtr newRender) {
    nextUpdate = newUpdate;
    nextRender = newRender;
}

void GameScene::pop() {
    nextUpdate = prevUpdate;
    nextRender = prevRender;
}

boolean isOffscreen(int16_t x, int16_t y) {
    return x < 0 || y < 0 || x > ROOM_WIDTH_PX || y > HEIGHT;
}

void GameScene::detectEntityCollisions(void) {
    for (uint8_t ge = 0; ge < MAX_ENTITIES; ++ge) {
        if (entities[ge].type == UNSET) {
            continue;
        }

        if (entities[ge].overlaps(&player)) {
            if (entities[ge].type == BUMPER) {
                player.undoMove();
            } else if (entities[ge].type == OVERWORLD_DOOR) {
                map = dungeons_map;
                entityDefs = dungeons_entities;
                tiles = dungeon_tiles;
                doorDefs = dungeons_doors;
                bumperDefs = dungeons_bumpers;
                tileRoom.map = map;
                tileRoom.tiles = tiles;

                // TODO: invert the sword properly
                player.entities[0].invert = true;

                tileRoom.x = entities[ge].prevX;
                tileRoom.y = entities[ge].prevY;

                setEntitiesInRoom(tileRoom.x, tileRoom.y);
            } else {
                player.onCollide(&entities[ge]);
            }
        }

        for (uint8_t pe = 0; pe < MAX_PLAYER_ENTITIES; ++pe) {
            if (player.entities[pe].type == UNSET) {
                continue;
            }

            if (entities[ge].overlaps(&player.entities[pe])) {
                entities[ge].onCollide(&player.entities[pe]);
                player.entities[pe].onCollide(&entities[ge]);
            }
        }
    }
}

void GameScene::goToNextRoom(int16_t x, int16_t y) {
    if (x < 0) {
        nextRoomX = tileRoom.x - 1;
        nextRoomY = tileRoom.y;
        roomTransitionCount = ROOM_WIDTH_PX;

    } else if (x > ROOM_WIDTH_PX) {
        nextRoomX = tileRoom.x + 1;
        nextRoomY = tileRoom.y;
        roomTransitionCount = ROOM_WIDTH_PX;

    } else if (y < 0) {
        nextRoomX = tileRoom.x;
        nextRoomY = tileRoom.y - 1;
        roomTransitionCount = ROOM_HEIGHT_PX;
 
    } else if (y > HEIGHT) {
        nextRoomX = tileRoom.x;
        nextRoomY = tileRoom.y + 1;
        roomTransitionCount = ROOM_HEIGHT_PX;
    }

    push(&GameScene::updateRoomTransition, &GameScene::renderRoomTransition);
}

void GameScene::setEntitiesInRoom(uint8_t x, uint8_t y) {
    uint8_t** rowPtr = pgm_read_word(&(entityDefs[y]));
    uint8_t* roomPtr = pgm_read_word(&(rowPtr[x]));

    uint8_t numEntitiesInCurrentRoom = pgm_read_byte(roomPtr++);

    int8_t i = 0;

    for (; i < numEntitiesInCurrentRoom; ++i) {
        uint8_t rawEntityType = (uint8_t)pgm_read_byte(roomPtr++);
        EntityType type = rawEntityType & ENTITY_MASK;
        uint8_t entityId = (rawEntityType & ENTITY_ID_MASK) >> 5;

        Entity& currentEntity = entities[i];

        loadEntity(currentEntity, type);

        currentEntity.x = pgm_read_byte(roomPtr++);
        currentEntity.y = pgm_read_byte(roomPtr++);

        if (type == BUMPER) {
            currentEntity.width = pgm_read_byte(bumperDefs + entityId * 2);
            currentEntity.height = pgm_read_byte(bumperDefs + entityId * 2 + 1);
        } else if (type == OVERWORLD_DOOR) {
            // reuse prevX/Y for destX/Y for doors
            currentEntity.prevX = pgm_read_byte(doorDefs + entityId * 2);
            currentEntity.prevY = pgm_read_byte(doorDefs + entityId * 2 + 1);
        } else {
            currentEntity.prevX = x;
            currentEntity.prevY = y;
        }
    }

    for (; i < MAX_ENTITIES; ++i) {
        entities[i].type = UNSET;
    }

    mapWidthInRooms = pgm_read_byte(map + 2);
    mapHeightInRooms = pgm_read_byte(map + 3);
}

boolean GameScene::playerLeftMap(void) {
    if (tileRoom.x == 0 && player.x < 4) {
        return true;
    }

    if (tileRoom.x == mapWidthInRooms - 1 && player.x + player.width - 4 > ROOM_WIDTH_PX) {
        return true;
    }

    if (tileRoom.y == 0 && player.y < 8) {
        return true;
    }

    if (tileRoom.y == mapHeightInRooms - 1 && player.y + player.height - 8 > ROOM_HEIGHT_PX) {
        return true;
    }

    return false;
}


void GameScene::updatePlay(uint8_t frame) {
    player.update(&player, arduboy, frame);

    if (playerLeftMap()) {
        player.undoMove();
    }

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
            player.moveTo(ROOM_WIDTH_PX - 1, player.y);
        } else if (nextRoomX > tileRoom.x) {
            player.moveTo(1, player.y);
        } else if (nextRoomY < tileRoom.y) {
            player.moveTo(player.x, ROOM_HEIGHT_PX - 1);
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
        translateX = ROOM_WIDTH_PX - roomTransitionCount;
    } else if (nextRoomX > tileRoom.x) {
        translateX = roomTransitionCount - ROOM_WIDTH_PX;
    } else if (nextRoomY < tileRoom.y) {
        translateY = ROOM_HEIGHT_PX - roomTransitionCount;
    } else if (nextRoomY > tileRoom.y) {
        translateY = roomTransitionCount - ROOM_HEIGHT_PX;
    }

    renderer->translateX = translateX;
    renderer->translateY = translateY;
    tileRoom.render(renderer, frame);

    // draw next room translated
    int16_t s = (translateX < 0 || translateY < 0) ? 1 : -1;

    renderer->translateX = translateX != 0 ? translateX + (ROOM_WIDTH_PX * s) : 0;
    renderer->translateY = translateY != 0 ? translateY + (ROOM_HEIGHT_PX * s) : 0;
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
