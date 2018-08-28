#ifndef overworld_h
#define overworld_h


const uint8_t PROGMEM overworld_map[495] = {
    // array length (16 bit, little endian), map width, map height (in rooms), tile size (in pixels)
    239, 1, 12, 8, 16,
    // room indices (16 bit, little endian), 192 bytes
    0, 0, 8, 0, 13, 0, 16, 0, 19, 0, 22, 0, 25, 0, 28, 0, 31, 0, 34, 0, 37, 0, 40, 0, 43, 0, 49, 0, 52, 0, 55, 0, 58, 0, 61, 0, 64, 0, 67, 0, 70, 0, 73, 0, 76, 0, 79, 0, 82, 0, 85, 0, 88, 0, 91, 0, 94, 0, 97, 0, 100, 0, 103, 0, 106, 0, 109, 0, 112, 0, 115, 0, 118, 0, 121, 0, 124, 0, 127, 0, 130, 0, 133, 0, 136, 0, 139, 0, 142, 0, 145, 0, 148, 0, 151, 0, 154, 0, 157, 0, 160, 0, 163, 0, 166, 0, 169, 0, 172, 0, 175, 0, 178, 0, 181, 0, 184, 0, 187, 0, 190, 0, 193, 0, 196, 0, 199, 0, 202, 0, 205, 0, 208, 0, 211, 0, 214, 0, 217, 0, 220, 0, 223, 0, 226, 0, 229, 0, 232, 0, 235, 0, 238, 0, 241, 0, 244, 0, 247, 0, 250, 0, 253, 0, 0, 1, 3, 1, 6, 1, 9, 1, 12, 1, 15, 1, 18, 1, 21, 1, 24, 1, 27, 1, 30, 1, 33, 1, 36, 1, 39, 1,
    // compressed room data, 298 bytes
    31, 107, 47, 96, 47, 96, 47, 96, 187, 191, 240, 250, 0, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 47, 96, 47, 96, 47, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208
};

const uint8_t PROGMEM overworld_room0_0[] = {
    0 // number of entities
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
    0x1,
    78, //x
    44, //y

    // entity 1, BLOB
    0x1,
    92, //x
    54, //y

    // entity 2, BLOB
    0x1,
    28, //x
    52  //y
};



const uint8_t PROGMEM overworld_room0_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room0_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room0_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room0_7[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room1_0[] = {
    1, // number of entities

    // entity 0, BLOB
    0x1,
    60, //x
    25  //y
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



const uint8_t PROGMEM overworld_room1_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room1_7[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room2_0[] = {
    1, // number of entities

    // entity 0, OVERWORLD_DOOR
    0x2,
    54, //x
    33  //y
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



const uint8_t PROGMEM overworld_room2_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room2_7[] = {
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



const uint8_t PROGMEM overworld_room3_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room3_7[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room4_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room4_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room4_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room4_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room4_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room4_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room4_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room4_7[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room5_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room5_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room5_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room5_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room5_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room5_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room5_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room5_7[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room6_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room6_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room6_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room6_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room6_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room6_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room6_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room6_7[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room7_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room7_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room7_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room7_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room7_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room7_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room7_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room7_7[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room8_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room8_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room8_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room8_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room8_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room8_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room8_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room8_7[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room9_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room9_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room9_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room9_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room9_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room9_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room9_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room9_7[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room10_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room10_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room10_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room10_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room10_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room10_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room10_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room10_7[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room11_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room11_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room11_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room11_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room11_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room11_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room11_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room11_7[] = {
    0 // number of entities
};

const uint8_t PROGMEM overworld_doors[] = {
    // dest x, dest y (in rooms)
    0, 0,
};



const uint8_t PROGMEM overworld_bumpers[] = {
    // width, height
};

const uint8_t * const PROGMEM overworld_row0[12] = {
    overworld_room0_0,
    overworld_room1_0,
    overworld_room2_0,
    overworld_room3_0,
    overworld_room4_0,
    overworld_room5_0,
    overworld_room6_0,
    overworld_room7_0,
    overworld_room8_0,
    overworld_room9_0,
    overworld_room10_0,
    overworld_room11_0
};


const uint8_t * const PROGMEM overworld_row1[12] = {
    overworld_room0_1,
    overworld_room1_1,
    overworld_room2_1,
    overworld_room3_1,
    overworld_room4_1,
    overworld_room5_1,
    overworld_room6_1,
    overworld_room7_1,
    overworld_room8_1,
    overworld_room9_1,
    overworld_room10_1,
    overworld_room11_1
};


const uint8_t * const PROGMEM overworld_row2[12] = {
    overworld_room0_2,
    overworld_room1_2,
    overworld_room2_2,
    overworld_room3_2,
    overworld_room4_2,
    overworld_room5_2,
    overworld_room6_2,
    overworld_room7_2,
    overworld_room8_2,
    overworld_room9_2,
    overworld_room10_2,
    overworld_room11_2
};


const uint8_t * const PROGMEM overworld_row3[12] = {
    overworld_room0_3,
    overworld_room1_3,
    overworld_room2_3,
    overworld_room3_3,
    overworld_room4_3,
    overworld_room5_3,
    overworld_room6_3,
    overworld_room7_3,
    overworld_room8_3,
    overworld_room9_3,
    overworld_room10_3,
    overworld_room11_3
};


const uint8_t * const PROGMEM overworld_row4[12] = {
    overworld_room0_4,
    overworld_room1_4,
    overworld_room2_4,
    overworld_room3_4,
    overworld_room4_4,
    overworld_room5_4,
    overworld_room6_4,
    overworld_room7_4,
    overworld_room8_4,
    overworld_room9_4,
    overworld_room10_4,
    overworld_room11_4
};


const uint8_t * const PROGMEM overworld_row5[12] = {
    overworld_room0_5,
    overworld_room1_5,
    overworld_room2_5,
    overworld_room3_5,
    overworld_room4_5,
    overworld_room5_5,
    overworld_room6_5,
    overworld_room7_5,
    overworld_room8_5,
    overworld_room9_5,
    overworld_room10_5,
    overworld_room11_5
};


const uint8_t * const PROGMEM overworld_row6[12] = {
    overworld_room0_6,
    overworld_room1_6,
    overworld_room2_6,
    overworld_room3_6,
    overworld_room4_6,
    overworld_room5_6,
    overworld_room6_6,
    overworld_room7_6,
    overworld_room8_6,
    overworld_room9_6,
    overworld_room10_6,
    overworld_room11_6
};


const uint8_t * const PROGMEM overworld_row7[12] = {
    overworld_room0_7,
    overworld_room1_7,
    overworld_room2_7,
    overworld_room3_7,
    overworld_room4_7,
    overworld_room5_7,
    overworld_room6_7,
    overworld_room7_7,
    overworld_room8_7,
    overworld_room9_7,
    overworld_room10_7,
    overworld_room11_7
};


const uint8_t ** const PROGMEM overworld_entities[8] = {
    overworld_row0,
    overworld_row1,
    overworld_row2,
    overworld_row3,
    overworld_row4,
    overworld_row5,
    overworld_row6,
    overworld_row7
};


#endif