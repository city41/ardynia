#ifndef dungeons_h
#define dungeons_h

#include "emptyRoom.h"


const uint8_t PROGMEM dungeons_map[604] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    92, 2, 10, 6,
    // room indices (16 bit, little endian), 120 bytes
    0, 0, 10, 0, 20, 0, 28, 0, 33, 0, 38, 0, 43, 0, 48, 0, 53, 0, 61, 0, 71, 0, 82, 0, 90, 0, 95, 0, 100, 0, 105, 0, 113, 0, 121, 0, 126, 0, 129, 0, 137, 0, 149, 0, 160, 0, 168, 0, 173, 0, 181, 0, 191, 0, 201, 0, 211, 0, 219, 0, 227, 0, 237, 0, 242, 0, 250, 0, 4, 1, 14, 1, 22, 1, 27, 1, 35, 1, 45, 1, 55, 1, 65, 1, 73, 1, 81, 1, 89, 1, 94, 1, 102, 1, 110, 1, 115, 1, 125, 1, 135, 1, 146, 1, 155, 1, 165, 1, 176, 1, 184, 1, 189, 1, 197, 1, 206, 1, 215, 1,
    // compressed room data, 480 bytes
    31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 31, 109, 47, 96, 47, 96, 175, 99, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 247, 223, 240, 246, 0, 247, 223, 240, 246, 0, 246, 219, 246, 14, 246, 14, 246, 14, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 31, 93, 178, 245, 14, 47, 80, 234, 51, 3, 60, 47, 96, 47, 96, 47, 96, 47, 96, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 246, 219, 246, 14, 246, 14, 246, 14, 47, 96, 47, 96, 47, 96, 47, 96, 255, 15, 96, 247, 48, 255, 15, 208, 246, 219, 246, 14, 246, 14, 246, 14, 29, 208, 221, 178, 245, 14, 47, 80, 234, 51, 3, 60, 47, 80, 226, 245, 14, 47, 80, 233, 67, 3, 72, 31, 109, 47, 96, 47, 96, 47, 96, 247, 223, 224, 247, 48, 246, 219, 246, 14, 246, 14, 246, 14, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 47, 96, 47, 96, 47, 96, 47, 96, 246, 14, 246, 14, 246, 14, 246, 60, 29, 208, 221, 210, 246, 2, 246, 10, 246, 48, 247, 223, 240, 246, 0, 246, 14, 246, 14, 246, 14, 246, 14, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 47, 96, 47, 96, 47, 96, 47, 96, 247, 223, 224, 247, 48, 246, 14, 246, 14, 246, 14, 246, 60, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 47, 96, 47, 96, 47, 96, 79, 96, 246, 14, 246, 14, 246, 14, 246, 14, 47, 96, 47, 96, 47, 96, 175, 99, 247, 223, 240, 246, 0, 246, 14, 246, 14, 246, 14, 246, 14, 31, 109, 47, 96, 47, 96, 175, 99, 247, 223, 240, 245, 4, 246, 14, 246, 14, 246, 14, 64, 68, 64, 64, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 68, 137, 68, 66, 246, 2, 246, 10, 51, 3, 51, 79, 176, 102, 245, 6, 79, 67, 102, 64, 247, 6, 102, 86, 102, 79, 80, 100, 245, 54, 246, 219, 102, 244, 14, 102, 244, 14, 102, 244, 60, 47, 96, 47, 96, 47, 96, 175, 99, 255, 15, 96, 247, 48, 246, 219, 246, 14, 246, 14, 246, 60, 47, 80, 66, 246, 2, 246, 10, 246, 48, 144, 132, 144, 143, 224, 51, 48, 51, 48, 79, 93, 191, 96, 239, 96, 239, 99, 192
};

const uint8_t PROGMEM dungeons_room0_1[] = {
    1, // number of entities

    // entity 0, CHEST
    0xa6,
    5 << 4 | 6, // x/8 | y/4
};



const uint8_t PROGMEM dungeons_room0_2[] = {
    3, // number of entities

    // entity 0, BLOB_MOTHER
    0xa,
    5 << 4 | 4, // x/8 | y/4

    // entity 1, TRIGGER_DOOR
    0x11,
    6 << 4 | 14, // x/8 | y/4

    // entity 2, TRIGGER_DOOR
    0x11,
    6 << 4 | 0, // x/8 | y/4
};



const uint8_t PROGMEM dungeons_room0_3[] = {
    1, // number of entities

    // entity 0, LOCK
    0xd,
    6 << 4 | 1, // x/8 | y/4
};



const uint8_t PROGMEM dungeons_room0_5[] = {
    1, // number of entities

    // entity 0, TELEPORTER
    0xc,
    6 << 4 | 13, // x/8 | y/4
};



const uint8_t PROGMEM dungeons_room1_2[] = {
    1, // number of entities

    // entity 0, TELEPORTER
    0x2c,
    6 << 4 | 14, // x/8 | y/4
};



const uint8_t PROGMEM dungeons_room1_5[] = {
    3, // number of entities

    // entity 0, BAT
    0x9,
    7 << 4 | 14, // x/8 | y/4

    // entity 1, BAT
    0x9,
    9 << 4 | 14, // x/8 | y/4

    // entity 2, BAT
    0x9,
    7 << 4 | 9, // x/8 | y/4
};



const uint8_t PROGMEM dungeons_room2_4[] = {
    1, // number of entities

    // entity 0, NEMESIS
    0xb,
    6 << 4 | 7, // x/8 | y/4
};



const uint8_t PROGMEM dungeons_room3_5[] = {
    1, // number of entities

    // entity 0, CHEST
    0x86,
    6 << 4 | 5, // x/8 | y/4
};



const uint8_t PROGMEM dungeons_room4_3[] = {
    1, // number of entities

    // entity 0, CHEST
    0x26,
    10 << 4 | 2, // x/8 | y/4
};



const uint8_t PROGMEM dungeons_room8_5[] = {
    1, // number of entities

    // entity 0, TELEPORTER
    0x4c,
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
    empty_room,
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
    dungeons_room1_5,
    empty_room,
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