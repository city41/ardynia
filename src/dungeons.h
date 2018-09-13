#ifndef dungeons_h
#define dungeons_h

#include "emptyRoom.h"


const uint8_t PROGMEM dungeons_map[602] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    90, 2, 10, 6,
    // room indices (16 bit, little endian), 120 bytes
    0, 0, 10, 0, 20, 0, 28, 0, 33, 0, 38, 0, 43, 0, 48, 0, 53, 0, 61, 0, 71, 0, 82, 0, 90, 0, 95, 0, 100, 0, 105, 0, 113, 0, 121, 0, 126, 0, 129, 0, 137, 0, 149, 0, 160, 0, 168, 0, 173, 0, 182, 0, 192, 0, 202, 0, 212, 0, 220, 0, 228, 0, 239, 0, 244, 0, 252, 0, 6, 1, 17, 1, 25, 1, 30, 1, 38, 1, 48, 1, 58, 1, 68, 1, 77, 1, 85, 1, 93, 1, 98, 1, 106, 1, 114, 1, 119, 1, 129, 1, 139, 1, 148, 1, 155, 1, 164, 1, 174, 1, 182, 1, 187, 1, 195, 1, 204, 1, 213, 1,
    // compressed room data, 478 bytes
    31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 31, 109, 47, 96, 47, 96, 175, 99, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 247, 223, 240, 246, 0, 247, 223, 240, 246, 0, 246, 219, 246, 14, 246, 14, 246, 14, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 31, 93, 178, 245, 14, 47, 80, 234, 51, 3, 60, 47, 96, 47, 96, 47, 96, 47, 96, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 246, 219, 246, 14, 246, 14, 246, 14, 47, 96, 47, 96, 47, 96, 47, 96, 255, 15, 96, 247, 48, 255, 15, 208, 246, 219, 246, 14, 246, 14, 246, 14, 29, 208, 221, 178, 245, 14, 47, 80, 234, 51, 3, 60, 47, 80, 226, 245, 14, 47, 80, 233, 67, 3, 72, 31, 109, 47, 96, 47, 96, 47, 96, 247, 223, 224, 247, 48, 246, 219, 246, 14, 246, 14, 48, 244, 60, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 47, 96, 47, 96, 47, 96, 47, 96, 246, 14, 246, 14, 246, 14, 246, 60, 29, 208, 221, 223, 70, 85, 98, 246, 10, 246, 48, 247, 223, 118, 254, 0, 246, 14, 247, 111, 96, 239, 99, 192, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 16, 244, 219, 47, 80, 226, 245, 14, 175, 83, 192, 47, 96, 47, 96, 47, 96, 47, 96, 247, 223, 224, 247, 48, 246, 14, 246, 14, 246, 14, 246, 60, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 47, 96, 47, 96, 47, 96, 79, 80, 48, 246, 219, 246, 14, 246, 14, 246, 60, 47, 96, 47, 96, 47, 96, 175, 99, 247, 223, 240, 246, 0, 246, 14, 246, 14, 246, 14, 246, 14, 31, 109, 47, 96, 47, 96, 175, 99, 247, 223, 240, 245, 4, 246, 14, 246, 14, 246, 14, 64, 68, 64, 64, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 247, 66, 246, 2, 246, 10, 51, 3, 51, 79, 80, 79, 208, 79, 99, 64, 247, 79, 112, 74, 12, 245, 67, 244, 64, 31, 93, 191, 96, 226, 245, 14, 175, 83, 192, 47, 96, 47, 96, 47, 96, 175, 99, 255, 15, 96, 247, 48, 246, 219, 246, 14, 246, 14, 246, 60, 47, 80, 66, 246, 2, 246, 10, 246, 48, 144, 132, 144, 143, 224, 51, 48, 51, 48, 79, 93, 191, 96, 239, 96, 239, 99, 192
};

const uint8_t PROGMEM dungeons_room0_1[] = {
    1, // number of entities

    // entity 0, CHEST
    0x85,
    5 << 4 | 6, // x/8 | y/4
};



const uint8_t PROGMEM dungeons_room0_2[] = {
    3, // number of entities

    // entity 0, BLOB_MOTHER
    0xb,
    5 << 4 | 4, // x/8 | y/4

    // entity 1, TRIGGER_DOOR
    0x12,
    6 << 4 | 14, // x/8 | y/4

    // entity 2, TRIGGER_DOOR
    0x12,
    6 << 4 | 0, // x/8 | y/4
};



const uint8_t PROGMEM dungeons_room0_3[] = {
    1, // number of entities

    // entity 0, LOCK
    0xe,
    6 << 4 | 1, // x/8 | y/4
};



const uint8_t PROGMEM dungeons_room0_5[] = {
    1, // number of entities

    // entity 0, TELEPORTER
    0xd,
    6 << 4 | 13, // x/8 | y/4
};



const uint8_t PROGMEM dungeons_room1_2[] = {
    1, // number of entities

    // entity 0, TELEPORTER
    0x2d,
    6 << 4 | 14, // x/8 | y/4
};



const uint8_t PROGMEM dungeons_room2_4[] = {
    1, // number of entities

    // entity 0, CHEST
    0x65,
    8 << 4 | 5, // x/8 | y/4
};



const uint8_t PROGMEM dungeons_room2_5[] = {
    1, // number of entities

    // entity 0, LOCK
    0xe,
    12 << 4 | 5, // x/8 | y/4
};



const uint8_t PROGMEM dungeons_room3_5[] = {
    1, // number of entities

    // entity 0, CHEST
    0x25,
    10 << 4 | 11, // x/8 | y/4
};



const uint8_t PROGMEM dungeons_room4_2[] = {
    5, // number of entities

    // entity 0, TRIGGER_DOOR
    0x12,
    2 << 4 | 14, // x/8 | y/4

    // entity 1, SKELETON
    0xa,
    10 << 4 | 6, // x/8 | y/4

    // entity 2, SKELETON
    0xa,
    5 << 4 | 9, // x/8 | y/4

    // entity 3, BAT
    0x9,
    9 << 4 | 11, // x/8 | y/4

    // entity 4, BAT
    0x9,
    11 << 4 | 10, // x/8 | y/4
};



const uint8_t PROGMEM dungeons_room4_3[] = {
    1, // number of entities

    // entity 0, CHEST
    0x65,
    10 << 4 | 8, // x/8 | y/4
};



const uint8_t PROGMEM dungeons_room8_5[] = {
    1, // number of entities

    // entity 0, TELEPORTER
    0x4d,
    6 << 4 | 13, // x/8 | y/4
};

const uint8_t PROGMEM dungeons_teleporters[] = {
    // dest x, dest y (in rooms)
    4, 6,
    6, 0,
    4, 6,
};





const uint8_t * const PROGMEM dungeons_row0[10] = {
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM dungeons_row1[10] = {
    dungeons_room0_1,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM dungeons_row2[10] = {
    dungeons_room0_2,
    dungeons_room1_2,
    empty_room,
    empty_room,
    dungeons_room4_2,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM dungeons_row3[10] = {
    dungeons_room0_3,
    empty_room,
    empty_room,
    empty_room,
    dungeons_room4_3,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM dungeons_row4[10] = {
    empty_room,
    empty_room,
    dungeons_room2_4,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM dungeons_row5[10] = {
    dungeons_room0_5,
    empty_room,
    dungeons_room2_5,
    dungeons_room3_5,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    dungeons_room8_5,
    empty_room
};


const uint8_t * const* const PROGMEM dungeons_entities[6] = {
    dungeons_row0,
    dungeons_row1,
    dungeons_row2,
    dungeons_row3,
    dungeons_row4,
    dungeons_row5
};


#endif