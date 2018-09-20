#ifndef dungeons_h
#define dungeons_h

#include "emptyRoom.h"
#include "entityTypes.h"
#include "entityExpressions.h"


const uint8_t PROGMEM dungeons_map[608] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    96, 2, 10, 6,
    // room indices (16 bit, little endian), 120 bytes
    0, 0, 10, 0, 20, 0, 28, 0, 33, 0, 38, 0, 43, 0, 48, 0, 53, 0, 61, 0, 71, 0, 81, 0, 89, 0, 94, 0, 99, 0, 104, 0, 112, 0, 120, 0, 125, 0, 128, 0, 136, 0, 148, 0, 158, 0, 166, 0, 175, 0, 185, 0, 195, 0, 205, 0, 215, 0, 223, 0, 231, 0, 241, 0, 254, 0, 6, 1, 14, 1, 25, 1, 33, 1, 38, 1, 46, 1, 56, 1, 66, 1, 76, 1, 85, 1, 94, 1, 102, 1, 107, 1, 115, 1, 123, 1, 128, 1, 138, 1, 148, 1, 157, 1, 163, 1, 169, 1, 178, 1, 188, 1, 193, 1, 201, 1, 210, 1, 219, 1,
    // compressed room data, 484 bytes
    31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 31, 109, 47, 96, 47, 96, 175, 99, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 247, 223, 240, 246, 0, 247, 223, 240, 246, 0, 246, 219, 246, 14, 246, 14, 246, 14, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 249, 96, 0, 244, 96, 0, 245, 96, 102, 96, 47, 96, 47, 96, 47, 96, 175, 99, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 246, 219, 246, 14, 246, 14, 246, 14, 47, 96, 47, 96, 47, 96, 47, 96, 255, 15, 96, 247, 48, 255, 15, 208, 246, 219, 246, 14, 246, 14, 246, 14, 29, 208, 221, 178, 245, 14, 47, 80, 234, 51, 3, 60, 31, 93, 178, 245, 14, 47, 96, 175, 67, 14, 31, 93, 178, 252, 14, 175, 83, 192, 31, 93, 191, 112, 47, 80, 234, 245, 60, 31, 93, 191, 96, 226, 245, 14, 160, 244, 60, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 47, 96, 47, 96, 47, 96, 47, 96, 246, 14, 246, 14, 246, 14, 246, 60, 29, 208, 221, 210, 246, 2, 246, 15, 100, 48, 214, 221, 96, 224, 96, 6, 14, 6, 101, 96, 239, 96, 224, 31, 109, 47, 96, 47, 96, 175, 99, 246, 219, 246, 14, 246, 14, 246, 14, 64, 68, 77, 68, 4, 68, 4, 79, 80, 248, 64, 47, 96, 47, 96, 47, 96, 47, 96, 247, 223, 224, 247, 48, 246, 14, 246, 14, 246, 14, 246, 60, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 47, 96, 47, 96, 47, 96, 79, 80, 48, 245, 214, 246, 6, 246, 6, 15, 83, 96, 47, 96, 47, 96, 47, 96, 175, 99, 247, 223, 240, 246, 0, 246, 14, 246, 14, 246, 14, 246, 14, 31, 109, 47, 96, 47, 96, 175, 99, 247, 223, 240, 245, 4, 246, 14, 246, 14, 246, 14, 64, 68, 64, 64, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 247, 66, 246, 2, 246, 10, 51, 3, 54, 79, 80, 79, 208, 79, 118, 247, 79, 112, 247, 79, 118, 31, 93, 191, 96, 228, 245, 14, 247, 96, 47, 96, 47, 96, 47, 96, 148, 48, 52, 128, 255, 15, 96, 247, 48, 246, 219, 246, 14, 246, 14, 246, 60, 47, 80, 66, 246, 2, 246, 10, 246, 48, 144, 132, 144, 143, 224, 51, 48, 51, 48, 79, 93, 191, 96, 239, 96, 239, 99, 192
};

const uint8_t PROGMEM dungeons_room0_1[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(4, CHEST),
    xy(56, 24),
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
    5, // number of entities

    // entity 0
    miscAndEntityType(0, BOSS_LOCK),
    xy(48, 0),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(24, 40),

    // entity 2
    miscAndEntityType(2, BAT),
    xy(88, 12),

    // entity 3
    miscAndEntityType(0, BAT),
    xy(32, 36),

    // entity 4
    miscAndEntityType(0, BAT),
    xy(16, 20),
};



const uint8_t PROGMEM dungeons_room0_5[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, TELEPORTER),
    xy(48, 52),
};



const uint8_t PROGMEM dungeons_room1_2[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(96, 36),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(72, 24),
};



const uint8_t PROGMEM dungeons_room1_3[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(5, CHEST),
    xy(48, 8),

    // entity 1
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(48, 36),

    // entity 2
    miscAndEntityType(0, SWITCH),
    xy(32, 20),
};



const uint8_t PROGMEM dungeons_room1_4[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, BLOB),
    xy(48, 32),
};



const uint8_t PROGMEM dungeons_room2_2[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, BLOB),
    xy(48, 20),

    // entity 1
    miscAndEntityType(0, BAT),
    xy(16, 16),

    // entity 2
    miscAndEntityType(0, BAT),
    xy(64, 52),
};



const uint8_t PROGMEM dungeons_room2_4[] = {
    5, // number of entities

    // entity 0
    miscAndEntityType(0, BAT),
    xy(32, 32),

    // entity 1
    miscAndEntityType(0, BAT),
    xy(56, 36),

    // entity 2
    miscAndEntityType(0, BLOB),
    xy(96, 52),

    // entity 3
    miscAndEntityType(0, HEART),
    xy(104, 24),

    // entity 4
    miscAndEntityType(0, HEART),
    xy(104, 8),
};



const uint8_t PROGMEM dungeons_room2_5[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, BLOB),
    xy(32, 24),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(64, 24),
};



const uint8_t PROGMEM dungeons_room3_2[] = {
    5, // number of entities

    // entity 0
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(104, 20),

    // entity 1
    miscAndEntityType(1, SKELETON),
    xy(56, 12),

    // entity 2
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(0, 20),

    // entity 3
    miscAndEntityType(0, SKELETON),
    xy(32, 52),

    // entity 4
    miscAndEntityType(0, SKELETON),
    xy(64, 52),
};



const uint8_t PROGMEM dungeons_room3_4[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(3, CHEST),
    xy(48, 20),
};



const uint8_t PROGMEM dungeons_room3_5[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(2, BAT),
    xy(80, 20),

    // entity 1
    miscAndEntityType(2, BAT),
    xy(80, 36),

    // entity 2
    miscAndEntityType(2, BAT),
    xy(80, 48),
};



const uint8_t PROGMEM dungeons_room4_2[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, SKELETON),
    xy(80, 24),

    // entity 1
    miscAndEntityType(0, LOCK),
    xy(16, 52),
};



const uint8_t PROGMEM dungeons_room4_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(1, CHEST),
    xy(80, 20),
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
    dungeons_room1_2,
    dungeons_room2_2,
    dungeons_room3_2,
    dungeons_room4_2,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM dungeons_row3[10] = {
    dungeons_room0_3,
    dungeons_room1_3,
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
    dungeons_room1_4,
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