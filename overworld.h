#ifndef overworld_h
#define overworld_h


const uint8_t PROGMEM overworld_map[49] = {
    // array length (16 bit, little endian), map width, map height (in rooms), tile size (in pixels)
    49, 0, 2, 2, 16,
    // room indices (16 bit, little endian), 8 bytes
    0, 0, 9, 0, 18, 0, 26, 0,
    // compressed room data, 36 bytes
    27, 127, 75, 47, 96, 47, 96, 47, 96, 246, 185, 246, 12, 246, 12, 244, 1, 185, 47, 96, 47, 96, 47, 96, 143, 99, 244, 2, 246, 8, 51, 244, 4, 116, 246, 58
};

const uint8_t PROGMEM overworld_room0_0[] = {
    2, // number of entities

    // entity 0, TELEPORTER
    0x12,
    38, //x
    9, //y

    // entity 1, CHEST
    0x87,
    12, //x
    14  //y
};



const uint8_t PROGMEM overworld_room0_1[] = {
    3, // number of entities

    // entity 0, BLOB
    0x8,
    47, //x
    43, //y

    // entity 1, CHEST
    0x47,
    23, //x
    20, //y

    // entity 2, BLOB
    0x8,
    65, //x
    43  //y
};



const uint8_t PROGMEM overworld_room1_0[] = {
    1, // number of entities

    // entity 0, BUMPER
    0x31,
    65, //x
    49  //y
};



const uint8_t PROGMEM overworld_room1_1[] = {
    2, // number of entities

    // entity 0, BUMPER
    0x11,
    65, //x
    1, //y

    // entity 1, TELEPORTER
    0x32,
    86, //x
    38  //y
};

const uint8_t PROGMEM overworld_teleporters[] = {
    // dest x, dest y (in rooms)
    1, 2,
    0, 1,
};



const uint8_t PROGMEM overworld_bumpers[] = {
    // width, height
    42, 39,
    42, 12,
};

const uint8_t * const PROGMEM overworld_row0[2] = {
    overworld_room0_0,
    overworld_room1_0
};


const uint8_t * const PROGMEM overworld_row1[2] = {
    overworld_room0_1,
    overworld_room1_1
};


const uint8_t ** const PROGMEM overworld_entities[2] = {
    overworld_row0,
    overworld_row1
};


#endif