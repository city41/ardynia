#ifndef overworld_h
#define overworld_h

#include "emptyRoom.h"
#include "entityTypes.h"
#include "entityExpressions.h"


const uint8_t PROGMEM overworld_map[479] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    223, 1, 7, 7,
    // room indices (16 bit, little endian), 98 bytes
    // room 0, index 0
    0, 0,
    // room 1, index 11
    11, 0,
    // room 2, index 20
    20, 0,
    // room 3, index 25
    25, 0,
    // room 4, index 32
    32, 0,
    // room 5, index 35
    35, 0,
    // room 6, index 39
    39, 0,
    // room 7, index 47
    47, 0,
    // room 8, index 57
    57, 0,
    // room 9, index 63
    63, 0,
    // room 10, index 68
    68, 0,
    // room 11, index 76
    76, 0,
    // room 12, index 87
    87, 0,
    // room 13, index 95
    95, 0,
    // room 14, index 100
    100, 0,
    // room 15, index 106
    106, 0,
    // room 16, index 115
    115, 0,
    // room 17, index 118
    118, 0,
    // room 18, index 124
    124, 0,
    // room 19, index 131
    131, 0,
    // room 20, index 137
    137, 0,
    // room 21, index 147
    147, 0,
    // room 22, index 154
    154, 0,
    // room 23, index 160
    160, 0,
    // room 24, index 165
    165, 0,
    // room 25, index 172
    172, 0,
    // room 26, index 180
    180, 0,
    // room 27, index 188
    188, 0,
    // room 28, index 197
    197, 0,
    // room 29, index 205
    205, 0,
    // room 30, index 209
    209, 0,
    // room 31, index 219
    219, 0,
    // room 32, index 226
    226, 0,
    // room 33, index 237
    237, 0,
    // room 34, index 245
    245, 0,
    // room 35, index 257
    1, 1,
    // room 36, index 266
    10, 1,
    // room 37, index 271
    15, 1,
    // room 38, index 277
    21, 1,
    // room 39, index 287
    31, 1,
    // room 40, index 296
    40, 1,
    // room 41, index 303
    47, 1,
    // room 42, index 314
    58, 1,
    // room 43, index 323
    67, 1,
    // room 44, index 332
    76, 1,
    // room 45, index 340
    84, 1,
    // room 46, index 349
    93, 1,
    // room 47, index 358
    102, 1,
    // room 48, index 367
    111, 1,

    // compressed room data, 377 bytes
    0x1f, 0x6d, 0x20, 0x44, 0x40, 0x2, 0x4, 0x44, 0x0, 0x2f, 0x60, 0xd6, 0xf5, 0xd0, 0x6f, 0x60, 0x6f, 0x60, 0x6f, 0x50, 0xf7, 0xdf, 0xf0, 0xf6, 0x0, 0xdd, 0xf5, 0x40, 0xf, 0x54, 0xfe, 0x0, 0xfe, 0x4f, 0xe0, 0xfe, 0x4f, 0xd0, 0x60, 0xfb, 0x48, 0x79, 0xf6, 0xc, 0xf4, 0x64, 0x44, 0x2f, 0x60, 0x66, 0x5f, 0x46, 0x2f, 0x60, 0x44, 0xf5, 0x0, 0x6, 0xf5, 0xf, 0x76, 0xfe, 0x0, 0xf7, 0xf, 0x76, 0xfe, 0x0, 0xf7, 0xf, 0x76, 0xf5, 0x6, 0x6f, 0x50, 0x66, 0xf7, 0x6, 0x66, 0xf4, 0x6, 0x66, 0xf4, 0x6, 0x66, 0xf4, 0x0, 0xf6, 0x6, 0xf6, 0x6, 0xf6, 0x6, 0xf6, 0x4, 0xfb, 0x6f, 0xe4, 0x0, 0x40, 0x44, 0xf5, 0xf, 0xf4, 0xf6, 0x40, 0xf7, 0x4, 0xf6, 0x4, 0xf5, 0x64, 0x4f, 0x50, 0x40, 0xfe, 0xf, 0xe4, 0xf5, 0x6, 0x6f, 0x70, 0xfe, 0x40, 0x66, 0x6f, 0xb0, 0x4f, 0x60, 0x4f, 0x60, 0xf6, 0x4, 0xff, 0xf, 0x50, 0x40, 0xf4, 0x40, 0x4, 0xf6, 0xe, 0xf6, 0xe, 0x44, 0xf, 0x44, 0xf7, 0x42, 0xf6, 0x2, 0xf6, 0xf, 0x74, 0x4f, 0x50, 0x4f, 0xe0, 0x4f, 0x60, 0xf7, 0x4f, 0xf0, 0xf, 0x54, 0xf7, 0x4f, 0x50, 0x44, 0xf6, 0xf, 0x84, 0x4f, 0x60, 0x4f, 0x60, 0x4f, 0x60, 0x4f, 0x60, 0xf6, 0x4, 0xf6, 0x4, 0xf6, 0x4, 0xf, 0x64, 0x44, 0xf, 0x54, 0xf5, 0xe, 0x40, 0x4, 0xf, 0x94, 0xf7, 0x42, 0xf6, 0x2, 0xf6, 0x2, 0xf6, 0x0, 0x4f, 0xf0, 0xfc, 0x0, 0x0, 0xf5, 0x40, 0xf, 0x54, 0x0, 0xf5, 0x40, 0xf, 0x54, 0xf8, 0x4f, 0x60, 0x4f, 0x60, 0xf7, 0x40, 0x4f, 0x80, 0xf4, 0x40, 0x0, 0xf4, 0x40, 0x44, 0x40, 0x4, 0x40, 0xf, 0x64, 0x4, 0xf6, 0x4, 0xf5, 0xf, 0x74, 0xf4, 0x40, 0x44, 0x0, 0x4, 0x4, 0x4f, 0x50, 0x44, 0x40, 0xf, 0x44, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x50, 0x40, 0xff, 0xf, 0x60, 0x4f, 0x60, 0x0, 0xf5, 0x4f, 0xf0, 0xf5, 0x4, 0xf7, 0x4f, 0x50, 0x44, 0xf5, 0x4, 0x44, 0xf4, 0x4, 0x40, 0x44, 0x40, 0x4, 0x44, 0xf6, 0x4, 0xf6, 0xf, 0x74, 0xf7, 0x4f, 0xe0, 0x40, 0x0, 0x44, 0x40, 0x40, 0xf, 0x54, 0x0, 0xf5, 0x40, 0xf, 0x54, 0x0, 0xf4, 0x40, 0x2f, 0x50, 0x4f, 0x56, 0x56, 0x2f, 0x50, 0x4f, 0x76, 0x4f, 0x60, 0x66, 0xf5, 0x4, 0x6f, 0x50, 0xf7, 0x60, 0xf6, 0x4, 0xf6, 0x4, 0xf6, 0x4, 0xf7, 0x60, 0x4f, 0x40, 0x44, 0x4f, 0x60, 0x4f, 0x60, 0xf7, 0x60, 0x44, 0x48, 0x79, 0x4f, 0x60, 0x4f, 0x60, 0x4f, 0x76, 0x40, 0x0, 0xf4, 0x4f, 0x60, 0x4f, 0x60, 0xf7, 0x60, 0x40, 0xf, 0x44, 0x0, 0xf, 0x44, 0xf5, 0x4, 0x4f, 0x76
};

const uint8_t PROGMEM overworld_room0_0[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(48, 32),

    // entity 1
    miscAndEntityType(2, TELEPORTER),
    xy(48, 32),
};



const uint8_t PROGMEM overworld_room0_4[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, BLOB),
    xy(24, 28),
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
    miscAndEntityType(1, CHEST),
    xy(96, 28),
};



const uint8_t PROGMEM overworld_room1_5[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, SKELETON),
    xy(48, 32),
};



const uint8_t PROGMEM overworld_room1_6[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(3, CHEST),
    xy(56, 20),
};



const uint8_t PROGMEM overworld_room2_2[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(2, CHEST),
    xy(24, 16),
};



const uint8_t PROGMEM overworld_room4_6[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(1, TELEPORTER),
    xy(64, 4),
};



const uint8_t PROGMEM overworld_room6_0[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, TELEPORTER),
    xy(80, 24),
};



const uint8_t PROGMEM overworld_room6_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(64, 48),
};

const uint8_t PROGMEM overworld_teleporters[] = {
    // dest x, dest y (in rooms)
    3, 7,
    0, 7,
    0, 0,
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
    overworld_room2_2,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM overworld_row3[7] = {
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    overworld_room6_3
};


const uint8_t * const PROGMEM overworld_row4[7] = {
    overworld_room0_4,
    overworld_room1_4,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM overworld_row5[7] = {
    empty_room,
    overworld_room1_5,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM overworld_row6[7] = {
    empty_room,
    overworld_room1_6,
    empty_room,
    empty_room,
    overworld_room4_6,
    empty_room,
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