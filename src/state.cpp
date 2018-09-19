#include "state.h"
#include "tileRoom.h"


GameState State::gameState = {};

/**
 * Tells whether a given room's state has triggered.
 * So if this returns true, it means this room's chest is open,
 * key is taken, etc.
 */
bool State::isTriggered(uint8_t roomIndex) {
    // setting state will only ever happen in "real time", so
    // let's hide the overworld/dungeon distinction from the rest of the game
    if (isInDungeon()) {
        roomIndex += DUNGEON_ROOM_OFFSET;
    }

    const uint8_t byteToGrab = roomIndex >> 3;
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

    const uint8_t byteToSet = roomIndex >> 3;
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
        gameState.numAcquiredItems = 0;
        gameState.currentDungeon = -1;
        memset(gameState.numKeys, 0, MAX_DUNGEON_COUNT);
        memset(gameState.bossKeys, 0, MAX_DUNGEON_COUNT);
        
        // this may not be necessary, but rather play it safe
        memset(gameState.roomStates, 0, MAX_ROOM_COUNT);
    }
}

void State::clearEEPROM() {
    if (hasUserSaved()) {
        EEPROM.put(EEPROM_START, 0);
        load();
    }
}

