#ifndef dungeons_h
#define dungeons_h


const uint8_t PROGMEM dungeons_map[593] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    81, 2, 10, 6,
    // room indices (16 bit, little endian), 120 bytes
    0, 0, 8, 0, 16, 0, 24, 0, 29, 0, 34, 0, 39, 0, 44, 0, 49, 0, 57, 0, 67, 0, 78, 0, 86, 0, 91, 0, 96, 0, 101, 0, 109, 0, 117, 0, 122, 0, 125, 0, 133, 0, 145, 0, 159, 0, 167, 0, 172, 0, 180, 0, 190, 0, 200, 0, 210, 0, 218, 0, 226, 0, 236, 0, 241, 0, 249, 0, 3, 1, 13, 1, 21, 1, 26, 1, 34, 1, 44, 1, 54, 1, 64, 1, 72, 1, 80, 1, 88, 1, 93, 1, 101, 1, 109, 1, 114, 1, 122, 1, 132, 1, 145, 1, 150, 1, 155, 1, 163, 1, 171, 1, 176, 1, 184, 1, 192, 1, 205, 1,
    // compressed room data, 469 bytes
    31, 109, 47, 96, 47, 96, 175, 99, 246, 219, 246, 14, 246, 14, 246, 14, 31, 109, 47, 96, 47, 96, 175, 99, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 247, 223, 240, 246, 0, 247, 223, 240, 246, 0, 246, 219, 246, 14, 246, 14, 246, 14, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 31, 93, 178, 245, 14, 47, 80, 234, 51, 3, 60, 47, 96, 47, 96, 47, 96, 47, 96, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 247, 223, 224, 247, 48, 246, 219, 246, 14, 246, 14, 246, 14, 47, 96, 47, 96, 47, 96, 47, 96, 255, 15, 96, 247, 48, 255, 15, 208, 246, 219, 246, 14, 246, 14, 246, 14, 29, 208, 221, 178, 245, 14, 47, 80, 234, 51, 3, 60, 32, 9, 0, 226, 8, 8, 14, 41, 0, 9, 234, 51, 3, 60, 31, 109, 47, 96, 47, 96, 47, 96, 247, 223, 224, 247, 48, 246, 219, 246, 14, 246, 14, 246, 14, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 47, 96, 47, 96, 47, 96, 47, 96, 246, 14, 246, 14, 246, 14, 246, 60, 29, 208, 221, 210, 246, 2, 246, 10, 246, 48, 247, 223, 240, 246, 0, 246, 14, 246, 14, 246, 14, 246, 14, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 47, 96, 47, 96, 47, 96, 47, 96, 247, 223, 224, 247, 48, 246, 14, 246, 14, 246, 14, 246, 60, 47, 80, 226, 245, 14, 47, 80, 226, 245, 14, 31, 93, 178, 245, 14, 47, 80, 226, 245, 14, 31, 93, 178, 245, 14, 47, 80, 234, 245, 60, 47, 96, 47, 96, 47, 96, 47, 96, 246, 14, 246, 14, 246, 14, 246, 14, 47, 96, 47, 96, 47, 96, 175, 99, 247, 223, 240, 246, 0, 246, 14, 246, 14, 246, 14, 246, 14, 31, 109, 47, 96, 47, 96, 175, 99, 247, 223, 240, 246, 0, 246, 14, 246, 14, 246, 14, 246, 14, 47, 80, 226, 245, 14, 47, 80, 234, 245, 60, 31, 109, 32, 9, 0, 2, 128, 0, 128, 163, 48, 51, 48, 255, 15, 96, 247, 48, 255, 15, 96, 247, 48, 246, 219, 246, 14, 246, 14, 246, 60, 47, 96, 47, 96, 47, 96, 175, 99, 255, 15, 96, 247, 48, 246, 219, 246, 14, 246, 14, 246, 60, 47, 96, 47, 96, 47, 96, 175, 99, 15, 89, 0, 152, 152, 144, 8, 152, 152, 3, 51, 3, 51, 246, 219, 246, 14, 246, 14, 246, 60
};

const uint8_t PROGMEM dungeons_room0_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room0_1[] = {
    1, // number of entities

    // entity 0, CHEST
    0xa6,
    39, //x
    22  //y
};



const uint8_t PROGMEM dungeons_room0_2[] = {
    2, // number of entities

    // entity 0, BLOB_MOTHER
    0xd,
    38, //x
    17, //y

    // entity 1, LOCK
    0x12,
    48, //x
    0  //y
};



const uint8_t PROGMEM dungeons_room0_3[] = {
    1, // number of entities

    // entity 0, LOCK
    0x12,
    49, //x
    4  //y
};



const uint8_t PROGMEM dungeons_room0_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room0_5[] = {
    1, // number of entities

    // entity 0, TELEPORTER
    0x10,
    50, //x
    53  //y
};



const uint8_t PROGMEM dungeons_room1_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room1_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room1_2[] = {
    1, // number of entities

    // entity 0, TELEPORTER
    0x30,
    48, //x
    54  //y
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
    1, // number of entities

    // entity 0, CHEST
    0x86,
    51, //x
    20  //y
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
    1, // number of entities

    // entity 0, CHEST
    0x26,
    78, //x
    8  //y
};



const uint8_t PROGMEM dungeons_room4_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room4_5[] = {
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
    1, // number of entities

    // entity 0, TELEPORTER
    0x50,
    48, //x
    53  //y
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

const uint8_t PROGMEM dungeons_teleporters[] = {
    // dest x, dest y (in rooms)
    4, 7,
    6, 0,
    4, 6,
};



const uint8_t PROGMEM dungeons_bumpers[] = {
    // width, height
};

const uint8_t * const PROGMEM dungeons_row0[10] = {
    dungeons_room0_0,
    dungeons_room1_0,
    dungeons_room2_0,
    dungeons_room3_0,
    dungeons_room4_0,
    dungeons_room5_0,
    dungeons_room6_0,
    dungeons_room7_0,
    dungeons_room8_0,
    dungeons_room9_0
};


const uint8_t * const PROGMEM dungeons_row1[10] = {
    dungeons_room0_1,
    dungeons_room1_1,
    dungeons_room2_1,
    dungeons_room3_1,
    dungeons_room4_1,
    dungeons_room5_1,
    dungeons_room6_1,
    dungeons_room7_1,
    dungeons_room8_1,
    dungeons_room9_1
};


const uint8_t * const PROGMEM dungeons_row2[10] = {
    dungeons_room0_2,
    dungeons_room1_2,
    dungeons_room2_2,
    dungeons_room3_2,
    dungeons_room4_2,
    dungeons_room5_2,
    dungeons_room6_2,
    dungeons_room7_2,
    dungeons_room8_2,
    dungeons_room9_2
};


const uint8_t * const PROGMEM dungeons_row3[10] = {
    dungeons_room0_3,
    dungeons_room1_3,
    dungeons_room2_3,
    dungeons_room3_3,
    dungeons_room4_3,
    dungeons_room5_3,
    dungeons_room6_3,
    dungeons_room7_3,
    dungeons_room8_3,
    dungeons_room9_3
};


const uint8_t * const PROGMEM dungeons_row4[10] = {
    dungeons_room0_4,
    dungeons_room1_4,
    dungeons_room2_4,
    dungeons_room3_4,
    dungeons_room4_4,
    dungeons_room5_4,
    dungeons_room6_4,
    dungeons_room7_4,
    dungeons_room8_4,
    dungeons_room9_4
};


const uint8_t * const PROGMEM dungeons_row5[10] = {
    dungeons_room0_5,
    dungeons_room1_5,
    dungeons_room2_5,
    dungeons_room3_5,
    dungeons_room4_5,
    dungeons_room5_5,
    dungeons_room6_5,
    dungeons_room7_5,
    dungeons_room8_5,
    dungeons_room9_5
};


const uint8_t ** const PROGMEM dungeons_entities[6] = {
    dungeons_row0,
    dungeons_row1,
    dungeons_row2,
    dungeons_row3,
    dungeons_row4,
    dungeons_row5
};


#endif