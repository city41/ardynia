#ifndef dungeons_h
#define dungeons_h

#include "emptyRoom.h"
#include "entityTypes.h"
#include "entityExpressions.h"


const uint8_t PROGMEM dungeons_map[807] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    39, 3, 8, 8,
    // room indices (16 bit, little endian), 128 bytes
    // room 0, index 0
    0, 0,
    // room 1, index 11
    11, 0,
    // room 2, index 20
    20, 0,
    // room 3, index 27
    27, 0,
    // room 4, index 37
    37, 0,
    // room 5, index 51
    51, 0,
    // room 6, index 63
    63, 0,
    // room 7, index 76
    76, 0,
    // room 8, index 84
    84, 0,
    // room 9, index 96
    96, 0,
    // room 10, index 110
    110, 0,
    // room 11, index 120
    120, 0,
    // room 12, index 130
    130, 0,
    // room 13, index 142
    142, 0,
    // room 14, index 155
    155, 0,
    // room 15, index 164
    164, 0,
    // room 16, index 175
    175, 0,
    // room 17, index 186
    186, 0,
    // room 18, index 196
    196, 0,
    // room 19, index 207
    207, 0,
    // room 20, index 217
    217, 0,
    // room 21, index 228
    228, 0,
    // room 22, index 238
    238, 0,
    // room 23, index 250
    250, 0,
    // room 24, index 262
    6, 1,
    // room 25, index 273
    17, 1,
    // room 26, index 282
    26, 1,
    // room 27, index 294
    38, 1,
    // room 28, index 304
    48, 1,
    // room 29, index 315
    59, 1,
    // room 30, index 325
    69, 1,
    // room 31, index 333
    77, 1,
    // room 32, index 344
    88, 1,
    // room 33, index 356
    100, 1,
    // room 34, index 367
    111, 1,
    // room 35, index 377
    121, 1,
    // room 36, index 387
    131, 1,
    // room 37, index 399
    143, 1,
    // room 38, index 409
    153, 1,
    // room 39, index 421
    165, 1,
    // room 40, index 432
    176, 1,
    // room 41, index 442
    186, 1,
    // room 42, index 451
    195, 1,
    // room 43, index 461
    205, 1,
    // room 44, index 474
    218, 1,
    // room 45, index 485
    229, 1,
    // room 46, index 493
    237, 1,
    // room 47, index 505
    249, 1,
    // room 48, index 515
    3, 2,
    // room 49, index 524
    12, 2,
    // room 50, index 534
    22, 2,
    // room 51, index 539
    27, 2,
    // room 52, index 551
    39, 2,
    // room 53, index 561
    49, 2,
    // room 54, index 571
    59, 2,
    // room 55, index 584
    72, 2,
    // room 56, index 595
    83, 2,
    // room 57, index 608
    96, 2,
    // room 58, index 620
    108, 2,
    // room 59, index 629
    117, 2,
    // room 60, index 638
    126, 2,
    // room 61, index 647
    135, 2,
    // room 62, index 656
    144, 2,
    // room 63, index 664
    152, 2,

    // compressed room data, 675 bytes
    0x1f, 0x1b, 0x92, 0xf1, 0xc, 0x2f, 0x20, 0x44, 0x40, 0x44, 0x40, 0x1f, 0x1b, 0x42, 0xf1, 0x4, 0xf3, 0x8, 0xf1, 0x34, 0xf5, 0x4f, 0x10, 0x4f, 0x20, 0xf3, 0x40, 0x4f, 0x1b, 0x4f, 0x20, 0x4f, 0x20, 0x44, 0xf0, 0x30, 0x40, 0x44, 0x46, 0x64, 0x44, 0x4, 0x66, 0x40, 0x4f, 0x0, 0x46, 0x40, 0x40, 0x4, 0x0, 0x4b, 0xb6, 0xbb, 0x40, 0x0, 0x60, 0x4, 0xf0, 0x6f, 0x20, 0x60, 0x4, 0x4b, 0xbb, 0x4b, 0x44, 0x4, 0xf2, 0x4, 0x4, 0x4, 0x43, 0x40, 0x44, 0x40, 0x4b, 0xf1, 0x4f, 0x20, 0x44, 0xf1, 0xf, 0x44, 0x44, 0x10, 0x94, 0x44, 0xf1, 0x4, 0x44, 0xf0, 0xf, 0x4, 0xa, 0x44, 0x1b, 0xb6, 0x44, 0x42, 0x0, 0x60, 0x0, 0x20, 0x6, 0x0, 0xf0, 0x46, 0x44, 0x40, 0x1f, 0x1b, 0x9f, 0x20, 0xcf, 0x36, 0x83, 0x30, 0x33, 0xa0, 0x1f, 0xb, 0x4, 0x2f, 0x20, 0x2f, 0x20, 0x8f, 0x3, 0x4, 0x40, 0x40, 0x4, 0x0, 0x4, 0x0, 0x40, 0x0, 0xf0, 0x40, 0x4f, 0x23, 0x0, 0x6, 0x0, 0x90, 0x0, 0x60, 0xc, 0x0, 0x6, 0x56, 0x6f, 0x20, 0x40, 0x4b, 0xbb, 0xf0, 0x4f, 0x20, 0x40, 0x0, 0xf6, 0x40, 0x1f, 0x1b, 0x9f, 0x20, 0xc2, 0xf1, 0xc, 0x83, 0x30, 0x33, 0xa0, 0x44, 0x40, 0x44, 0x42, 0xf2, 0x2, 0xf1, 0xc, 0x8f, 0x13, 0xa0, 0x1f, 0x1b, 0x9f, 0x20, 0xc2, 0xf1, 0xc, 0x8f, 0x13, 0xa0, 0x1b, 0xb0, 0xbb, 0x92, 0xf1, 0xc, 0xf3, 0x62, 0x0, 0x6, 0xc, 0xf1, 0x40, 0x44, 0xf1, 0x4, 0x4f, 0x10, 0x44, 0xf1, 0x34, 0x1b, 0xb0, 0xbb, 0x92, 0xf1, 0xc, 0x2f, 0x10, 0xc8, 0xf1, 0x3a, 0x2f, 0x10, 0x42, 0xf1, 0x4, 0x2f, 0x20, 0x4f, 0x10, 0x40, 0xf0, 0x46, 0xbf, 0x4, 0x6, 0x4, 0xf0, 0x5, 0xf, 0x14, 0x63, 0x40, 0x44, 0x40, 0xf0, 0x4f, 0x10, 0x42, 0xf1, 0xc, 0x44, 0x40, 0x44, 0x40, 0x1f, 0x1b, 0x92, 0xf2, 0x2, 0xf1, 0xc, 0x44, 0x40, 0x44, 0x40, 0x1f, 0x1b, 0x9f, 0x30, 0x2f, 0x10, 0xc8, 0xf1, 0x3a, 0x20, 0x0, 0x60, 0xcf, 0x0, 0x60, 0xcf, 0x16, 0xc, 0x8f, 0x3, 0x4, 0xf3, 0x62, 0xf1, 0xc, 0x2f, 0x10, 0xc8, 0x33, 0x3, 0x3a, 0x1f, 0x1b, 0x42, 0xf2, 0x2, 0xf1, 0x4, 0x83, 0x30, 0x33, 0x40, 0x1f, 0x10, 0x4f, 0x20, 0xc2, 0xf1, 0xc, 0x8f, 0x13, 0xa0, 0xf8, 0x40, 0x44, 0x4f, 0x0, 0x44, 0xf1, 0x4, 0x44, 0x40, 0x44, 0x4f, 0x20, 0xc4, 0xf1, 0xc, 0x4f, 0x13, 0xa0, 0x1b, 0xb0, 0xbb, 0x92, 0xf1, 0xc, 0x2f, 0x10, 0xc8, 0x33, 0x3, 0x3a, 0x1f, 0x1b, 0x92, 0xf1, 0xc, 0x2f, 0x10, 0xc8, 0x33, 0x3, 0x3a, 0x1f, 0xb, 0x4, 0x2f, 0x10, 0x42, 0xf2, 0x8, 0xf1, 0x3a, 0x44, 0x40, 0xf2, 0x40, 0x44, 0x4f, 0x20, 0xc8, 0xf1, 0x3a, 0x1b, 0xb0, 0xbb, 0x92, 0xf1, 0xc, 0x2f, 0x10, 0xc4, 0x4, 0x44, 0x4, 0x4f, 0x1b, 0x42, 0xf2, 0x2, 0xf1, 0x4, 0x4f, 0x13, 0x40, 0x4f, 0x10, 0x40, 0x6, 0x66, 0xc, 0x40, 0x66, 0x60, 0xc4, 0xf1, 0xc, 0x44, 0xf1, 0x64, 0x4f, 0x0, 0x64, 0xf1, 0x6, 0x40, 0xf1, 0x40, 0x1b, 0xb0, 0xbb, 0xb2, 0xf2, 0x2, 0xf2, 0x8, 0xf1, 0x3a, 0xf2, 0xb9, 0xf2, 0xc, 0xf2, 0xc, 0x8f, 0x10, 0xc0, 0x1f, 0x1b, 0x92, 0xf1, 0xc, 0x2f, 0x20, 0x8f, 0x13, 0xa0, 0x1b, 0xb6, 0xbb, 0x42, 0x0, 0x5f, 0x20, 0x50, 0xc, 0x83, 0x36, 0x33, 0x40, 0x40, 0x44, 0x40, 0x4f, 0x30, 0x4f, 0x10, 0x44, 0x4, 0x4, 0x4, 0xf3, 0x4f, 0x20, 0xc8, 0xf1, 0xc, 0xf3, 0x40, 0x4f, 0x10, 0xc2, 0x4, 0x44, 0xc, 0x20, 0x40, 0x40, 0xc8, 0xf1, 0xc, 0x44, 0x4b, 0xf2, 0x40, 0xf2, 0x40, 0xf2, 0x40, 0x44, 0x40, 0x1f, 0x1b, 0x92, 0xf2, 0x2, 0xf2, 0x8, 0xf1, 0x3a, 0x1f, 0x10, 0xcf, 0x20, 0xcf, 0x30, 0x20, 0x0, 0x66, 0x60, 0xfa, 0x4f, 0x30, 0xf3, 0x40, 0x4b, 0xb6, 0xbb, 0x42, 0x0, 0x60, 0x4, 0x0, 0x6, 0x0, 0xf4, 0x40, 0x40, 0x40, 0x40, 0x42, 0xf1, 0xc, 0x2f, 0x10, 0xcf, 0x34, 0x1f, 0x1b, 0x42, 0xf1, 0x4, 0x2f, 0x20, 0x44, 0xf0, 0x34, 0x4f, 0x10, 0xc4, 0x40, 0x40, 0x4c, 0x40, 0x4, 0x0, 0xc4, 0x8f, 0x0, 0x40, 0x1f, 0x1b, 0x92, 0xf1, 0xc, 0x2f, 0x10, 0xc8, 0x33, 0x3, 0x3a, 0x1b, 0x6f, 0xb, 0x20, 0x6f, 0x0, 0x20, 0x6f, 0x0, 0x83, 0x60, 0x33, 0x30, 0xf0, 0x6, 0x66, 0xf0, 0x6, 0xc, 0xf0, 0x5, 0xc, 0xf0, 0x35, 0x3a, 0x44, 0xf0, 0xb4, 0x4f, 0x20, 0x4f, 0x10, 0xf4, 0x40, 0xf4, 0x4f, 0x20, 0x4f, 0x10, 0xf0, 0x40, 0x44, 0x40, 0x1f, 0x1b, 0x9f, 0x30, 0x4f, 0x20, 0x4f, 0x13, 0x40, 0x44, 0xf0, 0xb4, 0xf2, 0x4, 0x4, 0xf1, 0xf, 0x34, 0x4b, 0xf0, 0x4, 0x4f, 0x80, 0x44, 0xf1, 0x34, 0x4f, 0x1b, 0x4f, 0x20, 0x44, 0xf0, 0x4, 0x44, 0xf0, 0x34, 0x40
};

const uint8_t PROGMEM dungeons_room0_0[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, POT),
    xy(16, 40),

    // entity 1
    miscAndEntityType(0, POT),
    xy(24, 16),

    // entity 2
    miscAndEntityType(0, LOCK),
    xy(48, 48),
};



const uint8_t PROGMEM dungeons_room0_1[] = {
    6, // number of entities

    // entity 0
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(48, 0),

    // entity 1
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(48, 60),

    // entity 2
    miscAndEntityType(SLAM_SHUT, SNAKE),
    xy(80, 36),

    // entity 3
    miscAndEntityType(SLAM_SHUT, SNAKE),
    xy(16, 20),

    // entity 4
    miscAndEntityType(SLAM_SHUT, SNAKE),
    xy(32, 36),

    // entity 5
    miscAndEntityType(SLAM_SHUT, SNAKE),
    xy(64, 44),
};



const uint8_t PROGMEM dungeons_room0_2[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, BOSS_LOCK),
    xy(96, 20),
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
    miscAndEntityType(OPEN_CHESTS_IN_RIGHT_ORDER, SUNKEN_BRIDGE),
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
    miscAndEntityType(SLAM_SHUT, BAT),
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
    1, // number of entities

    // entity 0
    miscAndEntityType(0, POT),
    xy(16, 36),
};



const uint8_t PROGMEM dungeons_room0_6[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(KEY, POT),
    xy(16, 28),

    // entity 1
    miscAndEntityType(0, SNAKE),
    xy(48, 52),

    // entity 2
    miscAndEntityType(0, SNAKE),
    xy(32, 8),
};



const uint8_t PROGMEM dungeons_room0_7[] = {
    5, // number of entities

    // entity 0
    miscAndEntityType(0, TELEPORTER),
    xy(48, 60),

    // entity 1
    miscAndEntityType(KEY, CHEST),
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
    7, // number of entities

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

    // entity 4
    miscAndEntityType(0, BAT),
    xy(32, 28),

    // entity 5
    miscAndEntityType(0, BAT),
    xy(88, 8),

    // entity 6
    miscAndEntityType(0, BAT),
    xy(56, 12),
};



const uint8_t PROGMEM dungeons_room1_1[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(HEART, CHEST),
    xy(16, 16),

    // entity 1
    miscAndEntityType(0, SUNKEN_BRIDGE),
    xy(48, 16),

    // entity 2
    miscAndEntityType(0, SWITCH),
    xy(32, 32),
};



const uint8_t PROGMEM dungeons_room1_2[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(SLAM_SHUT, NEMESIS),
    xy(80, 20),

    // entity 1
    miscAndEntityType(VERTICAL, TRIGGER_DOOR),
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
    5, // number of entities

    // entity 0
    miscAndEntityType(2, TELEPORTER),
    xy(48, 60),

    // entity 1
    miscAndEntityType(LAST_ENEMY_HAS_HEART_CONTAINER, SKELETON),
    xy(16, 8),

    // entity 2
    miscAndEntityType(LAST_ENEMY_HAS_HEART_CONTAINER, SKELETON),
    xy(32, 8),

    // entity 3
    miscAndEntityType(LAST_ENEMY_HAS_HEART_CONTAINER, SKELETON),
    xy(64, 8),

    // entity 4
    miscAndEntityType(LAST_ENEMY_HAS_HEART_CONTAINER, SKELETON),
    xy(80, 8),
};



const uint8_t PROGMEM dungeons_room1_5[] = {
    5, // number of entities

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
    miscAndEntityType(LAST_ENEMY_HAS_KEY, BAT),
    xy(96, 36),

    // entity 4
    miscAndEntityType(0, BAT),
    xy(0, 60),
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
    xy(96, 36),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(96, 44),

    // entity 2
    miscAndEntityType(KEY, CHEST),
    xy(80, 24),
};



const uint8_t PROGMEM dungeons_room2_0[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(0, 32),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(32, 20),

    // entity 2
    miscAndEntityType(0, BLOB),
    xy(48, 20),

    // entity 3
    miscAndEntityType(0, BLOB),
    xy(64, 20),
};



const uint8_t PROGMEM dungeons_room2_1[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(0, TRIGGER_DOOR),
    xy(48, 60),

    // entity 1
    miscAndEntityType(SLAM_SHUT, GIANT_BAT),
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
    xy(32, 8),
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
    3, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(96, 32),

    // entity 1
    miscAndEntityType(0, SNAKE),
    xy(16, 12),

    // entity 2
    miscAndEntityType(0, SNAKE),
    xy(40, 52),
};



const uint8_t PROGMEM dungeons_room2_5[] = {
    7, // number of entities

    // entity 0
    miscAndEntityType(LAST_ENEMY_HAS_BOSS_KEY, SKELETON),
    xy(16, 8),

    // entity 1
    miscAndEntityType(LAST_ENEMY_HAS_BOSS_KEY, SKELETON),
    xy(16, 52),

    // entity 2
    miscAndEntityType(LAST_ENEMY_HAS_BOSS_KEY, SNAKE),
    xy(48, 12),

    // entity 3
    miscAndEntityType(LAST_ENEMY_HAS_BOSS_KEY, BLOB),
    xy(56, 52),

    // entity 4
    miscAndEntityType(LAST_ENEMY_HAS_BOSS_KEY, SNAKE),
    xy(48, 24),

    // entity 5
    miscAndEntityType(LAST_ENEMY_HAS_BOSS_KEY, SNAKE),
    xy(32, 40),

    // entity 6
    miscAndEntityType(LAST_ENEMY_HAS_BOSS_KEY, SKELETON),
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
    miscAndEntityType(LAST_ENEMY_HAS_BOSS_KEY, SNAKE),
    xy(48, 32),

    // entity 1
    miscAndEntityType(0, SNAKE),
    xy(48, 44),

    // entity 2
    miscAndEntityType(0, SNAKE),
    xy(32, 36),
};



const uint8_t PROGMEM dungeons_room3_0[] = {
    6, // number of entities

    // entity 0
    miscAndEntityType(LAST_TORCH_OPENS_DOORS, SPIKE),
    xy(32, 8),

    // entity 1
    miscAndEntityType(LAST_TORCH_OPENS_DOORS, SPIKE),
    xy(32, 48),

    // entity 2
    miscAndEntityType(LAST_TORCH_OPENS_DOORS, SPIKE),
    xy(40, 8),

    // entity 3
    miscAndEntityType(LAST_TORCH_OPENS_DOORS, SPIKE),
    xy(40, 48),

    // entity 4
    miscAndEntityType(LAST_TORCH_OPENS_DOORS, SPIKE),
    xy(56, 8),

    // entity 5
    miscAndEntityType(LAST_TORCH_OPENS_DOORS, SPIKE),
    xy(56, 48),
};



const uint8_t PROGMEM dungeons_room3_1[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(SLAM_SHUT, GIANT_BAT),
    xy(16, 20),
};



const uint8_t PROGMEM dungeons_room3_2[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(LAST_ENEMY_HAS_KEY, BAT),
    xy(16, 36),

    // entity 1
    miscAndEntityType(LAST_ENEMY_HAS_KEY, SKELETON),
    xy(48, 20),

    // entity 2
    miscAndEntityType(LAST_ENEMY_HAS_KEY, SKELETON),
    xy(32, 52),

    // entity 3
    miscAndEntityType(LAST_ENEMY_HAS_KEY, BLOB),
    xy(40, 28),
};



const uint8_t PROGMEM dungeons_room3_3[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(LAST_ENEMY_HAS_BOSS_KEY, SKELETON),
    xy(16, 20),

    // entity 1
    miscAndEntityType(0, SNAKE),
    xy(16, 32),

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
    miscAndEntityType(VERTICAL, TRIGGER_DOOR),
    xy(0, 32),

    // entity 1
    miscAndEntityType(VERTICAL, TRIGGER_DOOR),
    xy(104, 16),

    // entity 2
    miscAndEntityType(SLAM_SHUT, BLOB_MOTHER),
    xy(16, 36),
};



const uint8_t PROGMEM dungeons_room3_6[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(BOOMERANG, CHEST),
    xy(32, 24),

    // entity 1
    miscAndEntityType(VERTICAL, TRIGGER_DOOR),
    xy(0, 32),

    // entity 2
    miscAndEntityType(0, SWITCH),
    xy(80, 16),
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
    3, // number of entities

    // entity 0
    miscAndEntityType(VERTICAL, TRIGGER_DOOR),
    xy(32, 32),

    // entity 1
    miscAndEntityType(LAST_TORCH_OPENS_DOORS, TORCH),
    xy(16, 24),

    // entity 2
    miscAndEntityType(0, TORCH),
    xy(48, 52),
};



const uint8_t PROGMEM dungeons_room4_1[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(KEY, CHEST),
    xy(48, 12),
};



const uint8_t PROGMEM dungeons_room4_2[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(3, TELEPORTER),
    xy(48, 0),

    // entity 1
    miscAndEntityType(RING, CHEST),
    xy(80, 28),
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
    4, // number of entities

    // entity 0
    miscAndEntityType(0, SNAKE),
    xy(16, 28),

    // entity 1
    miscAndEntityType(0, SNAKE),
    xy(80, 28),

    // entity 2
    miscAndEntityType(0, SNAKE),
    xy(96, 36),

    // entity 3
    miscAndEntityType(0, SNAKE),
    xy(32, 32),
};



const uint8_t PROGMEM dungeons_room4_5[] = {
    5, // number of entities

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
    miscAndEntityType(0, LOCK),
    xy(16, 48),

    // entity 4
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
    miscAndEntityType(OPEN_CHESTS_IN_RIGHT_ORDER, SUNKEN_BRIDGE),
    xy(96, 44),

    // entity 4
    miscAndEntityType(0, CHEST),
    xy(32, 28),
};



const uint8_t PROGMEM dungeons_room4_7[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(0, SWITCH),
    xy(64, 44),

    // entity 1
    miscAndEntityType(THREE_SWITCHES_ONE_BOOMERANG, SWITCH),
    xy(64, 16),

    // entity 2
    miscAndEntityType(0, SWITCH),
    xy(32, 16),

    // entity 3
    miscAndEntityType(0, SWITCH),
    xy(48, 44),
};



const uint8_t PROGMEM dungeons_room5_0[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, TORCH),
    xy(24, 20),

    // entity 1
    miscAndEntityType(0, SNAKE),
    xy(32, 12),

    // entity 2
    miscAndEntityType(0, SNAKE),
    xy(8, 28),
};



const uint8_t PROGMEM dungeons_room5_1[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, SNAKE),
    xy(40, 24),

    // entity 1
    miscAndEntityType(0, SNAKE),
    xy(32, 36),
};



const uint8_t PROGMEM dungeons_room5_2[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(96, 32),

    // entity 1
    miscAndEntityType(0, SKELETON),
    xy(48, 36),

    // entity 2
    miscAndEntityType(0, SKELETON),
    xy(40, 36),

    // entity 3
    miscAndEntityType(0, SKELETON),
    xy(16, 40),
};



const uint8_t PROGMEM dungeons_room5_3[] = {
    5, // number of entities

    // entity 0
    miscAndEntityType(VERTICAL, TRIGGER_DOOR),
    xy(0, 16),

    // entity 1
    miscAndEntityType(0, TORCH),
    xy(24, 48),

    // entity 2
    miscAndEntityType(LAST_TORCH_OPENS_DOORS, TORCH),
    xy(80, 48),

    // entity 3
    miscAndEntityType(KEY, POT),
    xy(80, 20),

    // entity 4
    miscAndEntityType(0, SKELETON),
    xy(96, 48),
};



const uint8_t PROGMEM dungeons_room5_4[] = {
    5, // number of entities

    // entity 0
    miscAndEntityType(BOMB, CHEST),
    xy(16, 28),

    // entity 1
    miscAndEntityType(0, SPIKE),
    xy(40, 8),

    // entity 2
    miscAndEntityType(0, SPIKE),
    xy(40, 48),

    // entity 3
    miscAndEntityType(0, SPIKE),
    xy(56, 8),

    // entity 4
    miscAndEntityType(0, SPIKE),
    xy(56, 48),
};



const uint8_t PROGMEM dungeons_room5_5[] = {
    6, // number of entities

    // entity 0
    miscAndEntityType(0, SWITCH),
    xy(88, 16),

    // entity 1
    miscAndEntityType(0, SWITCH),
    xy(88, 36),

    // entity 2
    miscAndEntityType(0, SWITCH),
    xy(56, 36),

    // entity 3
    miscAndEntityType(THREE_SWITCHES_ONE_BOOMERANG, HEART),
    xy(96, 44),

    // entity 4
    miscAndEntityType(0, SNAKE),
    xy(80, 44),

    // entity 5
    miscAndEntityType(0, SNAKE),
    xy(40, 44),
};



const uint8_t PROGMEM dungeons_room5_6[] = {
    5, // number of entities

    // entity 0
    miscAndEntityType(KEY, POT),
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

    // entity 4
    miscAndEntityType(0, SKELETON),
    xy(48, 48),
};



const uint8_t PROGMEM dungeons_room5_7[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, POT),
    xy(40, 8),

    // entity 1
    miscAndEntityType(0, BLOB),
    xy(48, 36),

    // entity 2
    miscAndEntityType(0, LOCK),
    xy(96, 32),
};



const uint8_t PROGMEM dungeons_room6_0[] = {
    5, // number of entities

    // entity 0
    miscAndEntityType(7, TELEPORTER),
    xy(48, 60),

    // entity 1
    miscAndEntityType(0, TORCH),
    xy(80, 36),

    // entity 2
    miscAndEntityType(VERTICAL, TRIGGER_DOOR),
    xy(0, 32),

    // entity 3
    miscAndEntityType(VERTICAL, TRIGGER_DOOR),
    xy(104, 16),

    // entity 4
    miscAndEntityType(0, SWITCH),
    xy(24, 44),
};



const uint8_t PROGMEM dungeons_room6_1[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(HEART, CHEST),
    xy(32, 20),
};



const uint8_t PROGMEM dungeons_room6_2[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(64, 32),

    // entity 1
    miscAndEntityType(KEY, CHEST),
    xy(80, 20),
};



const uint8_t PROGMEM dungeons_room6_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(96, 16),
};



const uint8_t PROGMEM dungeons_room6_4[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(0, 16),

    // entity 1
    miscAndEntityType(0, BAT),
    xy(56, 32),

    // entity 2
    miscAndEntityType(0, BAT),
    xy(64, 40),

    // entity 3
    miscAndEntityType(0, BAT),
    xy(48, 44),
};



const uint8_t PROGMEM dungeons_room6_5[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(LAST_ENEMY_HAS_KEY, SNAKE),
    xy(16, 32),

    // entity 1
    miscAndEntityType(0, SNAKE),
    xy(80, 20),

    // entity 2
    miscAndEntityType(0, SNAKE),
    xy(96, 32),
};



const uint8_t PROGMEM dungeons_room6_6[] = {
    4, // number of entities

    // entity 0
    miscAndEntityType(0, SECRET_WALL),
    xy(0, 32),

    // entity 1
    miscAndEntityType(0, BAT),
    xy(56, 24),

    // entity 2
    miscAndEntityType(0, BAT),
    xy(24, 24),

    // entity 3
    miscAndEntityType(0, BAT),
    xy(88, 24),
};



const uint8_t PROGMEM dungeons_room6_7[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(96, 16),
};



const uint8_t PROGMEM dungeons_room7_0[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(0, TORCH),
    xy(24, 12),

    // entity 1
    miscAndEntityType(KEY, CHEST),
    xy(64, 32),
};



const uint8_t PROGMEM dungeons_room7_1[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(SLAM_SHUT, BLOB_MOTHER),
    xy(48, 20),

    // entity 1
    miscAndEntityType(VERTICAL, TRIGGER_DOOR),
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
    miscAndEntityType(BOMB, POT),
    xy(24, 28),

    // entity 2
    miscAndEntityType(BOMB, POT),
    xy(80, 28),
};



const uint8_t PROGMEM dungeons_room7_3[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(48, 0),

    // entity 1
    miscAndEntityType(0, SNAKE),
    xy(80, 44),

    // entity 2
    miscAndEntityType(0, SNAKE),
    xy(16, 48),
};



const uint8_t PROGMEM dungeons_room7_4[] = {
    2, // number of entities

    // entity 0
    miscAndEntityType(4, TELEPORTER),
    xy(16, 60),

    // entity 1
    miscAndEntityType(HEART, CHEST),
    xy(80, 24),
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
    3, // number of entities

    // entity 0
    miscAndEntityType(0, BOMB),
    xy(32, 16),

    // entity 1
    miscAndEntityType(0, HEART),
    xy(72, 16),

    // entity 2
    miscAndEntityType(6, TELEPORTER),
    xy(48, 60),
};



const uint8_t PROGMEM dungeons_room7_7[] = {
    3, // number of entities

    // entity 0
    miscAndEntityType(0, KEY),
    xy(80, 20),

    // entity 1
    miscAndEntityType(0, SPIKE),
    xy(48, 48),

    // entity 2
    miscAndEntityType(0, SPIKE),
    xy(48, 8),
};

const uint8_t PROGMEM dungeons_teleporters[] = {
    // dest x, dest y (in rooms)
    4, 5,
    6, 0,
    0, 2,
    0, 0,
    3, 3,
    2, 5,
    6, 1,
    4, 3,
};





const uint8_t * const PROGMEM dungeons_row0[8] = {
    dungeons_room0_0,
    dungeons_room1_0,
    dungeons_room2_0,
    dungeons_room3_0,
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
    dungeons_room5_1,
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