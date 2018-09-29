#ifndef overworld_h
#define overworld_h

#include "emptyRoom.h"
#include "entityTypes.h"
#include "entityExpressions.h"


const uint8_t PROGMEM overworld_map[486] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    230, 1, 7, 7,
    // room indices (16 bit, little endian), 98 bytes
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
    // room 7, index 51
    51, 0,
    // room 8, index 61
    61, 0,
    // room 9, index 66
    66, 0,
    // room 10, index 69
    69, 0,
    // room 11, index 75
    75, 0,
    // room 12, index 83
    83, 0,
    // room 13, index 91
    91, 0,
    // room 14, index 99
    99, 0,
    // room 15, index 104
    104, 0,
    // room 16, index 113
    113, 0,
    // room 17, index 116
    116, 0,
    // room 18, index 119
    119, 0,
    // room 19, index 125
    125, 0,
    // room 20, index 130
    130, 0,
    // room 21, index 141
    141, 0,
    // room 22, index 150
    150, 0,
    // room 23, index 156
    156, 0,
    // room 24, index 161
    161, 0,
    // room 25, index 170
    170, 0,
    // room 26, index 179
    179, 0,
    // room 27, index 187
    187, 0,
    // room 28, index 196
    196, 0,
    // room 29, index 204
    204, 0,
    // room 30, index 208
    208, 0,
    // room 31, index 218
    218, 0,
    // room 32, index 229
    229, 0,
    // room 33, index 243
    243, 0,
    // room 34, index 251
    251, 0,
    // room 35, index 263
    7, 1,
    // room 36, index 272
    16, 1,
    // room 37, index 277
    21, 1,
    // room 38, index 282
    26, 1,
    // room 39, index 292
    36, 1,
    // room 40, index 301
    45, 1,
    // room 41, index 311
    55, 1,
    // room 42, index 322
    66, 1,
    // room 43, index 330
    74, 1,
    // room 44, index 339
    83, 1,
    // room 45, index 347
    91, 1,
    // room 46, index 356
    100, 1,
    // room 47, index 365
    109, 1,
    // room 48, index 374
    118, 1,

    // compressed room data, 384 bytes
    0x44, 0x4f, 0xd, 0x44, 0x4f, 0x0, 0x2f, 0x20, 0x2f, 0x20, 0xd6, 0xf1, 0xd0, 0x6f, 0x20, 0x6f, 0x20, 0x6f, 0x10, 0xf3, 0xdf, 0xf0, 0x0, 0xdd, 0xf1, 0x40, 0xf, 0x14, 0xf2, 0x4, 0xf2, 0x4, 0xfb, 0x4f, 0x20, 0x4f, 0x10, 0x40, 0xfa, 0x4f, 0x30, 0x4f, 0x26, 0xf7, 0x48, 0x79, 0xf2, 0xc, 0xf0, 0x64, 0x44, 0x2f, 0x20, 0x66, 0x5f, 0x6, 0xaf, 0x20, 0x44, 0xf1, 0x0, 0x6, 0xf1, 0x6, 0x6f, 0xf0, 0xff, 0xf, 0x50, 0xf2, 0x4, 0xf2, 0x4, 0xfa, 0x0, 0x4f, 0x10, 0xf1, 0x4f, 0x0, 0x44, 0x4f, 0x60, 0x4f, 0x26, 0xf2, 0x6, 0xf2, 0x6, 0xf2, 0x4, 0xf4, 0x6f, 0x44, 0x0, 0xf1, 0x40, 0x4, 0x44, 0x44, 0xf1, 0xf, 0xf4, 0x44, 0xf3, 0x4, 0xf2, 0x4, 0xf1, 0x64, 0x4f, 0x10, 0x40, 0xfa, 0xf, 0xa4, 0xfa, 0xf, 0xa4, 0xfa, 0x4, 0xf2, 0x4, 0xf2, 0x0, 0xf2, 0x4, 0xff, 0x0, 0x40, 0x44, 0x0, 0x44, 0x4f, 0x20, 0xef, 0x20, 0xe4, 0x40, 0xf0, 0x40, 0x44, 0x47, 0xf0, 0x4f, 0x20, 0x4f, 0x20, 0xf3, 0x40, 0x4f, 0x10, 0x4f, 0xa0, 0x4f, 0x20, 0xf3, 0x4f, 0xc0, 0xf1, 0x40, 0x4d, 0xdd, 0x44, 0x4f, 0x10, 0x44, 0xf1, 0xf, 0x54, 0x4f, 0x20, 0x4f, 0x20, 0x4f, 0x20, 0x40, 0xf0, 0x40, 0xf2, 0x4, 0xf2, 0x4, 0xf2, 0x4, 0xf, 0x24, 0x44, 0xf, 0x14, 0xf1, 0xe, 0x40, 0x4, 0xf, 0x54, 0xf3, 0x41, 0xf2, 0x2, 0xf2, 0x2, 0xf2, 0x0, 0x4f, 0xf0, 0xf4, 0x0, 0x0, 0xf1, 0x40, 0xf, 0x14, 0x0, 0xf1, 0x40, 0xf, 0x14, 0x47, 0xf2, 0x40, 0x0, 0x60, 0x4, 0x0, 0x6, 0x0, 0xf3, 0x40, 0x40, 0xf0, 0x40, 0x0, 0x40, 0x4, 0x0, 0x4, 0x0, 0x40, 0x44, 0x40, 0x4, 0x40, 0xf, 0x24, 0x4, 0xf2, 0x4, 0xf1, 0xf, 0x34, 0xf0, 0x40, 0x44, 0x0, 0x4, 0x4, 0x4f, 0x10, 0x44, 0x40, 0xf, 0x4, 0x2f, 0x20, 0x2f, 0x20, 0x2f, 0x20, 0x2f, 0x10, 0x40, 0xff, 0x0, 0x4, 0xf2, 0x0, 0x0, 0xf1, 0x4f, 0xf0, 0x4, 0xf3, 0x4f, 0x10, 0x44, 0xf1, 0x4, 0x44, 0xf0, 0x4, 0x40, 0x44, 0x40, 0x4, 0x44, 0xf2, 0x4, 0xf2, 0xf, 0x34, 0xf3, 0x4f, 0x0, 0x40, 0x4f, 0x20, 0x44, 0x0, 0x4, 0x44, 0x40, 0xf, 0x14, 0x0, 0xf1, 0x40, 0xf, 0x14, 0x0, 0xf0, 0x40, 0x2f, 0x10, 0x4f, 0x36, 0x2f, 0x10, 0x4f, 0x36, 0x4f, 0x20, 0x66, 0xf1, 0x4, 0x6f, 0x10, 0xf3, 0x60, 0xf2, 0x4, 0xf2, 0x4, 0xf2, 0x4, 0xf3, 0x60, 0x4f, 0x0, 0x44, 0x4f, 0x20, 0x4f, 0x20, 0xf3, 0x60, 0xf0, 0x47, 0x94, 0xf2, 0x4, 0xf2, 0x4, 0xf3, 0x60, 0x40, 0x0, 0xf0, 0x4f, 0x20, 0x4f, 0x20, 0xf3, 0x60, 0x40, 0xf, 0x4, 0x0, 0xf, 0x4, 0xf1, 0x4, 0x4f, 0x36
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



const uint8_t PROGMEM overworld_room0_3[] = {
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



const uint8_t PROGMEM overworld_room0_4[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, BLOB),
    xy(32, 36),
};



const uint8_t PROGMEM overworld_room0_6[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, KEY),
    xy(48, 36),
};



const uint8_t PROGMEM overworld_room1_2[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, SUNKEN_BRIDGE),
    xy(64, 36),

    // entity 1
    miscAndEntityType(0, SWITCH),
    xy(32, 20),

    // entity 2
    miscAndEntityType(0, SWITCH),
    xy(32, 52),
};



const uint8_t PROGMEM overworld_room1_4[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, SKELETON),
    xy(104, 8),
};



const uint8_t PROGMEM overworld_room1_5[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, BLOB),
    xy(40, 28),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(56, 36),
};



const uint8_t PROGMEM overworld_room2_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(4, BLOB),
    xy(96, 24),
};



const uint8_t PROGMEM overworld_room3_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, CHEST),
    xy(32, 20),
};



const uint8_t PROGMEM overworld_room3_4[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, SUNKEN_BRIDGE),
    xy(64, 32),

    // entity 1
    miscAndEntityType(0, SWITCH),
    xy(32, 28),

    // entity 2
    miscAndEntityType(5, TELEPORTER),
    xy(16, 0),
};



const uint8_t PROGMEM overworld_room3_6[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, BLOB),
    xy(24, 44),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(56, 44),
};



const uint8_t PROGMEM overworld_room4_4[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(64, 0),

    // entity 1
    miscAndEntityType(4, TELEPORTER),
    xy(64, 0),
};



const uint8_t PROGMEM overworld_room4_6[] = {
    5, // number of entities

    // entity 0
    miscAndEntityType(1, TELEPORTER),
    xy(64, 0),

    // entity 1
    miscAndEntityType(0, BAT),
    xy(96, 44),

    // entity 2
    miscAndEntityType(0, BAT),
    xy(56, 20),

    // entity 3
    miscAndEntityType(0, BAT),
    xy(72, 48),

    // entity 4
    miscAndEntityType(0, BAT),
    xy(80, 20),
};



const uint8_t PROGMEM overworld_room5_5[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(80, 0),

    // entity 1
    miscAndEntityType(6, TELEPORTER),
    xy(80, 0),
};



const uint8_t PROGMEM overworld_room5_6[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, SKELETON),
    xy(56, 36),
};



const uint8_t PROGMEM overworld_room6_0[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, TELEPORTER),
    xy(80, 16),

    // entity 1
    miscAndEntityType(0, LOCK),
    xy(80, 36),
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



const uint8_t PROGMEM overworld_room6_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(64, 48),
};



const uint8_t PROGMEM overworld_room6_4[] = {
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
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    overworld_room6_1
};


const uint8_t * const PROGMEM overworld_row2[7] = {
    empty_room,
    overworld_room1_2,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM overworld_row3[7] = {
    overworld_room0_3,
    empty_room,
    overworld_room2_3,
    overworld_room3_3,
    empty_room,
    empty_room,
    overworld_room6_3
};


const uint8_t * const PROGMEM overworld_row4[7] = {
    overworld_room0_4,
    overworld_room1_4,
    empty_room,
    overworld_room3_4,
    overworld_room4_4,
    empty_room,
    overworld_room6_4
};


const uint8_t * const PROGMEM overworld_row5[7] = {
    empty_room,
    overworld_room1_5,
    empty_room,
    empty_room,
    empty_room,
    overworld_room5_5,
    empty_room
};


const uint8_t * const PROGMEM overworld_row6[7] = {
    overworld_room0_6,
    empty_room,
    empty_room,
    overworld_room3_6,
    overworld_room4_6,
    overworld_room5_6,
    empty_room
};


const uint8_t * const* const PROGMEM overworld_entities[7] = {
    overworld_row0,
    overworld_row1,
    overworld_row2,
    overworld_row3,
    overworld_row4,
    overworld_row5,
    overworld_row6
};


#endif