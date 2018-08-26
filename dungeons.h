#ifndef dungeons_h
#define dungeons_h


const uint8_t PROGMEM dungeons_map[831] = {
    // array length (16 bit, little endian), map width, map height (in rooms), tile size (in pixels)
    63, 3, 8, 12, 16,
    // room indices (16 bit, little endian), 192 bytes
    0, 0, 10, 0, 17, 0, 25, 0, 36, 0, 39, 0, 49, 0, 52, 0, 62, 0, 73, 0, 82, 0, 85, 0, 96, 0, 101, 0, 112, 0, 116, 0, 127, 0, 134, 0, 141, 0, 146, 0, 155, 0, 158, 0, 167, 0, 170, 0, 176, 0, 179, 0, 184, 0, 190, 0, 200, 0, 203, 0, 208, 0, 214, 0, 222, 0, 227, 0, 235, 0, 244, 0, 254, 0, 1, 1, 9, 1, 14, 1, 22, 1, 25, 1, 28, 1, 37, 1, 46, 1, 56, 1, 68, 1, 71, 1, 74, 1, 77, 1, 88, 1, 92, 1, 96, 1, 104, 1, 111, 1, 117, 1, 122, 1, 127, 1, 131, 1, 134, 1, 139, 1, 142, 1, 145, 1, 148, 1, 151, 1, 157, 1, 163, 1, 169, 1, 181, 1, 184, 1, 188, 1, 198, 1, 203, 1, 206, 1, 216, 1, 222, 1, 236, 1, 242, 1, 252, 1, 255, 1, 2, 2, 7, 2, 16, 2, 21, 2, 35, 2, 38, 2, 48, 2, 52, 2, 62, 2, 72, 2, 75, 2, 85, 2, 95, 2, 98, 2, 107, 2, 110, 2,
    // compressed room data, 634 bytes
    244, 64, 4, 64, 249, 64, 0, 68, 79, 64, 255, 15, 80, 95, 64, 85, 80, 0, 95, 64, 85, 245, 5, 253, 0, 244, 5, 95, 80, 95, 80, 85, 245, 5, 0, 0, 255, 15, 208, 0, 5, 246, 5, 246, 5, 246, 5, 0, 0, 255, 15, 208, 4, 15, 68, 15, 100, 0, 245, 64, 15, 84, 68, 245, 4, 246, 4, 244, 5, 80, 0, 85, 80, 0, 85, 0, 5, 85, 244, 5, 253, 0, 255, 15, 208, 0, 5, 246, 5, 245, 5, 95, 80, 80, 6, 96, 255, 15, 96, 247, 96, 0, 5, 246, 5, 0, 15, 118, 0, 5, 0, 0, 254, 6, 253, 0, 0, 4, 79, 80, 68, 246, 4, 79, 80, 68, 0, 244, 80, 0, 95, 240, 245, 0, 252, 6, 96, 0, 102, 249, 0, 245, 15, 118, 255, 0, 245, 111, 64, 95, 96, 95, 96, 95, 64, 255, 15, 208, 244, 5, 246, 5, 246, 5, 246, 5, 80, 255, 15, 208, 246, 4, 246, 4, 254, 0, 255, 15, 208, 255, 15, 160, 85, 80, 255, 15, 96, 85, 245, 0, 0, 95, 96, 95, 96, 85, 246, 5, 0, 0, 255, 15, 208, 246, 5, 255, 15, 96, 85, 95, 112, 244, 95, 224, 247, 5, 246, 15, 101, 244, 15, 69, 247, 15, 117, 254, 0, 5, 85, 0, 5, 95, 240, 244, 0, 0, 95, 96, 95, 96, 95, 96, 95, 64, 0, 5, 246, 5, 95, 96, 95, 96, 80, 0, 255, 15, 208, 253, 5, 245, 5, 95, 64, 80, 0, 247, 15, 117, 254, 0, 5, 85, 0, 5, 95, 240, 244, 0, 255, 15, 208, 255, 15, 208, 0, 95, 80, 95, 80, 95, 96, 95, 96, 249, 6, 96, 102, 0, 245, 96, 246, 96, 247, 6, 111, 80, 102, 6, 96, 15, 86, 0, 0, 5, 95, 64, 85, 244, 5, 95, 64, 85, 245, 0, 255, 15, 208, 255, 15, 208, 255, 15, 208, 246, 5, 245, 5, 95, 64, 85, 0, 5, 85, 0, 95, 240, 252, 0, 15, 246, 251, 96, 102, 111, 64, 102, 245, 6, 253, 0, 95, 96, 80, 0, 247, 95, 160, 244, 15, 117, 255, 0, 0, 247, 95, 240, 246, 0, 247, 95, 240, 246, 0, 85, 255, 15, 176, 255, 15, 208, 244, 6, 255, 15, 128, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 15, 208, 255, 0, 15, 70, 247, 80, 254, 6, 111, 80, 95, 102, 255, 15, 96, 102, 111, 64, 244, 5, 245, 5, 95, 64, 80, 95, 64, 80, 80, 0, 255, 15, 208, 255, 15, 192, 80, 245, 5, 80, 244, 80, 5, 95, 80, 95, 96, 247, 15, 117, 254, 0, 255, 15, 208, 5, 85, 246, 5, 95, 96, 85, 246, 5, 0, 0, 245, 111, 96, 111, 224, 5, 0, 80, 15, 70, 80, 0, 80, 6, 102, 5, 0, 80, 0, 254, 6, 102, 247, 15, 70, 246, 5, 245, 5, 95, 80, 80, 244, 96, 80, 255, 15, 208, 255, 15, 208, 255, 15, 96, 79, 96, 245, 5, 95, 96, 95, 96, 95, 96, 80, 255, 15, 96, 95, 96, 5, 0, 80, 5, 0, 5, 0, 80, 0, 80, 5, 244, 5, 0, 255, 15, 208, 244, 6, 102, 244, 5, 246, 5, 246, 5, 0, 111, 240, 252, 0, 250, 15, 68, 0, 4, 4, 64, 0, 64, 68, 79, 96, 68, 245, 15, 68, 0, 15, 84, 0, 255, 15, 208, 95, 96, 95, 96, 95, 80, 80, 95, 64, 80, 95, 64, 80, 95, 64, 95, 112, 95, 96, 80, 255, 15, 208, 244, 5, 246, 5, 246, 5, 246, 5, 0, 255, 15, 208, 0, 245, 64, 4, 4, 68, 0, 245, 64, 15, 68, 0
};

const uint8_t PROGMEM dungeons_room0_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room0_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room0_2[] = {
    1, // number of entities

    // entity 0, BLOB
    1,
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
    0 // number of entities
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