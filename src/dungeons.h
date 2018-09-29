#ifndef dungeons_h
#define dungeons_h

#include "emptyRoom.h"
#include "entityTypes.h"
#include "entityExpressions.h"


const uint8_t PROGMEM dungeons_map[778] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    10, 3, 8, 8,
    // room indices (16 bit, little endian), 128 bytes
    // room 0, index 0
    0, 0,
    // room 1, index 11
    11, 0,
    // room 2, index 20
    20, 0,
    // room 3, index 29
    29, 0,
    // room 4, index 36
    36, 0,
    // room 5, index 50
    50, 0,
    // room 6, index 62
    62, 0,
    // room 7, index 69
    69, 0,
    // room 8, index 80
    80, 0,
    // room 9, index 92
    92, 0,
    // room 10, index 102
    102, 0,
    // room 11, index 112
    112, 0,
    // room 12, index 125
    125, 0,
    // room 13, index 134
    134, 0,
    // room 14, index 147
    147, 0,
    // room 15, index 157
    157, 0,
    // room 16, index 168
    168, 0,
    // room 17, index 179
    179, 0,
    // room 18, index 189
    189, 0,
    // room 19, index 199
    199, 0,
    // room 20, index 209
    209, 0,
    // room 21, index 220
    220, 0,
    // room 22, index 230
    230, 0,
    // room 23, index 242
    242, 0,
    // room 24, index 254
    254, 0,
    // room 25, index 264
    8, 1,
    // room 26, index 272
    16, 1,
    // room 27, index 280
    24, 1,
    // room 28, index 290
    34, 1,
    // room 29, index 301
    45, 1,
    // room 30, index 311
    55, 1,
    // room 31, index 319
    63, 1,
    // room 32, index 330
    74, 1,
    // room 33, index 342
    86, 1,
    // room 34, index 353
    97, 1,
    // room 35, index 363
    107, 1,
    // room 36, index 371
    115, 1,
    // room 37, index 384
    128, 1,
    // room 38, index 398
    142, 1,
    // room 39, index 407
    151, 1,
    // room 40, index 420
    164, 1,
    // room 41, index 430
    174, 1,
    // room 42, index 438
    182, 1,
    // room 43, index 448
    192, 1,
    // room 44, index 456
    200, 1,
    // room 45, index 466
    210, 1,
    // room 46, index 476
    220, 1,
    // room 47, index 488
    232, 1,
    // room 48, index 498
    242, 1,
    // room 49, index 506
    250, 1,
    // room 50, index 512
    0, 2,
    // room 51, index 520
    8, 2,
    // room 52, index 529
    17, 2,
    // room 53, index 539
    27, 2,
    // room 54, index 550
    38, 2,
    // room 55, index 560
    48, 2,
    // room 56, index 571
    59, 2,
    // room 57, index 583
    71, 2,
    // room 58, index 591
    79, 2,
    // room 59, index 600
    88, 2,
    // room 60, index 609
    97, 2,
    // room 61, index 621
    109, 2,
    // room 62, index 631
    119, 2,
    // room 63, index 638
    126, 2,

    // compressed room data, 646 bytes
    0x1f, 0x1d, 0xb2, 0xf1, 0xe, 0x2f, 0x20, 0x44, 0x40, 0x44, 0x40, 0x1f, 0x1d, 0x42, 0xf1, 0x4, 0xf3, 0xa, 0xf1, 0x34, 0xf2, 0x4d, 0x44, 0xf1, 0x4, 0xf2, 0xf, 0x14, 0x33, 0xf2, 0xd4, 0xfa, 0xf, 0x3, 0x40, 0x0, 0x44, 0x46, 0x64, 0x40, 0x4, 0x66, 0x40, 0x0, 0x40, 0x4, 0x60, 0x4, 0x0, 0x40, 0x4d, 0xd6, 0xdd, 0xd0, 0x0, 0x60, 0x0, 0xf0, 0x6f, 0x20, 0x60, 0x0, 0xf3, 0xdf, 0xa0, 0x33, 0x30, 0x33, 0x40, 0xf0, 0xd4, 0x44, 0xf2, 0x4, 0xf1, 0x4, 0x44, 0xf0, 0x34, 0x40, 0x44, 0x10, 0xb4, 0x44, 0xf1, 0x4, 0x44, 0xf0, 0xf, 0x4, 0xc, 0x44, 0x1d, 0xdb, 0x44, 0x42, 0xf2, 0x2, 0xf1, 0xe, 0xf3, 0x40, 0x1f, 0x1d, 0xbf, 0x20, 0xef, 0x36, 0xa3, 0x30, 0x33, 0xc0, 0x1d, 0xdd, 0x40, 0x2, 0xf2, 0x2, 0x0, 0x4, 0x0, 0xa3, 0x33, 0x40, 0x30, 0x0, 0x40, 0x4, 0x0, 0xf, 0x4, 0xf4, 0xf, 0x33, 0x0, 0x6, 0x0, 0xe0, 0x0, 0x60, 0xe, 0x0, 0x6, 0x56, 0x6f, 0x20, 0xe0, 0x1f, 0x1d, 0xb2, 0xf2, 0x2, 0xf1, 0xe, 0xaf, 0x13, 0xc0, 0x1f, 0x1d, 0xbf, 0x20, 0xe2, 0xf1, 0xe, 0xa3, 0x30, 0x33, 0xc0, 0x44, 0x40, 0x44, 0x42, 0xf2, 0x2, 0xf1, 0xe, 0xaf, 0x13, 0xc0, 0x1f, 0x1d, 0xbf, 0x20, 0xe2, 0xf1, 0xe, 0xaf, 0x13, 0xc0, 0x1d, 0xd0, 0xdd, 0xb2, 0xf1, 0xe, 0xf3, 0x62, 0xf1, 0xe, 0xf1, 0x40, 0x44, 0xf1, 0x4, 0x4f, 0x10, 0x44, 0xf1, 0x34, 0x1d, 0xd0, 0xdd, 0xb2, 0xf1, 0xe, 0x2f, 0x10, 0xea, 0xf1, 0x3c, 0x2f, 0x10, 0x42, 0xf1, 0x4, 0x2f, 0x20, 0x4f, 0x10, 0x40, 0xf0, 0x46, 0xdf, 0x4, 0x6, 0x4, 0xf0, 0x6, 0xf, 0x14, 0x63, 0x40, 0x44, 0x40, 0xf0, 0x4f, 0x10, 0x42, 0xf1, 0xe, 0x44, 0x40, 0x44, 0x40, 0x1f, 0x2d, 0x2f, 0x20, 0x2f, 0x20, 0xa3, 0x30, 0x33, 0x30, 0xf2, 0xdb, 0xf7, 0x6, 0x66, 0xf0, 0x36, 0x33, 0xf2, 0xe, 0xf2, 0xe, 0xf3, 0x6f, 0x13, 0x4, 0xf3, 0x62, 0xf1, 0xe, 0x2f, 0x10, 0xea, 0x33, 0x3, 0x3c, 0x1f, 0x1d, 0x42, 0xf2, 0x2, 0xf1, 0x4, 0xa3, 0x30, 0x33, 0x40, 0x4f, 0x10, 0x4f, 0x20, 0xe4, 0xf1, 0xe, 0x4f, 0x13, 0xc0, 0xf8, 0x40, 0x44, 0x4f, 0x0, 0x44, 0xf1, 0x4, 0x44, 0x40, 0x44, 0x4f, 0x20, 0xe4, 0xf1, 0xe, 0x4f, 0x13, 0xc0, 0x1d, 0xd0, 0xdd, 0xb2, 0xf1, 0xe, 0x2f, 0x10, 0xea, 0x33, 0x3, 0x3c, 0x1f, 0x1d, 0xb2, 0xf1, 0xe, 0x2f, 0x10, 0xea, 0x33, 0x3, 0x3c, 0x1f, 0xd, 0x4, 0x2f, 0x10, 0x42, 0xf2, 0xa, 0xf1, 0x3c, 0xf6, 0x40, 0x44, 0x4f, 0x20, 0xea, 0xf1, 0x3c, 0x20, 0x60, 0x0, 0xe2, 0x6, 0x0, 0xe, 0x66, 0x60, 0x0, 0xe4, 0xf1, 0x4, 0x4d, 0xdd, 0x6d, 0x42, 0x0, 0x6, 0x0, 0x20, 0x0, 0x60, 0x4, 0x33, 0x36, 0x33, 0x4f, 0x10, 0x4f, 0x20, 0xef, 0x20, 0xef, 0x20, 0xe0, 0x1f, 0xd, 0x64, 0x2f, 0x0, 0x64, 0x2f, 0x0, 0x64, 0xa0, 0x33, 0x36, 0x40, 0x1d, 0xd0, 0xdd, 0xd2, 0xf2, 0x2, 0xf2, 0xa, 0xf2, 0x30, 0xf2, 0xdb, 0xf2, 0xe, 0xf2, 0xe, 0xf2, 0xe, 0x8f, 0x1d, 0x92, 0xf1, 0xe, 0x2f, 0x20, 0xaf, 0x13, 0xc0, 0x1f, 0x1d, 0x42, 0xf8, 0xc, 0xaf, 0x13, 0x40, 0x4f, 0x10, 0x4f, 0x30, 0x4f, 0x10, 0xf0, 0x40, 0x44, 0x40, 0xf3, 0x40, 0x0, 0x40, 0xe, 0xa0, 0x4, 0x0, 0xef, 0x34, 0x2f, 0x10, 0xe2, 0x4, 0x44, 0xe, 0x20, 0x40, 0x40, 0xe2, 0xf1, 0xe, 0x44, 0x4d, 0xf2, 0x40, 0xf2, 0x40, 0xf2, 0x40, 0x44, 0x40, 0x1f, 0x2d, 0x2f, 0x20, 0x2f, 0x20, 0xaf, 0x23, 0xf2, 0xe, 0xf2, 0xe, 0xf9, 0xe, 0x1f, 0x1d, 0xb2, 0xf1, 0xe, 0xf3, 0xf, 0x34, 0x4f, 0x1d, 0x42, 0x5, 0x5, 0x4, 0xf2, 0xf, 0x44, 0x44, 0x40, 0x44, 0x42, 0xf1, 0xe, 0x2f, 0x10, 0xef, 0x34, 0x1f, 0xd, 0xb4, 0x2f, 0x10, 0x42, 0xf1, 0x4, 0x44, 0xf0, 0x30, 0x4f, 0x10, 0xe4, 0xf1, 0xe, 0x4f, 0x10, 0xe4, 0xf1, 0x4, 0x1f, 0x1d, 0xb2, 0xf1, 0xe, 0x2f, 0x10, 0xea, 0x33, 0x3, 0x3c, 0x1d, 0x6f, 0xd, 0x66, 0x6f, 0x0, 0x2f, 0x20, 0xa3, 0x30, 0x33, 0x30, 0xf2, 0xe, 0xf2, 0xe, 0xf2, 0xe, 0xf2, 0x3c, 0x44, 0xf0, 0xd4, 0x4f, 0x20, 0x4f, 0x10, 0xf4, 0x40, 0xf4, 0x4f, 0x20, 0x4f, 0x10, 0xf0, 0x40, 0x44, 0x40, 0xf0, 0x4d, 0x44, 0x0, 0x4, 0x0, 0x4, 0x0, 0x44, 0x40, 0x4f, 0x23, 0x44, 0xf0, 0xd4, 0xf4, 0x4, 0x0, 0x4, 0x3, 0xf1, 0x43, 0x4f, 0x10, 0x4f, 0x90, 0x4f, 0x23, 0x40, 0x4f, 0x1d, 0x4f, 0x20, 0x44, 0xf0, 0xf, 0x54
};

const uint8_t PROGMEM dungeons_room0_0[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, POT),
    xy(16, 40),

    // entity 1
    miscAndEntityType(0, POT),
    xy(24, 16),
};



const uint8_t PROGMEM dungeons_room0_1[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(48, 4),

    // entity 1
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(48, 60),

    // entity 2
    miscAndEntityType(1, SKELETON),
    xy(80, 36),

    // entity 3
    miscAndEntityType(1, SKELETON),
    xy(16, 20),
};



const uint8_t PROGMEM dungeons_room0_2[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, BOSS_LOCK),
    xy(96, 20),

    // entity 1
    miscAndEntityType(0, TORCH),
    xy(16, 36),
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
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(48, 56),

    // entity 1
    miscAndEntityType(0, TRIGGER_DOOR),
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
    miscAndEntityType(4, POT),
    xy(8, 40),

    // entity 2
    miscAndEntityType(0, POT),
    xy(48, 20),
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
    xy(80, 20),
};



const uint8_t PROGMEM dungeons_room1_0[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(0, 32),

    // entity 1
    miscAndEntityType(0, POT),
    xy(64, 52),

    // entity 2
    miscAndEntityType(0, BAT),
    xy(24, 12),

    // entity 3
    miscAndEntityType(0, BAT),
    xy(48, 52),
};



const uint8_t PROGMEM dungeons_room1_1[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(5, CHEST),
    xy(32, 20),
};



const uint8_t PROGMEM dungeons_room1_2[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(1, NEMESIS),
    xy(80, 20),

    // entity 1
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(0, 16),
};



const uint8_t PROGMEM dungeons_room1_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(96, 16),
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
    2, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(96, 32),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(32, 36),
};



const uint8_t PROGMEM dungeons_room1_7[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, BLOB),
    xy(80, 52),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(32, 52),
};



const uint8_t PROGMEM dungeons_room2_0[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(0, 32),
};



const uint8_t PROGMEM dungeons_room2_1[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(48, 60),

    // entity 1
    miscAndEntityType(1, GIANT_BAT),
    xy(48, 16),

    // entity 2
    miscAndEntityType(0, SUNKEN_BRIDGE),
    xy(80, 32),

    // entity 3
    miscAndEntityType(0, SUNKEN_BRIDGE),
    xy(16, 32),
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
    3, // number of entities

    // entity 0
    miscAndEntityType(0, SUNKEN_BRIDGE),
    xy(48, 36),

    // entity 1
    miscAndEntityType(0, SWITCH),
    xy(16, 52),

    // entity 2
    miscAndEntityType(0, LOCK),
    xy(80, 52),
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



const uint8_t PROGMEM dungeons_room2_5[] = {
    7, // number of entities

    // entity 0
    miscAndEntityType(3, BLOB),
    xy(16, 8),

    // entity 1
    miscAndEntityType(3, BLOB),
    xy(16, 52),

    // entity 2
    miscAndEntityType(3, BLOB),
    xy(16, 24),

    // entity 3
    miscAndEntityType(3, BAT),
    xy(48, 12),

    // entity 4
    miscAndEntityType(3, BAT),
    xy(56, 52),

    // entity 5
    miscAndEntityType(3, BAT),
    xy(48, 24),

    // entity 6
    miscAndEntityType(3, BAT),
    xy(32, 40),
};



const uint8_t PROGMEM dungeons_room2_6[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(1, SKELETON),
    xy(48, 20),

    // entity 1
    miscAndEntityType(1, SKELETON),
    xy(48, 36),

    // entity 2
    miscAndEntityType(1, TRIGGER_DOOR),
    xy(104, 32),

    // entity 3
    miscAndEntityType(1, TRIGGER_DOOR),
    xy(0, 32),
};



const uint8_t PROGMEM dungeons_room2_7[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(3, SKELETON),
    xy(24, 36),

    // entity 1
    miscAndEntityType(0, SKELETON),
    xy(32, 36),

    // entity 2
    miscAndEntityType(0, SKELETON),
    xy(48, 8),
};



const uint8_t PROGMEM dungeons_room3_1[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(64, 20),

    // entity 1
    miscAndEntityType(1, BAT),
    xy(48, 8),

    // entity 2
    miscAndEntityType(4, CHEST),
    xy(16, 20),
};



const uint8_t PROGMEM dungeons_room3_2[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(2, BAT),
    xy(16, 36),

    // entity 1
    miscAndEntityType(2, SKELETON),
    xy(48, 20),

    // entity 2
    miscAndEntityType(2, SKELETON),
    xy(32, 52),

    // entity 3
    miscAndEntityType(2, BLOB),
    xy(40, 28),
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



const uint8_t PROGMEM dungeons_room3_5[] = {
    8, // number of entities

    // entity 0
    miscAndEntityType(1, TRIGGER_DOOR),
    xy(0, 36),

    // entity 1
    miscAndEntityType(1, TRIGGER_DOOR),
    xy(112, 16),

    // entity 2
    miscAndEntityType(1, SKELETON),
    xy(48, 8),

    // entity 3
    miscAndEntityType(1, SKELETON),
    xy(40, 8),

    // entity 4
    miscAndEntityType(1, SKELETON),
    xy(56, 8),

    // entity 5
    miscAndEntityType(1, SKELETON),
    xy(32, 56),

    // entity 6
    miscAndEntityType(1, SKELETON),
    xy(48, 56),

    // entity 7
    miscAndEntityType(1, SKELETON),
    xy(56, 56),
};



const uint8_t PROGMEM dungeons_room3_6[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(1, CHEST),
    xy(48, 24),
};



const uint8_t PROGMEM dungeons_room3_7[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(1, TELEPORTER),
    xy(48, 60),

    // entity 1
    miscAndEntityType(0, SECRET_WALL),
    xy(0, 16),
};



const uint8_t PROGMEM dungeons_room4_0[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(32, 32),

    // entity 1
    miscAndEntityType(0, TORCH),
    xy(16, 36),

    // entity 2
    miscAndEntityType(0, BOMB),
    xy(104, 24),
};



const uint8_t PROGMEM dungeons_room4_1[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(4, CHEST),
    xy(56, 8),
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



const uint8_t PROGMEM dungeons_room4_3[] = {
    5, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(48, 52),

    // entity 1
    miscAndEntityType(0, POT),
    xy(16, 20),

    // entity 2
    miscAndEntityType(0, POT),
    xy(16, 36),

    // entity 3
    miscAndEntityType(0, BAT),
    xy(16, 52),

    // entity 4
    miscAndEntityType(0, BAT),
    xy(32, 24),
};



const uint8_t PROGMEM dungeons_room4_4[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(2, POT),
    xy(16, 20),

    // entity 1
    miscAndEntityType(0, SUNKEN_BRIDGE),
    xy(16, 36),

    // entity 2
    miscAndEntityType(0, SWITCH),
    xy(80, 20),
};



const uint8_t PROGMEM dungeons_room4_5[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(0, 16),

    // entity 1
    miscAndEntityType(0, LOCK),
    xy(48, 48),

    // entity 2
    miscAndEntityType(0, LOCK),
    xy(96, 16),

    // entity 3
    miscAndEntityType(0, TORCH),
    xy(80, 36),
};



const uint8_t PROGMEM dungeons_room4_6[] = {
    5, // number of entities

    // entity 0
    miscAndEntityType(4, POT),
    xy(16, 36),

    // entity 1
    miscAndEntityType(0, POT),
    xy(32, 36),

    // entity 2
    miscAndEntityType(0, POT),
    xy(48, 36),

    // entity 3
    miscAndEntityType(0, POT),
    xy(64, 36),

    // entity 4
    miscAndEntityType(0, POT),
    xy(80, 36),
};



const uint8_t PROGMEM dungeons_room4_7[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, POT),
    xy(72, 20),
};



const uint8_t PROGMEM dungeons_room5_0[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, TORCH),
    xy(24, 20),
};



const uint8_t PROGMEM dungeons_room5_2[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(96, 36),

    // entity 1
    miscAndEntityType(0, SKELETON),
    xy(48, 36),
};



const uint8_t PROGMEM dungeons_room5_3[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(0, 20),

    // entity 1
    miscAndEntityType(0, TORCH),
    xy(48, 36),
};



const uint8_t PROGMEM dungeons_room5_4[] = {
    6, // number of entities

    // entity 0
    miscAndEntityType(4, CHEST),
    xy(48, 24),

    // entity 1
    miscAndEntityType(0, SUNKEN_BRIDGE),
    xy(64, 36),

    // entity 2
    miscAndEntityType(0, SWITCH),
    xy(80, 12),

    // entity 3
    miscAndEntityType(0, SECRET_WALL),
    xy(80, 0),

    // entity 4
    miscAndEntityType(0, BAT),
    xy(16, 52),

    // entity 5
    miscAndEntityType(0, BAT),
    xy(16, 24),
};



const uint8_t PROGMEM dungeons_room5_5[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(48, 32),

    // entity 1
    miscAndEntityType(0, CHEST),
    xy(80, 28),
};



const uint8_t PROGMEM dungeons_room5_6[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(4, POT),
    xy(16, 20),

    // entity 1
    miscAndEntityType(0, POT),
    xy(32, 20),

    // entity 2
    miscAndEntityType(0, POT),
    xy(64, 20),

    // entity 3
    miscAndEntityType(0, SKELETON),
    xy(16, 36),
};



const uint8_t PROGMEM dungeons_room5_7[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, POT),
    xy(40, 36),

    // entity 1
    miscAndEntityType(0, POT),
    xy(72, 36),

    // entity 2
    miscAndEntityType(0, BLOB),
    xy(48, 36),
};



const uint8_t PROGMEM dungeons_room6_0[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(7, TELEPORTER),
    xy(48, 60),

    // entity 1
    miscAndEntityType(0, TORCH),
    xy(48, 12),
};



const uint8_t PROGMEM dungeons_room6_1[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(5, CHEST),
    xy(32, 20),
};



const uint8_t PROGMEM dungeons_room6_2[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(0, SWITCH),
    xy(32, 28),

    // entity 1
    miscAndEntityType(0, SECRET_WALL),
    xy(32, 16),

    // entity 2
    miscAndEntityType(0, SUNKEN_BRIDGE),
    xy(64, 32),

    // entity 3
    miscAndEntityType(4, CHEST),
    xy(80, 20),
};



const uint8_t PROGMEM dungeons_room6_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(96, 16),
};



const uint8_t PROGMEM dungeons_room6_5[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(2, BAT),
    xy(8, 20),

    // entity 1
    miscAndEntityType(0, BAT),
    xy(96, 52),
};



const uint8_t PROGMEM dungeons_room6_6[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(0, 52),
};



const uint8_t PROGMEM dungeons_room6_7[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(96, 20),
};



const uint8_t PROGMEM dungeons_room7_0[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, TORCH),
    xy(80, 24),

    // entity 1
    miscAndEntityType(2, POT),
    xy(32, 16),

    // entity 2
    miscAndEntityType(2, POT),
    xy(48, 20),
};



const uint8_t PROGMEM dungeons_room7_1[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(1, BLOB_MOTHER),
    xy(48, 20),

    // entity 1
    miscAndEntityType(1, TRIGGER_DOOR),
    xy(0, 16),

    // entity 2
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(48, 60),
};



const uint8_t PROGMEM dungeons_room7_2[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, BOSS_LOCK),
    xy(48, 4),

    // entity 1
    miscAndEntityType(2, POT),
    xy(24, 28),

    // entity 2
    miscAndEntityType(2, POT),
    xy(88, 24),
};



const uint8_t PROGMEM dungeons_room7_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(48, 0),
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



const uint8_t PROGMEM dungeons_room7_7[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(2, CHEST),
    xy(48, 20),
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
    4, 4,
};





const uint8_t * const PROGMEM dungeons_row0[8] = {
    dungeons_room0_0,
    dungeons_room1_0,
    dungeons_room2_0,
    empty_room,
    dungeons_room4_0,
    dungeons_room5_0,
    dungeons_room6_0,
    dungeons_room7_0
};


const uint8_t * const PROGMEM dungeons_row1[8] = {
    dungeons_room0_1,
    dungeons_room1_1,
    dungeons_room2_1,
    dungeons_room3_1,
    dungeons_room4_1,
    empty_room,
    dungeons_room6_1,
    dungeons_room7_1
};


const uint8_t * const PROGMEM dungeons_row2[8] = {
    dungeons_room0_2,
    dungeons_room1_2,
    dungeons_room2_2,
    dungeons_room3_2,
    dungeons_room4_2,
    dungeons_room5_2,
    dungeons_room6_2,
    dungeons_room7_2
};


const uint8_t * const PROGMEM dungeons_row3[8] = {
    dungeons_room0_3,
    dungeons_room1_3,
    dungeons_room2_3,
    dungeons_room3_3,
    dungeons_room4_3,
    dungeons_room5_3,
    dungeons_room6_3,
    dungeons_room7_3
};


const uint8_t * const PROGMEM dungeons_row4[8] = {
    dungeons_room0_4,
    dungeons_room1_4,
    dungeons_room2_4,
    dungeons_room3_4,
    dungeons_room4_4,
    dungeons_room5_4,
    empty_room,
    dungeons_room7_4
};


const uint8_t * const PROGMEM dungeons_row5[8] = {
    empty_room,
    dungeons_room1_5,
    dungeons_room2_5,
    dungeons_room3_5,
    dungeons_room4_5,
    dungeons_room5_5,
    dungeons_room6_5,
    dungeons_room7_5
};


const uint8_t * const PROGMEM dungeons_row6[8] = {
    dungeons_room0_6,
    dungeons_room1_6,
    dungeons_room2_6,
    dungeons_room3_6,
    dungeons_room4_6,
    dungeons_room5_6,
    dungeons_room6_6,
    dungeons_room7_6
};


const uint8_t * const PROGMEM dungeons_row7[8] = {
    dungeons_room0_7,
    dungeons_room1_7,
    dungeons_room2_7,
    dungeons_room3_7,
    dungeons_room4_7,
    dungeons_room5_7,
    dungeons_room6_7,
    dungeons_room7_7
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