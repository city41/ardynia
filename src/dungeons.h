#ifndef dungeons_h
#define dungeons_h

#include "emptyRoom.h"
#include "entityTypes.h"
#include "entityExpressions.h"


const uint8_t PROGMEM dungeons_map[658] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    146, 2, 8, 8,
    // room indices (16 bit, little endian), 128 bytes
    // room 0, index 0
    0, 0,
    // room 1, index 8
    8, 0,
    // room 2, index 13
    13, 0,
    // room 3, index 18
    18, 0,
    // room 4, index 23
    23, 0,
    // room 5, index 28
    28, 0,
    // room 6, index 33
    33, 0,
    // room 7, index 40
    40, 0,
    // room 8, index 48
    48, 0,
    // room 9, index 58
    58, 0,
    // room 10, index 68
    68, 0,
    // room 11, index 78
    78, 0,
    // room 12, index 86
    86, 0,
    // room 13, index 91
    91, 0,
    // room 14, index 99
    99, 0,
    // room 15, index 107
    107, 0,
    // room 16, index 115
    115, 0,
    // room 17, index 123
    123, 0,
    // room 18, index 131
    131, 0,
    // room 19, index 141
    141, 0,
    // room 20, index 151
    151, 0,
    // room 21, index 162
    162, 0,
    // room 22, index 170
    170, 0,
    // room 23, index 178
    178, 0,
    // room 24, index 188
    188, 0,
    // room 25, index 198
    198, 0,
    // room 26, index 206
    206, 0,
    // room 27, index 214
    214, 0,
    // room 28, index 226
    226, 0,
    // room 29, index 234
    234, 0,
    // room 30, index 242
    242, 0,
    // room 31, index 250
    250, 0,
    // room 32, index 258
    2, 1,
    // room 33, index 270
    14, 1,
    // room 34, index 281
    25, 1,
    // room 35, index 291
    35, 1,
    // room 36, index 299
    43, 1,
    // room 37, index 309
    53, 1,
    // room 38, index 317
    61, 1,
    // room 39, index 325
    69, 1,
    // room 40, index 338
    82, 1,
    // room 41, index 348
    92, 1,
    // room 42, index 356
    100, 1,
    // room 43, index 364
    108, 1,
    // room 44, index 369
    113, 1,
    // room 45, index 372
    116, 1,
    // room 46, index 380
    124, 1,
    // room 47, index 390
    134, 1,
    // room 48, index 400
    144, 1,
    // room 49, index 408
    152, 1,
    // room 50, index 414
    158, 1,
    // room 51, index 422
    166, 1,
    // room 52, index 431
    175, 1,
    // room 53, index 441
    185, 1,
    // room 54, index 449
    193, 1,
    // room 55, index 457
    201, 1,
    // room 56, index 468
    212, 1,
    // room 57, index 480
    224, 1,
    // room 58, index 488
    232, 1,
    // room 59, index 496
    240, 1,
    // room 60, index 503
    247, 1,
    // room 61, index 508
    252, 1,
    // room 62, index 513
    1, 2,
    // room 63, index 518
    6, 2,

    // compressed room data, 526 bytes
    0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0xf7, 0xdf, 0xe0, 0xf7, 0x30, 0xf7, 0xdf, 0xe0, 0xf7, 0x30, 0xf7, 0xdf, 0xf0, 0xf6, 0x0, 0xf7, 0xdf, 0xf0, 0xf6, 0x0, 0xf7, 0xdf, 0xf0, 0xf6, 0x0, 0xf7, 0xdf, 0xe0, 0x33, 0x30, 0x33, 0x30, 0xf6, 0xdb, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0x3c, 0x2f, 0x50, 0xe2, 0xf5, 0xe, 0x2f, 0x50, 0xe2, 0xf5, 0xe, 0x1d, 0xdb, 0x44, 0x42, 0xf6, 0x2, 0xf5, 0xe, 0xf7, 0x40, 0x1f, 0x5d, 0xbf, 0x60, 0xef, 0x76, 0xa3, 0x30, 0x33, 0xc0, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0xff, 0xf, 0x60, 0xf7, 0x30, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0xaf, 0x63, 0xf6, 0xdb, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0xaf, 0x63, 0xf6, 0xdb, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0x3c, 0x1d, 0xd0, 0xdd, 0xb2, 0xf5, 0xe, 0xf7, 0x62, 0xf5, 0xe, 0x2f, 0x50, 0xe2, 0xf5, 0xe, 0x2f, 0x50, 0xea, 0xf5, 0x3c, 0x1d, 0xd0, 0xdd, 0xb2, 0xf5, 0xe, 0x2f, 0x50, 0xea, 0xf5, 0x3c, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0xf6, 0xdb, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0x3c, 0x2f, 0x50, 0xe2, 0xf5, 0xe, 0x2f, 0x50, 0xe2, 0xf5, 0xe, 0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0xa3, 0x30, 0x33, 0x30, 0xf7, 0xdf, 0xb0, 0x66, 0x6f, 0x43, 0x63, 0x30, 0xf6, 0xe, 0xf6, 0xe, 0xf7, 0x6f, 0x60, 0x40, 0x1f, 0x5d, 0xb2, 0x5, 0x55, 0xe, 0x2f, 0x50, 0xea, 0x33, 0x3, 0x3c, 0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0x3c, 0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0x3c, 0x1d, 0xd0, 0xdd, 0xb2, 0xf5, 0xe, 0x2f, 0x50, 0xea, 0x33, 0x3, 0x3c, 0x1f, 0x5d, 0xb2, 0xf5, 0xe, 0x2f, 0x50, 0xea, 0x33, 0x3, 0x3c, 0x2f, 0x50, 0x42, 0xf5, 0x4, 0x2f, 0x60, 0xaf, 0x53, 0xc0, 0xfa, 0x40, 0x44, 0x4f, 0x60, 0xea, 0xf5, 0x3c, 0x2f, 0x50, 0xe2, 0xf5, 0xe, 0x2f, 0x50, 0xe2, 0xf5, 0xe, 0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0xaf, 0x63, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0x1f, 0x4d, 0x64, 0x2f, 0x40, 0x64, 0x2f, 0x40, 0x64, 0xa0, 0x33, 0x36, 0x40, 0x1d, 0xd0, 0xdd, 0xd2, 0xf6, 0x2, 0xf6, 0xa, 0xf6, 0x30, 0xf6, 0xdb, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0xaf, 0x63, 0xf7, 0xdf, 0xe0, 0xf7, 0x30, 0xff, 0xf, 0xd0, 0xf6, 0xdb, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0x3c, 0x2f, 0x50, 0xe2, 0xf5, 0xe, 0x2f, 0x50, 0xe2, 0xf5, 0xe, 0x44, 0x4d, 0xf6, 0x40, 0xf6, 0x40, 0xf6, 0x40, 0x44, 0x40, 0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0xaf, 0x63, 0xf6, 0xe, 0xf6, 0xe, 0xfd, 0xe, 0x1f, 0x5d, 0xb2, 0xf5, 0xe, 0xf7, 0xf, 0x74, 0x4f, 0x5d, 0x42, 0x5, 0x5, 0x4, 0xf6, 0xf, 0x84, 0x2f, 0x50, 0xe2, 0xf5, 0xe, 0x2f, 0x50, 0xea, 0xf5, 0x3c, 0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0x1f, 0x5d, 0xb2, 0xf5, 0xe, 0x2f, 0x50, 0xea, 0x33, 0x3, 0x3c, 0x1d, 0x6f, 0x4d, 0x66, 0x6f, 0x40, 0x2f, 0x60, 0xa3, 0x30, 0x33, 0x30, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0x3c, 0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0xaf, 0x63, 0xf7, 0xdf, 0xe0, 0x33, 0x30, 0x33, 0x30, 0xf7, 0xdf, 0xe0, 0xf7, 0x30, 0xff, 0xf, 0x60, 0xf7, 0x30, 0xff, 0xf, 0x60, 0xf7, 0x30, 0xf6, 0xdb, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0x3c
};

const uint8_t PROGMEM dungeons_room0_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(4, CHEST),
    xy(48, 20),
};



const uint8_t PROGMEM dungeons_room0_4[] = {
    6, // number of entities

    // entity 0
    miscAndEntityType(1, TRIGGER_DOOR),
    xy(48, 56),

    // entity 1
    miscAndEntityType(1, TRIGGER_DOOR),
    xy(48, 0),

    // entity 2
    miscAndEntityType(0, BAT),
    xy(88, 24),

    // entity 3
    miscAndEntityType(1, BAT),
    xy(24, 24),

    // entity 4
    miscAndEntityType(0, BAT),
    xy(88, 36),

    // entity 5
    miscAndEntityType(0, BAT),
    xy(16, 36),
};



const uint8_t PROGMEM dungeons_room0_6[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, BLOB),
    xy(32, 20),

    // entity 1
    miscAndEntityType(0, POT),
    xy(8, 36),

    // entity 2
    miscAndEntityType(0, POT),
    xy(8, 20),
};



const uint8_t PROGMEM dungeons_room0_7[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, TELEPORTER),
    xy(48, 60),

    // entity 1
    miscAndEntityType(0, KEY),
    xy(24, 8),

    // entity 2
    miscAndEntityType(0, POT),
    xy(80, 4),
};



const uint8_t PROGMEM dungeons_room1_1[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(5, CHEST),
    xy(32, 20),
};



const uint8_t PROGMEM dungeons_room1_4[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(2, TELEPORTER),
    xy(48, 60),

    // entity 1
    miscAndEntityType(5, CHEST),
    xy(32, 24),
};



const uint8_t PROGMEM dungeons_room1_5[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(0, POT),
    xy(96, 20),

    // entity 1
    miscAndEntityType(0, BAT),
    xy(48, 8),

    // entity 2
    miscAndEntityType(0, BAT),
    xy(80, 20),

    // entity 3
    miscAndEntityType(0, BAT),
    xy(96, 36),
};



const uint8_t PROGMEM dungeons_room1_6[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(96, 32),
};



const uint8_t PROGMEM dungeons_room1_7[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, BLOB),
    xy(80, 52),
};



const uint8_t PROGMEM dungeons_room2_1[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(48, 60),

    // entity 1
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(0, 16),

    // entity 2
    miscAndEntityType(1, BLOB_MOTHER),
    xy(48, 16),
};



const uint8_t PROGMEM dungeons_room2_2[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(0, BOSS_LOCK),
    xy(48, 0),

    // entity 1
    miscAndEntityType(0, SUNKEN_BRIDGE),
    xy(80, 36),

    // entity 2
    miscAndEntityType(0, SUNKEN_BRIDGE),
    xy(16, 32),

    // entity 3
    miscAndEntityType(0, SWITCH),
    xy(32, 20),
};



const uint8_t PROGMEM dungeons_room2_3[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, SUNKEN_BRIDGE),
    xy(48, 36),

    // entity 1
    miscAndEntityType(0, SWITCH),
    xy(16, 52),
};



const uint8_t PROGMEM dungeons_room2_4[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(3, SKELETON),
    xy(16, 48),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(48, 48),

    // entity 2
    miscAndEntityType(0, BLOB),
    xy(64, 48),
};



const uint8_t PROGMEM dungeons_room2_6[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(1, SKELETON),
    xy(48, 20),

    // entity 1
    miscAndEntityType(0, SKELETON),
    xy(48, 36),

    // entity 2
    miscAndEntityType(1, TRIGGER_DOOR),
    xy(104, 32),

    // entity 3
    miscAndEntityType(1, TRIGGER_DOOR),
    xy(0, 32),
};



const uint8_t PROGMEM dungeons_room3_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(5, CHEST),
    xy(48, 24),
};



const uint8_t PROGMEM dungeons_room3_4[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(48, 0),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(80, 36),
};



const uint8_t PROGMEM dungeons_room3_6[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(1, CHEST),
    xy(48, 24),
};



const uint8_t PROGMEM dungeons_room3_7[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(1, TELEPORTER),
    xy(48, 60),
};



const uint8_t PROGMEM dungeons_room4_2[] = {
    7, // number of entities

    // entity 0
    miscAndEntityType(3, TELEPORTER),
    xy(48, 0),

    // entity 1
    miscAndEntityType(3, CHEST),
    xy(80, 36),

    // entity 2
    miscAndEntityType(0, HEART),
    xy(16, 12),

    // entity 3
    miscAndEntityType(0, HEART),
    xy(16, 20),

    // entity 4
    miscAndEntityType(0, HEART),
    xy(16, 28),

    // entity 5
    miscAndEntityType(0, HEART),
    xy(16, 36),

    // entity 6
    miscAndEntityType(0, HEART),
    xy(16, 44),
};



const uint8_t PROGMEM dungeons_room7_4[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(4, TELEPORTER),
    xy(16, 60),

    // entity 1
    miscAndEntityType(5, CHEST),
    xy(64, 20),
};



const uint8_t PROGMEM dungeons_room7_5[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(5, CHEST),
    xy(48, 20),

    // entity 1
    miscAndEntityType(5, TELEPORTER),
    xy(48, 60),
};



const uint8_t PROGMEM dungeons_room7_6[] = {
    7, // number of entities

    // entity 0
    miscAndEntityType(0, HEART),
    xy(16, 16),

    // entity 1
    miscAndEntityType(0, BOMB),
    xy(32, 16),

    // entity 2
    miscAndEntityType(0, BOMB),
    xy(72, 16),

    // entity 3
    miscAndEntityType(0, HEART),
    xy(88, 16),

    // entity 4
    miscAndEntityType(6, TELEPORTER),
    xy(48, 60),

    // entity 5
    miscAndEntityType(0, HEART),
    xy(16, 24),

    // entity 6
    miscAndEntityType(0, HEART),
    xy(88, 24),
};

const uint8_t PROGMEM dungeons_teleporters[] = {
    // dest x, dest y (in rooms)
    4, 6,
    6, 0,
    0, 3,
    0, 0,
    3, 4,
    5, 5,
    6, 1,
};





const uint8_t * const PROGMEM dungeons_row0[8] = {
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM dungeons_row1[8] = {
    empty_room,
    dungeons_room1_1,
    dungeons_room2_1,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM dungeons_row2[8] = {
    empty_room,
    empty_room,
    dungeons_room2_2,
    empty_room,
    dungeons_room4_2,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM dungeons_row3[8] = {
    dungeons_room0_3,
    empty_room,
    dungeons_room2_3,
    dungeons_room3_3,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM dungeons_row4[8] = {
    dungeons_room0_4,
    dungeons_room1_4,
    dungeons_room2_4,
    dungeons_room3_4,
    empty_room,
    empty_room,
    empty_room,
    dungeons_room7_4
};


const uint8_t * const PROGMEM dungeons_row5[8] = {
    empty_room,
    dungeons_room1_5,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    dungeons_room7_5
};


const uint8_t * const PROGMEM dungeons_row6[8] = {
    dungeons_room0_6,
    dungeons_room1_6,
    dungeons_room2_6,
    dungeons_room3_6,
    empty_room,
    empty_room,
    empty_room,
    dungeons_room7_6
};


const uint8_t * const PROGMEM dungeons_row7[8] = {
    dungeons_room0_7,
    dungeons_room1_7,
    empty_room,
    dungeons_room3_7,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const* const PROGMEM dungeons_entities[8] = {
    dungeons_row0,
    dungeons_row1,
    dungeons_row2,
    dungeons_row3,
    dungeons_row4,
    dungeons_row5,
    dungeons_row6,
    dungeons_row7
};


#endif