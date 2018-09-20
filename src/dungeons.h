#ifndef dungeons_h
#define dungeons_h

#include "emptyRoom.h"
#include "entityTypes.h"
#include "entityExpressions.h"


const uint8_t PROGMEM dungeons_map[613] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    101, 2, 8, 8,
    // room indices (16 bit, little endian), 128 bytes
    0, 0, 8, 0, 13, 0, 18, 0, 23, 0, 28, 0, 33, 0, 38, 0, 46, 0, 56, 0, 64, 0, 72, 0, 80, 0, 85, 0, 93, 0, 103, 0, 113, 0, 121, 0, 129, 0, 139, 0, 149, 0, 159, 0, 167, 0, 175, 0, 185, 0, 193, 0, 198, 0, 201, 0, 209, 0, 217, 0, 225, 0, 233, 0, 241, 0, 251, 0, 5, 1, 13, 1, 21, 1, 31, 1, 39, 1, 42, 1, 50, 1, 58, 1, 66, 1, 74, 1, 79, 1, 82, 1, 90, 1, 98, 1, 106, 1, 116, 1, 124, 1, 129, 1, 137, 1, 147, 1, 155, 1, 163, 1, 173, 1, 181, 1, 189, 1, 197, 1, 202, 1, 207, 1, 212, 1, 217, 1,
    // compressed room data, 481 bytes
    31, 109, 47, 96, 47, 96, 47, 96, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 247, 223, 240, 246, 0, 247, 223, 240, 246, 0, 247, 223, 240, 246, 0, 247, 223, 224, 247, 48, 246, 219, 246, 14, 246, 14, 246, 60, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 31, 109, 47, 96, 47, 96, 175, 99, 246, 219, 246, 14, 246, 14, 246, 14, 47, 96, 47, 96, 47, 96, 47, 96, 255, 15, 96, 247, 48, 246, 14, 246, 14, 246, 14, 246, 14, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 47, 96, 47, 96, 47, 96, 175, 99, 246, 219, 246, 14, 246, 14, 246, 60, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 47, 96, 47, 96, 47, 96, 47, 96, 246, 219, 246, 14, 246, 14, 246, 60, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 31, 109, 47, 96, 47, 96, 47, 96, 247, 223, 224, 247, 48, 255, 15, 208, 246, 219, 246, 14, 246, 14, 246, 14, 31, 109, 47, 96, 47, 96, 47, 96, 246, 14, 246, 14, 246, 14, 246, 60, 31, 109, 47, 96, 47, 96, 47, 96, 246, 14, 246, 14, 246, 14, 246, 14, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 47, 96, 47, 96, 47, 96, 175, 99, 246, 14, 246, 14, 246, 14, 246, 60, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 31, 109, 47, 96, 47, 96, 175, 99, 255, 15, 208, 246, 14, 246, 14, 246, 14, 246, 14, 47, 96, 47, 96, 47, 96, 175, 99, 246, 219, 246, 14, 246, 14, 246, 14, 31, 109, 47, 96, 47, 96, 175, 99, 247, 223, 224, 247, 48, 255, 15, 208, 246, 219, 246, 14, 246, 14, 246, 60, 47, 96, 47, 96, 47, 96, 47, 96, 246, 14, 246, 14, 246, 14, 246, 60, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 47, 96, 47, 96, 47, 96, 47, 96, 247, 223, 224, 247, 48, 246, 219, 246, 14, 246, 14, 246, 60, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 31, 109, 47, 96, 47, 96, 47, 96, 246, 14, 246, 14, 246, 14, 246, 14, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 31, 109, 47, 96, 47, 96, 175, 99, 246, 14, 246, 14, 246, 14, 246, 60, 31, 109, 47, 96, 47, 96, 175, 99, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 255, 15, 96, 247, 48, 255, 15, 96, 247, 48, 246, 219, 246, 14, 246, 14, 246, 60
};

const uint8_t PROGMEM dungeons_room0_7[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(0, TELEPORTER),
    xy(48, 52),
};



const uint8_t PROGMEM dungeons_room2_7[] = {
    1, // number of entities

    // entity 0
    miscAndEntityType(1, TELEPORTER),
    xy(48, 52),
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
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM dungeons_row3[8] = {
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room,
    empty_room
};


const uint8_t * const PROGMEM dungeons_row4[8] = {
    empty_room,
    empty_room,
    empty_room,
    empty_room,
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
    empty_room,
    empty_room,
    empty_room,
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