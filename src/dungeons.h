#ifndef dungeons_h
#define dungeons_h

#include "emptyRoom.h"
#include "entityTypes.h"
#include "entityExpressions.h"


const uint8_t PROGMEM dungeons_map[619] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    107, 2, 10, 6,
    // room indices (16 bit, little endian), 120 bytes
    0, 0, 10, 0, 20, 0, 28, 0, 33, 0, 38, 0, 43, 0, 48, 0, 53, 0, 61, 0, 71, 0, 81, 0, 89, 0, 94, 0, 99, 0, 104, 0, 112, 0, 120, 0, 125, 0, 128, 0, 136, 0, 148, 0, 158, 0, 170, 0, 183, 0, 193, 0, 203, 0, 213, 0, 223, 0, 231, 0, 239, 0, 251, 0, 2, 1, 14, 1, 24, 1, 35, 1, 43, 1, 48, 1, 56, 1, 66, 1, 76, 1, 86, 1, 95, 1, 103, 1, 111, 1, 116, 1, 124, 1, 132, 1, 137, 1, 147, 1, 157, 1, 166, 1, 172, 1, 178, 1, 189, 1, 199, 1, 204, 1, 212, 1, 221, 1, 230, 1,
    // compressed room data, 495 bytes
    31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 31, 109, 47, 96, 47, 96, 175, 99, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 247, 223, 240, 246, 0, 247, 223, 240, 246, 0, 246, 219, 246, 14, 246, 14, 246, 14, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 249, 96, 0, 244, 96, 0, 245, 96, 102, 96, 47, 96, 47, 96, 47, 96, 47, 96, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 246, 219, 246, 14, 246, 14, 246, 14, 47, 96, 47, 96, 47, 96, 47, 96, 255, 15, 96, 247, 48, 255, 15, 208, 246, 219, 246, 14, 246, 14, 246, 14, 29, 208, 221, 178, 245, 14, 47, 80, 234, 51, 3, 60, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 6, 244, 219, 6, 245, 6, 111, 64, 230, 99, 3, 60, 29, 109, 221, 176, 6, 244, 2, 6, 101, 102, 175, 83, 192, 31, 93, 191, 96, 226, 245, 14, 160, 244, 60, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 47, 96, 47, 96, 47, 96, 47, 96, 246, 14, 246, 14, 246, 14, 246, 60, 29, 208, 0, 210, 246, 2, 6, 101, 102, 163, 111, 67, 246, 214, 246, 15, 134, 247, 0, 102, 208, 221, 182, 111, 64, 230, 111, 64, 239, 99, 192, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 64, 68, 77, 68, 4, 68, 4, 79, 80, 248, 64, 47, 96, 47, 96, 47, 96, 47, 96, 247, 223, 224, 247, 48, 246, 14, 246, 14, 246, 14, 246, 60, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 47, 96, 47, 96, 47, 96, 79, 80, 48, 246, 219, 246, 14, 246, 14, 246, 60, 47, 96, 47, 96, 47, 96, 175, 99, 247, 223, 240, 246, 0, 246, 14, 246, 14, 246, 14, 246, 14, 31, 109, 47, 96, 47, 96, 175, 99, 247, 223, 240, 245, 4, 246, 14, 246, 14, 246, 14, 64, 68, 64, 64, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 247, 66, 246, 2, 246, 10, 51, 3, 54, 79, 80, 79, 208, 79, 118, 247, 79, 112, 247, 79, 118, 22, 244, 219, 5, 0, 6, 98, 248, 111, 67, 192, 47, 96, 47, 96, 47, 96, 148, 48, 52, 128, 255, 15, 96, 247, 48, 246, 219, 246, 14, 246, 14, 246, 60, 47, 80, 66, 246, 2, 246, 10, 246, 48, 144, 132, 144, 143, 224, 51, 48, 51, 48, 79, 93, 191, 96, 239, 96, 239, 99, 192
};

const uint8_t PROGMEM dungeons_room0_1[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(4, CHEST),
    xy(48, 24),
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
    3, // number of entities

    // entity 0
    miscAndEntityType(0, BOSS_LOCK),
    xy(48, 0),

    // entity 1
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(64, 48),

    // entity 2
    miscAndEntityType(0, SWITCH),
    xy(80, 16),
};



const uint8_t PROGMEM dungeons_room0_5[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, TELEPORTER),
    xy(48, 52),
};



const uint8_t PROGMEM dungeons_room1_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(3, CHEST),
    xy(48, 20),
};



const uint8_t PROGMEM dungeons_room1_4[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(2, BAT),
    xy(16, 20),

    // entity 1
    miscAndEntityType(0, BAT),
    xy(8, 36),

    // entity 2
    miscAndEntityType(0, BAT),
    xy(24, 28),
};



const uint8_t PROGMEM dungeons_room1_5[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, BLOB),
    xy(64, 32),
};



const uint8_t PROGMEM dungeons_room2_2[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, HEART),
    xy(8, 16),

    // entity 1
    miscAndEntityType(0, HEART),
    xy(8, 28),
};



const uint8_t PROGMEM dungeons_room2_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(48, 4),
};



const uint8_t PROGMEM dungeons_room2_4[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(0, BAT),
    xy(32, 32),

    // entity 1
    miscAndEntityType(2, BAT),
    xy(64, 44),

    // entity 2
    miscAndEntityType(0, BLOB),
    xy(88, 20),

    // entity 3
    miscAndEntityType(0, BLOB),
    xy(88, 40),
};



const uint8_t PROGMEM dungeons_room2_5[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(96, 20),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(32, 24),

    // entity 2
    miscAndEntityType(0, BLOB),
    xy(64, 24),
};



const uint8_t PROGMEM dungeons_room3_2[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(64, 48),

    // entity 1
    miscAndEntityType(0, SWITCH),
    xy(56, 20),

    // entity 2
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
    xy(56, 20),
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
    xy(56, 12),

    // entity 3
    miscAndEntityType(0, SKELETON),
    xy(88, 40),

    // entity 4
    miscAndEntityType(0, SKELETON),
    xy(72, 48),
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
    dungeons_room2_3,
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
    dungeons_room1_5,
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