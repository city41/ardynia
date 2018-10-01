#ifndef overworld_h
#define overworld_h

#include "emptyRoom.h"
#include "entityTypes.h"
#include "entityExpressions.h"


const uint8_t PROGMEM overworld_map[436] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    180, 1, 7, 6,
    // room indices (16 bit, little endian), 84 bytes
    // room 0, index 0
    0, 0,
    // room 1, index 10
    10, 0,
    // room 2, index 19
    19, 0,
    // room 3, index 23
    23, 0,
    // room 4, index 32
    32, 0,
    // room 5, index 38
    38, 0,
    // room 6, index 43
    43, 0,
    // room 7, index 56
    56, 0,
    // room 8, index 63
    63, 0,
    // room 9, index 71
    71, 0,
    // room 10, index 75
    75, 0,
    // room 11, index 82
    82, 0,
    // room 12, index 92
    92, 0,
    // room 13, index 100
    100, 0,
    // room 14, index 108
    108, 0,
    // room 15, index 117
    117, 0,
    // room 16, index 123
    123, 0,
    // room 17, index 128
    128, 0,
    // room 18, index 137
    137, 0,
    // room 19, index 146
    146, 0,
    // room 20, index 152
    152, 0,
    // room 21, index 162
    162, 0,
    // room 22, index 170
    170, 0,
    // room 23, index 174
    174, 0,
    // room 24, index 184
    184, 0,
    // room 25, index 193
    193, 0,
    // room 26, index 207
    207, 0,
    // room 27, index 215
    215, 0,
    // room 28, index 227
    227, 0,
    // room 29, index 236
    236, 0,
    // room 30, index 241
    241, 0,
    // room 31, index 246
    246, 0,
    // room 32, index 256
    0, 1,
    // room 33, index 265
    9, 1,
    // room 34, index 275
    19, 1,
    // room 35, index 286
    30, 1,
    // room 36, index 294
    38, 1,
    // room 37, index 303
    47, 1,
    // room 38, index 311
    55, 1,
    // room 39, index 320
    64, 1,
    // room 40, index 329
    73, 1,
    // room 41, index 338
    82, 1,

    // compressed room data, 348 bytes
    0x44, 0x4f, 0xb, 0x44, 0x4f, 0x0, 0x2f, 0x20, 0x2f, 0x20, 0xb6, 0xf1, 0xb0, 0x6f, 0x20, 0x6f, 0x20, 0x6f, 0x10, 0xf3, 0xbf, 0xf0, 0x0, 0xbb, 0xf1, 0x40, 0xf, 0x14, 0xf2, 0x4, 0xf2, 0x4, 0xfb, 0x4f, 0x20, 0x4f, 0x10, 0x40, 0xfa, 0x4f, 0x30, 0x4f, 0x26, 0x44, 0x6f, 0x14, 0x6, 0x4, 0x74, 0x0, 0x50, 0x0, 0xcf, 0x6, 0x44, 0x40, 0x2f, 0x20, 0xf3, 0x68, 0xf2, 0xf, 0x34, 0x6, 0xf1, 0x6, 0x6f, 0x80, 0x4f, 0x10, 0x40, 0xff, 0x0, 0xf, 0x34, 0xf2, 0x4, 0xf2, 0x4, 0xf3, 0xf, 0x34, 0x4f, 0x10, 0xf1, 0x4f, 0x10, 0x44, 0x0, 0x4, 0xf2, 0x0, 0x4f, 0x26, 0xf2, 0x6, 0xf2, 0x6, 0xf2, 0x4, 0xf4, 0x6f, 0x44, 0x0, 0xf1, 0x40, 0x4, 0x44, 0x44, 0x47, 0xf0, 0x4f, 0x20, 0x4f, 0x20, 0xf3, 0x40, 0x4f, 0x10, 0x4f, 0xa0, 0x4f, 0x20, 0xf3, 0x4f, 0xc0, 0xf1, 0x40, 0x4b, 0xbb, 0x44, 0x4f, 0x10, 0x44, 0xf1, 0xf, 0x54, 0x4f, 0x20, 0x4f, 0x20, 0x4f, 0x20, 0x40, 0xf0, 0x40, 0xf2, 0x4, 0xf9, 0x4, 0xf, 0x24, 0x44, 0x0, 0x44, 0x4f, 0x20, 0x44, 0x0, 0x40, 0xf5, 0x40, 0xf3, 0x41, 0xf2, 0x2, 0xf2, 0x2, 0xf2, 0x0, 0x4f, 0xf0, 0xf4, 0x0, 0x0, 0xf1, 0x40, 0x4, 0x4f, 0x10, 0x44, 0xf1, 0xf, 0x14, 0x47, 0xf1, 0x4f, 0x0, 0x6f, 0x20, 0x60, 0xf, 0x34, 0x40, 0xf0, 0x40, 0x0, 0x40, 0x4, 0x0, 0x4, 0x0, 0x40, 0x44, 0x40, 0x4, 0x40, 0xf, 0x24, 0x4, 0xf2, 0x4, 0xf1, 0xf, 0x34, 0xf0, 0x40, 0x44, 0x0, 0x4, 0x4, 0x4f, 0x10, 0x44, 0x40, 0xf, 0x4, 0x2f, 0x20, 0x2f, 0x20, 0x2f, 0x20, 0x2f, 0x10, 0x40, 0xff, 0x0, 0x4, 0xf2, 0x0, 0x0, 0xf1, 0x4f, 0xf0, 0x4, 0xf3, 0x4f, 0x10, 0x44, 0xf1, 0x4, 0x44, 0xf0, 0x4, 0x40, 0x44, 0x40, 0x4, 0x44, 0xf2, 0x4, 0xf2, 0xf, 0x34, 0xf3, 0x4f, 0x0, 0x40, 0x4f, 0x20, 0x44, 0x0, 0x4, 0x44, 0x40, 0xf, 0x14, 0x0, 0xf1, 0x40, 0xf, 0x14, 0x0, 0xf0, 0x40, 0x2f, 0x10, 0x4f, 0x36, 0x2f, 0x10, 0x4f, 0x36, 0x4f, 0x20, 0x66, 0xf1, 0x4, 0x6f, 0x10, 0xf3, 0x60, 0xf2, 0x4, 0xf2, 0x4, 0xf2, 0x4, 0xf3, 0x60, 0x4f, 0x0, 0x44, 0x4f, 0x20, 0x4f, 0x20, 0xf3, 0x60, 0xf0, 0x47, 0x44, 0xf2, 0x4, 0xf2, 0x4, 0xf3, 0x60, 0x40, 0x0, 0xf0, 0x4f, 0x20, 0x4f, 0x20, 0xf3, 0x60, 0x40, 0xf, 0x4, 0x0, 0xf, 0x4, 0xf1, 0x4, 0x4f, 0x36
};

const uint8_t PROGMEM overworld_room0_0[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(16, 16),

    // entity 1
    miscAndEntityType(2, TELEPORTER),
    xy(16, 16),
};



const uint8_t PROGMEM overworld_room0_1[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, SUNKEN_BRIDGE),
    xy(48, 16),

    // entity 1
    miscAndEntityType(0, SWITCH),
    xy(64, 4),
};



const uint8_t PROGMEM overworld_room0_2[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(6, TORCH),
    xy(40, 16),

    // entity 1
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(48, 16),

    // entity 2
    miscAndEntityType(3, TELEPORTER),
    xy(48, 0),

    // entity 3
    miscAndEntityType(6, TORCH),
    xy(64, 16),
};



const uint8_t PROGMEM overworld_room0_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, BLOB),
    xy(40, 36),
};



const uint8_t PROGMEM overworld_room0_5[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, KEY),
    xy(48, 36),
};



const uint8_t PROGMEM overworld_room1_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, BLOB_MOTHER),
    xy(80, 40),
};



const uint8_t PROGMEM overworld_room1_4[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, BLOB),
    xy(40, 28),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(56, 36),
};



const uint8_t PROGMEM overworld_room2_2[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(4, BLOB),
    xy(104, 24),
};



const uint8_t PROGMEM overworld_room3_1[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(96, 32),
};



const uint8_t PROGMEM overworld_room3_2[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, CHEST),
    xy(32, 20),
};



const uint8_t PROGMEM overworld_room3_3[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, SUNKEN_BRIDGE),
    xy(64, 36),

    // entity 1
    miscAndEntityType(0, SWITCH),
    xy(40, 28),

    // entity 2
    miscAndEntityType(5, TELEPORTER),
    xy(16, 0),
};



const uint8_t PROGMEM overworld_room3_5[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, BLOB),
    xy(24, 44),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(56, 44),
};



const uint8_t PROGMEM overworld_room4_3[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(64, 0),

    // entity 1
    miscAndEntityType(4, TELEPORTER),
    xy(64, 0),
};



const uint8_t PROGMEM overworld_room4_5[] = {
    5, // number of entities

    // entity 0
    miscAndEntityType(1, TELEPORTER),
    xy(64, 0),

    // entity 1
    miscAndEntityType(0, BAT),
    xy(96, 44),

    // entity 2
    miscAndEntityType(0, BAT),
    xy(64, 20),

    // entity 3
    miscAndEntityType(0, BAT),
    xy(72, 48),

    // entity 4
    miscAndEntityType(0, BAT),
    xy(80, 20),
};



const uint8_t PROGMEM overworld_room5_4[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(80, 0),

    // entity 1
    miscAndEntityType(6, TELEPORTER),
    xy(80, 0),
};



const uint8_t PROGMEM overworld_room5_5[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, SKELETON),
    xy(56, 36),
};



const uint8_t PROGMEM overworld_room6_0[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, TELEPORTER),
    xy(80, 16),
};



const uint8_t PROGMEM overworld_room6_1[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(48, 16),

    // entity 1
    miscAndEntityType(7, TELEPORTER),
    xy(48, 16),
};



const uint8_t PROGMEM overworld_room6_2[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(64, 48),
};



const uint8_t PROGMEM overworld_room6_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, SKELETON),
    xy(24, 36),
};

const uint8_t PROGMEM overworld_teleporters[] = {
    // dest x, dest y (in rooms)
    3, 7,
    0, 7,
    4, 2,
    1, 4,
    6, 0,
    7, 4,
    7, 5,
    7, 6,
};





const uint8_t * const PROGMEM overworld_row0[7] = {
    overworld_room0_0,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    overworld_room6_0
};


const uint8_t * const PROGMEM overworld_row1[7] = {
    overworld_room0_1,
    empty_room,
    empty_room,
    overworld_room3_1,
    empty_room,
    empty_room,
    overworld_room6_1
};


const uint8_t * const PROGMEM overworld_row2[7] = {
    overworld_room0_2,
    empty_room,
    overworld_room2_2,
    overworld_room3_2,
    empty_room,
    empty_room,
    overworld_room6_2
};


const uint8_t * const PROGMEM overworld_row3[7] = {
    overworld_room0_3,
    overworld_room1_3,
    empty_room,
    overworld_room3_3,
    overworld_room4_3,
    empty_room,
    overworld_room6_3
};


const uint8_t * const PROGMEM overworld_row4[7] = {
    empty_room,
    overworld_room1_4,
    empty_room,
    empty_room,
    empty_room,
    overworld_room5_4,
    empty_room
};


const uint8_t * const PROGMEM overworld_row5[7] = {
    overworld_room0_5,
    empty_room,
    empty_room,
    overworld_room3_5,
    overworld_room4_5,
    overworld_room5_5,
    empty_room
};


const uint8_t * const* const PROGMEM overworld_entities[6] = {
    overworld_row0,
    overworld_row1,
    overworld_row2,
    overworld_row3,
    overworld_row4,
    overworld_row5
};


#endif