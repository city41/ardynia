#ifndef dungeons_h
#define dungeons_h


const uint8_t PROGMEM dungeons_map[742] = {
    // array length (16 bit, little endian), map width, map height (in rooms), tile size (in pixels)
    230, 2, 12, 7, 16,
    // room indices (16 bit, little endian), 168 bytes
    0, 0, 8, 0, 13, 0, 21, 0, 31, 0, 34, 0, 42, 0, 47, 0, 52, 0, 60, 0, 66, 0, 71, 0, 79, 0, 89, 0, 97, 0, 105, 0, 113, 0, 118, 0, 123, 0, 126, 0, 129, 0, 132, 0, 137, 0, 142, 0, 150, 0, 160, 0, 168, 0, 173, 0, 178, 0, 183, 0, 191, 0, 199, 0, 204, 0, 207, 0, 212, 0, 215, 0, 223, 0, 236, 0, 241, 0, 246, 0, 254, 0, 1, 1, 9, 1, 14, 1, 22, 1, 32, 1, 42, 1, 50, 1, 58, 1, 68, 1, 76, 1, 79, 1, 84, 1, 89, 1, 97, 1, 105, 1, 113, 1, 123, 1, 133, 1, 141, 1, 149, 1, 160, 1, 168, 1, 176, 1, 184, 1, 189, 1, 194, 1, 197, 1, 200, 1, 205, 1, 208, 1, 216, 1, 226, 1, 234, 1, 239, 1, 244, 1, 249, 1, 1, 2, 15, 2, 20, 2, 25, 2, 30, 2, 35, 2, 43, 2,
    // compressed room data, 569 bytes
    31, 109, 47, 96, 47, 96, 175, 99, 247, 223, 240, 246, 0, 246, 219, 246, 14, 246, 14, 246, 14, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 255, 95, 213, 31, 109, 47, 96, 47, 96, 47, 96, 247, 223, 240, 246, 0, 247, 223, 240, 246, 0, 246, 219, 246, 14, 246, 14, 246, 14, 31, 109, 47, 208, 175, 99, 247, 223, 224, 247, 48, 246, 219, 246, 14, 246, 14, 246, 60, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 47, 96, 47, 96, 47, 96, 47, 96, 246, 14, 246, 14, 246, 14, 246, 14, 47, 96, 47, 96, 47, 96, 175, 99, 247, 223, 224, 247, 48, 255, 15, 96, 247, 48, 255, 15, 208, 255, 15, 208, 255, 15, 208, 247, 223, 240, 246, 0, 247, 223, 240, 246, 0, 246, 219, 246, 14, 246, 14, 246, 14, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 47, 96, 47, 96, 47, 96, 175, 99, 255, 15, 96, 247, 48, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 246, 219, 246, 14, 246, 14, 246, 14, 47, 96, 47, 96, 47, 96, 175, 99, 255, 15, 96, 247, 48, 255, 15, 208, 255, 15, 96, 247, 48, 255, 15, 208, 246, 14, 246, 14, 246, 14, 246, 14, 41, 8, 9, 2, 246, 2, 128, 144, 128, 163, 48, 51, 48, 247, 223, 240, 246, 0, 247, 223, 240, 246, 0, 246, 219, 246, 14, 246, 14, 246, 14, 255, 95, 213, 47, 96, 47, 96, 47, 96, 175, 99, 247, 223, 240, 246, 0, 246, 219, 246, 14, 246, 14, 246, 14, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 47, 96, 47, 96, 47, 96, 47, 96, 246, 14, 246, 14, 246, 14, 246, 14, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 47, 96, 47, 96, 47, 96, 47, 96, 255, 15, 208, 255, 15, 96, 247, 48, 247, 223, 224, 247, 48, 246, 219, 246, 14, 246, 14, 246, 60, 47, 96, 47, 96, 47, 96, 47, 96, 246, 14, 246, 14, 246, 14, 246, 14, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 47, 96, 47, 96, 47, 96, 175, 99, 246, 14, 246, 14, 246, 14, 246, 14, 47, 80, 226, 245, 14, 47, 80, 234, 51, 3, 60, 47, 96, 47, 96, 47, 96, 47, 96, 246, 14, 246, 14, 246, 14, 246, 14, 31, 109, 47, 96, 47, 96, 175, 99, 247, 223, 224, 247, 48, 247, 223, 240, 246, 0, 255, 15, 208, 255, 15, 208, 247, 223, 240, 246, 0, 255, 15, 208, 246, 219, 246, 14, 246, 14, 246, 14, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 31, 109, 47, 96, 47, 96, 175, 99, 255, 15, 96, 247, 48, 255, 15, 96, 247, 48, 247, 223, 224, 247, 48, 246, 219, 246, 14, 246, 14, 246, 60, 40, 137, 136, 2, 144, 0, 144, 40, 0, 8, 10, 51, 3, 51, 255, 15, 96, 247, 48, 255, 15, 96, 247, 48, 255, 15, 96, 247, 48, 255, 15, 96, 247, 48, 246, 14, 246, 14, 246, 14, 246, 60, 40, 152, 152, 226, 152, 152, 158, 40, 152, 152, 234, 51, 3, 60
};

const uint8_t PROGMEM dungeons_room0_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room0_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room0_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room0_3[] = {
    1, // number of entities

    // entity 0, TELEPORTER
    0x11,
    48, //x
    57  //y
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
    1, // number of entities

    // entity 0, TELEPORTER
    0x31,
    48, //x
    54  //y
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



const uint8_t PROGMEM dungeons_room8_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room8_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room8_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room8_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room8_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room8_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room8_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room9_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room9_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room9_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room9_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room9_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room9_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room9_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room10_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room10_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room10_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room10_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room10_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room10_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room10_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room11_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room11_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room11_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room11_3[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room11_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room11_5[] = {
    1, // number of entities

    // entity 0, BLOB
    0x8,
    68, //x
    19  //y
};



const uint8_t PROGMEM dungeons_room11_6[] = {
    1, // number of entities

    // entity 0, TELEPORTER
    0x51,
    48, //x
    53  //y
};

const uint8_t PROGMEM dungeons_teleporters[] = {
    // dest x, dest y (in rooms)
    4, 7,
    7, 0,
    0, 4,
};



const uint8_t PROGMEM dungeons_bumpers[] = {
    // width, height
};

const uint8_t * const PROGMEM dungeons_row0[12] = {
    dungeons_room0_0,
    dungeons_room1_0,
    dungeons_room2_0,
    dungeons_room3_0,
    dungeons_room4_0,
    dungeons_room5_0,
    dungeons_room6_0,
    dungeons_room7_0,
    dungeons_room8_0,
    dungeons_room9_0,
    dungeons_room10_0,
    dungeons_room11_0
};


const uint8_t * const PROGMEM dungeons_row1[12] = {
    dungeons_room0_1,
    dungeons_room1_1,
    dungeons_room2_1,
    dungeons_room3_1,
    dungeons_room4_1,
    dungeons_room5_1,
    dungeons_room6_1,
    dungeons_room7_1,
    dungeons_room8_1,
    dungeons_room9_1,
    dungeons_room10_1,
    dungeons_room11_1
};


const uint8_t * const PROGMEM dungeons_row2[12] = {
    dungeons_room0_2,
    dungeons_room1_2,
    dungeons_room2_2,
    dungeons_room3_2,
    dungeons_room4_2,
    dungeons_room5_2,
    dungeons_room6_2,
    dungeons_room7_2,
    dungeons_room8_2,
    dungeons_room9_2,
    dungeons_room10_2,
    dungeons_room11_2
};


const uint8_t * const PROGMEM dungeons_row3[12] = {
    dungeons_room0_3,
    dungeons_room1_3,
    dungeons_room2_3,
    dungeons_room3_3,
    dungeons_room4_3,
    dungeons_room5_3,
    dungeons_room6_3,
    dungeons_room7_3,
    dungeons_room8_3,
    dungeons_room9_3,
    dungeons_room10_3,
    dungeons_room11_3
};


const uint8_t * const PROGMEM dungeons_row4[12] = {
    dungeons_room0_4,
    dungeons_room1_4,
    dungeons_room2_4,
    dungeons_room3_4,
    dungeons_room4_4,
    dungeons_room5_4,
    dungeons_room6_4,
    dungeons_room7_4,
    dungeons_room8_4,
    dungeons_room9_4,
    dungeons_room10_4,
    dungeons_room11_4
};


const uint8_t * const PROGMEM dungeons_row5[12] = {
    dungeons_room0_5,
    dungeons_room1_5,
    dungeons_room2_5,
    dungeons_room3_5,
    dungeons_room4_5,
    dungeons_room5_5,
    dungeons_room6_5,
    dungeons_room7_5,
    dungeons_room8_5,
    dungeons_room9_5,
    dungeons_room10_5,
    dungeons_room11_5
};


const uint8_t * const PROGMEM dungeons_row6[12] = {
    dungeons_room0_6,
    dungeons_room1_6,
    dungeons_room2_6,
    dungeons_room3_6,
    dungeons_room4_6,
    dungeons_room5_6,
    dungeons_room6_6,
    dungeons_room7_6,
    dungeons_room8_6,
    dungeons_room9_6,
    dungeons_room10_6,
    dungeons_room11_6
};


const uint8_t ** const PROGMEM dungeons_entities[7] = {
    dungeons_row0,
    dungeons_row1,
    dungeons_row2,
    dungeons_row3,
    dungeons_row4,
    dungeons_row5,
    dungeons_row6
};


#endif