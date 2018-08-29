#ifndef dungeons_h
#define dungeons_h


const uint8_t PROGMEM dungeons_map[139] = {
    // array length (16 bit, little endian), map width, map height (in rooms), tile size (in pixels)
    139, 0, 3, 4, 16,
    // room indices (16 bit, little endian), 24 bytes
    0, 0, 9, 0, 15, 0, 24, 0, 35, 0, 45, 0, 55, 0, 65, 0, 76, 0, 86, 0, 95, 0, 101, 0,
    // compressed room data, 110 bytes
    31, 107, 47, 96, 47, 96, 143, 83, 160, 247, 191, 224, 47, 80, 192, 246, 185, 246, 12, 246, 12, 143, 83, 160, 27, 183, 187, 146, 245, 12, 47, 80, 194, 245, 12, 47, 80, 194, 245, 12, 47, 80, 194, 245, 12, 31, 91, 146, 245, 12, 47, 80, 194, 245, 12, 47, 80, 194, 245, 12, 47, 80, 194, 245, 12, 47, 80, 194, 245, 12, 47, 80, 200, 51, 3, 58, 47, 80, 194, 245, 12, 47, 80, 194, 245, 12, 47, 80, 194, 246, 2, 246, 8, 246, 48, 31, 91, 159, 224, 247, 48, 47, 80, 207, 96, 207, 96, 207, 99, 160
};

const uint8_t PROGMEM dungeons_room0_0[] = {
    2, // number of entities

    // entity 0, BUMPER
    0x11,
    1, //x
    57, //y

    // entity 1, BUMPER
    0x71,
    107, //x
    48  //y
};



const uint8_t PROGMEM dungeons_room0_1[] = {
    4, // number of entities

    // entity 0, BUMPER
    0x11,
    2, //x
    1, //y

    // entity 1, BUMPER
    0x31,
    106, //x
    0, //y

    // entity 2, TELEPORTER
    0x32,
    52, //x
    9, //y

    // entity 3, BLOB
    0x8,
    11, //x
    35  //y
};



const uint8_t PROGMEM dungeons_room0_2[] = {
    1, // number of entities

    // entity 0, BUMPER
    0x31,
    105, //x
    1  //y
};



const uint8_t PROGMEM dungeons_room0_3[] = {
    1, // number of entities

    // entity 0, BUMPER
    0x51,
    106, //x
    1  //y
};



const uint8_t PROGMEM dungeons_room1_0[] = {
    2, // number of entities

    // entity 0, BUMPER
    0x71,
    0, //x
    48, //y

    // entity 1, BUMPER
    0x71,
    106, //x
    48  //y
};



const uint8_t PROGMEM dungeons_room1_1[] = {
    2, // number of entities

    // entity 0, BUMPER
    0x31,
    106, //x
    1, //y

    // entity 1, BUMPER
    0x31,
    0, //x
    0  //y
};



const uint8_t PROGMEM dungeons_room1_2[] = {
    5, // number of entities

    // entity 0, BUMPER
    0x11,
    1, //x
    57, //y

    // entity 1, BUMPER
    0x31,
    0, //x
    0, //y

    // entity 2, BUMPER
    0x31,
    106, //x
    0, //y

    // entity 3, TELEPORTER
    0x12,
    50, //x
    54, //y

    // entity 4, BLOB
    0x8,
    96, //x
    28  //y
};



const uint8_t PROGMEM dungeons_room1_3[] = {
    3, // number of entities

    // entity 0, BUMPER
    0x11,
    1, //x
    1, //y

    // entity 1, BUMPER
    0x51,
    0, //x
    1, //y

    // entity 2, BUMPER
    0x51,
    106, //x
    0  //y
};



const uint8_t PROGMEM dungeons_room2_0[] = {
    2, // number of entities

    // entity 0, BUMPER
    0x11,
    1, //x
    57, //y

    // entity 1, BUMPER
    0x71,
    0, //x
    48  //y
};



const uint8_t PROGMEM dungeons_room2_1[] = {
    2, // number of entities

    // entity 0, BUMPER
    0x11,
    1, //x
    0, //y

    // entity 1, BUMPER
    0x31,
    1, //x
    0  //y
};



const uint8_t PROGMEM dungeons_room2_2[] = {
    1, // number of entities

    // entity 0, BUMPER
    0x31,
    1, //x
    0  //y
};



const uint8_t PROGMEM dungeons_room2_3[] = {
    1, // number of entities

    // entity 0, BUMPER
    0x51,
    1, //x
    1  //y
};

const uint8_t PROGMEM dungeons_teleporters[] = {
    // dest x, dest y (in rooms)
    0, 0,
    1, 1,
};



const uint8_t PROGMEM dungeons_bumpers[] = {
    // width, height
    109, 5,
    5, 63,
    5, 14,
    5, 18,
};

const uint8_t * const PROGMEM dungeons_row0[3] = {
    dungeons_room0_0,
    dungeons_room1_0,
    dungeons_room2_0
};


const uint8_t * const PROGMEM dungeons_row1[3] = {
    dungeons_room0_1,
    dungeons_room1_1,
    dungeons_room2_1
};


const uint8_t * const PROGMEM dungeons_row2[3] = {
    dungeons_room0_2,
    dungeons_room1_2,
    dungeons_room2_2
};


const uint8_t * const PROGMEM dungeons_row3[3] = {
    dungeons_room0_3,
    dungeons_room1_3,
    dungeons_room2_3
};


const uint8_t ** const PROGMEM dungeons_entities[4] = {
    dungeons_row0,
    dungeons_row1,
    dungeons_row2,
    dungeons_row3
};


#endif