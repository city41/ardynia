#ifndef state_h
#define state_h

#include <Arduino.h>

const uint8_t MAX_ROOM_COUNT = 152;
const uint8_t DUNGEON_ROOM_OFFSET = 4; // this will be 64 for the full map

class State {
    public:
        static uint8_t roomStates[MAX_ROOM_COUNT / 8];
        static bool isTriggered(uint8_t roomIndex);
        static void setTriggered(uint8_t roomIndex);
};

#endif

