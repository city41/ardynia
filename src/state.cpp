#include "state.h"
#include "tileRoom.h"


GameState State::gameState = {};

/**
 * Tells whether a given room's state has triggered.
 * So if this returns true, it means this room's chest is open,
 * key is taken, etc.
 */
bool State::isTriggered(uint8_t roomIndex, bool considerMap) {
    // setting state will only ever happen in "real time", so
    // let's hide the overworld/dungeon distinction from the rest of the game
    if (considerMap && isInDungeon()) {
        roomIndex += DUNGEON_ROOM_OFFSET;
    }

    const uint8_t byteToGrab = roomIndex / 8;
    const uint8_t bitToGrab = roomIndex % 8;
    const uint8_t bitMask = 1 << bitToGrab;

    return gameState.roomStates[byteToGrab] & bitMask;
}

/**
 * Set the state for a room. ie after the user takes a key, call this method
 * So the key never respawns again
 */
void State::setTriggered(uint8_t roomIndex) {
    if (isInDungeon()) {
        roomIndex += DUNGEON_ROOM_OFFSET;
    }

    const uint8_t byteToSet = roomIndex / 8;
    const uint8_t bitToSet = roomIndex % 8;
    const uint8_t bitMask = 1 << bitToSet;

    gameState.roomStates[byteToSet] |= bitMask;
}

void State::setCurrentRoomTriggered() {
    const uint8_t roomIndex = TileRoom::getRoomIndex(TileRoom::x, TileRoom::y);
    setTriggered(roomIndex);
    saveToEEPROM();
}

bool State::hasUserSaved() {
    uint8_t id;
    EEPROM.get(EEPROM_START, id);

    return id == GAME_ID;
}

void State::saveToEEPROM() {
    EEPROM.write(EEPROM_START, GAME_ID);
    EEPROM.put(EEPROM_START + 1, gameState);
}

void State::load() {
    if (hasUserSaved()) {
        EEPROM.get(EEPROM_START + 1, gameState);
    } else {
        gameState.totalHealth = 2;
        gameState.hasSword = 0;
        gameState.numAcquiredItems = 0;
        gameState.currentDungeon = 0;

        uint8_t i = 0;
        for (; i < MAX_DUNGEON_COUNT; ++i) {
            gameState.numKeys[i] = 0;
            gameState.bossKeys[i] = 0;
        }
        
        for (i = 0; i < ROOM_STATE_BYTE_COUNT; ++i) {
            gameState.roomStates[i] = 0;
        }

        for (i = 0; i < 4; ++i) {
            for (uint8_t m = 0; m < 8; ++m) {
                gameState.mapStates[i][m] = 0;
            }
        }
    }
}

void State::clearEEPROM() {
    EEPROM.put(EEPROM_START, 0);
    load();
}

