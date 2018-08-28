#ifndef overworld_h
#define overworld_h


const uint8_t PROGMEM overworld_map[518] = {
    // array length (16 bit, little endian), map width, map height (in rooms), tile size (in pixels)
    6, 2, 12, 8, 16,
    // room indices (16 bit, little endian), 192 bytes
    0, 0, 11, 0, 16, 0, 21, 0, 26, 0, 31, 0, 36, 0, 41, 0, 46, 0, 51, 0, 56, 0, 61, 0, 66, 0, 72, 0, 75, 0, 78, 0, 81, 0, 84, 0, 87, 0, 90, 0, 93, 0, 96, 0, 99, 0, 102, 0, 105, 0, 108, 0, 111, 0, 114, 0, 117, 0, 120, 0, 123, 0, 126, 0, 129, 0, 132, 0, 135, 0, 138, 0, 141, 0, 144, 0, 147, 0, 150, 0, 153, 0, 156, 0, 159, 0, 162, 0, 165, 0, 168, 0, 171, 0, 174, 0, 177, 0, 180, 0, 183, 0, 186, 0, 189, 0, 192, 0, 195, 0, 198, 0, 201, 0, 204, 0, 207, 0, 210, 0, 213, 0, 216, 0, 219, 0, 222, 0, 225, 0, 228, 0, 231, 0, 234, 0, 237, 0, 240, 0, 243, 0, 246, 0, 249, 0, 252, 0, 255, 0, 2, 1, 5, 1, 8, 1, 11, 1, 14, 1, 17, 1, 20, 1, 23, 1, 26, 1, 29, 1, 32, 1, 35, 1, 38, 1, 41, 1, 44, 1, 47, 1, 50, 1, 53, 1, 56, 1, 59, 1, 62, 1,
    // compressed room data, 321 bytes
    27, 123, 27, 178, 0, 8, 83, 47, 96, 47, 96, 247, 179, 255, 15, 80, 247, 191, 240, 246, 0, 247, 191, 240, 246, 0, 247, 191, 240, 246, 0, 247, 191, 240, 246, 0, 247, 191, 240, 246, 0, 247, 191, 240, 246, 0, 247, 191, 240, 246, 0, 247, 191, 240, 246, 0, 247, 191, 240, 246, 0, 246, 185, 255, 15, 96, 47, 96, 47, 96, 47, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208
};

const uint8_t PROGMEM overworld_room0_0[] = {
    2, // number of entities

    // entity 0, CHEST
    0x7,
    80, //x
    3, //y

    // entity 1, OVERWORLD_DOOR
    0x2,
    32, //x
    1  //y
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