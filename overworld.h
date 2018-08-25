#ifndef overworld_h
#define overworld_h


const uint8_t PROGMEM overworld_map[718] = {
    // array length (16 bit, little endian), map width, map height (in rooms), tile size (in pixels)
    206, 2, 4, 6, 8,
    // room indices (16 bit, little endian), 48 bytes
    0, 0, 33, 0, 55, 0, 95, 0, 122, 0, 156, 0, 181, 0, 218, 0, 236, 0, 2, 1, 22, 1, 56, 1, 86, 1, 120, 1, 150, 1, 185, 1, 223, 1, 241, 1, 253, 1, 16, 2, 34, 2, 65, 2, 96, 2, 127, 2,
    // compressed room data, 665 bytes
    143, 208, 160, 17, 250, 8, 32, 1, 2, 7, 111, 64, 143, 112, 84, 244, 8, 128, 47, 64, 63, 80, 136, 246, 2, 63, 64, 168, 252, 8, 175, 160, 48, 252, 2, 47, 112, 47, 224, 16, 0, 32, 47, 240, 249, 2, 0, 2, 47, 240, 244, 1, 255, 15, 64, 47, 176, 34, 249, 1, 0, 2, 0, 31, 160, 32, 1, 0, 2, 34, 244, 2, 0, 170, 0, 47, 96, 32, 42, 160, 2, 244, 7, 111, 64, 160, 2, 244, 5, 79, 112, 32, 1, 244, 0, 34, 252, 2, 47, 64, 47, 112, 47, 64, 34, 247, 2, 244, 2, 248, 2, 244, 2, 253, 2, 254, 2, 253, 15, 66, 244, 0, 138, 252, 8, 130, 251, 10, 247, 2, 244, 1, 143, 96, 63, 80, 26, 2, 249, 1, 8, 169, 0, 31, 128, 136, 170, 154, 160, 47, 80, 143, 106, 245, 10, 160, 0, 1, 255, 0, 0, 63, 80, 244, 31, 64, 47, 240, 245, 2, 255, 0, 0, 48, 63, 208, 35, 42, 163, 254, 160, 1, 244, 2, 47, 64, 31, 128, 34, 0, 1, 0, 32, 159, 64, 34, 247, 8, 1, 251, 8, 247, 7, 96, 51, 249, 5, 64, 48, 8, 245, 1, 247, 9, 246, 7, 96, 112, 249, 15, 82, 254, 7, 111, 192, 84, 255, 15, 240, 251, 1, 252, 6, 0, 175, 160, 249, 15, 83, 244, 1, 248, 3, 255, 15, 64, 51, 245, 3, 63, 240, 0, 31, 240, 255, 15, 112, 16, 245, 63, 144, 246, 63, 144, 245, 63, 128, 63, 240, 244, 1, 255, 15, 240, 249, 3, 63, 128, 244, 47, 96, 84, 5, 0, 34, 0, 31, 80, 118, 16, 34, 245, 1, 16, 84, 0, 47, 160, 160, 15, 66, 251, 1, 2, 253, 2, 47, 160, 245, 47, 80, 16, 64, 170, 250, 7, 106, 160, 10, 247, 5, 79, 90, 247, 15, 90, 251, 10, 170, 251, 10, 175, 144, 32, 10, 244, 15, 114, 247, 2, 245, 2, 249, 1, 255, 15, 64, 32, 32, 34, 47, 112, 32, 32, 2, 248, 2, 34, 0, 47, 128, 32, 32, 2, 0, 1, 16, 0, 16, 32, 34, 47, 96, 17, 252, 0, 249, 7, 111, 192, 84, 1, 245, 1, 252, 7, 111, 192, 84, 245, 1, 247, 7, 111, 64, 118, 246, 5, 71, 96, 5, 79, 128, 84, 246, 0, 245, 15, 98, 250, 2, 47, 144, 245, 32, 118, 118, 118, 244, 2, 34, 5, 69, 69, 64, 16, 51, 47, 64, 118, 0, 244, 63, 64, 16, 84, 252, 7, 111, 192, 84, 247, 2, 245, 2, 247, 2, 245, 2, 247, 2, 245, 2, 247, 2, 47, 64, 39, 111, 96, 32, 0, 34, 84, 247, 15, 82, 118, 0, 10, 160, 2, 32, 0, 84, 0, 245, 175, 82, 31, 208, 31, 208, 31, 208, 31, 208, 17, 253, 1, 253, 1, 31, 208, 17, 250, 0, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 255, 15, 240, 255, 15, 240, 252, 15, 81, 248, 1, 16, 0, 31, 128, 31, 64, 31, 112, 255, 15, 240, 251, 1, 252, 1, 31, 176, 17, 251, 1, 31, 192, 31, 208, 16, 0, 0, 1, 31, 192, 17, 252, 1, 253, 1, 245, 1, 17, 245, 1, 244, 1, 16, 31, 80, 16, 0, 17, 0, 17, 244, 15, 81, 244, 1, 31, 224, 255, 15, 64, 17, 31, 144, 17, 0, 17, 248, 1, 244, 1, 244, 1, 0, 17, 244, 1, 16, 1, 16, 1, 246, 15, 65, 1, 17, 255, 15, 160, 17, 244, 1, 247, 1, 245, 1, 247, 1, 244, 1, 31, 112, 31, 64, 31, 208, 17, 245, 1, 247, 1, 17, 0, 17, 31, 128, 244, 16, 31, 224, 250, 1, 253, 1, 252, 1, 31, 192, 31, 208, 31, 112, 17, 16, 1, 31, 64, 16, 17, 15, 65, 245, 1, 17, 251, 0
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



const uint8_t PROGMEM overworld_room0_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room0_5[] = {
    0 // number of entities
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



const uint8_t PROGMEM overworld_room1_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room1_5[] = {
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



const uint8_t PROGMEM overworld_room2_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room2_5[] = {
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



const uint8_t PROGMEM overworld_room3_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room3_5[] = {
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


const uint8_t * const PROGMEM overworld_row4[4] = {
    overworld_room0_4,
    overworld_room1_4,
    overworld_room2_4,
    overworld_room3_4
};


const uint8_t * const PROGMEM overworld_row5[4] = {
    overworld_room0_5,
    overworld_room1_5,
    overworld_room2_5,
    overworld_room3_5
};


const uint8_t ** const PROGMEM overworld_entities[6] = {
    overworld_row0,
    overworld_row1,
    overworld_row2,
    overworld_row3,
    overworld_row4,
    overworld_row5
};


#endif