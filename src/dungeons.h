#ifndef dungeons_h
#define dungeons_h

#include "emptyRoom.h"
#include "entityTypes.h"
#include "entityExpressions.h"


const uint8_t PROGMEM dungeons_map[651] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    139, 2, 8, 8,
    // room indices (16 bit, little endian), 128 bytes
    0, 0, 8, 0, 13, 0, 18, 0, 23, 0, 28, 0, 33, 0, 38, 0, 46, 0, 56, 0, 64, 0, 74, 0, 82, 0, 87, 0, 95, 0, 105, 0, 115, 0, 123, 0, 131, 0, 143, 0, 153, 0, 163, 0, 171, 0, 179, 0, 189, 0, 199, 0, 207, 0, 217, 0, 228, 0, 236, 0, 244, 0, 252, 0, 4, 1, 16, 1, 26, 1, 35, 1, 43, 1, 53, 1, 61, 1, 64, 1, 72, 1, 82, 1, 90, 1, 98, 1, 103, 1, 106, 1, 114, 1, 122, 1, 130, 1, 140, 1, 150, 1, 159, 1, 169, 1, 179, 1, 187, 1, 195, 1, 205, 1, 217, 1, 225, 1, 235, 1, 240, 1, 245, 1, 250, 1, 255, 1,
    // compressed room data, 519 bytes
    31, 109, 47, 96, 47, 96, 47, 96, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 247, 223, 240, 246, 0, 247, 223, 240, 246, 0, 247, 223, 240, 246, 0, 247, 223, 224, 247, 48, 246, 219, 246, 14, 246, 14, 246, 60, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 31, 109, 47, 96, 47, 96, 175, 99, 246, 219, 246, 14, 246, 14, 51, 48, 51, 192, 47, 96, 47, 96, 47, 96, 47, 96, 255, 15, 96, 247, 48, 246, 14, 246, 14, 246, 14, 246, 14, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 47, 96, 47, 96, 47, 96, 175, 99, 246, 219, 246, 14, 246, 14, 246, 60, 29, 208, 221, 178, 245, 14, 102, 101, 102, 98, 245, 14, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 47, 96, 47, 96, 47, 96, 47, 96, 246, 219, 246, 14, 246, 14, 246, 60, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 31, 109, 47, 96, 47, 96, 163, 48, 51, 48, 247, 223, 176, 102, 111, 67, 99, 48, 246, 14, 246, 14, 102, 101, 102, 111, 96, 64, 31, 93, 178, 245, 14, 47, 80, 234, 51, 3, 60, 31, 109, 47, 96, 47, 96, 47, 96, 246, 14, 246, 14, 246, 14, 246, 60, 31, 109, 47, 96, 47, 96, 47, 96, 246, 14, 246, 14, 246, 14, 246, 14, 29, 208, 221, 178, 245, 14, 47, 80, 234, 51, 3, 60, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 47, 80, 66, 245, 4, 47, 96, 175, 99, 250, 64, 68, 79, 96, 239, 99, 192, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 31, 109, 47, 96, 47, 96, 175, 99, 255, 15, 208, 246, 14, 246, 14, 246, 14, 246, 14, 29, 208, 221, 210, 246, 2, 246, 10, 246, 48, 246, 219, 246, 14, 246, 14, 246, 14, 31, 109, 47, 96, 47, 96, 175, 99, 247, 223, 224, 247, 48, 255, 15, 208, 246, 219, 246, 14, 246, 14, 246, 60, 47, 96, 47, 96, 47, 96, 47, 96, 246, 14, 246, 14, 246, 14, 246, 60, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 47, 80, 226, 245, 14, 47, 96, 47, 80, 224, 31, 93, 178, 245, 14, 247, 10, 245, 60, 31, 93, 178, 245, 14, 246, 14, 175, 83, 192, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 31, 109, 47, 96, 47, 96, 47, 96, 246, 14, 246, 14, 246, 14, 246, 14, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 29, 111, 77, 102, 111, 64, 47, 96, 163, 48, 51, 48, 246, 14, 246, 14, 246, 14, 246, 60, 31, 109, 47, 96, 47, 96, 163, 48, 51, 48, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 255, 15, 96, 247, 48, 255, 15, 96, 247, 48, 246, 219, 246, 14, 246, 14, 246, 60
};

const uint8_t PROGMEM dungeons_room0_3[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(3, CHEST),
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
    2, // number of entities

    // entity 0
    miscAndEntityType(0, TELEPORTER),
    xy(48, 52),

    // entity 1
    miscAndEntityType(0, KEY),
    xy(24, 8),
};



const uint8_t PROGMEM dungeons_room1_6[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, LOCK),
    xy(96, 36),
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

const uint8_t PROGMEM dungeons_teleporters[] = {
    // dest x, dest y (in rooms)
    4, 6,
    6, 0,
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
    empty_room,
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
    empty_room,
    empty_room,
    dungeons_room3_4,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM dungeons_row5[8] = {
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM dungeons_row6[8] = {
    empty_room,
    dungeons_room1_6,
    dungeons_room2_6,
    dungeons_room3_6,
    empty_room,
    empty_room,
    empty_room,
    empty_room
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