#ifndef overworld_h
#define overworld_h


const uint8_t PROGMEM overworld_map[538] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    26, 2, 7, 8,
    // room indices (16 bit, little endian), 112 bytes
    0, 0, 11, 0, 20, 0, 25, 0, 32, 0, 35, 0, 39, 0, 47, 0, 56, 0, 62, 0, 67, 0, 76, 0, 87, 0, 95, 0, 100, 0, 111, 0, 117, 0, 122, 0, 129, 0, 137, 0, 145, 0, 156, 0, 162, 0, 172, 0, 175, 0, 178, 0, 184, 0, 188, 0, 197, 0, 204, 0, 210, 0, 215, 0, 222, 0, 230, 0, 238, 0, 248, 0, 0, 1, 4, 1, 14, 1, 21, 1, 26, 1, 34, 1, 46, 1, 55, 1, 60, 1, 66, 1, 76, 1, 85, 1, 92, 1, 103, 1, 111, 1, 120, 1, 128, 1, 137, 1, 146, 1, 155, 1,
    // compressed room data, 422 bytes
    31, 109, 32, 68, 0, 2, 4, 64, 0, 47, 96, 214, 245, 208, 111, 96, 111, 96, 111, 80, 247, 223, 240, 246, 0, 221, 245, 64, 15, 84, 254, 0, 254, 79, 224, 254, 79, 208, 96, 251, 72, 121, 246, 12, 244, 100, 68, 47, 96, 102, 95, 70, 47, 96, 47, 96, 6, 245, 15, 118, 254, 0, 247, 15, 118, 253, 4, 247, 15, 118, 245, 6, 100, 244, 6, 96, 247, 6, 102, 244, 6, 102, 244, 6, 102, 244, 0, 246, 6, 246, 6, 246, 6, 246, 4, 251, 111, 228, 0, 64, 47, 96, 68, 244, 4, 68, 244, 4, 68, 245, 0, 247, 4, 246, 4, 253, 0, 246, 4, 255, 15, 96, 79, 64, 102, 245, 6, 111, 224, 102, 111, 64, 102, 111, 240, 0, 0, 246, 4, 246, 6, 246, 6, 247, 0, 244, 64, 4, 102, 244, 14, 102, 244, 14, 246, 14, 68, 245, 15, 244, 246, 64, 247, 4, 246, 4, 102, 101, 100, 79, 80, 64, 254, 15, 228, 254, 15, 228, 254, 4, 246, 4, 246, 0, 255, 15, 192, 64, 246, 14, 246, 14, 246, 14, 68, 15, 68, 247, 66, 246, 2, 246, 15, 116, 79, 80, 79, 224, 79, 96, 247, 79, 240, 15, 84, 247, 79, 80, 68, 245, 15, 148, 79, 96, 79, 96, 79, 96, 79, 96, 246, 4, 246, 4, 246, 4, 15, 100, 68, 15, 68, 246, 14, 246, 14, 244, 64, 68, 247, 66, 246, 2, 246, 2, 246, 0, 79, 240, 252, 0, 0, 245, 64, 15, 84, 0, 245, 64, 15, 84, 248, 79, 96, 79, 96, 247, 64, 79, 240, 245, 15, 116, 15, 100, 4, 246, 4, 245, 15, 116, 244, 64, 68, 0, 4, 4, 79, 80, 68, 64, 15, 68, 47, 96, 47, 96, 47, 96, 47, 80, 64, 255, 15, 96, 79, 96, 0, 245, 79, 240, 245, 4, 247, 79, 80, 68, 245, 4, 68, 244, 4, 64, 72, 121, 244, 79, 96, 79, 96, 247, 64, 247, 79, 224, 64, 0, 68, 64, 64, 15, 84, 0, 245, 64, 15, 84, 0, 244, 64, 47, 80, 79, 118, 47, 80, 79, 118, 79, 96, 102, 245, 4, 111, 80, 247, 96, 246, 4, 246, 4, 246, 4, 247, 96, 79, 64, 68, 79, 96, 79, 96, 247, 96, 68, 72, 121, 79, 96, 79, 96, 79, 118, 64, 0, 244, 79, 96, 79, 96, 247, 96, 64, 15, 68, 0, 15, 68, 0, 15, 68, 247, 96
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
    0 // number of entities
};



const uint8_t PROGMEM overworld_room0_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room0_5[] = {
    2, // number of entities

    // entity 0, CHEST
    0x26,
    54, //x
    32, //y

    // entity 1, BLOB
    0x7,
    20, //x
    36  //y
};



const uint8_t PROGMEM overworld_room0_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room0_7[] = {
    2, // number of entities

    // entity 0, BLOB
    0x7,
    22, //x
    7, //y

    // entity 1, CHEST
    0x26,
    22, //x
    34  //y
};



const uint8_t PROGMEM overworld_room1_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room1_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room1_2[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room1_3[] = {
    1, // number of entities

    // entity 0, LOCK
    0x12,
    66, //x
    44  //y
};



const uint8_t PROGMEM overworld_room1_4[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room1_5[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room1_6[] = {
    2, // number of entities

    // entity 0, BLOB
    0x7,
    23, //x
    35, //y

    // entity 1, BLOB
    0x7,
    40, //x
    46  //y
};



const uint8_t PROGMEM overworld_room1_7[] = {
    1, // number of entities

    // entity 0, CHEST
    0x86,
    74, //x
    20  //y
};



const uint8_t PROGMEM overworld_room2_0[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room2_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room2_2[] = {
    1, // number of entities

    // entity 0, CHEST
    0x46,
    24, //x
    17  //y
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
    1, // number of entities

    // entity 0, OLD_MAN
    0x15,
    94, //x
    10  //y
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
    1, // number of entities

    // entity 0, CHEST
    0x6,
    50, //x
    19  //y
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
    1, // number of entities

    // entity 0, TELEPORTER
    0x30,
    31, //x
    5  //y
};



const uint8_t PROGMEM overworld_room4_7[] = {
    1, // number of entities

    // entity 0, TELEPORTER
    0x50,
    63, //x
    7  //y
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
    1, // number of entities

    // entity 0, SECRET_WALL
    0x77,
    48, //x
    1  //y
};



const uint8_t PROGMEM overworld_room5_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room5_7[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room6_0[] = {
    1, // number of entities

    // entity 0, TELEPORTER
    0x10,
    77, //x
    23  //y
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

const uint8_t PROGMEM overworld_teleporters[] = {
    // dest x, dest y (in rooms)
    1, 2,
    8, 5,
    0, 5,
    0, 5,
};



const uint8_t PROGMEM overworld_bumpers[] = {
    // width, height
};

const uint8_t * const PROGMEM overworld_row0[7] = {
    overworld_room0_0,
    overworld_room1_0,
    overworld_room2_0,
    overworld_room3_0,
    overworld_room4_0,
    overworld_room5_0,
    overworld_room6_0
};


const uint8_t * const PROGMEM overworld_row1[7] = {
    overworld_room0_1,
    overworld_room1_1,
    overworld_room2_1,
    overworld_room3_1,
    overworld_room4_1,
    overworld_room5_1,
    overworld_room6_1
};


const uint8_t * const PROGMEM overworld_row2[7] = {
    overworld_room0_2,
    overworld_room1_2,
    overworld_room2_2,
    overworld_room3_2,
    overworld_room4_2,
    overworld_room5_2,
    overworld_room6_2
};


const uint8_t * const PROGMEM overworld_row3[7] = {
    overworld_room0_3,
    overworld_room1_3,
    overworld_room2_3,
    overworld_room3_3,
    overworld_room4_3,
    overworld_room5_3,
    overworld_room6_3
};


const uint8_t * const PROGMEM overworld_row4[7] = {
    overworld_room0_4,
    overworld_room1_4,
    overworld_room2_4,
    overworld_room3_4,
    overworld_room4_4,
    overworld_room5_4,
    overworld_room6_4
};


const uint8_t * const PROGMEM overworld_row5[7] = {
    overworld_room0_5,
    overworld_room1_5,
    overworld_room2_5,
    overworld_room3_5,
    overworld_room4_5,
    overworld_room5_5,
    overworld_room6_5
};


const uint8_t * const PROGMEM overworld_row6[7] = {
    overworld_room0_6,
    overworld_room1_6,
    overworld_room2_6,
    overworld_room3_6,
    overworld_room4_6,
    overworld_room5_6,
    overworld_room6_6
};


const uint8_t * const PROGMEM overworld_row7[7] = {
    overworld_room0_7,
    overworld_room1_7,
    overworld_room2_7,
    overworld_room3_7,
    overworld_room4_7,
    overworld_room5_7,
    overworld_room6_7
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