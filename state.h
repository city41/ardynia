#ifndef state_h
#define state_h

#include <Arduino.h>

const uint8_t MAX_ROOM_COUNT = 152;
const uint8_t DUNGEON_ROOM_OFFSET = 4; // this will be 64 for the full map
const uint8_t MAX_KEYS = 6;

// hoo boy, just randomly grabbed this
const uint8_t GAME_ID = 81;
// hoo boy, just randomly grabbed this too O_o
const uint8_t EEPROM_START = 64;

struct GameState {
    int8_t health;
    int8_t totalHealth;
    uint8_t acquiredItemsBitMask;
    uint8_t beatenBossesBitMask;
    uint8_t numKeys;
    uint8_t numBombs;

    // the room states. Each room gets one bit. This means each room
    // can only have ONE thing about it that is stateful. That means each
    // room can only have one chest OR one locked door, etc. It is not allowed
    // for a single room to have both a chest and a key for example, one or the other
    uint8_t roomStates[MAX_ROOM_COUNT / 8];
};

class State {
    public:
        static GameState gameState;
        static bool isTriggered(uint8_t roomIndex);
        static void setTriggered(uint8_t roomIndex);

        static bool hasUserSaved();
        static void saveToEEPROM();
        static void clearEEPROM();
        static void load();
};

#endif

