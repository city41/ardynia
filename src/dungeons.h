#ifndef dungeons_h
#define dungeons_h

#include "emptyRoom.h"
#include "entityTypes.h"
#include "entityExpressions.h"


const uint8_t PROGMEM dungeons_map[659] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    147, 2, 8, 8,
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
    // room 10, index 66
    66, 0,
    // room 11, index 76
    76, 0,
    // room 12, index 84
    84, 0,
    // room 13, index 89
    89, 0,
    // room 14, index 97
    97, 0,
    // room 15, index 105
    105, 0,
    // room 16, index 113
    113, 0,
    // room 17, index 121
    121, 0,
    // room 18, index 129
    129, 0,
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
    // room 27, index 216
    216, 0,
    // room 28, index 227
    227, 0,
    // room 29, index 235
    235, 0,
    // room 30, index 243
    243, 0,
    // room 31, index 251
    251, 0,
    // room 32, index 259
    3, 1,
    // room 33, index 271
    15, 1,
    // room 34, index 282
    26, 1,
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
    // room 40, index 337
    81, 1,
    // room 41, index 347
    91, 1,
    // room 42, index 355
    99, 1,
    // room 43, index 363
    107, 1,
    // room 44, index 368
    112, 1,
    // room 45, index 371
    115, 1,
    // room 46, index 379
    123, 1,
    // room 47, index 389
    133, 1,
    // room 48, index 399
    143, 1,
    // room 49, index 407
    151, 1,
    // room 50, index 413
    157, 1,
    // room 51, index 422
    166, 1,
    // room 52, index 432
    176, 1,
    // room 53, index 442
    186, 1,
    // room 54, index 450
    194, 1,
    // room 55, index 458
    202, 1,
    // room 56, index 469
    213, 1,
    // room 57, index 481
    225, 1,
    // room 58, index 489
    233, 1,
    // room 59, index 497
    241, 1,
    // room 60, index 504
    248, 1,
    // room 61, index 509
    253, 1,
    // room 62, index 514
    2, 2,
    // room 63, index 519
    7, 2,

    // compressed room data, 527 bytes
    0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0xf7, 0xdf, 0xe0, 0xf7, 0x30, 0xf7, 0xdf, 0xe0, 0xf7, 0x30, 0xf7, 0xdf, 0xf0, 0xf6, 0x0, 0xf7, 0xdf, 0xf0, 0xf6, 0x0, 0xf7, 0xdf, 0xf0, 0xf6, 0x0, 0xf7, 0xdf, 0xe0, 0x33, 0x30, 0x33, 0x30, 0xf6, 0xdb, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0x3c, 0x2f, 0x50, 0xe2, 0xf5, 0xe, 0x2f, 0x50, 0xe2, 0xf5, 0xe, 0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0xaf, 0x63, 0xf6, 0xdb, 0xf6, 0xe, 0xf6, 0xe, 0x33, 0x30, 0x33, 0xc0, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0xff, 0xf, 0x60, 0xf7, 0x30, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0xaf, 0x63, 0xf6, 0xdb, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0xaf, 0x63, 0xf6, 0xdb, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0x3c, 0x1d, 0xd0, 0xdd, 0xb2, 0xf5, 0xe, 0x66, 0x65, 0x66, 0x62, 0xf5, 0xe, 0x2f, 0x50, 0xe2, 0xf5, 0xe, 0x2f, 0x50, 0xea, 0xf5, 0x3c, 0x1d, 0xd0, 0xdd, 0xb2, 0xf5, 0xe, 0x2f, 0x50, 0xea, 0xf5, 0x3c, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0xf6, 0xdb, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0x3c, 0x2f, 0x50, 0xe2, 0xf5, 0xe, 0x2f, 0x50, 0xe2, 0xf5, 0xe, 0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0xa3, 0x30, 0x33, 0x30, 0xf7, 0xdf, 0xb0, 0x66, 0x6f, 0x43, 0x63, 0x30, 0xf6, 0xe, 0xf6, 0xe, 0x66, 0x65, 0x66, 0x6f, 0x60, 0x40, 0x1f, 0x5d, 0xb2, 0xf5, 0xe, 0x2f, 0x50, 0xea, 0x33, 0x3, 0x3c, 0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0x3c, 0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0x3c, 0x1d, 0xd0, 0xdd, 0xb2, 0xf5, 0xe, 0x2f, 0x50, 0xea, 0x33, 0x3, 0x3c, 0x1f, 0x5d, 0xb2, 0xf5, 0xe, 0x2f, 0x50, 0xea, 0x33, 0x3, 0x3c, 0x2f, 0x50, 0x42, 0xf5, 0x4, 0x2f, 0x60, 0xaf, 0x63, 0xfa, 0x40, 0x44, 0x4f, 0x60, 0xef, 0x63, 0xc0, 0x2f, 0x50, 0xe2, 0xf5, 0xe, 0x2f, 0x50, 0xe2, 0xf5, 0xe, 0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0xaf, 0x63, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0x1f, 0x4d, 0x64, 0xf5, 0x6, 0x42, 0xf4, 0x6, 0x4a, 0xf4, 0x36, 0x40, 0x1d, 0xd0, 0xdd, 0xd2, 0xf6, 0x2, 0xf6, 0xa, 0xf6, 0x30, 0xf6, 0xdb, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0xaf, 0x63, 0xf7, 0xdf, 0xe0, 0xf7, 0x30, 0xff, 0xf, 0xd0, 0xf6, 0xdb, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0x3c, 0x2f, 0x50, 0xe2, 0xf5, 0xe, 0x2f, 0x50, 0xe2, 0xf5, 0xe, 0x44, 0x4d, 0xf6, 0x40, 0xf6, 0x40, 0xf6, 0x40, 0x44, 0x40, 0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0xaf, 0x63, 0xf6, 0xe, 0xf6, 0xe, 0xfd, 0xe, 0x1f, 0x5d, 0xb2, 0xf5, 0xe, 0xf7, 0xa, 0xf5, 0x3c, 0x1f, 0x5d, 0xb2, 0xf5, 0xe, 0xf6, 0xe, 0xaf, 0x53, 0xc0, 0x2f, 0x50, 0xe2, 0xf5, 0xe, 0x2f, 0x50, 0xea, 0xf5, 0x3c, 0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0x2f, 0x60, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0x1f, 0x5d, 0xb2, 0xf5, 0xe, 0x2f, 0x50, 0xea, 0x33, 0x3, 0x3c, 0x1d, 0x6f, 0x4d, 0x66, 0x6f, 0x40, 0x2f, 0x60, 0xa3, 0x30, 0x33, 0x30, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0x3c, 0x1f, 0x6d, 0x2f, 0x60, 0x2f, 0x60, 0xaf, 0x63, 0xf7, 0xdf, 0xe0, 0x33, 0x30, 0x33, 0x30, 0xf7, 0xdf, 0xe0, 0xf7, 0x30, 0xff, 0xf, 0x60, 0xf7, 0x30, 0xff, 0xf, 0x60, 0xf7, 0x30, 0xf6, 0xdb, 0xf6, 0xe, 0xf6, 0xe, 0xf6, 0x3c
};

const uint8_t PROGMEM dungeons_room0_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(4, CHEST),
    xy(48, 20),
};



const uint8_t PROGMEM dungeons_room0_4[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(1, TRIGGER_DOOR),
    xy(48, 60),

    // entity 1
    miscAndEntityType(1, TRIGGER_DOOR),
    xy(48, 4),

    // entity 2
    miscAndEntityType(1, SKELETON),
    xy(88, 24),

    // entity 3
    miscAndEntityType(1, SKELETON),
    xy(24, 24),
};



const uint8_t PROGMEM dungeons_room0_7[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, TELEPORTER),
    xy(48, 52),

    // entity 1
    miscAndEntityType(0, KEY),
    xy(24, 8),

    // entity 2
    miscAndEntityType(0, TORCH),
    xy(80, 8),
};



const uint8_t PROGMEM dungeons_room1_4[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(2, TELEPORTER),
    xy(48, 52),

    // entity 1
    miscAndEntityType(5, CHEST),
    xy(32, 24),
};



const uint8_t PROGMEM dungeons_room1_6[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(96, 32),

    // entity 1
    miscAndEntityType(5, POT),
    xy(16, 20),

    // entity 2
    miscAndEntityType(0, POT),
    xy(40, 20),
};



const uint8_t PROGMEM dungeons_room2_2[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, BOSS_LOCK),
    xy(48, 0),
};



const uint8_t PROGMEM dungeons_room2_6[] = {
    5, // number of entities

    // entity 0
    miscAndEntityType(1, SKELETON),
    xy(48, 20),

    // entity 1
    miscAndEntityType(0, SKELETON),
    xy(64, 44),

    // entity 2
    miscAndEntityType(0, SKELETON),
    xy(48, 52),

    // entity 3
    miscAndEntityType(1, TRIGGER_DOOR),
    xy(96, 36),

    // entity 4
    miscAndEntityType(1, TRIGGER_DOOR),
    xy(0, 36),
};



const uint8_t PROGMEM dungeons_room2_7[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(1, TELEPORTER),
    xy(48, 52),
};



const uint8_t PROGMEM dungeons_room3_4[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(48, 0),
};



const uint8_t PROGMEM dungeons_room3_6[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(1, CHEST),
    xy(48, 24),
};



const uint8_t PROGMEM dungeons_room4_2[] = {
    7, // number of entities

    // entity 0
    miscAndEntityType(3, TELEPORTER),
    xy(48, 4),

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
    xy(0, 20),

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
    xy(48, 48),
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
    xy(48, 48),

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
    empty_room,
    empty_room,
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
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM dungeons_row4[8] = {
    dungeons_room0_4,
    dungeons_room1_4,
    empty_room,
    dungeons_room3_4,
    empty_room,
    empty_room,
    empty_room,
    dungeons_room7_4
};


const uint8_t * const PROGMEM dungeons_row5[8] = {
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    dungeons_room7_5
};


const uint8_t * const PROGMEM dungeons_row6[8] = {
    empty_room,
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
    empty_room,
    dungeons_room2_7,
    empty_room,
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