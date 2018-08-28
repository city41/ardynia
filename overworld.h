#ifndef overworld_h
#define overworld_h


const uint8_t PROGMEM overworld_map[53] = {
    // array length (16 bit, little endian), map width, map height (in rooms), tile size (in pixels)
    53, 0, 2, 2, 16,
    // room indices (16 bit, little endian), 8 bytes
    0, 0, 9, 0, 19, 0, 27, 0,
    // compressed room data, 40 bytes
    27, 127, 75, 47, 96, 47, 96, 47, 96, 246, 185, 246, 12, 246, 12, 0, 1, 187, 144, 47, 96, 47, 96, 47, 96, 143, 99, 0, 2, 0, 192, 0, 131, 58, 0, 4, 116, 79, 99, 160
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
    49, //x
    49  //y
};



const uint8_t PROGMEM overworld_room1_1[] = {
    2, // number of entities

    // entity 0, BUMPER
    0x11,
    49, //x
    1, //y

    // entity 1, TELEPORTER
    0x32,
    70, //x
    38  //y
};

const uint8_t PROGMEM overworld_teleporters[] = {
    // dest x, dest y (in rooms)
    1, 2,
    0, 1,
};



const uint8_t PROGMEM overworld_bumpers[] = {
    // width, height
    58, 39,
    58, 12,
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