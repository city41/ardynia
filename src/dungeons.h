#ifndef dungeons_h
#define dungeons_h

#include "emptyRoom.h"
#include "entityTypes.h"
#include "entityExpressions.h"


const uint8_t PROGMEM dungeons_map[787] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    19, 3, 8, 8,
    // room indices (16 bit, little endian), 128 bytes
    // room 0, index 0
    0, 0,
    // room 1, index 11
    11, 0,
    // room 2, index 20
    20, 0,
    // room 3, index 29
    29, 0,
    // room 4, index 35
    35, 0,
    // room 5, index 48
    48, 0,
    // room 6, index 60
    60, 0,
    // room 7, index 67
    67, 0,
    // room 8, index 78
    78, 0,
    // room 9, index 90
    90, 0,
    // room 10, index 99
    99, 0,
    // room 11, index 109
    109, 0,
    // room 12, index 119
    119, 0,
    // room 13, index 131
    131, 0,
    // room 14, index 144
    144, 0,
    // room 15, index 152
    152, 0,
    // room 16, index 163
    163, 0,
    // room 17, index 174
    174, 0,
    // room 18, index 184
    184, 0,
    // room 19, index 195
    195, 0,
    // room 20, index 205
    205, 0,
    // room 21, index 216
    216, 0,
    // room 22, index 226
    226, 0,
    // room 23, index 238
    238, 0,
    // room 24, index 250
    250, 0,
    // room 25, index 261
    5, 1,
    // room 26, index 270
    14, 1,
    // room 27, index 282
    26, 1,
    // room 28, index 292
    36, 1,
    // room 29, index 303
    47, 1,
    // room 30, index 313
    57, 1,
    // room 31, index 321
    65, 1,
    // room 32, index 332
    76, 1,
    // room 33, index 344
    88, 1,
    // room 34, index 355
    99, 1,
    // room 35, index 365
    109, 1,
    // room 36, index 375
    119, 1,
    // room 37, index 388
    132, 1,
    // room 38, index 402
    146, 1,
    // room 39, index 414
    158, 1,
    // room 40, index 427
    171, 1,
    // room 41, index 437
    181, 1,
    // room 42, index 445
    189, 1,
    // room 43, index 455
    199, 1,
    // room 44, index 463
    207, 1,
    // room 45, index 473
    217, 1,
    // room 46, index 482
    226, 1,
    // room 47, index 494
    238, 1,
    // room 48, index 504
    248, 1,
    // room 49, index 513
    1, 2,
    // room 50, index 523
    11, 2,
    // room 51, index 528
    16, 2,
    // room 52, index 536
    24, 2,
    // room 53, index 546
    34, 2,
    // room 54, index 556
    44, 2,
    // room 55, index 566
    54, 2,
    // room 56, index 577
    65, 2,
    // room 57, index 590
    78, 2,
    // room 58, index 602
    90, 2,
    // room 59, index 612
    100, 2,
    // room 60, index 621
    109, 2,
    // room 61, index 630
    118, 2,
    // room 62, index 638
    126, 2,
    // room 63, index 647
    135, 2,

    // compressed room data, 655 bytes
    0x1f, 0x1b, 0x92, 0xf1, 0xc, 0x2f, 0x20, 0x44, 0x40, 0x44, 0x40, 0x1f, 0x1b, 0x42, 0xf1, 0x4, 0xf3, 0x8, 0xf1, 0x34, 0xf2, 0x4b, 0x44, 0xf1, 0x4, 0xf2, 0xf, 0x14, 0x33, 0xf2, 0xb4, 0xfa, 0xf, 0x23, 0x0, 0x44, 0x46, 0x64, 0x40, 0x4, 0x66, 0x4f, 0x20, 0x46, 0x0, 0x40, 0x4, 0x0, 0x4b, 0xb6, 0xbb, 0xb0, 0x0, 0x60, 0x0, 0xf0, 0x6f, 0x20, 0x60, 0x0, 0xf3, 0xbf, 0xa0, 0x33, 0x30, 0x33, 0x40, 0xf0, 0xb4, 0x44, 0xf2, 0x4, 0xf1, 0x4, 0x44, 0xf0, 0x34, 0x40, 0x44, 0x10, 0x94, 0x44, 0xf1, 0x4, 0x44, 0xf0, 0xf, 0x4, 0xa, 0x44, 0x1b, 0xbb, 0x44, 0x42, 0xf2, 0x2, 0xf1, 0xf, 0x44, 0x1f, 0x1b, 0x9f, 0x20, 0xcf, 0x36, 0x83, 0x30, 0x33, 0xa0, 0x1f, 0x1b, 0x2, 0xf2, 0x2, 0xf2, 0x8, 0xf0, 0x30, 0x30, 0x0, 0x40, 0x4, 0x0, 0x4, 0x0, 0x40, 0x0, 0xf0, 0x40, 0xf3, 0x30, 0x0, 0x6, 0x0, 0xc0, 0x0, 0x60, 0xc, 0x0, 0x6, 0x56, 0x6f, 0x20, 0x40, 0x4b, 0xbf, 0x14, 0xf2, 0x4, 0x0, 0xf7, 0x40, 0x1f, 0x1b, 0x9f, 0x20, 0xc2, 0xf1, 0xc, 0x83, 0x30, 0x33, 0xa0, 0x44, 0x40, 0x44, 0x42, 0xf2, 0x2, 0xf1, 0xc, 0x8f, 0x13, 0xa0, 0x1f, 0x1b, 0x9f, 0x20, 0xc2, 0xf1, 0xc, 0x8f, 0x13, 0xa0, 0x1b, 0xb0, 0xbb, 0x92, 0xf1, 0xc, 0xf3, 0x62, 0x0, 0x6, 0xc, 0xf1, 0x40, 0x44, 0xf1, 0x4, 0x4f, 0x10, 0x44, 0xf1, 0x34, 0x1b, 0xb0, 0xbb, 0x92, 0xf1, 0xc, 0x2f, 0x10, 0xc8, 0xf1, 0x3a, 0x2f, 0x10, 0x42, 0xf1, 0x4, 0x2f, 0x20, 0x4f, 0x10, 0x40, 0xf0, 0x46, 0xbf, 0x4, 0x6, 0x4, 0xf0, 0x5, 0xf, 0x14, 0x63, 0x40, 0x44, 0x40, 0xf0, 0x4f, 0x10, 0x42, 0xf1, 0xc, 0x44, 0x40, 0x44, 0x40, 0x1f, 0x1b, 0x92, 0xf2, 0x2, 0xf1, 0xc, 0x44, 0x40, 0x44, 0x40, 0x1f, 0x1b, 0x9f, 0x30, 0x2f, 0x10, 0xc8, 0xf1, 0x3a, 0x20, 0x0, 0x60, 0xcf, 0x0, 0x60, 0xcf, 0x16, 0xc, 0x8f, 0x3, 0x4, 0xf3, 0x62, 0xf1, 0xc, 0x2f, 0x10, 0xc8, 0x33, 0x3, 0x3a, 0x1f, 0x1b, 0x42, 0xf2, 0x2, 0xf1, 0x4, 0x83, 0x30, 0x33, 0x40, 0x4f, 0x10, 0x4f, 0x20, 0xc4, 0xf1, 0xc, 0x4f, 0x13, 0xa0, 0xf8, 0x40, 0x44, 0x4f, 0x0, 0x44, 0xf1, 0x4, 0x44, 0x40, 0x44, 0x4f, 0x20, 0xc4, 0xf1, 0xc, 0x4f, 0x13, 0xa0, 0x1b, 0xb0, 0xbb, 0x92, 0xf1, 0xc, 0x2f, 0x10, 0xc8, 0x33, 0x3, 0x3a, 0x1f, 0x1b, 0x92, 0xf1, 0xc, 0x2f, 0x10, 0xc8, 0x33, 0x3, 0x3a, 0x1f, 0xb, 0x4, 0x2f, 0x10, 0x42, 0xf2, 0x8, 0xf1, 0x3a, 0x44, 0x40, 0xf2, 0x40, 0x44, 0x4f, 0x20, 0xc8, 0xf1, 0x3a, 0x1b, 0x60, 0xbb, 0x92, 0x6, 0x0, 0xc, 0x66, 0x60, 0x0, 0xc4, 0xf1, 0x4, 0x4b, 0xbb, 0x6b, 0x42, 0x0, 0x6, 0x0, 0x20, 0x0, 0x60, 0x44, 0x33, 0x36, 0x34, 0x4f, 0x10, 0x40, 0x6, 0x66, 0xc, 0x40, 0x66, 0x60, 0xc4, 0xf1, 0xc, 0x1f, 0xb, 0x64, 0x2f, 0x0, 0x64, 0x2f, 0x0, 0x64, 0x80, 0x33, 0x36, 0x40, 0x1b, 0xb0, 0xbb, 0xb2, 0xf2, 0x2, 0xf2, 0x8, 0xf2, 0x30, 0xf2, 0xb9, 0xf2, 0xc, 0xf2, 0xc, 0xf2, 0xc, 0x1f, 0x1b, 0x92, 0xf1, 0xc, 0x2f, 0x20, 0x8f, 0x13, 0xa0, 0x1f, 0x1b, 0x42, 0xf8, 0xc, 0x8f, 0x13, 0x40, 0x4f, 0x10, 0x4f, 0x30, 0x4f, 0x10, 0x44, 0x4, 0x4, 0x4, 0xf3, 0x4f, 0x10, 0x4c, 0x8f, 0x0, 0x4c, 0xf3, 0x40, 0x4f, 0x10, 0xc2, 0x4, 0x44, 0xc, 0x20, 0x40, 0x40, 0xc2, 0xf1, 0xc, 0x44, 0x4b, 0xf2, 0x40, 0xf2, 0x40, 0xf2, 0x40, 0x44, 0x40, 0x1f, 0x1b, 0x92, 0xf2, 0x2, 0xf2, 0x8, 0xf1, 0x3a, 0x2f, 0x10, 0xcf, 0x20, 0xcf, 0x30, 0x20, 0x0, 0x66, 0x60, 0xfa, 0x4f, 0x30, 0xf3, 0x40, 0x4f, 0x1b, 0x42, 0xf1, 0x4, 0xf2, 0xf, 0x44, 0x40, 0x40, 0x40, 0x42, 0xf1, 0xc, 0x2f, 0x10, 0xcf, 0x34, 0x1f, 0x1b, 0x42, 0xf1, 0x4, 0x2f, 0x20, 0x44, 0xf0, 0x34, 0x4f, 0x10, 0xc4, 0xf1, 0xc, 0x4f, 0x10, 0xc4, 0xf1, 0x4, 0x1f, 0x1b, 0x92, 0xf1, 0xc, 0x2f, 0x10, 0xc8, 0x33, 0x3, 0x3a, 0x1b, 0x6f, 0xb, 0x20, 0x6f, 0x0, 0x20, 0x6f, 0x0, 0x83, 0x60, 0x33, 0x30, 0xf0, 0x6, 0x66, 0xf0, 0x6, 0xc, 0xf0, 0x5, 0xc, 0xf0, 0x36, 0x3a, 0x14, 0xf0, 0xb4, 0x2f, 0x20, 0x2f, 0x10, 0x48, 0xf1, 0x34, 0xf4, 0x4f, 0x20, 0x4f, 0x10, 0xf0, 0x40, 0x44, 0x40, 0x1f, 0x1b, 0x9f, 0x30, 0x4f, 0x20, 0x4f, 0x13, 0x40, 0x44, 0xf0, 0xb4, 0xf4, 0x4, 0x0, 0xf, 0x54, 0x4f, 0x10, 0x4f, 0x30, 0x4f, 0x10, 0x44, 0xf1, 0x34, 0x4f, 0x1b, 0x4f, 0x20, 0x44, 0xf0, 0xf, 0x54
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
    xy(48, 0),

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
    4, // number of entities

    // entity 0
    miscAndEntityType(0, CHEST),
    xy(48, 20),

    // entity 1
    miscAndEntityType(0, CHEST),
    xy(80, 20),

    // entity 2
    miscAndEntityType(0, CHEST),
    xy(16, 20),

    // entity 3
    miscAndEntityType(6, SUNKEN_BRIDGE),
    xy(8, 40),
};



const uint8_t PROGMEM dungeons_room0_4[] = {
    7, // number of entities

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

    // entity 6
    miscAndEntityType(0, BAT),
    xy(96, 44),
};



const uint8_t PROGMEM dungeons_room0_5[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, POT),
    xy(16, 36),

    // entity 1
    miscAndEntityType(0, POT),
    xy(32, 36),
};



const uint8_t PROGMEM dungeons_room0_6[] = {
    8, // number of entities

    // entity 0
    miscAndEntityType(0, BLOB),
    xy(32, 20),

    // entity 1
    miscAndEntityType(3, POT),
    xy(16, 12),

    // entity 2
    miscAndEntityType(0, POT),
    xy(48, 12),

    // entity 3
    miscAndEntityType(0, BLOB),
    xy(32, 24),

    // entity 4
    miscAndEntityType(0, POT),
    xy(48, 48),

    // entity 5
    miscAndEntityType(0, POT),
    xy(16, 48),

    // entity 6
    miscAndEntityType(0, BLOB),
    xy(32, 36),

    // entity 7
    miscAndEntityType(0, BLOB),
    xy(32, 44),
};



const uint8_t PROGMEM dungeons_room0_7[] = {
    5, // number of entities

    // entity 0
    miscAndEntityType(0, TELEPORTER),
    xy(48, 60),

    // entity 1
    miscAndEntityType(3, CHEST),
    xy(16, 16),

    // entity 2
    miscAndEntityType(0, SWITCH),
    xy(16, 44),

    // entity 3
    miscAndEntityType(0, SUNKEN_BRIDGE),
    xy(32, 32),

    // entity 4
    miscAndEntityType(0, POT),
    xy(72, 48),
};



const uint8_t PROGMEM dungeons_room1_0[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(0, 32),

    // entity 1
    miscAndEntityType(0, POT),
    xy(64, 16),

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
    miscAndEntityType(4, CHEST),
    xy(32, 20),
};



const uint8_t PROGMEM dungeons_room1_2[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(1, NEMESIS),
    xy(80, 20),

    // entity 1
    miscAndEntityType(1, TRIGGER_DOOR),
    xy(0, 16),
};



const uint8_t PROGMEM dungeons_room1_3[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(96, 16),

    // entity 1
    miscAndEntityType(0, SKELETON),
    xy(48, 36),
};



const uint8_t PROGMEM dungeons_room1_4[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(2, TELEPORTER),
    xy(48, 60),

    // entity 1
    miscAndEntityType(3, GIANT_BAT),
    xy(48, 12),
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
    miscAndEntityType(2, BAT),
    xy(96, 36),
};



const uint8_t PROGMEM dungeons_room1_6[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(96, 32),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(48, 32),

    // entity 2
    miscAndEntityType(0, BLOB),
    xy(64, 32),
};



const uint8_t PROGMEM dungeons_room1_7[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, BLOB),
    xy(64, 52),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(80, 20),

    // entity 2
    miscAndEntityType(3, CHEST),
    xy(80, 36),
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
    xy(32, 36),

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
    miscAndEntityType(0, SWITCH),
    xy(96, 20),

    // entity 1
    miscAndEntityType(0, SUNKEN_BRIDGE),
    xy(16, 36),
};



const uint8_t PROGMEM dungeons_room2_4[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(96, 36),
};



const uint8_t PROGMEM dungeons_room2_5[] = {
    8, // number of entities

    // entity 0
    miscAndEntityType(4, BLOB),
    xy(16, 8),

    // entity 1
    miscAndEntityType(4, BLOB),
    xy(16, 52),

    // entity 2
    miscAndEntityType(4, BLOB),
    xy(16, 24),

    // entity 3
    miscAndEntityType(4, BAT),
    xy(48, 12),

    // entity 4
    miscAndEntityType(4, BLOB),
    xy(56, 52),

    // entity 5
    miscAndEntityType(4, BAT),
    xy(48, 24),

    // entity 6
    miscAndEntityType(4, BAT),
    xy(32, 40),

    // entity 7
    miscAndEntityType(0, SKELETON),
    xy(32, 52),
};



const uint8_t PROGMEM dungeons_room2_6[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(96, 32),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(56, 36),
};



const uint8_t PROGMEM dungeons_room2_7[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(4, SKELETON),
    xy(24, 36),

    // entity 1
    miscAndEntityType(0, SKELETON),
    xy(32, 36),

    // entity 2
    miscAndEntityType(0, SKELETON),
    xy(48, 8),
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
    3, // number of entities

    // entity 0
    miscAndEntityType(4, SKELETON),
    xy(16, 20),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(80, 20),

    // entity 2
    miscAndEntityType(0, BLOB),
    xy(88, 20),
};



const uint8_t PROGMEM dungeons_room3_4[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(48, 0),
};



const uint8_t PROGMEM dungeons_room3_5[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(1, TRIGGER_DOOR),
    xy(0, 36),

    // entity 1
    miscAndEntityType(1, TRIGGER_DOOR),
    xy(104, 16),

    // entity 2
    miscAndEntityType(1, BLOB_MOTHER),
    xy(16, 36),
};



const uint8_t PROGMEM dungeons_room3_6[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(1, CHEST),
    xy(48, 24),
};



const uint8_t PROGMEM dungeons_room3_7[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(1, TELEPORTER),
    xy(48, 60),

    // entity 1
    miscAndEntityType(0, SECRET_WALL),
    xy(0, 16),

    // entity 2
    miscAndEntityType(0, POT),
    xy(88, 36),

    // entity 3
    miscAndEntityType(0, POT),
    xy(24, 36),
};



const uint8_t PROGMEM dungeons_room4_0[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(1, TRIGGER_DOOR),
    xy(32, 32),

    // entity 1
    miscAndEntityType(7, TORCH),
    xy(16, 24),

    // entity 2
    miscAndEntityType(0, BOMB),
    xy(104, 24),

    // entity 3
    miscAndEntityType(0, TORCH),
    xy(64, 36),
};



const uint8_t PROGMEM dungeons_room4_1[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(3, CHEST),
    xy(48, 12),
};



const uint8_t PROGMEM dungeons_room4_2[] = {
    7, // number of entities

    // entity 0
    miscAndEntityType(3, TELEPORTER),
    xy(48, 0),

    // entity 1
    miscAndEntityType(5, CHEST),
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
    6, // number of entities

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

    // entity 4
    miscAndEntityType(0, LOCK),
    xy(16, 48),

    // entity 5
    miscAndEntityType(0, LOCK),
    xy(80, 48),
};



const uint8_t PROGMEM dungeons_room4_6[] = {
    5, // number of entities

    // entity 0
    miscAndEntityType(0, CHEST),
    xy(80, 28),

    // entity 1
    miscAndEntityType(0, CHEST),
    xy(64, 28),

    // entity 2
    miscAndEntityType(0, CHEST),
    xy(16, 28),

    // entity 3
    miscAndEntityType(6, SUNKEN_BRIDGE),
    xy(96, 44),

    // entity 4
    miscAndEntityType(0, CHEST),
    xy(32, 28),
};



const uint8_t PROGMEM dungeons_room4_7[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(0, SWITCH),
    xy(80, 44),

    // entity 1
    miscAndEntityType(5, SWITCH),
    xy(64, 16),

    // entity 2
    miscAndEntityType(0, SWITCH),
    xy(32, 16),

    // entity 3
    miscAndEntityType(0, SWITCH),
    xy(48, 44),
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
    xy(96, 32),

    // entity 1
    miscAndEntityType(0, SKELETON),
    xy(48, 36),
};



const uint8_t PROGMEM dungeons_room5_3[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(1, TRIGGER_DOOR),
    xy(0, 16),

    // entity 1
    miscAndEntityType(0, TORCH),
    xy(16, 48),

    // entity 2
    miscAndEntityType(7, TORCH),
    xy(80, 48),

    // entity 3
    miscAndEntityType(3, POT),
    xy(80, 20),
};



const uint8_t PROGMEM dungeons_room5_4[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(2, CHEST),
    xy(48, 24),

    // entity 1
    miscAndEntityType(0, SUNKEN_BRIDGE),
    xy(64, 36),

    // entity 2
    miscAndEntityType(0, SWITCH),
    xy(32, 36),
};



const uint8_t PROGMEM dungeons_room5_5[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(0, SWITCH),
    xy(96, 16),

    // entity 1
    miscAndEntityType(0, SWITCH),
    xy(96, 36),

    // entity 2
    miscAndEntityType(0, SWITCH),
    xy(64, 36),

    // entity 3
    miscAndEntityType(5, HEART),
    xy(96, 44),
};



const uint8_t PROGMEM dungeons_room5_6[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(3, POT),
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
    4, // number of entities

    // entity 0
    miscAndEntityType(0, POT),
    xy(40, 8),

    // entity 1
    miscAndEntityType(0, POT),
    xy(72, 36),

    // entity 2
    miscAndEntityType(0, BLOB),
    xy(48, 36),

    // entity 3
    miscAndEntityType(0, LOCK),
    xy(96, 16),
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
    miscAndEntityType(4, CHEST),
    xy(32, 20),
};



const uint8_t PROGMEM dungeons_room6_2[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(64, 32),

    // entity 1
    miscAndEntityType(3, CHEST),
    xy(80, 20),
};



const uint8_t PROGMEM dungeons_room6_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(96, 16),
};



const uint8_t PROGMEM dungeons_room6_4[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(0, 16),
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
    3, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(0, 32),

    // entity 1
    miscAndEntityType(0, BAT),
    xy(56, 36),

    // entity 2
    miscAndEntityType(0, BAT),
    xy(72, 36),
};



const uint8_t PROGMEM dungeons_room6_7[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(96, 16),
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
    5, // number of entities

    // entity 0
    miscAndEntityType(0, BOSS_LOCK),
    xy(48, 4),

    // entity 1
    miscAndEntityType(2, POT),
    xy(24, 28),

    // entity 2
    miscAndEntityType(2, POT),
    xy(88, 24),

    // entity 3
    miscAndEntityType(2, POT),
    xy(88, 36),

    // entity 4
    miscAndEntityType(2, POT),
    xy(24, 36),
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
    miscAndEntityType(4, CHEST),
    xy(64, 20),
};



const uint8_t PROGMEM dungeons_room7_5[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, BLOB),
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
    5, // number of entities

    // entity 0
    miscAndEntityType(2, BAT),
    xy(80, 20),

    // entity 1
    miscAndEntityType(2, BAT),
    xy(72, 40),

    // entity 2
    miscAndEntityType(2, BAT),
    xy(48, 12),

    // entity 3
    miscAndEntityType(2, BAT),
    xy(56, 40),

    // entity 4
    miscAndEntityType(2, BAT),
    xy(72, 40),
};

const uint8_t PROGMEM dungeons_teleporters[] = {
    // dest x, dest y (in rooms)
    4, 5,
    6, 0,
    0, 2,
    0, 0,
    3, 3,
    5, 4,
    6, 1,
    4, 3,
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
    empty_room,
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
    dungeons_room6_4,
    dungeons_room7_4
};


const uint8_t * const PROGMEM dungeons_row5[8] = {
    dungeons_room0_5,
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