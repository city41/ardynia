#ifndef dungeons_h
#define dungeons_h

#include "emptyRoom.h"
#include "entityTypes.h"
#include "entityExpressions.h"


const uint8_t PROGMEM dungeons_map[603] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    91, 2, 10, 6,
    // room indices (16 bit, little endian), 120 bytes
    0, 0, 10, 0, 20, 0, 28, 0, 33, 0, 38, 0, 43, 0, 48, 0, 53, 0, 61, 0, 71, 0, 82, 0, 90, 0, 95, 0, 100, 0, 105, 0, 113, 0, 121, 0, 126, 0, 129, 0, 137, 0, 149, 0, 159, 0, 167, 0, 172, 0, 181, 0, 191, 0, 201, 0, 211, 0, 219, 0, 227, 0, 238, 0, 243, 0, 251, 0, 5, 1, 16, 1, 24, 1, 29, 1, 37, 1, 47, 1, 57, 1, 67, 1, 76, 1, 84, 1, 92, 1, 97, 1, 105, 1, 113, 1, 118, 1, 128, 1, 138, 1, 147, 1, 154, 1, 163, 1, 173, 1, 183, 1, 188, 1, 196, 1, 205, 1, 214, 1,
    // compressed room data, 479 bytes
    31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 31, 109, 47, 96, 47, 96, 175, 99, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 247, 223, 240, 246, 0, 247, 223, 240, 246, 0, 246, 219, 246, 14, 246, 14, 246, 14, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 31, 93, 178, 245, 14, 47, 80, 234, 51, 3, 60, 47, 96, 47, 96, 47, 96, 47, 96, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 246, 219, 246, 14, 246, 14, 246, 14, 47, 96, 47, 96, 47, 96, 47, 96, 255, 15, 96, 247, 48, 255, 15, 208, 246, 219, 246, 14, 246, 14, 246, 14, 29, 208, 221, 178, 245, 14, 47, 80, 234, 51, 3, 60, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 31, 109, 47, 96, 47, 96, 47, 96, 247, 223, 224, 247, 48, 246, 219, 246, 14, 246, 14, 48, 244, 60, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 47, 96, 47, 96, 47, 96, 47, 96, 246, 14, 246, 14, 246, 14, 246, 60, 29, 208, 221, 223, 70, 85, 98, 246, 10, 246, 48, 247, 223, 118, 254, 0, 246, 14, 247, 111, 96, 239, 99, 192, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 16, 244, 219, 47, 80, 226, 245, 14, 175, 83, 192, 47, 96, 47, 96, 47, 96, 47, 96, 247, 223, 224, 247, 48, 246, 14, 246, 14, 246, 14, 246, 60, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 47, 96, 47, 96, 47, 96, 79, 80, 48, 246, 219, 246, 14, 246, 14, 246, 60, 47, 96, 47, 96, 47, 96, 175, 99, 247, 223, 240, 246, 0, 246, 14, 246, 14, 246, 14, 246, 14, 31, 109, 47, 96, 47, 96, 175, 99, 247, 223, 240, 245, 4, 246, 14, 246, 14, 246, 14, 64, 68, 64, 64, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 247, 66, 246, 2, 246, 10, 51, 3, 51, 79, 80, 79, 208, 79, 99, 64, 247, 79, 112, 74, 12, 245, 67, 244, 64, 31, 93, 191, 96, 226, 245, 14, 175, 83, 192, 47, 96, 47, 96, 47, 96, 148, 48, 52, 128, 255, 15, 96, 247, 48, 246, 219, 246, 14, 246, 14, 246, 60, 47, 80, 66, 246, 2, 246, 10, 246, 48, 144, 132, 144, 143, 224, 51, 48, 51, 48, 79, 93, 191, 96, 239, 96, 239, 99, 192
};

const uint8_t PROGMEM dungeons_room0_1[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(4, CHEST),
    xy(40, 24),
};



const uint8_t PROGMEM dungeons_room0_2[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(1, BLOB_MOTHER),
    xy(40, 16),

    // entity 1
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(48, 56),

    // entity 2
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(48, 0),
};



const uint8_t PROGMEM dungeons_room0_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, BOSS_LOCK),
    xy(48, 0),
};



const uint8_t PROGMEM dungeons_room0_5[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, TELEPORTER),
    xy(48, 52),
};



const uint8_t PROGMEM dungeons_room2_4[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, BAT),
    xy(32, 32),

    // entity 1
    miscAndEntityType(2, BAT),
    xy(64, 44),
};



const uint8_t PROGMEM dungeons_room2_5[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(96, 20),
};



const uint8_t PROGMEM dungeons_room3_4[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(3, CHEST),
    xy(48, 20),
};



const uint8_t PROGMEM dungeons_room3_5[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(1, CHEST),
    xy(80, 44),
};



const uint8_t PROGMEM dungeons_room4_2[] = {
    5, // number of entities

    // entity 0
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(16, 56),

    // entity 1
    miscAndEntityType(0, SKELETON),
    xy(80, 24),

    // entity 2
    miscAndEntityType(1, SKELETON),
    xy(40, 36),

    // entity 3
    miscAndEntityType(0, BAT),
    xy(72, 44),

    // entity 4
    miscAndEntityType(0, BAT),
    xy(88, 40),
};



const uint8_t PROGMEM dungeons_room4_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(5, CHEST),
    xy(80, 32),
};



const uint8_t PROGMEM dungeons_room4_4[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(3, CHEST),
    xy(56, 36),
};



const uint8_t PROGMEM dungeons_room4_5[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(1, TELEPORTER),
    xy(48, 52),
};



const uint8_t PROGMEM dungeons_room5_4[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(1, SKELETON),
    xy(48, 24),
};



const uint8_t PROGMEM dungeons_room8_5[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(2, TELEPORTER),
    xy(48, 52),
};

const uint8_t PROGMEM dungeons_teleporters[] = {
    // dest x, dest y (in rooms)
    4, 6,
    6, 0,
    4, 6,
};





const uint8_t * const PROGMEM dungeons_row0[10] = {
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM dungeons_row1[10] = {
    dungeons_room0_1,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM dungeons_row2[10] = {
    dungeons_room0_2,
    empty_room,
    empty_room,
    empty_room,
    dungeons_room4_2,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM dungeons_row3[10] = {
    dungeons_room0_3,
    empty_room,
    empty_room,
    empty_room,
    dungeons_room4_3,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM dungeons_row4[10] = {
    empty_room,
    empty_room,
    dungeons_room2_4,
    dungeons_room3_4,
    dungeons_room4_4,
    dungeons_room5_4,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM dungeons_row5[10] = {
    dungeons_room0_5,
    empty_room,
    dungeons_room2_5,
    dungeons_room3_5,
    dungeons_room4_5,
    empty_room,
    empty_room,
    empty_room,
    dungeons_room8_5,
    empty_room
};


const uint8_t * const* const PROGMEM dungeons_entities[6] = {
    dungeons_row0,
    dungeons_row1,
    dungeons_row2,
    dungeons_row3,
    dungeons_row4,
    dungeons_row5
};


#endif