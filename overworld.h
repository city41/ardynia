#ifndef overworld_h
#define overworld_h


const uint8_t PROGMEM overworld_map[899] = {
    // map width, map height (in rooms), tile size (in pixels)
    4, 4, 8,
    128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 32, 0, 0, 0, 0, 0, 34, 34, 0, 0, 0, 0, 0, 0, 160, 17, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 34, 0, 0, 32, 0, 0, 0, 130, 0, 16, 32, 118, 0, 0, 0, 0, 0, 0, 16, 0, 32, 0, 16, 0, 0, 0, 0, 2, 32, 0, 2, 32, 0, 0, 0, 128, 0, 0, 0, 84, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 16, 0, 34, 32, 0, 2, 32, 0, 2, 0, 0, 0, 0, 136, 2, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 170, 0, 32, 0, 0, 2, 32, 0, 2, 0, 0, 0, 0, 136, 0, 0, 0, 35, 0, 0, 2, 32, 0, 0, 0, 0, 0, 2, 170, 0, 32, 0, 7, 96, 0, 0, 2, 0, 0, 0, 0, 168, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0, 10, 0, 32, 0, 5, 64, 0, 0, 0, 32, 0, 0, 0, 138, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 1, 0, 0, 0, 0, 0, 34, 34, 0, 0, 138, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 34, 0, 0, 16, 0, 0, 0, 0, 2, 34, 34, 136, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 2, 32, 0, 16, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0, 0, 32, 0, 1, 17, 17, 0, 0, 32, 0, 0, 2, 9, 0, 0, 34, 0, 0, 118, 0, 0, 0, 0, 0, 0, 128, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 8, 1, 0, 0, 0, 0, 84, 0, 0, 0, 0, 0, 0, 160, 32, 0, 0, 0, 0, 16, 2, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 7, 96, 0, 0, 0, 0, 0, 0, 0, 138, 144, 1, 0, 0, 0, 0, 0, 0, 0, 48, 48, 0, 0, 51, 0, 0, 0, 0, 5, 64, 0, 0, 0, 0, 0, 0, 0, 136, 170, 154, 160, 32, 0, 0, 0, 0, 0, 0, 35, 42, 163, 48, 8, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 138, 170, 170, 160, 0, 0, 170, 170, 170, 170, 170, 170, 170, 170, 0, 9, 0, 0, 0, 118, 7, 96, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 51, 51, 51, 51, 48, 0, 0, 0, 0, 34, 34, 0, 0, 0, 84, 5, 64, 170, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0, 3, 51, 51, 51, 0, 0, 0, 0, 0, 34, 0, 16, 0, 0, 118, 118, 170, 0, 160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 51, 51, 0, 0, 0, 0, 16, 34, 0, 0, 1, 16, 84, 84, 170, 170, 160, 0, 0, 0, 0, 0, 3, 48, 0, 0, 51, 48, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 10, 170, 170, 160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 34, 34, 0, 0, 0, 0, 0, 170, 160, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 170, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 32, 0, 0, 0, 0, 160, 0, 2, 34, 34, 34, 0, 0, 0, 0, 0, 0, 1, 0, 0, 51, 0, 0, 0, 0, 0, 2, 34, 34, 0, 0, 1, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 96, 0, 0, 0, 2, 34, 34, 32, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 64, 16, 0, 0, 0, 2, 32, 0, 0, 0, 0, 0, 2, 0, 0, 2, 2, 2, 2, 34, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 34, 34, 32, 118, 118, 0, 0, 0, 2, 0, 0, 2, 2, 2, 0, 32, 0, 0, 0, 0, 7, 96, 0, 0, 0, 0, 118, 0, 0, 34, 32, 84, 84, 0, 0, 0, 2, 32, 0, 2, 2, 34, 0, 32, 0, 0, 0, 0, 5, 64, 0, 0, 16, 0, 84, 1, 3, 50, 0, 0, 118, 118, 0, 0, 0, 32, 0, 34, 2, 2, 0, 32, 0, 17, 0, 0, 0, 118, 0, 0, 118, 0, 0, 51, 51, 0, 0, 16, 84, 84, 0, 0, 0, 2, 34, 34, 2, 2, 2, 34, 0, 0, 0, 0, 0, 84, 118, 0, 84, 0, 0, 0, 0, 0, 0, 0, 118, 118, 0, 10, 160, 2, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 84, 84, 0, 170, 170, 162, 34, 34
};

const uint8_t PROGMEM overworld_room0_0[] = {
    2, // number of entities

    // entity 0, BLOB
    1,
    43, //x
    39, //y

    // entity 1, BLOB
    1,
    77, //x
    44  //y
};



const uint8_t PROGMEM overworld_room0_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room0_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room0_3[] = {
    3, // number of entities

    // entity 0, BLOB
    1,
    20, //x
    47, //y

    // entity 1, BLOB
    1,
    35, //x
    45, //y

    // entity 2, BLOB
    1,
    60, //x
    44  //y
};



const uint8_t PROGMEM overworld_room1_0[] = {
    1, // number of entities

    // entity 0, OVERWORLD_DOOR
    0x2,
    57, //x
    20  //y
};



const uint8_t PROGMEM overworld_room1_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room1_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room1_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room2_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room2_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room2_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room2_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room3_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room3_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room3_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room3_3[] = {
    0 // number of entities
};

const uint8_t PROGMEM overworld_doors[] = {
    // dest x, dest y (in rooms)
    0, 1
};



const uint8_t * const PROGMEM overworld_row0[4] = {
    overworld_room0_0,
    overworld_room1_0,
    overworld_room2_0,
    overworld_room3_0
};


const uint8_t * const PROGMEM overworld_row1[4] = {
    overworld_room0_1,
    overworld_room1_1,
    overworld_room2_1,
    overworld_room3_1
};


const uint8_t * const PROGMEM overworld_row2[4] = {
    overworld_room0_2,
    overworld_room1_2,
    overworld_room2_2,
    overworld_room3_2
};


const uint8_t * const PROGMEM overworld_row3[4] = {
    overworld_room0_3,
    overworld_room1_3,
    overworld_room2_3,
    overworld_room3_3
};


const uint8_t ** const PROGMEM overworld_entities[4] = {
    overworld_row0,
    overworld_row1,
    overworld_row2,
    overworld_row3
};


#endif