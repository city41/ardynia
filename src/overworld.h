#ifndef overworld_h
#define overworld_h

#include "emptyRoom.h"
#include "entityTypes.h"
#include "entityExpressions.h"


const uint8_t PROGMEM overworld_map[487] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    231, 1, 7, 7,
    // room indices (16 bit, little endian), 98 bytes
    // room 0, index 0
    0, 0,
    // room 1, index 10
    10, 0,
    // room 2, index 19
    19, 0,
    // room 3, index 24
    24, 0,
    // room 4, index 33
    33, 0,
    // room 5, index 39
    39, 0,
    // room 6, index 44
    44, 0,
    // room 7, index 52
    52, 0,
    // room 8, index 62
    62, 0,
    // room 9, index 69
    69, 0,
    // room 10, index 72
    72, 0,
    // room 11, index 78
    78, 0,
    // room 12, index 86
    86, 0,
    // room 13, index 94
    94, 0,
    // room 14, index 99
    99, 0,
    // room 15, index 105
    105, 0,
    // room 16, index 114
    114, 0,
    // room 17, index 117
    117, 0,
    // room 18, index 120
    120, 0,
    // room 19, index 126
    126, 0,
    // room 20, index 132
    132, 0,
    // room 21, index 142
    142, 0,
    // room 22, index 151
    151, 0,
    // room 23, index 157
    157, 0,
    // room 24, index 164
    164, 0,
    // room 25, index 174
    174, 0,
    // room 26, index 182
    182, 0,
    // room 27, index 190
    190, 0,
    // room 28, index 199
    199, 0,
    // room 29, index 207
    207, 0,
    // room 30, index 211
    211, 0,
    // room 31, index 221
    221, 0,
    // room 32, index 232
    232, 0,
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
    // room 38, index 283
    27, 1,
    // room 39, index 293
    37, 1,
    // room 40, index 302
    46, 1,
    // room 41, index 312
    56, 1,
    // room 42, index 323
    67, 1,
    // room 43, index 331
    75, 1,
    // room 44, index 340
    84, 1,
    // room 45, index 348
    92, 1,
    // room 46, index 357
    101, 1,
    // room 47, index 366
    110, 1,
    // room 48, index 375
    119, 1,

    // compressed room data, 385 bytes
    0x44, 0x4f, 0x4d, 0x44, 0x4f, 0x40, 0x2f, 0x60, 0x2f, 0x60, 0xd6, 0xf5, 0xd0, 0x6f, 0x60, 0x6f, 0x60, 0x6f, 0x50, 0xf7, 0xdf, 0xf0, 0xf6, 0x0, 0xdd, 0xf5, 0x40, 0xf, 0x54, 0xf6, 0x4, 0xf6, 0x4, 0xff, 0x4f, 0x60, 0x4f, 0x50, 0x40, 0xfe, 0x4f, 0x70, 0x4f, 0x66, 0xfb, 0x48, 0x79, 0xf6, 0xc, 0xf4, 0x64, 0x44, 0x2f, 0x60, 0x66, 0x5f, 0x46, 0xaf, 0x60, 0x44, 0xf5, 0x0, 0x6, 0xf5, 0x6, 0x6f, 0xf0, 0xf4, 0x0, 0xff, 0xf, 0xd0, 0xf6, 0x4, 0xf6, 0x4, 0xfe, 0x0, 0x4f, 0x50, 0xf5, 0x4f, 0x40, 0x44, 0x4f, 0xa0, 0x4f, 0x66, 0xf6, 0x6, 0xf6, 0x6, 0xf6, 0x4, 0xfb, 0x6f, 0xe4, 0x0, 0x40, 0x44, 0xf5, 0xf, 0xf4, 0xf6, 0x40, 0xf7, 0x4, 0xf6, 0x4, 0xf5, 0x64, 0x4f, 0x50, 0x40, 0xfe, 0xf, 0xe4, 0xfe, 0xf, 0xe4, 0xfe, 0x4, 0xf6, 0x4, 0xf6, 0x0, 0xf6, 0x4, 0xff, 0xf, 0x50, 0x40, 0xf4, 0x40, 0x4, 0xf6, 0xe, 0xf6, 0xe, 0x44, 0xf, 0x44, 0x44, 0x47, 0xf4, 0x4f, 0x60, 0x4f, 0x60, 0xf7, 0x40, 0x4f, 0x50, 0x4f, 0xe0, 0x4f, 0x60, 0xf7, 0x4f, 0x90, 0xf5, 0x30, 0xf, 0x54, 0x1d, 0xdd, 0xb4, 0x4f, 0x40, 0xe4, 0x4f, 0x43, 0xcf, 0x94, 0x4f, 0x60, 0x4f, 0x60, 0x4f, 0x60, 0x4f, 0x60, 0xf6, 0x4, 0xf6, 0x4, 0xf6, 0x4, 0xf, 0x64, 0x44, 0xf, 0x54, 0xf5, 0xe, 0x40, 0x4, 0xf, 0x94, 0xf7, 0x41, 0xf6, 0x2, 0xf6, 0x2, 0xf6, 0x0, 0x4f, 0xf0, 0xfc, 0x0, 0x0, 0xf5, 0x40, 0xf, 0x54, 0x0, 0xf5, 0x40, 0xf, 0x54, 0x47, 0xf6, 0x40, 0x0, 0x60, 0x4, 0x0, 0x6, 0x0, 0xf7, 0x40, 0x4f, 0x80, 0xf4, 0x40, 0x0, 0xf4, 0x40, 0x44, 0x40, 0x4, 0x40, 0xf, 0x64, 0x4, 0xf6, 0x4, 0xf5, 0xf, 0x74, 0xf4, 0x40, 0x44, 0x0, 0x4, 0x4, 0x4f, 0x50, 0x44, 0x40, 0xf, 0x44, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x50, 0x40, 0xff, 0xf, 0x60, 0x4f, 0x60, 0x0, 0xf5, 0x4f, 0xf0, 0xf5, 0x4, 0xf7, 0x4f, 0x50, 0x44, 0xf5, 0x4, 0x44, 0xf4, 0x4, 0x40, 0x44, 0x40, 0x4, 0x44, 0xf6, 0x4, 0xf6, 0xf, 0x74, 0xf7, 0x4f, 0x40, 0x40, 0x4f, 0x60, 0x44, 0x0, 0x4, 0x44, 0x40, 0xf, 0x54, 0x0, 0xf5, 0x40, 0xf, 0x54, 0x0, 0xf4, 0x40, 0x2f, 0x50, 0x4f, 0x76, 0x2f, 0x50, 0x4f, 0x76, 0x4f, 0x60, 0x66, 0xf5, 0x4, 0x6f, 0x50, 0xf7, 0x60, 0xf6, 0x4, 0xf6, 0x4, 0xf6, 0x4, 0xf7, 0x60, 0x4f, 0x40, 0x44, 0x4f, 0x60, 0x4f, 0x60, 0xf7, 0x60, 0xf4, 0x47, 0x94, 0xf6, 0x4, 0xf6, 0x4, 0xf7, 0x60, 0x40, 0x0, 0xf4, 0x4f, 0x60, 0x4f, 0x60, 0xf7, 0x60, 0x40, 0xf, 0x44, 0x0, 0xf, 0x44, 0xf5, 0x4, 0x4f, 0x76
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
    3, // number of entities

    // entity 0
    miscAndEntityType(0, TORCH),
    xy(32, 32),

    // entity 1
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(48, 16),

    // entity 2
    miscAndEntityType(3, TELEPORTER),
    xy(48, 0),
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
    2, // number of entities

    // entity 0
    miscAndEntityType(0, SUNKEN_BRIDGE),
    xy(64, 36),

    // entity 1
    miscAndEntityType(0, SWITCH),
    xy(32, 20),
};



const uint8_t PROGMEM overworld_room1_4[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, SKELETON),
    xy(48, 36),
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
    xy(16, 4),
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
    xy(64, 32),

    // entity 1
    miscAndEntityType(4, TELEPORTER),
    xy(64, 32),
};



const uint8_t PROGMEM overworld_room4_6[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(1, TELEPORTER),
    xy(64, 4),

    // entity 1
    miscAndEntityType(0, BAT),
    xy(96, 44),
};



const uint8_t PROGMEM overworld_room5_5[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(80, 4),
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
    xy(80, 24),

    // entity 1
    miscAndEntityType(0, LOCK),
    xy(80, 36),
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
    0, 0,
    7, 4,
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
    empty_room
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
    empty_room,
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