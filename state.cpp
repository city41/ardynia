#include "state.h"

uint8_t State::overworldRoomStates[MAX_NUM_OVERWORLD_ROOMS / 8] = { 0 };

boolean State::isTriggered(uint8_t roomIndex, uint8_t* roomStates) {
    const uint8_t byteToGrab = roomIndex >> 3;
    const uint8_t bitToGrab = roomIndex % 8;
    const uint8_t bitMask = 1 << bitToGrab;

    return roomStates[byteToGrab] & bitMask;
}

void State::setTriggered(uint8_t roomIndex, uint8_t* roomStates) {
    const uint8_t byteToSet = roomIndex >> 3;
    const uint8_t bitToSet = roomIndex % 8;
    const uint8_t bitMask = 1 << bitToSet;

    roomStates[byteToSet] |= bitMask;
}
