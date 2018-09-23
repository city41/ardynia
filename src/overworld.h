#ifndef overworld_h
#define overworld_h

#include "emptyRoom.h"
#include "entityTypes.h"
#include "entityExpressions.h"


const uint8_t PROGMEM overworld_map[490] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    234, 1, 7, 7,
    // room indices (16 bit, little endian), 98 bytes
    // room 0, index 0
    0, 0,
    // room 1, index 11
    11, 0,
    // room 2, index 20
    20, 0,
    // room 3, index 25
    25, 0,
    // room 4, index 34
    34, 0,
    // room 5, index 40
    40, 0,
    // room 6, index 45
    45, 0,
    // room 7, index 53
    53, 0,
    // room 8, index 63
    63, 0,
    // room 9, index 70
    70, 0,
    // room 10, index 73
    73, 0,
    // room 11, index 79
    79, 0,
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
    // room 18, index 121
    121, 0,
    // room 19, index 127
    127, 0,
    // room 20, index 133
    133, 0,
    // room 21, index 143
    143, 0,
    // room 22, index 152
    152, 0,
    // room 23, index 158
    158, 0,
    // room 24, index 165
    165, 0,
    // room 25, index 175
    175, 0,
    // room 26, index 183
    183, 0,
    // room 27, index 191
    191, 0,
    // room 28, index 200
    200, 0,
    // room 29, index 208
    208, 0,
    // room 30, index 212
    212, 0,
    // room 31, index 222
    222, 0,
    // room 32, index 235
    235, 0,
    // room 33, index 246
    246, 0,
    // room 34, index 254
    254, 0,
    // room 35, index 266
    10, 1,
    // room 36, index 275
    19, 1,
    // room 37, index 280
    24, 1,
    // room 38, index 286
    30, 1,
    // room 39, index 296
    40, 1,
    // room 40, index 305
    49, 1,
    // room 41, index 315
    59, 1,
    // room 42, index 326
    70, 1,
    // room 43, index 334
    78, 1,
    // room 44, index 343
    87, 1,
    // room 45, index 351
    95, 1,
    // room 46, index 360
    104, 1,
    // room 47, index 369
    113, 1,
    // room 48, index 378
    122, 1,

    // compressed room data, 388 bytes
    0x1f, 0x6d, 0x20, 0x44, 0x40, 0x2, 0x4, 0x44, 0x0, 0x2f, 0x60, 0xd6, 0xf5, 0xd0, 0x6f, 0x60, 0x6f, 0x60, 0x6f, 0x50, 0xf7, 0xdf, 0xf0, 0xf6, 0x0, 0xdd, 0xf5, 0x40, 0xf, 0x54, 0xf6, 0x4, 0xf6, 0x4, 0xff, 0x4f, 0x60, 0x4f, 0x50, 0x40, 0xfe, 0x4f, 0x70, 0x4f, 0x66, 0xfb, 0x48, 0x79, 0xf6, 0xc, 0xf4, 0x64, 0x44, 0x2f, 0x60, 0x66, 0x5f, 0x46, 0xaf, 0x60, 0x44, 0xf5, 0x0, 0x6, 0xf5, 0x6, 0x6f, 0xf0, 0xf4, 0x0, 0xff, 0xf, 0xd0, 0xf6, 0x4, 0xf6, 0x4, 0xfe, 0x0, 0x4f, 0x50, 0xf5, 0x4f, 0x40, 0x44, 0x4f, 0xa0, 0x4f, 0x66, 0xf6, 0x6, 0xf6, 0x6, 0xf6, 0x4, 0xfb, 0x6f, 0xe4, 0x0, 0x40, 0x44, 0xf5, 0xf, 0xf4, 0xf6, 0x40, 0xf7, 0x4, 0xf6, 0x4, 0xf5, 0x64, 0x4f, 0x50, 0x40, 0xfe, 0xf, 0xe4, 0xfe, 0xf, 0xe4, 0xfe, 0x4, 0xf6, 0x4, 0xf6, 0x0, 0xf6, 0x4, 0xff, 0xf, 0x50, 0x40, 0xf4, 0x40, 0x4, 0xf6, 0xe, 0xf6, 0xe, 0x44, 0xf, 0x44, 0x44, 0x47, 0xf4, 0x4f, 0x60, 0x4f, 0x60, 0xf7, 0x40, 0x4f, 0x50, 0x4f, 0xe0, 0x4f, 0x60, 0xf7, 0x4f, 0x90, 0xf5, 0x30, 0xf, 0x54, 0x1d, 0xdd, 0xb4, 0x4f, 0x40, 0xe4, 0x4f, 0x43, 0xcf, 0x94, 0x4f, 0x60, 0x4f, 0x60, 0x4f, 0x60, 0x4f, 0x60, 0xf6, 0x4, 0xf6, 0x4, 0xf6, 0x4, 0xf, 0x64, 0x44, 0xf, 0x54, 0xf5, 0xe, 0x40, 0x4, 0xf, 0x94, 0xf7, 0x41, 0xf6, 0x2, 0xf6, 0x2, 0xf6, 0x0, 0x4f, 0xf0, 0xfc, 0x0, 0x0, 0xf5, 0x40, 0xf, 0x54, 0x0, 0xf5, 0x40, 0xf, 0x54, 0x47, 0xf6, 0x40, 0x6, 0x0, 0x4, 0x0, 0x60, 0x0, 0x44, 0x46, 0x44, 0x40, 0x4f, 0x80, 0xf4, 0x40, 0x0, 0xf4, 0x40, 0x44, 0x40, 0x4, 0x40, 0xf, 0x64, 0x4, 0xf6, 0x4, 0xf5, 0xf, 0x74, 0xf4, 0x40, 0x44, 0x0, 0x4, 0x4, 0x4f, 0x50, 0x44, 0x40, 0xf, 0x44, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x50, 0x40, 0xff, 0xf, 0x60, 0x4f, 0x60, 0x0, 0xf5, 0x4f, 0xf0, 0xf5, 0x4, 0xf7, 0x4f, 0x50, 0x44, 0xf5, 0x4, 0x44, 0xf4, 0x4, 0x40, 0x44, 0x40, 0x4, 0x44, 0xf6, 0x4, 0xf6, 0xf, 0x74, 0xf7, 0x4f, 0x40, 0x40, 0x4f, 0x60, 0x44, 0x0, 0x4, 0x44, 0x40, 0xf, 0x54, 0x0, 0xf5, 0x40, 0xf, 0x54, 0x0, 0xf4, 0x40, 0x2f, 0x50, 0x4f, 0x76, 0x2f, 0x50, 0x4f, 0x76, 0x4f, 0x60, 0x66, 0xf5, 0x4, 0x6f, 0x50, 0xf7, 0x60, 0xf6, 0x4, 0xf6, 0x4, 0xf6, 0x4, 0xf7, 0x60, 0x4f, 0x40, 0x44, 0x4f, 0x60, 0x4f, 0x60, 0xf7, 0x60, 0xf4, 0x47, 0x94, 0xf6, 0x4, 0xf6, 0x4, 0xf7, 0x60, 0x40, 0x0, 0xf4, 0x4f, 0x60, 0x4f, 0x60, 0xf7, 0x60, 0x40, 0xf, 0x44, 0x0, 0xf, 0x44, 0xf5, 0x4, 0x4f, 0x76
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
    xy(16, 0),
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



const uint8_t PROGMEM overworld_room1_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(5, CHEST),
    xy(48, 28),
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
    2, // number of entities

    // entity 0
    miscAndEntityType(0, SUNKEN_BRIDGE),
    xy(48, 32),

    // entity 1
    miscAndEntityType(0, SWITCH),
    xy(32, 28),
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
    0, 0,
    0, 0,
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
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM overworld_row3[7] = {
    overworld_room0_3,
    overworld_room1_3,
    empty_room,
    overworld_room3_3,
    empty_room,
    empty_room,
    overworld_room6_3
};


const uint8_t * const PROGMEM overworld_row4[7] = {
    overworld_room0_4,
    empty_room,
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