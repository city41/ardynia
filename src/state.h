#ifndef state_h
#define state_h

#include <Arduino.h>

// counting the overworld as a "dungeon" and all 5 secret areas
// as a single "dungeon"
const uint8_t MAX_DUNGEON_COUNT = 5;
const uint8_t MAX_ROOM_COUNT = (8 * 8) + (7 * 6);
const uint8_t ROOM_STATE_BYTE_COUNT = MAX_ROOM_COUNT / 8 + 1;
const uint8_t DUNGEON_ROOM_OFFSET = 7 * 6;
const uint8_t MAX_KEYS = 6;

const uint8_t GAME_ID = 81;
const uint8_t EEPROM_START = 64;

struct GameState {
    int8_t totalHealth;
    int8_t hasSword;
    int8_t numAcquiredItems;
    int8_t numKeys[MAX_DUNGEON_COUNT];
    int8_t bossKeys[MAX_DUNGEON_COUNT];
    uint8_t currentDungeon;

    // the room states. Each room gets one bit. This means each room
    // can only have ONE thing about it that is stateful. That means each
    // room can only have one chest OR one locked door, etc. It is not allowed
    // for a single room to have both a chest and a locked door for example, one or the other
    // 
    // The +1 is because the number of rooms is not necessarily divisible by 8, there
    // are some leftover bits we need to store
    uint8_t roomStates[ROOM_STATE_BYTE_COUNT];
    uint8_t mapStates[4][8];
};

class State {
    public:
        static GameState gameState;
        static bool isTriggered(uint8_t roomIndex, bool considerMap = true);
        static void setTriggered(uint8_t roomIndex);
        static void setCurrentRoomTriggered();

        static bool isInDungeon() { return gameState.currentDungeon > 0; }

        static bool hasUserSaved();
        static void saveToEEPROM();
        static void clearEEPROM();
        static void load();
};

#endif

