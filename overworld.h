#ifndef overworld_h
#define overworld_h


const uint8_t PROGMEM overworld_map[604] = {
    // array length (16 bit, little endian), map width, map height (in rooms), tile size (in pixels)
    92, 2, 8, 8, 16,
    // room indices (16 bit, little endian), 128 bytes
    0, 0, 8, 0, 17, 0, 22, 0, 30, 0, 33, 0, 36, 0, 45, 0, 53, 0, 61, 0, 67, 0, 72, 0, 81, 0, 92, 0, 96, 0, 106, 0, 113, 0, 124, 0, 130, 0, 135, 0, 142, 0, 150, 0, 155, 0, 166, 0, 174, 0, 180, 0, 190, 0, 193, 0, 196, 0, 202, 0, 206, 0, 211, 0, 220, 0, 229, 0, 235, 0, 240, 0, 247, 0, 255, 0, 7, 1, 15, 1, 24, 1, 32, 1, 36, 1, 46, 1, 53, 1, 58, 1, 66, 1, 72, 1, 82, 1, 91, 1, 96, 1, 102, 1, 112, 1, 119, 1, 126, 1, 133, 1, 144, 1, 153, 1, 163, 1, 171, 1, 180, 1, 189, 1, 198, 1, 203, 1,
    // compressed room data, 471 bytes
    31, 107, 47, 96, 47, 96, 47, 96, 182, 245, 176, 111, 96, 111, 96, 111, 80, 247, 191, 240, 246, 0, 187, 245, 64, 4, 68, 4, 254, 0, 254, 79, 224, 254, 79, 224, 244, 70, 246, 70, 68, 244, 6, 249, 0, 252, 71, 79, 96, 207, 64, 68, 64, 47, 96, 247, 98, 246, 2, 246, 0, 6, 245, 15, 118, 254, 0, 247, 15, 118, 253, 4, 247, 15, 118, 245, 6, 100, 244, 6, 96, 247, 6, 102, 244, 6, 102, 244, 6, 102, 244, 0, 255, 15, 192, 64, 244, 6, 246, 6, 244, 4, 70, 246, 70, 68, 244, 4, 68, 244, 15, 244, 68, 47, 96, 68, 244, 4, 68, 244, 4, 68, 245, 0, 247, 4, 246, 4, 253, 0, 246, 4, 255, 15, 96, 79, 64, 102, 245, 6, 111, 224, 102, 111, 64, 102, 111, 240, 0, 0, 246, 4, 255, 15, 96, 244, 70, 68, 0, 6, 102, 244, 6, 102, 248, 0, 247, 79, 96, 207, 96, 207, 96, 192, 68, 245, 15, 244, 246, 64, 247, 4, 246, 4, 102, 96, 100, 79, 80, 64, 254, 15, 228, 254, 15, 228, 254, 4, 246, 4, 246, 0, 255, 15, 192, 64, 255, 15, 96, 247, 64, 246, 12, 246, 12, 246, 12, 68, 15, 68, 68, 127, 68, 47, 96, 47, 96, 247, 64, 79, 80, 79, 224, 79, 96, 247, 79, 240, 15, 84, 247, 79, 80, 68, 245, 15, 148, 79, 96, 79, 96, 79, 96, 79, 96, 246, 4, 246, 4, 246, 4, 15, 100, 248, 79, 96, 79, 96, 79, 80, 64, 68, 15, 68, 246, 12, 246, 12, 247, 64, 247, 66, 246, 2, 246, 2, 246, 0, 79, 240, 252, 0, 0, 245, 64, 15, 84, 0, 245, 64, 15, 84, 248, 79, 96, 79, 96, 247, 64, 79, 240, 245, 15, 116, 15, 100, 4, 246, 4, 245, 15, 116, 79, 80, 79, 224, 247, 64, 247, 64, 0, 244, 64, 0, 245, 64, 15, 68, 47, 96, 47, 96, 47, 96, 47, 80, 64, 255, 15, 96, 79, 96, 0, 245, 79, 240, 245, 4, 247, 79, 80, 68, 245, 4, 68, 244, 4, 64, 248, 79, 96, 79, 96, 247, 64, 247, 79, 224, 64, 0, 68, 64, 247, 79, 96, 79, 96, 248, 64, 64, 15, 84, 0, 245, 64, 15, 84, 0, 244, 64, 47, 80, 79, 118, 47, 80, 72, 245, 52, 79, 96, 102, 245, 4, 111, 80, 70, 245, 48, 246, 4, 246, 4, 246, 4, 246, 52, 79, 64, 68, 79, 96, 79, 96, 79, 99, 244, 71, 68, 246, 4, 246, 4, 246, 52, 64, 0, 244, 79, 96, 79, 96, 79, 99, 247, 79, 224, 247, 48, 64, 15, 68, 0, 15, 68, 0, 15, 68, 51, 63, 68
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
    1, // number of entities

    // entity 0, TELEPORTER
    0x32,
    31, //x
    6  //y
};



const uint8_t PROGMEM overworld_room0_5[] = {
    1, // number of entities

    // entity 0, CHEST
    0x27,
    54, //x
    32  //y
};



const uint8_t PROGMEM overworld_room0_6[] = {
    0 // number of entities
};



const uint8_t PROGMEM overworld_room0_7[] = {
    0 // number of entities
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
    1, // number of entities

    // entity 0, OLD_MAN
    0x17,
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
    0x7,
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
    0 // number of entities
};



const uint8_t PROGMEM overworld_room4_7[] = {
    1, // number of entities

    // entity 0, TELEPORTER
    0x52,
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
    1, // number of entities

    // entity 0, TELEPORTER
    0x12,
    78, //x
    23  //y
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

const uint8_t PROGMEM overworld_teleporters[] = {
    // dest x, dest y (in rooms)
    5, 6,
    11, 6,
    0, 3,
};



const uint8_t PROGMEM overworld_bumpers[] = {
    // width, height
};

const uint8_t * const PROGMEM overworld_row0[8] = {
    overworld_room0_0,
    overworld_room1_0,
    overworld_room2_0,
    overworld_room3_0,
    overworld_room4_0,
    overworld_room5_0,
    overworld_room6_0,
    overworld_room7_0
};


const uint8_t * const PROGMEM overworld_row1[8] = {
    overworld_room0_1,
    overworld_room1_1,
    overworld_room2_1,
    overworld_room3_1,
    overworld_room4_1,
    overworld_room5_1,
    overworld_room6_1,
    overworld_room7_1
};


const uint8_t * const PROGMEM overworld_row2[8] = {
    overworld_room0_2,
    overworld_room1_2,
    overworld_room2_2,
    overworld_room3_2,
    overworld_room4_2,
    overworld_room5_2,
    overworld_room6_2,
    overworld_room7_2
};


const uint8_t * const PROGMEM overworld_row3[8] = {
    overworld_room0_3,
    overworld_room1_3,
    overworld_room2_3,
    overworld_room3_3,
    overworld_room4_3,
    overworld_room5_3,
    overworld_room6_3,
    overworld_room7_3
};


const uint8_t * const PROGMEM overworld_row4[8] = {
    overworld_room0_4,
    overworld_room1_4,
    overworld_room2_4,
    overworld_room3_4,
    overworld_room4_4,
    overworld_room5_4,
    overworld_room6_4,
    overworld_room7_4
};


const uint8_t * const PROGMEM overworld_row5[8] = {
    overworld_room0_5,
    overworld_room1_5,
    overworld_room2_5,
    overworld_room3_5,
    overworld_room4_5,
    overworld_room5_5,
    overworld_room6_5,
    overworld_room7_5
};


const uint8_t * const PROGMEM overworld_row6[8] = {
    overworld_room0_6,
    overworld_room1_6,
    overworld_room2_6,
    overworld_room3_6,
    overworld_room4_6,
    overworld_room5_6,
    overworld_room6_6,
    overworld_room7_6
};


const uint8_t * const PROGMEM overworld_row7[8] = {
    overworld_room0_7,
    overworld_room1_7,
    overworld_room2_7,
    overworld_room3_7,
    overworld_room4_7,
    overworld_room5_7,
    overworld_room6_7,
    overworld_room7_7
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