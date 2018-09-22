#include "game.h"
#include "util.h"
#include "entityTemplates.h"
#include "state.h"
#include "map.h"
#include "tileBitmaps.h"
#include "strings.h"
#include "sfx.h"
#include "entities/nemesis.h"

const uint8_t ROOM_TRANSITION_VELOCITY = 2;
const uint8_t ROOM_WIDTH_PX = WIDTH - 16;
const uint8_t ROOM_HEIGHT_PX = HEIGHT;

const int8_t newGameLabel[] PROGMEM = "NEW GAME";
const int8_t continueLabel[] PROGMEM = "CONTINUE";
const int8_t deleteSaveLabel[] PROGMEM = "DELETE SAVE";

const uint8_t PLAY_GAME = 0;
const uint8_t SFX_ON_OFF = 1;
const uint8_t DELETE_SAVE = 2;

const uint8_t PROGMEM startingRooms[8] = {
    1, 4, // overworld (x, y)
    0, 7, // first dungeon
    3, 7, // second dungeon
    6, 0  // third dungeon
};


/**
 * Resets the game back to the last save. If there is no save,
 * resets back to the beginning of the game
 *
 * @param {bool} straightToPlay whether to skip the title screen
 */
void Game::loadSave(bool straightToPlay) {
    State::load();

    if (State::gameState.currentDungeon == -1) {
        TileRoom::map = overworld_map;
        entityDefs = overworld_entities;
        doorDefs = overworld_teleporters;
        mapWidthInRooms = OVERWORLD_WIDTH_IN_ROOMS;
        mapHeightInRooms = OVERWORLD_HEIGHT_IN_ROOMS;
    } else {
        TileRoom::map = dungeons_map;
        entityDefs = dungeons_entities;
        doorDefs = dungeons_teleporters;
        mapWidthInRooms = DUNGEONS_WIDTH_IN_ROOMS;
    }

    TileRoom::x = pgm_read_byte(startingRooms + (State::gameState.currentDungeon + 1) * 2);
    TileRoom::y = pgm_read_byte(startingRooms + (State::gameState.currentDungeon + 1) * 2 + 1);

    TileRoom::loadRoom(TileRoom::x, TileRoom::y, TileRoom::currentRoomOffset);
    loadEntitiesInRoom(TileRoom::x, TileRoom::y);

    player.reset();

    if (straightToPlay) {
        currentUpdate = &Game::updatePlay;
        currentRender = &Game::renderPlay;
    } else {
        currentUpdate = &Game::updateTitle;
        currentRender = &Game::renderTitle;
    }

    Map::reset();
    Map::visitRoom(TileRoom::x, TileRoom::y, mapWidthInRooms);
}

/**
 * push a game state onto the "stack". The stack can only go two deep.
 * This is used to go from play -> inGameMenu, for example.
 */
void Game::push(UpdatePtr newUpdate, RenderPtr newRender) {
    nextUpdate = newUpdate;
    nextRender = newRender;
}

/**
 * Go back one level in the "stack", ie from inGameMenu back to play
 */
void Game::pop() {
    nextUpdate = prevUpdate;
    nextRender = prevRender;
}

void Game::updateGameOver(uint8_t frame) {
    if (teleportTransitionCount > 0) {
        teleportTransitionCount -= 1;
    } else if (arduboy.justPressed(A_BUTTON)) {
        loadSave(true);
    } else if (arduboy.justPressed(B_BUTTON)) {
        loadSave();
    }
}

void Game::renderGameOver(uint8_t frame) {
    renderPlay(frame);

    renderer.translateX = 0;
    renderer.translateY = 0;

    // draw a black rectangle in the middle of the screen that grows
    // as the transition progresses
    // TODO: this is similar to renderTeleportTransition, can this be DRY'd?
    uint8_t rectW = 128 - (teleportTransitionCount * 4);
    uint8_t rectH = rectW / 2;
    uint8_t rectX = 64 - rectW / 2;
    uint8_t rectY = 32 - rectH / 2;

    renderer.fillRect(rectX, rectY, rectW, rectH, BLACK);

    renderer.drawString(40, 20, gameOver_string);

    if (teleportTransitionCount == 0) {
        renderer.drawString(32, HEIGHT - 10, continueFromGameOver_string);
        renderer.drawString(32, HEIGHT - 5, quitFromGameOver_string);
    }
}

void Game::updateTeleportTransition(uint8_t frame) {
    teleportTransitionCount -= 1;

    if (teleportTransitionCount == WIDTH / 4) {
        entityDefs = entityDefs == dungeons_entities ? overworld_entities : dungeons_entities;
        doorDefs = doorDefs == dungeons_teleporters ? overworld_teleporters : dungeons_teleporters;
        TileRoom::map = TileRoom::map == dungeons_map ? overworld_map : dungeons_map;

        State::gameState.currentDungeon = State::gameState.currentDungeon == -1 ? nextRoomX / 3 : -1;
        State::saveToEEPROM();
        

        TileRoom::x = nextRoomX;
        TileRoom::y = nextRoomY;

        loadEntitiesInRoom(nextRoomX, nextRoomY);
        TileRoom::loadRoom(nextRoomX, nextRoomY, TileRoom::currentRoomOffset);

        Map::reset();
        mapWidthInRooms = State::isInDungeon() ? DUNGEONS_WIDTH_IN_ROOMS : OVERWORLD_WIDTH_IN_ROOMS;
        mapHeightInRooms = State::isInDungeon() ? 0 : OVERWORLD_HEIGHT_IN_ROOMS;
        Map::visitRoom(nextRoomX, nextRoomY, mapWidthInRooms);

        // plop player in the center of the rooms
        // dest rooms must be able to accomodate this!
        player.moveTo(57, 33, true);
        player.dir = DOWN;

        // for example, if the player had a flying boomerang,
        // this causes it to go away, doesn't make sense
        // for it to survive a teleport
        player.entities[0].type = UNSET;
        player.entities[1].type = UNSET;
    } else if (teleportTransitionCount == 0) {
        pop();
    }
}

void Game::renderTeleportTransition(uint8_t frame) {
    renderPlay(frame);

    renderer.translateX = 0;
    renderer.translateY = 0;

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

    renderer.fillRect(rectX, rectY, rectW, rectH, BLACK);
}

void Game::detectEntityCollisions(void) {
    // first let the entities duke it out
    for (uint8_t ge = 0; ge < MAX_ENTITIES; ++ge) {
        if (entities[ge].type == UNSET) {
            continue;
        }

        if (entities[ge].overlaps(player)) {
            if (entities[ge].type == TELEPORTER) {
                // to save memory, teleporters store the next room coordinates
                // in prevX/prevY, two variables they otherwise wouldn't need
                // TODO: is it possible to save the memory without being confusing?
                nextRoomX = entities[ge].prevX;
                nextRoomY = entities[ge].prevY;
                teleportTransitionCount = WIDTH / 2;
                push(&Game::updateTeleportTransition, &Game::renderTeleportTransition);
            } else if (entities[ge].type == SECRET_WALL || entities[ge].type == LOCK || entities[ge].type == BOSS_LOCK || entities[ge].type == TRIGGER_DOOR) {
                if (entities[ge].health == 1) {
                    player.undoMove();
                }
            } else {
                EntityType newEntity = player.onCollide(entities[ge], player, *this);
                spawnNewEntity(newEntity, player);
            }

            entities[ge].onCollide(player, player, *this);
        }

        for (uint8_t pe = 0; pe < MAX_PLAYER_ENTITIES; ++pe) {
            if (player.entities[pe].type == UNSET) {
                continue;
            }

            if (entities[ge].overlaps(player.entities[pe])) {
                EntityType newEntity = entities[ge].onCollide(player.entities[pe], player, *this);

                spawnNewEntity(newEntity, entities[ge]);

                newEntity = player.entities[pe].onCollide(entities[ge], player, *this);
                spawnNewEntity(newEntity, player.entities[pe]);
            }
        }
    }

    if (Nemesis::sword.type == SWORD && Nemesis::sword.overlaps(player)) {
        player.onCollide(Nemesis::sword, player, *this);
    }

    // now let's confirm the player has stayed on the screen

    if (Util::isOffScreen(player.x, player.y)) {
        // if the player just went off the screen, did they legit go through a "passageway"?
        // if not, prevent them leaving the screen
        const uint8_t prevTileId = TileRoom::getTileAt(player.prevX, player.prevY);

        if (
            (player.x < 0 && prevTileId != Blank && prevTileId != UpperWall && prevTileId != LowerWall && prevTileId != RightWall) ||
            (player.x >= ROOM_WIDTH_PX && prevTileId != Blank && prevTileId != UpperWall && prevTileId != LowerWall && prevTileId != LeftWall) ||
            (player.y < 0 && prevTileId != Blank && prevTileId != LeftWall && prevTileId != RightWall && prevTileId != LowerWall) ||
            (player.y >= ROOM_HEIGHT_PX && prevTileId != Blank && prevTileId != LeftWall && prevTileId != RightWall && prevTileId != UpperWall)
        ) {
            if (!State::isInDungeon() || prevTileId != LeftFlavor || prevTileId != RightFlavor) {
                player.undoMove();
            }
        }
    } else {
        // otherwise the player is on screen, did they just walk onto something that is solid?
        // then prevent them walking on it
        const uint8_t currentTileId = TileRoom::getTileAt(player.x, player.y);

        // TODO: can we group these together so this can become a >=|<= check?
        // or add a solid mask to the tile id
        if (
            currentTileId == Water ||
            currentTileId == Stone || 
            currentTileId == LeftFlavor ||
            currentTileId == RightFlavor
        ) {
            player.undoMove();
        }
    }

}

void Game::goToNextRoom(int16_t x, int16_t y) {
    if (x < 0) {
        nextRoomX = TileRoom::x - 1;
        nextRoomY = TileRoom::y;
        roomTransitionCount = ROOM_WIDTH_PX;

    } else if (x >= ROOM_WIDTH_PX) {
        nextRoomX = TileRoom::x + 1;
        nextRoomY = TileRoom::y;
        roomTransitionCount = ROOM_WIDTH_PX;

    } else if (y < 0) {
        nextRoomX = TileRoom::x;
        nextRoomY = TileRoom::y - 1;
        roomTransitionCount = ROOM_HEIGHT_PX;
 
    } else if (y >= ROOM_HEIGHT_PX) {
        nextRoomX = TileRoom::x;
        nextRoomY = TileRoom::y + 1;
        roomTransitionCount = ROOM_HEIGHT_PX;
    }
    TileRoom::loadRoom(nextRoomX, nextRoomY, TileRoom::nextRoomOffset);

    firstRoomTransitionFrame = true;
    push(&Game::updateRoomTransition, &Game::renderRoomTransition);
}

int8_t Game::spawnNewEntity(EntityType entityType, Entity& spawner) {
    if (entityType == UNSET) {
        return -1;
    }

    int8_t e = 0;
    for (; e < MAX_ENTITIES; ++e) {
        if (entities[e].type == UNSET) {
            break;
        }
    }

    // no room! can't spawn anything right now
    if (e == MAX_ENTITIES) {
        return -1;
    }

    loadEntity(entities[e], entityType);
    int16_t offsetX = (entities[e].width - spawner.width) / 2;
    int16_t offsetY = (entities[e].height - spawner.height) / 2;
    entities[e].x = spawner.x - offsetX;
    entities[e].y = spawner.y - offsetY;

    return e;
}

void Game::loadEntitiesInRoom(uint8_t x, uint8_t y) {
    uint8_t** rowPtr = pgm_read_word(entityDefs + y);
    uint8_t* roomPtr = pgm_read_word(rowPtr + x);

    uint8_t roomIndex = mapWidthInRooms * y + x;

    uint8_t numEntitiesInCurrentRoom = pgm_read_byte(roomPtr++);

    int8_t i = 0;
    bool roomIsTriggered = State::isTriggered(roomIndex);
    roomType = NORMAL;
    bool isDefeatedSlamShutRoom = false;

    for (; i < numEntitiesInCurrentRoom; ++i) {
        uint8_t rawEntityType = (uint8_t)pgm_read_byte(roomPtr++);
        EntityType type = rawEntityType & ENTITY_MASK;
        uint8_t entityMisc = (rawEntityType >> 5) & ENTITY_MISC_MASK;


        Entity& currentEntity = entities[i];

        loadEntity(currentEntity, type);

        const uint8_t xy = pgm_read_byte(roomPtr++);

        // to get x, multiply the x component by 8.
        // turns out can do that by shifting it down once
        currentEntity.x = (xy & 0xF0) >> 1;

        // for y, multiply the y nibble by 4
        currentEntity.y = (xy & 0x0F) << 2;

        if (type == TELEPORTER || type == SECRET_WALL) {
            // reuse prevX/Y for destX/Y for doors
            currentEntity.prevX = pgm_read_byte(doorDefs + entityMisc * 2);
            currentEntity.prevY = pgm_read_byte(doorDefs + entityMisc * 2 + 1);

            if (type == SECRET_WALL) {
                // wall has already been blown up
                if (roomIsTriggered) {
                    currentEntity.currentFrame = 1;
                    currentEntity.health = 0;
                    TileRoom::setTileAt(currentEntity.x, currentEntity.y, Blank, TileRoom::nextRoomOffset);
                }
            }
        } else if (type == CHEST || type == POT) {
            // take what is in the chest (which here is entityMisc), and stick
            // it in the chest's health
            currentEntity.health = entityMisc;
            if (type == CHEST && roomIsTriggered) {
                // frame 1 is the open chest frame, indicates this chest
                // has already been looted
                currentEntity.currentFrame = 1;
            }
        } else if ((type == LOCK || type == KEY) && roomIsTriggered) {
            currentEntity.type = UNSET;
        } else if (entityMisc > 0) {
            roomType = entityMisc;

            if (roomType == SLAM_SHUT && roomIsTriggered) {
                currentEntity.type = UNSET;
                roomType = NORMAL;
                isDefeatedSlamShutRoom = true;
            } else if (roomType == LAST_ENEMY_HAS_KEY && roomIsTriggered) {
                roomType = NORMAL;
                loadEntity(currentEntity, CHEST);
                currentEntity.currentFrame = 1;
                currentEntity.x = (ROOM_WIDTH_PX / 2) - 8;
                currentEntity.y = (ROOM_HEIGHT_PX / 2) - 4;
            }
        }
    }

    for (; i < MAX_ENTITIES; ++i) {
        entities[i].type = UNSET;
    }

    Nemesis::sword.type = UNSET;

    if (isDefeatedSlamShutRoom) {
        removeAllTriggerDoors();
    }
}

void Game::removeAllTriggerDoors() {
    for (uint8_t ge = 0; ge < MAX_ENTITIES; ++ge) {
        if (entities[ge].type == TRIGGER_DOOR) {
            entities[ge].type = UNSET;
        }
    }
}

void Game::emergeAllBridges() {
    for (uint8_t ge = 0; ge < MAX_ENTITIES; ++ge) {
        if (entities[ge].type == SUNKEN_BRIDGE) {
            TileRoom::setTileAt(entities[ge].x, entities[ge].y, TileRoom::currentRoomOffset, Ladder);
        }
    }
}

void Game::updateTitle(uint8_t frame) {
    if (arduboy.justPressed(A_BUTTON)) {
        if (titleRow == PLAY_GAME) {
            loadSave();
            push(&Game::updatePlay, &Game::renderPlay);
        } else if (titleRow == DELETE_SAVE) {
            titleRow = 0;
            State::clearEEPROM();
        } else if (titleRow == SFX_ON_OFF) {
            Arduboy2Audio::toggle();
            Arduboy2Audio::saveOnOff();
        }
    }

    uint8_t rows = State::hasUserSaved() ? 2 : 1;

    if (arduboy.justPressed(UP_BUTTON)) {
        titleRow = Util::clamp(titleRow - 1, 0, rows);
    }

    if (arduboy.justPressed(DOWN_BUTTON)) {
        titleRow = Util::clamp(titleRow + 1, 0, rows);
    }
}

void Game::renderTitle(uint8_t frame) {
    renderer.drawOverwrite(35, 7, title_tiles, 0);

    const uint8_t* startGameLabel = State::hasUserSaved() ? continue_string : newGame_string;

    renderer.drawString(42, 42, startGameLabel);
    renderer.drawString(42, 50, Arduboy2Audio::enabled() ? sfxOn_string : sfxOff_string);

    if (State::hasUserSaved()) {
        renderer.drawString(42, 58, deleteSave_string);
    }

    renderer.drawRect(34, 42 + titleRow * 8, 4, 4, WHITE);
}

void Game::updatePlay(uint8_t frame) {
    if (swapRooms) {
        TileRoom::swapRooms();
        swapRooms = false;
    }

    if (bossDelayCount > 0) {
        bossDelayCount -= 1;
        return;
    }

    if (arduboy.pressed(LEFT_BUTTON | DOWN_BUTTON | RIGHT_BUTTON)) {
        if (player.bButtonEntityType != UNSET) {
            menu.chosenItem = player.bButtonEntityType;
            menu.row = player.bButtonEntityType - 1;
        } else {
            menu.row = 0;
        }

        push(&Game::updateMenu, &Game::renderMenu);

        return;
    }

    player.update(player, arduboy, frame);

    // player is in the middle of showing off a new item,
    // freeze the game while this is happening
    if (player.receiveItemCount > 0) {
        return;
    }

    int8_t e = 0;
    for (; e < MAX_PLAYER_ENTITIES; ++e) {
        Entity& entity = player.entities[e];

        EntityType newEntity = entity.update(player, arduboy, frame);
        loadEntity(player.entities[e], newEntity);
    }

    for (e = 0; e < MAX_ENTITIES; ++e) {
        Entity& entity = entities[e];

        EntityType newEntity = entity.update(player, arduboy, frame);
        spawnNewEntity(newEntity, entity);
    }

    detectEntityCollisions();

    if (Util::isOffScreen(player.x, player.y)) {
        goToNextRoom(player.x, player.y);
    }

    if (player.health <= 0) {
        teleportTransitionCount = WIDTH / 4;
        player.movedThisFrame = false;
        push(&Game::updateGameOver, &Game::renderGameOver);
    }

    if (roomType == SLAM_SHUT || roomType == LAST_ENEMY_HAS_KEY) {
        bool stillHasEnemies = false;

        for (e = 0; e < MAX_ENTITIES; ++e) {
            if (entities[e].type >= BLOB && entities[e].type <= NEMESIS) {
                stillHasEnemies = true;
                break;
            }
        }

        if (!stillHasEnemies) {
            if (roomType == SLAM_SHUT) {
                removeAllTriggerDoors();
                State::setCurrentRoomTriggered();
            } else {
                e = spawnNewEntity(CHEST, player);
                entities[e].x = (ROOM_WIDTH_PX / 2) - 8;
                entities[e].y = (ROOM_HEIGHT_PX / 2) - 4;
                entities[e].health = KEY;
            }

            roomType = NORMAL;
        }
    }
}

void Game::renderPlay(uint8_t frame) {
    TileRoom::renderRoom(renderer, TileRoom::currentRoomOffset);

    int8_t e = 0;
    for(; e < MAX_ENTITIES; ++e) {
        entities[e].render(renderer, frame);
    }

    for (e = 0; e < MAX_PLAYER_ENTITIES; ++e) {
        player.entities[e].render(renderer, frame);
    }

    player.render(renderer, frame);

    Nemesis::sword.render(renderer, frame);

    renderer.translateX = WIDTH - 16;
    renderer.translateY = 0;
    Hud::render(renderer, player);
}

void Game::updateMenu(uint8_t frame) {
    menu.update(arduboy, frame);

    if (arduboy.justPressed(A_BUTTON)) {
        // respond to the decision
        if (menu.chosenItem != UNSET && menu.chosenItem != player.bButtonEntityType) {
            player.bButtonEntityType = menu.chosenItem;
            player.entities[1].type = UNSET;
        }

        pop();
    }
}

void Game::renderMenu(uint8_t frame) {
    menu.render(renderer, player, frame);

    renderer.translateX = 54;
    renderer.translateY = 0;

    Map::render(renderer, mapWidthInRooms, mapHeightInRooms, TileRoom::x, TileRoom::y);
}

void Game::updateRoomTransition(uint8_t frame) {
    roomTransitionCount -= ROOM_TRANSITION_VELOCITY;

    if (firstRoomTransitionFrame) {
        firstRoomTransitionFrame = false;
        loadEntitiesInRoom(nextRoomX, nextRoomY);
    }

    if (roomTransitionCount == 0) {
        swapRooms = true;

        if (nextRoomX < TileRoom::x) {
            player.moveTo(ROOM_WIDTH_PX, player.y, true);
        } else if (nextRoomX > TileRoom::x) {
            player.moveTo(0, player.y, true);
        } else if (nextRoomY < TileRoom::y) {
            player.moveTo(player.x, ROOM_HEIGHT_PX, true);
        } else {
            player.moveTo(player.x, 0, true);
        }

        uint8_t offset = 4;

        if (roomType == SLAM_SHUT) {
            offset = 17;
            bossDelayCount = 120;
            Sfx::playerDamage(10);
        }

        player.stayInside(offset, ROOM_WIDTH_PX - offset, offset, ROOM_HEIGHT_PX - offset);

        TileRoom::x = nextRoomX;
        TileRoom::y = nextRoomY;

        Map::visitRoom(nextRoomX, nextRoomY, mapWidthInRooms);

        // for example, if the player had a flying boomerang,
        // this causes it to go away, easier than trying to deal
        // with items that can span across rooms O_o
        player.entities[0].type = UNSET;
        player.entities[1].type = UNSET;

        pop();
    }
}

void Game::renderRoomTransition(uint8_t frame) {
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

    renderer.translateX = translateX;
    renderer.translateY = translateY;
    TileRoom::renderRoom(renderer, TileRoom::currentRoomOffset);

    // draw next room translated
    int8_t s = (translateX < 0 || translateY < 0) ? 1 : -1;

    renderer.translateX = translateX != 0 ? translateX + (ROOM_WIDTH_PX * s) : 0;
    renderer.translateY = translateY != 0 ? translateY + (ROOM_HEIGHT_PX * s) : 0;
    TileRoom::renderRoom(renderer, TileRoom::nextRoomOffset);

    for (uint8_t ge = 0; ge < MAX_ENTITIES; ++ge) {
        entities[ge].render(renderer, frame);
    }
    
    // draw player and entities translated
    renderer.translateX = translateX;
    renderer.translateY = translateY;
    player.render(renderer, frame);

    renderer.translateX = WIDTH - 16;
    renderer.translateY = 0;
    Hud::render(renderer, player);
}

void Game::update(uint8_t frame) {
    (this->*currentUpdate)(frame);

    if (nextUpdate != NULL) {
        prevUpdate = currentUpdate;
        currentUpdate = nextUpdate;
        nextUpdate = NULL;
    }
}

void Game::render(uint8_t frame) {
    renderer.translateX = 0;
    renderer.translateY = 0;

    (this->*currentRender)(frame);

    renderer.translateX = 0;
    renderer.translateY = 0;

    if (nextRender != NULL) {
        prevRender = currentRender;
        currentRender = nextRender;
        nextRender = NULL;
    }
}
