#include "state.h"
#include "tileRoom.h"

// this DOES initialize the entire array to zero, phew
uint8_t State::roomStates[MAX_ROOM_COUNT / 8] = {};

boolean State::isTriggered(uint8_t roomIndex) {
    // setting state will only ever happen in "real time", so
    // let's hide the overworld/dungeon distinction from the rest of the game
    if (TileRoom::isInDungeon()) {
        roomIndex += DUNGEON_ROOM_OFFSET;
    }

    const uint8_t byteToGrab = roomIndex >> 3;
    const uint8_t bitToGrab = roomIndex % 8;
    const uint8_t bitMask = 1 << bitToGrab;

    return roomStates[byteToGrab] & bitMask;
}

void State::setTriggered(uint8_t roomIndex) {
    if (TileRoom::isInDungeon()) {
        roomIndex += DUNGEON_ROOM_OFFSET;
    }

    const uint8_t byteToSet = roomIndex >> 3;
    const uint8_t bitToSet = roomIndex % 8;
    const uint8_t bitMask = 1 << bitToSet;

    roomStates[byteToSet] |= bitMask;
}
