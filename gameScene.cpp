#include "gameScene.h"
#include "util.h"
#include "entityTemplates.h"
#include "state.h"
#include "map.h"

const uint8_t ROOM_TRANSITION_VELOCITY = 2;
const uint8_t ROOM_WIDTH_PX = WIDTH - 16;
const uint8_t ROOM_HEIGHT_PX = HEIGHT;

void GameScene::loadSave() {
    State::load();

    TileRoom::map = overworld_map;
    TileRoom::tiles = overworld_tiles;
    TileRoom::x = START_ROOM_X;
    TileRoom::y = START_ROOM_Y;
    TileRoom::mapType = OVERWORLD;

    entityDefs = overworld_entities;
    doorDefs = overworld_teleporters;
    bumperDefs = overworld_bumpers;

    loadEntitiesinRoom(START_ROOM_X, START_ROOM_Y);

    player.reset();

    currentUpdate = &GameScene::updatePlay;
    currentRender = &GameScene::renderPlay;

    Map::reset();
    Map::visitRoom(START_ROOM_X, START_ROOM_Y, OVERWORLD_WIDTH_IN_ROOMS);
}

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

void GameScene::updateGameOver(uint8_t frame) {
    // ghost "floats" into sky
    if (frame == 15 || frame == 30) {
        player.moveTo(player.x + 1, player.y);
    } else if (frame == 45 || frame == 60) {
        player.moveTo(player.x - 1, player.y);
    }

    if (frame % 4 == 1) {
        player.moveTo(player.x, player.y - 1);
    }

    if (teleportTransitionCount > 0) {
        teleportTransitionCount -= 1;
    } else if (arduboy->justPressed(A_BUTTON)) {
        loadSave();
    }
}

void GameScene::renderGameOver(uint8_t frame) {
    renderPlay(frame);

    renderer->translateX = 0;
    renderer->translateY = 0;

        // draw a black rectangle in the middle of the screen that grows
        // as the transition progresses
    uint8_t rectW = 128 - (teleportTransitionCount * 4);
    uint8_t rectH = rectW / 2;
    uint8_t rectX = 64 - rectW / 2;
    uint8_t rectY = 32 - rectH / 2;

    renderer->fillRect(rectX, rectY, rectW, rectH, BLACK);

    renderer->print(40, 20, F("game over"));

    if (teleportTransitionCount == 0) {
        renderer->print(4, HEIGHT - 8, F("press A to load save"));
    }

    player.render(renderer, frame);
}

void GameScene::updateTeleportTransition(uint8_t frame) {
    teleportTransitionCount -= 1;

    if (teleportTransitionCount == WIDTH / 4) {
        entityDefs = entityDefs == dungeons_entities ? overworld_entities : dungeons_entities;
        doorDefs = doorDefs == dungeons_teleporters ? overworld_teleporters : dungeons_teleporters;
        bumperDefs = bumperDefs == dungeons_bumpers ? overworld_bumpers : dungeons_bumpers;
        TileRoom::map = TileRoom::map == dungeons_map ? overworld_map : dungeons_map;
        TileRoom::tiles = TileRoom::tiles == dungeon_tiles ? overworld_tiles : dungeon_tiles;

        // TODO: get rid of this! this is here because for some crazy reason, sometimes
        // TileRoom::map == dungeons_map while in the dungeon is false. No idea why
        // mapType is either 0 or 1 for dungeon and overworld
        TileRoom::mapType = 1 - TileRoom::mapType;

        TileRoom::x = nextRoomX;
        TileRoom::y = nextRoomY;

        loadEntitiesinRoom(TileRoom::x, TileRoom::y);

        Map::reset();
        const uint8_t mapWidthInRooms = TileRoom::isInDungeon() ? DUNGEONS_WIDTH_IN_ROOMS : OVERWORLD_WIDTH_IN_ROOMS;
        Map::visitRoom(nextRoomX, nextRoomY, mapWidthInRooms);

        // plop player in the center of the rooms
        // dest rooms must be able to accomodate this!
        player.moveTo(57, 33, true);
        player.dir = DOWN;

    } else if (teleportTransitionCount == 0) {
        pop();
    }
}

void GameScene::renderTeleportTransition(uint8_t frame) {
    renderPlay(frame);

    renderer->translateX = 0;
    renderer->translateY = 0;

    uint8_t rectH;

    if (teleportTransitionCount > 32) {
        // draw a black rectangle in the middle of the screen that grows
        // as the transition progresses
        rectH = 128 - (teleportTransitionCount * 2);
    } else {
        // now we've switched to the new map, reverse the rectangle
        // and shrink it to nothing
        rectH = teleportTransitionCount * 2;
    }

    uint8_t rectW = rectH * 2;
    uint8_t rectX = 64 - rectW / 2;
    uint8_t rectY = 32 - rectH / 2;

    renderer->fillRect(rectX, rectY, rectW, rectH, BLACK);
}

void GameScene::detectEntityCollisions(void) {
    if (!TileRoom::isInDungeon()) {
        const uint8_t tileId = TileRoom::getTileAt(TileRoom::x, TileRoom::y, player.x, player.y);

        if (tileId == Water || tileId == Stone) {
            player.undoMove();
        }
    }

    for (uint8_t ge = 0; ge < MAX_ENTITIES; ++ge) {
        if (entities[ge].type == UNSET) {
            continue;
        }

        if (entities[ge].overlaps(&player)) {
            if (entities[ge].type == BUMPER) {
                player.undoMove();
            } else if (entities[ge].type == TELEPORTER) {
                // to save memory, teleporters store the next room coordinates
                // in prevX/prevY, two variables they otherwise wouldn't need
                // TODO: is it possible to save the memory without being confusing?
                nextRoomX = entities[ge].prevX;
                nextRoomY = entities[ge].prevY;
                teleportTransitionCount = WIDTH / 2;
                push(&GameScene::updateTeleportTransition, &GameScene::renderTeleportTransition);
            } else if (entities[ge].type == OLD_MAN) {
                if (State::gameState.numAcquiredItems == 0) {
                    player.undoMove();
                    swordWarningCount = 20;
                }
            } else {
                EntityType newEntity = player.onCollide(&entities[ge], &player);
                if (newEntity != UNSET) {
                    spawnNewEntity(newEntity, player);
                }
            }
        }

        for (uint8_t pe = 0; pe < MAX_PLAYER_ENTITIES; ++pe) {
            if (player.entities[pe].type == UNSET) {
                continue;
            }

            if (entities[ge].overlaps(&player.entities[pe])) {
                EntityType newEntity = entities[ge].onCollide(&player.entities[pe], &player);

                if (newEntity != UNSET) {
                    spawnNewEntity(newEntity, entities[ge]);
                }

                newEntity = player.entities[pe].onCollide(&entities[ge], &player);

                if (newEntity != UNSET) {
                    spawnNewEntity(newEntity, player.entities[pe]);
                }
            }
        }
    }
}

void GameScene::goToNextRoom(int16_t x, int16_t y) {
    if (x < 0) {
        nextRoomX = TileRoom::x - 1;
        nextRoomY = TileRoom::y;
        roomTransitionCount = ROOM_WIDTH_PX;

    } else if (x > ROOM_WIDTH_PX) {
        nextRoomX = TileRoom::x + 1;
        nextRoomY = TileRoom::y;
        roomTransitionCount = ROOM_WIDTH_PX;

    } else if (y < 0) {
        nextRoomX = TileRoom::x;
        nextRoomY = TileRoom::y - 1;
        roomTransitionCount = ROOM_HEIGHT_PX;
 
    } else if (y > HEIGHT) {
        nextRoomX = TileRoom::x;
        nextRoomY = TileRoom::y + 1;
        roomTransitionCount = ROOM_HEIGHT_PX;
    }

    push(&GameScene::updateRoomTransition, &GameScene::renderRoomTransition);
}

void GameScene::spawnNewEntity(EntityType entityType, BaseEntity& spawner) {
    uint8_t e = 0;
    for (; e < MAX_ENTITIES; ++e) {
        if (entities[e].type == UNSET) {
            break;
        }
    }

    // no room! can't spawn anything right now
    if (e == MAX_ENTITIES) {
        return;
    }

    loadEntity(entities[e], entityType);
    entities[e].x = spawner.x;
    entities[e].y = spawner.y;
}

void GameScene::loadEntitiesinRoom(uint8_t x, uint8_t y) {
    uint8_t** rowPtr = pgm_read_word(&(entityDefs[y]));
    uint8_t* roomPtr = pgm_read_word(&(rowPtr[x]));

    mapWidthInRooms = pgm_read_byte(TileRoom::map + 2);
    mapHeightInRooms = pgm_read_byte(TileRoom::map + 3);

    uint8_t roomIndex = mapWidthInRooms * y + x;

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
        } else if (type == TELEPORTER) {
            // reuse prevX/Y for destX/Y for doors
            currentEntity.prevX = pgm_read_byte(doorDefs + entityId * 2);
            currentEntity.prevY = pgm_read_byte(doorDefs + entityId * 2 + 1);
        } else if (type == CHEST) {
            // take what is in the chest (which here is entityId), and stick
            // it in the chest's health
            currentEntity.health = entityId;
            if (State::isTriggered(roomIndex)) {
                // frame 1 is the open chest frame, indicates this chest
                // has already been looted
                currentEntity.currentFrame = 1;
            }
        } else {
            currentEntity.prevX = x;
            currentEntity.prevY = y;
        }
    }

    for (; i < MAX_ENTITIES; ++i) {
        entities[i].type = UNSET;
    }
}

boolean GameScene::playerLeftMap(void) {
    if (TileRoom::x == 0 && player.x < 6) {
        return true;
    }

    if (TileRoom::x == mapWidthInRooms - 1 && player.x + player.width > ROOM_WIDTH_PX - 6) {
        return true;
    }

    if (TileRoom::y == 0 && player.y < 8) {
        return true;
    }

    if (TileRoom::y == mapHeightInRooms - 1 && player.y + player.height > ROOM_HEIGHT_PX - 8) {
        return true;
    }

    return false;
}


void GameScene::updatePlay(uint8_t frame) {
    if (paused) {
        if (arduboy->justPressed(B_BUTTON)) {
            paused = false;
        } else {
            return;
        }
    }

    if (arduboy->pressed(A_BUTTON) && arduboy->pressed(B_BUTTON)) {
        if (player.bButtonEntityType != UNSET) {
            menu.decision = player.bButtonEntityType;
            menu.column = 1;
            menu.row = player.bButtonEntityType - 1;
        } else {
            menu.column = 1;
            menu.row = 0;
        }

        push(&GameScene::updateMenu, &GameScene::renderMenu);

        return;
    }

    player.update(&player, arduboy, frame);

    // player is in the middle of showing off a new item,
    // freeze the game while this is happening
    if (player.receiveItemCount > 0) {
        return;
    }

    if (playerLeftMap()) {
        player.undoMove();
    }

    if (swordWarningCount > 0) {
        swordWarningCount -= 1;
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

    if (State::gameState.health <= 0) {
        teleportTransitionCount = WIDTH / 4;
        player.movedThisFrame = false;
        push(&GameScene::updateGameOver, &GameScene::renderGameOver);
    }
}

void GameScene::renderPlay(uint8_t frame) {
    TileRoom::render(renderer, frame);

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

    if (swordWarningCount > 0) {
        renderer->print(0, HEIGHT - 8, F("you need a sword   "));
    }

    renderer->translateX = WIDTH - 16;
    renderer->translateY = 0;
    Hud::render(renderer, frame, player, TileRoom::x, TileRoom::y);
}

void GameScene::updateMenu(uint8_t frame) {
    menu.update(arduboy, frame);

    if (arduboy->justPressed(A_BUTTON)) {
        // respond to the decision
        if (menu.decision == Pause) {
            paused = true;
        } else if (menu.decision == Save) {
            State::saveToEEPROM();
            toastCount = 60;
            toast = F("saved");
        } else if (menu.decision == Load) {
            loadSave();
            toast = F("loaded save");
            toastCount = 60;
            return;
        } else if (menu.decision == DeleteSave) {
            State::clearEEPROM();
            loadSave();
            toast = F("deleted!");
            toastCount = 60;
            return;
        } else if (menu.decision >= BOOMERANG && menu.decision <= CANDLE) {
            player.bButtonEntityType = menu.decision;
            player.entities[1].type = UNSET;
        }

        pop();
    } else if (arduboy->justPressed(B_BUTTON)) {
        // user canceled
        pop();
    }
}

void GameScene::renderMenu(uint8_t frame) {
    menu.render(renderer, frame);

    renderer->translateX = 79;
    renderer->translateY = 17;

    const uint8_t mapWidthInRooms = TileRoom::isInDungeon() ? DUNGEONS_WIDTH_IN_ROOMS : OVERWORLD_WIDTH_IN_ROOMS;
    Map::render(renderer, mapWidthInRooms, TileRoom::x, TileRoom::y);
}

void GameScene::updateRoomTransition(uint8_t frame) {
    roomTransitionCount -= ROOM_TRANSITION_VELOCITY;

    if (roomTransitionCount == 0) {

        if (nextRoomX < TileRoom::x) {
            player.moveTo(ROOM_WIDTH_PX - 1, player.y);
        } else if (nextRoomX > TileRoom::x) {
            player.moveTo(1, player.y);
        } else if (nextRoomY < TileRoom::y) {
            player.moveTo(player.x, ROOM_HEIGHT_PX - 1);
        } else {
            player.moveTo(player.x, 1);
        }

        TileRoom::x = nextRoomX;
        TileRoom::y = nextRoomY;

        const uint8_t mapWidthInRooms = TileRoom::isInDungeon() ? DUNGEONS_WIDTH_IN_ROOMS : OVERWORLD_WIDTH_IN_ROOMS;
        Map::visitRoom(nextRoomX, nextRoomY, mapWidthInRooms);

        loadEntitiesinRoom(nextRoomX, nextRoomY);

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
    if (nextRoomX < TileRoom::x) {
        translateX = ROOM_WIDTH_PX - roomTransitionCount;
    } else if (nextRoomX > TileRoom::x) {
        translateX = roomTransitionCount - ROOM_WIDTH_PX;
    } else if (nextRoomY < TileRoom::y) {
        translateY = ROOM_HEIGHT_PX - roomTransitionCount;
    } else if (nextRoomY > TileRoom::y) {
        translateY = roomTransitionCount - ROOM_HEIGHT_PX;
    }

    renderer->translateX = translateX;
    renderer->translateY = translateY;
    TileRoom::render(renderer, frame);

    // draw next room translated
    int16_t s = (translateX < 0 || translateY < 0) ? 1 : -1;

    renderer->translateX = translateX != 0 ? translateX + (ROOM_WIDTH_PX * s) : 0;
    renderer->translateY = translateY != 0 ? translateY + (ROOM_HEIGHT_PX * s) : 0;
    TileRoom::render(renderer, frame, nextRoomX, nextRoomY);
    
    // draw player translated
    renderer->translateX = translateX;
    renderer->translateY = translateY;
    player.render(renderer, frame);

    renderer->translateX = WIDTH - 16;
    renderer->translateY = 0;
    Hud::render(renderer, frame, player, TileRoom::x, TileRoom::y);
}

void GameScene::update(uint8_t frame) {
    if (toastCount > 0) {
        toastCount -= 1;
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
        renderer->print(0, 30, F("  press B to play  "));
    }

    if (toastCount > 0) {
        renderer->print(0, HEIGHT - 8, toast);
    }

    if (nextRender != NULL) {
        prevRender = currentRender;
        currentRender = nextRender;
        nextRender = NULL;
    }
}
