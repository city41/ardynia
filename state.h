#ifndef state_h
#define state_h

#include <Arduino.h>

const uint8_t MAX_NUM_OVERWORLD_ROOMS = 8;
const uint8_t MAX_NUM_DUNGEON_ROOMS = 0;

class State {
    public:
        static uint8_t overworldRoomStates[MAX_NUM_OVERWORLD_ROOMS / 8];
        static bool isTriggered(uint8_t roomIndex, uint8_t* roomStates);
        static void setTriggered(uint8_t roomIndex, uint8_t* roomStates);
};

#endif

