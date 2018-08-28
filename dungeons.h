#ifndef dungeons_h
#define dungeons_h


const uint8_t PROGMEM dungeons_map[832] = {
    // array length (16 bit, little endian), map width, map height (in rooms), tile size (in pixels)
    64, 3, 8, 12, 16,
    // room indices (16 bit, little endian), 192 bytes
    0, 0, 13, 0, 21, 0, 27, 0, 35, 0, 39, 0, 49, 0, 52, 0, 62, 0, 74, 0, 83, 0, 86, 0, 97, 0, 102, 0, 113, 0, 117, 0, 128, 0, 135, 0, 142, 0, 147, 0, 156, 0, 159, 0, 168, 0, 171, 0, 177, 0, 180, 0, 185, 0, 191, 0, 201, 0, 204, 0, 209, 0, 215, 0, 223, 0, 228, 0, 236, 0, 245, 0, 255, 0, 2, 1, 10, 1, 15, 1, 23, 1, 26, 1, 29, 1, 38, 1, 47, 1, 57, 1, 69, 1, 72, 1, 75, 1, 78, 1, 89, 1, 93, 1, 97, 1, 105, 1, 112, 1, 118, 1, 123, 1, 128, 1, 132, 1, 135, 1, 140, 1, 143, 1, 146, 1, 149, 1, 152, 1, 158, 1, 164, 1, 170, 1, 182, 1, 185, 1, 189, 1, 199, 1, 204, 1, 207, 1, 217, 1, 223, 1, 237, 1, 243, 1, 253, 1, 0, 2, 3, 2, 8, 2, 17, 2, 22, 2, 36, 2, 39, 2, 49, 2, 53, 2, 63, 2, 73, 2, 76, 2, 86, 2, 96, 2, 99, 2, 108, 2, 111, 2,
    // compressed room data, 635 bytes
    27, 123, 27, 146, 0, 8, 90, 47, 96, 131, 48, 51, 48, 31, 107, 47, 192, 83, 0, 5, 85, 247, 181, 95, 80, 95, 208, 247, 191, 160, 85, 245, 5, 0, 0, 191, 240, 252, 0, 0, 5, 246, 5, 246, 5, 246, 5, 0, 0, 255, 15, 208, 4, 15, 68, 15, 100, 0, 245, 64, 15, 84, 27, 183, 187, 146, 246, 2, 244, 5, 80, 0, 85, 80, 0, 85, 0, 5, 85, 244, 5, 253, 0, 255, 15, 208, 0, 5, 246, 5, 245, 5, 95, 80, 80, 6, 96, 255, 15, 96, 247, 96, 0, 5, 246, 5, 0, 15, 118, 0, 5, 0, 0, 254, 6, 253, 0, 0, 4, 79, 80, 68, 246, 4, 79, 80, 68, 0, 244, 80, 0, 95, 240, 245, 0, 252, 6, 96, 0, 102, 249, 0, 245, 15, 118, 255, 0, 245, 111, 64, 95, 96, 95, 96, 95, 64, 255, 15, 208, 244, 5, 246, 5, 246, 5, 246, 5, 80, 255, 15, 208, 246, 4, 246, 4, 254, 0, 255, 15, 208, 255, 15, 160, 85, 80, 255, 15, 96, 85, 245, 0, 0, 95, 96, 95, 96, 85, 246, 5, 0, 0, 255, 15, 208, 246, 5, 255, 15, 96, 85, 95, 112, 244, 95, 224, 247, 5, 246, 15, 101, 244, 15, 69, 247, 15, 117, 254, 0, 5, 85, 0, 5, 95, 240, 244, 0, 0, 95, 96, 95, 96, 95, 96, 95, 64, 0, 5, 246, 5, 95, 96, 95, 96, 80, 0, 255, 15, 208, 253, 5, 245, 5, 95, 64, 80, 0, 247, 15, 117, 254, 0, 5, 85, 0, 5, 95, 240, 244, 0, 255, 15, 208, 255, 15, 208, 0, 95, 80, 95, 80, 95, 96, 95, 96, 249, 6, 96, 102, 0, 245, 96, 246, 96, 247, 6, 111, 80, 102, 6, 96, 15, 86, 0, 0, 5, 95, 64, 85, 244, 5, 95, 64, 85, 245, 0, 255, 15, 208, 255, 15, 208, 255, 15, 208, 246, 5, 245, 5, 95, 64, 85, 0, 5, 85, 0, 95, 240, 252, 0, 15, 246, 251, 96, 102, 111, 64, 102, 245, 6, 253, 0, 95, 96, 80, 0, 247, 95, 160, 244, 15, 117, 255, 0, 0, 247, 95, 240, 246, 0, 247, 95, 240, 246, 0, 85, 255, 15, 176, 255, 15, 208, 244, 6, 255, 15, 128, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 0, 15, 70, 247, 80, 254, 6, 111, 80, 95, 102, 255, 15, 96, 102, 111, 64, 244, 5, 245, 5, 95, 64, 80, 95, 64, 80, 80, 0, 255, 15, 208, 255, 15, 192, 80, 245, 5, 80, 244, 80, 5, 95, 80, 95, 96, 247, 15, 117, 254, 0, 255, 15, 208, 5, 85, 246, 5, 95, 96, 85, 246, 5, 0, 0, 245, 111, 96, 111, 224, 5, 0, 80, 15, 70, 80, 0, 80, 6, 102, 5, 0, 80, 0, 254, 6, 102, 247, 15, 70, 246, 5, 245, 5, 95, 80, 80, 244, 96, 80, 255, 15, 208, 255, 15, 208, 255, 15, 96, 79, 96, 245, 5, 95, 96, 95, 96, 95, 96, 80, 255, 15, 96, 95, 96, 5, 0, 80, 5, 0, 5, 0, 80, 0, 80, 5, 244, 5, 0, 255, 15, 208, 244, 6, 102, 244, 5, 246, 5, 246, 5, 0, 111, 240, 252, 0, 250, 15, 68, 0, 4, 4, 64, 0, 64, 68, 79, 96, 68, 245, 15, 68, 0, 15, 84, 0, 255, 15, 208, 95, 96, 95, 96, 95, 80, 80, 95, 64, 80, 95, 64, 80, 95, 64, 95, 112, 95, 96, 80, 255, 15, 208, 244, 5, 246, 5, 246, 5, 246, 5, 0, 255, 15, 208, 0, 245, 64, 4, 4, 68, 0, 245, 64, 15, 68, 0
};

const uint8_t PROGMEM dungeons_room0_0[] = {
    9, // number of entities

    // entity 0, BUMPER
    0x3,
    3, //x
    59, //y

    // entity 1, BUMPER
    0x23,
    64, //x
    26, //y

    // entity 2, BUMPER
    0x43,
    98, //x
    26, //y

    // entity 3, BUMPER
    0x63,
    65, //x
    6, //y

    // entity 4, BUMPER
    0x83,
    107, //x
    7, //y

    // entity 5, BUMPER
    0xc3,
    71, //x
    59, //y

    // entity 6, KEY
    0x8,
    23, //x
    38, //y

    // entity 7, CHEST
    0x7,
    80, //x
    6, //y

    // entity 8, BOMB
    0x5,
    48, //x
    44  //y
};



const uint8_t PROGMEM dungeons_room0_1[] = {
    4, // number of entities

    // entity 0, BLOB
    0x1,
    24, //x
    36, //y

    // entity 1, BLOB
    0x1,
    17, //x
    29, //y

    // entity 2, BUMPER
    0xe3,
    70, //x
    0, //y

    // entity 3, BUMPER
    0x103,
    3, //x
    1  //y
};



const uint8_t PROGMEM dungeons_room0_2[] = {
    1, // number of entities

    // entity 0, BLOB
    0x1,
    54, //x
    47  //y
};



const uint8_t PROGMEM dungeons_room0_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room0_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room0_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room0_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room0_7[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room0_8[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room0_9[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room0_10[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room0_11[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room1_0[] = {
    1, // number of entities

    // entity 0, BUMPER
    0xa3,
    1, //x
    7  //y
};



const uint8_t PROGMEM dungeons_room1_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room1_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room1_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room1_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room1_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room1_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room1_7[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room1_8[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room1_9[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room1_10[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room1_11[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room2_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room2_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room2_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room2_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room2_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room2_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room2_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room2_7[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room2_8[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room2_9[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room2_10[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room2_11[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room3_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room3_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room3_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room3_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room3_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room3_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room3_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room3_7[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room3_8[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room3_9[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room3_10[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room3_11[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room4_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room4_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room4_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room4_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room4_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room4_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room4_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room4_7[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room4_8[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room4_9[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room4_10[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room4_11[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room5_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room5_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room5_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room5_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room5_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room5_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room5_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room5_7[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room5_8[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room5_9[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room5_10[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room5_11[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room6_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room6_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room6_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room6_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room6_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room6_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room6_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room6_7[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room6_8[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room6_9[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room6_10[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room6_11[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room7_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room7_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room7_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room7_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room7_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room7_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room7_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room7_7[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room7_8[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room7_9[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room7_10[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room7_11[] = {
    0 // number of entities
};

const uint8_t PROGMEM dungeons_doors[] = {
    // dest x, dest y (in rooms)
};



const uint8_t PROGMEM dungeons_bumpers[] = {
    // width, height
    39, 4,
    12, 4,
    12, 4,
    2, 17,
    2, 17,
    2, 23,
    37, 4,
    38, 4,
    39, 4,
};

const uint8_t * const PROGMEM dungeons_row0[8] = {
    dungeons_room0_0,
    dungeons_room1_0,
    dungeons_room2_0,
    dungeons_room3_0,
    dungeons_room4_0,
    dungeons_room5_0,
    dungeons_room6_0,
    dungeons_room7_0
};


const uint8_t * const PROGMEM dungeons_row1[8] = {
    dungeons_room0_1,
    dungeons_room1_1,
    dungeons_room2_1,
    dungeons_room3_1,
    dungeons_room4_1,
    dungeons_room5_1,
    dungeons_room6_1,
    dungeons_room7_1
};


const uint8_t * const PROGMEM dungeons_row2[8] = {
    dungeons_room0_2,
    dungeons_room1_2,
    dungeons_room2_2,
    dungeons_room3_2,
    dungeons_room4_2,
    dungeons_room5_2,
    dungeons_room6_2,
    dungeons_room7_2
};


const uint8_t * const PROGMEM dungeons_row3[8] = {
    dungeons_room0_3,
    dungeons_room1_3,
    dungeons_room2_3,
    dungeons_room3_3,
    dungeons_room4_3,
    dungeons_room5_3,
    dungeons_room6_3,
    dungeons_room7_3
};


const uint8_t * const PROGMEM dungeons_row4[8] = {
    dungeons_room0_4,
    dungeons_room1_4,
    dungeons_room2_4,
    dungeons_room3_4,
    dungeons_room4_4,
    dungeons_room5_4,
    dungeons_room6_4,
    dungeons_room7_4
};


const uint8_t * const PROGMEM dungeons_row5[8] = {
    dungeons_room0_5,
    dungeons_room1_5,
    dungeons_room2_5,
    dungeons_room3_5,
    dungeons_room4_5,
    dungeons_room5_5,
    dungeons_room6_5,
    dungeons_room7_5
};


const uint8_t * const PROGMEM dungeons_row6[8] = {
    dungeons_room0_6,
    dungeons_room1_6,
    dungeons_room2_6,
    dungeons_room3_6,
    dungeons_room4_6,
    dungeons_room5_6,
    dungeons_room6_6,
    dungeons_room7_6
};


const uint8_t * const PROGMEM dungeons_row7[8] = {
    dungeons_room0_7,
    dungeons_room1_7,
    dungeons_room2_7,
    dungeons_room3_7,
    dungeons_room4_7,
    dungeons_room5_7,
    dungeons_room6_7,
    dungeons_room7_7
};


const uint8_t * const PROGMEM dungeons_row8[8] = {
    dungeons_room0_8,
    dungeons_room1_8,
    dungeons_room2_8,
    dungeons_room3_8,
    dungeons_room4_8,
    dungeons_room5_8,
    dungeons_room6_8,
    dungeons_room7_8
};


const uint8_t * const PROGMEM dungeons_row9[8] = {
    dungeons_room0_9,
    dungeons_room1_9,
    dungeons_room2_9,
    dungeons_room3_9,
    dungeons_room4_9,
    dungeons_room5_9,
    dungeons_room6_9,
    dungeons_room7_9
};


const uint8_t * const PROGMEM dungeons_row10[8] = {
    dungeons_room0_10,
    dungeons_room1_10,
    dungeons_room2_10,
    dungeons_room3_10,
    dungeons_room4_10,
    dungeons_room5_10,
    dungeons_room6_10,
    dungeons_room7_10
};


const uint8_t * const PROGMEM dungeons_row11[8] = {
    dungeons_room0_11,
    dungeons_room1_11,
    dungeons_room2_11,
    dungeons_room3_11,
    dungeons_room4_11,
    dungeons_room5_11,
    dungeons_room6_11,
    dungeons_room7_11
};


const uint8_t ** const PROGMEM dungeons_entities[12] = {
    dungeons_row0,
    dungeons_row1,
    dungeons_row2,
    dungeons_row3,
    dungeons_row4,
    dungeons_row5,
    dungeons_row6,
    dungeons_row7,
    dungeons_row8,
    dungeons_row9,
    dungeons_row10,
    dungeons_row11
};


#endif