#ifndef overworld_h
#define overworld_h


const uint8_t PROGMEM overworld_map[917] = {
    // array length (16 bit, little endian), map width, map height (in rooms), tile size (in pixels)
    149, 3, 12, 8, 16,
    // room indices (16 bit, little endian), 192 bytes
    0, 0, 8, 0, 22, 0, 25, 0, 29, 0, 32, 0, 40, 0, 48, 0, 53, 0, 58, 0, 70, 0, 76, 0, 83, 0, 93, 0, 104, 0, 107, 0, 119, 0, 128, 0, 134, 0, 137, 0, 140, 0, 148, 0, 157, 0, 160, 0, 169, 0, 181, 0, 190, 0, 196, 0, 204, 0, 210, 0, 215, 0, 223, 0, 232, 0, 239, 0, 245, 0, 252, 0, 3, 1, 10, 1, 24, 1, 34, 1, 37, 1, 40, 1, 46, 1, 52, 1, 61, 1, 64, 1, 71, 1, 79, 1, 82, 1, 91, 1, 105, 1, 115, 1, 118, 1, 121, 1, 126, 1, 134, 1, 143, 1, 146, 1, 156, 1, 165, 1, 176, 1, 184, 1, 194, 1, 197, 1, 200, 1, 208, 1, 215, 1, 224, 1, 233, 1, 236, 1, 245, 1, 2, 2, 5, 2, 16, 2, 19, 2, 31, 2, 40, 2, 43, 2, 51, 2, 63, 2, 73, 2, 81, 2, 88, 2, 98, 2, 111, 2, 122, 2, 128, 2, 132, 2, 142, 2, 145, 2, 155, 2, 164, 2, 174, 2, 177, 2, 186, 2, 196, 2,
    // compressed room data, 720 bytes
    253, 144, 244, 144, 0, 153, 159, 64, 0, 68, 4, 0, 4, 0, 64, 4, 64, 4, 0, 64, 0, 64, 255, 15, 208, 255, 15, 176, 68, 255, 15, 208, 255, 0, 15, 68, 4, 64, 4, 64, 244, 15, 116, 246, 15, 116, 244, 0, 248, 15, 116, 253, 0, 247, 15, 116, 254, 0, 244, 4, 0, 64, 4, 0, 4, 68, 246, 4, 64, 0, 252, 6, 111, 96, 111, 112, 102, 15, 246, 102, 96, 15, 86, 153, 245, 4, 246, 4, 246, 4, 79, 64, 64, 79, 64, 64, 79, 64, 64, 79, 64, 79, 96, 64, 255, 15, 208, 245, 4, 79, 64, 64, 64, 0, 64, 4, 0, 245, 64, 245, 4, 64, 0, 247, 79, 64, 79, 96, 245, 64, 4, 255, 15, 80, 255, 15, 208, 255, 15, 208, 253, 4, 244, 4, 79, 64, 68, 0, 68, 4, 79, 96, 79, 112, 79, 96, 64, 255, 15, 208, 0, 6, 102, 244, 6, 111, 208, 68, 64, 4, 244, 4, 4, 64, 4, 0, 15, 68, 245, 4, 68, 245, 4, 246, 4, 246, 4, 246, 4, 0, 255, 15, 80, 79, 80, 64, 15, 68, 0, 68, 79, 240, 0, 0, 68, 246, 15, 100, 254, 0, 247, 15, 116, 254, 0, 247, 4, 247, 15, 84, 246, 4, 64, 252, 4, 64, 4, 68, 0, 68, 245, 0, 4, 79, 64, 79, 240, 245, 0, 246, 4, 246, 4, 254, 0, 251, 15, 132, 0, 68, 245, 0, 4, 68, 0, 4, 255, 15, 80, 0, 4, 64, 79, 240, 246, 0, 79, 64, 64, 68, 0, 4, 0, 64, 0, 64, 4, 64, 4, 0, 245, 4, 245, 4, 245, 4, 245, 4, 244, 0, 255, 15, 208, 255, 15, 208, 253, 4, 246, 4, 246, 4, 0, 247, 79, 240, 244, 0, 79, 96, 68, 246, 4, 246, 4, 79, 64, 255, 15, 208, 253, 4, 245, 4, 246, 4, 0, 79, 96, 79, 96, 79, 96, 79, 96, 255, 15, 208, 247, 4, 68, 247, 4, 246, 4, 0, 0, 0, 64, 4, 0, 4, 0, 64, 0, 64, 4, 0, 64, 0, 68, 0, 79, 64, 68, 245, 4, 246, 4, 246, 0, 255, 15, 208, 255, 15, 208, 246, 4, 255, 15, 96, 79, 96, 79, 96, 79, 112, 79, 80, 0, 79, 96, 68, 246, 4, 247, 4, 0, 255, 15, 208, 244, 4, 245, 4, 79, 80, 79, 80, 79, 64, 79, 96, 79, 96, 79, 96, 79, 80, 64, 245, 4, 64, 0, 68, 0, 4, 79, 64, 79, 96, 244, 4, 246, 15, 132, 246, 4, 0, 68, 0, 4, 68, 244, 4, 246, 4, 248, 0, 255, 15, 208, 255, 15, 208, 248, 4, 68, 247, 4, 68, 247, 0, 254, 4, 79, 96, 68, 64, 0, 4, 246, 4, 247, 4, 246, 4, 244, 0, 244, 4, 247, 4, 246, 4, 246, 4, 0, 255, 15, 208, 0, 79, 80, 79, 96, 79, 80, 79, 96, 79, 80, 64, 64, 0, 64, 4, 0, 64, 0, 68, 64, 0, 255, 15, 208, 244, 4, 246, 4, 245, 4, 64, 5, 0, 64, 0, 255, 15, 208, 0, 15, 68, 0, 68, 244, 4, 79, 64, 68, 245, 0, 79, 96, 79, 112, 79, 96, 68, 244, 0, 255, 15, 208, 244, 4, 247, 4, 79, 96, 79, 112, 0, 79, 96, 79, 64, 64, 4, 0, 4, 0, 64, 0, 244, 4, 79, 80, 79, 96, 79, 96, 64, 0, 246, 4, 246, 4, 246, 4, 246, 4, 255, 15, 64, 68, 79, 64, 64, 4, 245, 4, 79, 112, 79, 80, 68, 244, 0, 246, 4, 4, 64, 4, 4, 68, 0, 64, 64, 64, 4, 64, 85, 4, 0, 15, 69, 64, 15, 85, 64, 246, 84, 253, 4, 245, 15, 116, 0, 79, 240, 252, 0, 0, 79, 96, 79, 96, 68, 246, 4, 0, 0, 255, 15, 208, 246, 4, 246, 4, 245, 4, 79, 64, 68, 0, 64, 4, 247, 4, 247, 4, 246, 4, 0, 244, 4, 245, 4, 246, 4, 246, 4, 0, 0, 255, 15, 208, 64, 249, 79, 80, 64, 0, 64, 245, 64, 68, 244, 4, 15, 132, 0, 79, 80, 64, 0, 0, 79, 70, 70, 111, 68, 0, 244, 70, 15, 68, 102
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