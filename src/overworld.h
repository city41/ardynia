#ifndef overworld_h
#define overworld_h

#include "emptyRoom.h"


const uint8_t PROGMEM overworld_map[482] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    226, 1, 7, 7,
    // room indices (16 bit, little endian), 98 bytes
    0, 0, 11, 0, 20, 0, 25, 0, 32, 0, 35, 0, 39, 0, 47, 0, 57, 0, 63, 0, 68, 0, 76, 0, 87, 0, 95, 0, 100, 0, 106, 0, 116, 0, 119, 0, 125, 0, 132, 0, 138, 0, 148, 0, 155, 0, 161, 0, 166, 0, 173, 0, 181, 0, 189, 0, 200, 0, 208, 0, 212, 0, 222, 0, 229, 0, 240, 0, 248, 0, 4, 1, 13, 1, 18, 1, 24, 1, 34, 1, 43, 1, 50, 1, 61, 1, 70, 1, 79, 1, 87, 1, 96, 1, 105, 1, 114, 1,
    // compressed room data, 380 bytes
    31, 109, 32, 68, 64, 2, 4, 4, 0, 47, 96, 214, 245, 208, 111, 96, 111, 96, 111, 80, 247, 223, 240, 246, 0, 221, 245, 64, 15, 84, 254, 0, 254, 79, 224, 254, 79, 208, 96, 251, 72, 121, 246, 12, 244, 100, 68, 47, 96, 102, 95, 70, 47, 96, 68, 245, 0, 6, 245, 15, 118, 254, 0, 247, 15, 118, 254, 0, 247, 15, 118, 245, 6, 111, 80, 102, 247, 6, 102, 244, 6, 102, 244, 6, 102, 244, 0, 246, 6, 246, 6, 246, 6, 246, 4, 251, 111, 228, 0, 64, 68, 245, 15, 244, 246, 64, 247, 4, 246, 4, 102, 101, 100, 79, 80, 64, 254, 15, 228, 245, 6, 111, 112, 254, 64, 102, 111, 176, 79, 96, 79, 96, 246, 4, 255, 15, 80, 64, 244, 64, 4, 246, 14, 246, 14, 68, 15, 68, 247, 66, 246, 2, 246, 15, 116, 79, 80, 79, 224, 79, 96, 247, 79, 240, 15, 84, 247, 79, 80, 68, 246, 15, 132, 79, 96, 79, 96, 79, 96, 79, 96, 246, 4, 246, 4, 246, 4, 15, 100, 68, 15, 84, 245, 14, 64, 4, 15, 100, 4, 64, 247, 66, 246, 2, 246, 2, 246, 0, 79, 240, 252, 0, 0, 245, 64, 15, 84, 0, 245, 64, 15, 84, 248, 79, 96, 79, 96, 247, 64, 79, 128, 244, 64, 0, 244, 64, 68, 64, 4, 64, 15, 100, 4, 246, 4, 245, 15, 116, 244, 64, 68, 0, 4, 4, 79, 80, 68, 64, 15, 68, 47, 96, 47, 96, 47, 96, 47, 80, 64, 255, 15, 96, 79, 96, 0, 245, 79, 240, 245, 4, 247, 79, 80, 68, 245, 4, 68, 244, 4, 64, 68, 64, 4, 68, 246, 4, 246, 15, 116, 247, 79, 224, 64, 0, 68, 64, 64, 15, 84, 0, 245, 64, 15, 84, 0, 244, 64, 47, 80, 79, 86, 86, 47, 80, 79, 118, 79, 96, 102, 245, 4, 111, 80, 247, 96, 246, 4, 246, 4, 246, 4, 247, 96, 79, 64, 68, 79, 96, 79, 96, 247, 96, 68, 72, 121, 79, 96, 79, 96, 79, 118, 64, 0, 244, 79, 96, 79, 96, 247, 96, 64, 15, 68, 0, 15, 68, 245, 4, 79, 118
};

const uint8_t PROGMEM overworld_room0_0[] = {
    2, // number of entities

    // entity 0, SECRET_WALL
    0x10,
    6 << 4 | 8, // x/8 | y/4

    // entity 1, TELEPORTER
    0x6c,
    6 << 4 | 8, // x/8 | y/4
};



const uint8_t PROGMEM overworld_room0_4[] = {
    1, // number of entities

    // entity 0, BLOB
    0x7,
    3 << 4 | 7, // x/8 | y/4
};



const uint8_t PROGMEM overworld_room1_2[] = {
    2, // number of entities

    // entity 0, TRIGGER_DOOR
    0x11,
    8 << 4 | 11, // x/8 | y/4

    // entity 1, SWITCH
    0x12,
    4 << 4 | 5, // x/8 | y/4
};



const uint8_t PROGMEM overworld_room1_4[] = {
    1, // number of entities

    // entity 0, CHEST
    0x26,
    12 << 4 | 7, // x/8 | y/4
};



const uint8_t PROGMEM overworld_room2_2[] = {
    1, // number of entities

    // entity 0, CHEST
    0x46,
    3 << 4 | 4, // x/8 | y/4
};



const uint8_t PROGMEM overworld_room4_6[] = {
    2, // number of entities

    // entity 0, TELEPORTER
    0x2c,
    4 << 4 | 1, // x/8 | y/4

    // entity 1, TELEPORTER
    0x4c,
    8 << 4 | 1, // x/8 | y/4
};



const uint8_t PROGMEM overworld_room6_0[] = {
    1, // number of entities

    // entity 0, TELEPORTER
    0xc,
    10 << 4 | 6, // x/8 | y/4
};



const uint8_t PROGMEM overworld_room6_3[] = {
    1, // number of entities

    // entity 0, SECRET_WALL
    0x10,
    8 << 4 | 12, // x/8 | y/4
};

const uint8_t PROGMEM overworld_teleporters[] = {
    // dest x, dest y (in rooms)
    1, 2,
    8, 5,
    0, 5,
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
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM overworld_row6[7] = {
    empty_room,
    empty_room,
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