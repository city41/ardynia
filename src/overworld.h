#ifndef overworld_h
#define overworld_h

#include "emptyRoom.h"
#include "entityTypes.h"
#include "entityExpressions.h"


const uint8_t PROGMEM overworld_map[441] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    185, 1, 7, 6,
    // room indices (16 bit, little endian), 84 bytes
    // room 0, index 0
    0, 0,
    // room 1, index 10
    10, 0,
    // room 2, index 19
    19, 0,
    // room 3, index 28
    28, 0,
    // room 4, index 37
    37, 0,
    // room 5, index 43
    43, 0,
    // room 6, index 48
    48, 0,
    // room 7, index 61
    61, 0,
    // room 8, index 68
    68, 0,
    // room 9, index 76
    76, 0,
    // room 10, index 80
    80, 0,
    // room 11, index 87
    87, 0,
    // room 12, index 97
    97, 0,
    // room 13, index 105
    105, 0,
    // room 14, index 113
    113, 0,
    // room 15, index 122
    122, 0,
    // room 16, index 128
    128, 0,
    // room 17, index 133
    133, 0,
    // room 18, index 142
    142, 0,
    // room 19, index 151
    151, 0,
    // room 20, index 157
    157, 0,
    // room 21, index 167
    167, 0,
    // room 22, index 175
    175, 0,
    // room 23, index 179
    179, 0,
    // room 24, index 188
    188, 0,
    // room 25, index 197
    197, 0,
    // room 26, index 211
    211, 0,
    // room 27, index 219
    219, 0,
    // room 28, index 232
    232, 0,
    // room 29, index 241
    241, 0,
    // room 30, index 246
    246, 0,
    // room 31, index 251
    251, 0,
    // room 32, index 261
    5, 1,
    // room 33, index 270
    14, 1,
    // room 34, index 280
    24, 1,
    // room 35, index 291
    35, 1,
    // room 36, index 299
    43, 1,
    // room 37, index 308
    52, 1,
    // room 38, index 316
    60, 1,
    // room 39, index 325
    69, 1,
    // room 40, index 334
    78, 1,
    // room 41, index 343
    87, 1,

    // compressed room data, 353 bytes
    0x44, 0x4f, 0xb, 0x44, 0x4f, 0x0, 0x2f, 0x20, 0x2f, 0x20, 0xb6, 0xf1, 0xb0, 0x6f, 0x20, 0x6f, 0x20, 0x6f, 0x10, 0xbb, 0x4f, 0xb, 0x0, 0x4f, 0x20, 0xf1, 0x4f, 0x30, 0xf2, 0xb4, 0xf2, 0xf, 0x14, 0x4, 0x4f, 0x20, 0x40, 0xfb, 0x4f, 0x20, 0x4f, 0x10, 0x40, 0xfa, 0x4f, 0x30, 0x4f, 0x26, 0x44, 0x6f, 0x14, 0x6, 0x4, 0x74, 0x0, 0x50, 0x0, 0xcf, 0x6, 0x44, 0x40, 0x2f, 0x20, 0xf3, 0x68, 0xf2, 0xf, 0x34, 0x6, 0xf1, 0x6, 0x6f, 0x80, 0x4f, 0x10, 0x40, 0xff, 0x0, 0xf, 0x34, 0xf2, 0x4, 0xf2, 0x4, 0xf3, 0xf, 0x34, 0x4f, 0x10, 0xf1, 0x4f, 0x10, 0x44, 0x0, 0x4, 0xf2, 0x0, 0x4f, 0x26, 0xf2, 0x6, 0xf2, 0x6, 0xf2, 0x4, 0xf4, 0x6f, 0x44, 0x0, 0xf1, 0x40, 0x4, 0x44, 0x44, 0x47, 0xf0, 0x4f, 0x20, 0x4f, 0x20, 0xf3, 0x40, 0x4f, 0x10, 0x4f, 0xa0, 0x4f, 0x20, 0xf3, 0x4f, 0xc0, 0xf1, 0x40, 0x4b, 0xbb, 0x44, 0x4f, 0x10, 0x44, 0xf1, 0xf, 0x54, 0x4f, 0x20, 0x4f, 0x20, 0x4f, 0x20, 0x40, 0xf0, 0x40, 0xf2, 0x4, 0xf9, 0x4, 0xf, 0x24, 0x44, 0x0, 0x44, 0x4f, 0x20, 0x44, 0x0, 0x40, 0xf5, 0x40, 0xf3, 0x41, 0xf2, 0x2, 0xf2, 0x2, 0xf2, 0x0, 0x4f, 0xf0, 0xf4, 0x0, 0x0, 0xf1, 0x40, 0x4, 0xf2, 0x4, 0xf2, 0xf, 0x14, 0x47, 0xf1, 0x4f, 0x0, 0x6f, 0x20, 0x60, 0xf, 0x34, 0x40, 0xf0, 0x40, 0x0, 0x40, 0x4, 0x0, 0x4, 0x0, 0x40, 0x44, 0x40, 0x4, 0x40, 0xf, 0x24, 0x4, 0xf2, 0x4, 0x0, 0xf6, 0x40, 0xf0, 0x40, 0x44, 0x0, 0x4, 0x4, 0x44, 0xf0, 0x4, 0x44, 0x0, 0xf0, 0x40, 0x2f, 0x20, 0x2f, 0x20, 0x2f, 0x20, 0x2f, 0x10, 0x40, 0xff, 0x0, 0x4, 0xf2, 0x0, 0x0, 0xf1, 0x4f, 0xf0, 0x4, 0xf3, 0x4f, 0x10, 0x44, 0xf1, 0x4, 0x44, 0xf0, 0x4, 0x40, 0x44, 0x40, 0x4, 0x44, 0xf2, 0x4, 0xf2, 0xf, 0x34, 0xf3, 0x4f, 0x0, 0x40, 0x4f, 0x20, 0x44, 0x0, 0x4, 0x44, 0x40, 0xf, 0x14, 0x0, 0xf1, 0x40, 0xf, 0x14, 0x0, 0xf0, 0x40, 0x2f, 0x10, 0x4f, 0x36, 0x2f, 0x10, 0x4f, 0x36, 0x4f, 0x20, 0x66, 0xf1, 0x4, 0x6f, 0x10, 0xf3, 0x60, 0xf2, 0x4, 0xf2, 0x4, 0xf2, 0x4, 0xf3, 0x60, 0x4f, 0x0, 0x44, 0x4f, 0x20, 0x4f, 0x20, 0xf3, 0x60, 0xf0, 0x47, 0x44, 0xf2, 0x4, 0xf2, 0x4, 0xf3, 0x60, 0x40, 0x0, 0xf0, 0x4f, 0x20, 0x4f, 0x20, 0xf3, 0x60, 0x40, 0xf, 0x4, 0x0, 0xf, 0x4, 0xf1, 0x4, 0x4f, 0x36
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
    miscAndEntityType(LAST_TORCH_OPENS_DOORS, TORCH),
    xy(40, 16),

    // entity 1
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(48, 16),

    // entity 2
    miscAndEntityType(3, TELEPORTER),
    xy(48, 0),

    // entity 3
    miscAndEntityType(LAST_TORCH_OPENS_DOORS, TORCH),
    xy(64, 16),
};



const uint8_t PROGMEM overworld_room0_3[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(THREE_SWITCHES_ONE_BOOMERANG, BLOB),
    xy(8, 24),

    // entity 1
    miscAndEntityType(0, SWITCH),
    xy(32, 36),

    // entity 2
    miscAndEntityType(0, SWITCH),
    xy(48, 36),

    // entity 3
    miscAndEntityType(0, SWITCH),
    xy(64, 36),
};



const uint8_t PROGMEM overworld_room0_4[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(THREE_SWITCHES_ONE_BOOMERANG, BLOB),
    xy(16, 20),

    // entity 1
    miscAndEntityType(THREE_SWITCHES_ONE_BOOMERANG, BLOB),
    xy(16, 36),
};



const uint8_t PROGMEM overworld_room0_5[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, KEY),
    xy(48, 36),
};



const uint8_t PROGMEM overworld_room1_3[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, SNAKE),
    xy(40, 32),

    // entity 1
    miscAndEntityType(0, SNAKE),
    xy(64, 36),
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



const uint8_t PROGMEM overworld_room2_0[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(HEART, CHEST),
    xy(64, 20),
};



const uint8_t PROGMEM overworld_room2_1[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, BLOB),
    xy(48, 16),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(56, 24),

    // entity 2
    miscAndEntityType(0, BLOB),
    xy(48, 28),
};



const uint8_t PROGMEM overworld_room2_2[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(THREE_SWITCHES_ONE_BOOMERANG, BLOB),
    xy(48, 20),
};



const uint8_t PROGMEM overworld_room2_3[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(0, CHEST),
    xy(48, 28),

    // entity 1
    miscAndEntityType(0, CHEST),
    xy(64, 28),

    // entity 2
    miscAndEntityType(0, CHEST),
    xy(80, 28),

    // entity 3
    miscAndEntityType(OPEN_CHESTS_IN_RIGHT_ORDER, SUNKEN_BRIDGE),
    xy(16, 36),
};



const uint8_t PROGMEM overworld_room3_0[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(64, 32),
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
    miscAndEntityType(SWORD, CHEST),
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
    4, // number of entities

    // entity 0
    miscAndEntityType(0, BLOB),
    xy(24, 44),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(56, 44),

    // entity 2
    miscAndEntityType(0, BLOB),
    xy(40, 44),

    // entity 3
    miscAndEntityType(0, BLOB),
    xy(64, 44),
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



const uint8_t PROGMEM overworld_room5_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(HEART, CHEST),
    xy(32, 28),
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
    2, // number of entities

    // entity 0
    miscAndEntityType(0, SKELETON),
    xy(16, 32),

    // entity 1
    miscAndEntityType(0, SKELETON),
    xy(32, 32),
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
    2, // number of entities

    // entity 0
    miscAndEntityType(0, SKELETON),
    xy(24, 36),

    // entity 1
    miscAndEntityType(0, LOCK),
    xy(0, 16),
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
    overworld_room2_0,
    overworld_room3_0,
    empty_room,
    empty_room,
    overworld_room6_0
};


const uint8_t * const PROGMEM overworld_row1[7] = {
    overworld_room0_1,
    empty_room,
    overworld_room2_1,
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
    overworld_room2_3,
    overworld_room3_3,
    overworld_room4_3,
    overworld_room5_3,
    overworld_room6_3
};


const uint8_t * const PROGMEM overworld_row4[7] = {
    overworld_room0_4,
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