#ifndef dungeons_h
#define dungeons_h


const uint8_t PROGMEM dungeons_map[2068] = {
    // array length (16 bit, little endian), map width, map height (in rooms), tile size (in pixels)
    20, 8, 8, 12, 8,
    // room indices (16 bit, little endian), 192 bytes
    0, 0, 32, 0, 51, 0, 66, 0, 83, 0, 96, 0, 108, 0, 120, 0, 145, 0, 164, 0, 176, 0, 190, 0, 206, 0, 238, 0, 254, 0, 17, 1, 38, 1, 55, 1, 71, 1, 89, 1, 101, 1, 121, 1, 138, 1, 150, 1, 172, 1, 190, 1, 207, 1, 221, 1, 236, 1, 250, 1, 10, 2, 31, 2, 44, 2, 64, 2, 79, 2, 91, 2, 110, 2, 122, 2, 134, 2, 154, 2, 166, 2, 185, 2, 202, 2, 214, 2, 229, 2, 246, 2, 6, 3, 21, 3, 38, 3, 56, 3, 75, 3, 89, 3, 105, 3, 132, 3, 147, 3, 166, 3, 185, 3, 211, 3, 231, 3, 250, 3, 27, 4, 39, 4, 51, 4, 78, 4, 104, 4, 130, 4, 147, 4, 165, 4, 180, 4, 192, 4, 204, 4, 240, 4, 10, 5, 29, 5, 41, 5, 53, 5, 70, 5, 87, 5, 101, 5, 127, 5, 152, 5, 181, 5, 208, 5, 232, 5, 11, 6, 36, 6, 75, 6, 114, 6, 152, 6, 179, 6, 205, 6, 233, 6, 249, 6, 22, 7, 37, 7, 53, 7,
    // compressed room data, 1871 bytes
    31, 199, 53, 244, 9, 0, 159, 64, 133, 252, 8, 80, 159, 128, 144, 133, 0, 159, 96, 144, 8, 80, 0, 246, 144, 0, 133, 252, 8, 47, 198, 64, 255, 15, 240, 251, 9, 251, 9, 153, 250, 9, 159, 160, 153, 252, 15, 89, 253, 9, 144, 255, 15, 208, 250, 159, 208, 245, 159, 240, 255, 15, 192, 251, 144, 0, 255, 15, 240, 252, 9, 253, 15, 89, 253, 15, 73, 253, 15, 89, 253, 9, 153, 255, 15, 240, 255, 15, 240, 255, 15, 240, 248, 9, 253, 0, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 255, 15, 64, 248, 159, 80, 153, 247, 9, 244, 9, 248, 9, 244, 9, 248, 9, 244, 9, 253, 9, 252, 9, 159, 144, 255, 0, 0, 153, 252, 9, 252, 9, 159, 192, 159, 208, 153, 253, 9, 253, 9, 159, 128, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 251, 9, 153, 255, 15, 240, 255, 15, 240, 255, 15, 240, 248, 0, 153, 159, 224, 246, 159, 224, 153, 159, 224, 153, 255, 15, 240, 255, 15, 176, 15, 73, 253, 15, 73, 253, 9, 153, 244, 9, 248, 9, 159, 64, 153, 247, 9, 246, 9, 159, 80, 153, 247, 9, 159, 64, 159, 128, 153, 0, 153, 0, 255, 15, 240, 255, 15, 240, 249, 9, 252, 9, 159, 176, 153, 252, 9, 0, 255, 15, 176, 153, 247, 15, 89, 244, 15, 105, 246, 9, 153, 255, 15, 240, 255, 15, 128, 0, 153, 250, 9, 159, 176, 159, 208, 159, 208, 159, 192, 153, 251, 9, 159, 192, 159, 192, 144, 0, 245, 9, 153, 253, 15, 73, 253, 15, 73, 253, 9, 255, 15, 240, 255, 15, 176, 255, 15, 240, 252, 9, 159, 208, 153, 253, 9, 159, 208, 159, 208, 159, 160, 255, 15, 144, 244, 159, 160, 159, 208, 159, 208, 153, 253, 9, 253, 9, 254, 9, 0, 254, 15, 233, 255, 15, 240, 255, 15, 240, 255, 15, 144, 247, 15, 73, 0, 15, 169, 253, 9, 253, 9, 159, 208, 159, 208, 159, 224, 159, 208, 153, 0, 251, 9, 253, 9, 159, 208, 159, 208, 159, 224, 159, 208, 159, 208, 159, 208, 144, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 249, 9, 159, 176, 153, 251, 9, 159, 176, 153, 251, 9, 159, 160, 153, 251, 9, 159, 176, 153, 251, 0, 255, 15, 240, 255, 15, 240, 255, 15, 112, 153, 250, 9, 153, 249, 9, 153, 0, 0, 0, 9, 253, 9, 253, 9, 252, 9, 159, 160, 153, 255, 15, 240, 255, 15, 144, 252, 9, 159, 208, 159, 208, 159, 240, 255, 15, 240, 255, 15, 160, 255, 15, 208, 159, 208, 159, 208, 159, 224, 159, 208, 159, 224, 159, 176, 252, 9, 253, 9, 159, 208, 159, 240, 255, 15, 240, 255, 15, 160, 253, 9, 252, 9, 153, 249, 9, 153, 15, 185, 255, 15, 240, 255, 15, 224, 253, 9, 252, 9, 159, 176, 153, 251, 9, 159, 176, 153, 250, 9, 159, 176, 153, 251, 9, 159, 112, 159, 240, 255, 15, 240, 255, 15, 240, 255, 15, 240, 246, 0, 247, 9, 159, 176, 153, 251, 9, 159, 192, 159, 192, 153, 252, 9, 253, 9, 253, 9, 249, 0, 255, 15, 240, 254, 10, 253, 10, 253, 10, 253, 10, 253, 10, 251, 0, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 0, 159, 224, 159, 208, 153, 253, 9, 254, 9, 253, 9, 159, 208, 153, 254, 9, 159, 64, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 244, 9, 159, 176, 153, 252, 9, 253, 9, 253, 9, 253, 9, 254, 9, 159, 208, 153, 159, 96, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 244, 9, 253, 9, 254, 9, 253, 9, 253, 9, 159, 208, 159, 208, 159, 208, 153, 246, 0, 0, 175, 208, 175, 208, 175, 208, 175, 208, 175, 208, 175, 208, 175, 208, 175, 176, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 250, 9, 153, 253, 9, 159, 240, 255, 15, 240, 255, 15, 240, 249, 0, 254, 9, 159, 208, 244, 159, 224, 244, 159, 208, 244, 159, 224, 153, 255, 15, 208, 255, 15, 240, 255, 15, 240, 250, 9, 159, 224, 244, 159, 224, 244, 159, 64, 247, 15, 73, 254, 9, 153, 255, 15, 240, 255, 15, 240, 255, 15, 144, 255, 15, 208, 153, 254, 9, 159, 208, 153, 253, 9, 159, 208, 159, 224, 159, 112, 247, 9, 253, 9, 253, 9, 159, 208, 159, 208, 159, 224, 159, 208, 159, 208, 159, 64, 0, 175, 208, 175, 192, 175, 208, 175, 208, 175, 208, 175, 192, 170, 252, 10, 250, 9, 153, 255, 15, 240, 255, 15, 240, 255, 15, 240, 248, 9, 153, 251, 0, 255, 15, 240, 255, 15, 240, 255, 15, 112, 153, 0, 251, 144, 9, 159, 176, 255, 15, 240, 9, 153, 244, 10, 0, 160, 153, 144, 153, 247, 9, 159, 64, 153, 246, 9, 246, 9, 253, 9, 252, 9, 159, 96, 249, 15, 89, 253, 9, 255, 10, 255, 15, 240, 255, 10, 255, 15, 112, 254, 15, 73, 253, 15, 73, 253, 15, 73, 253, 9, 153, 253, 9, 159, 208, 159, 208, 153, 246, 9, 253, 9, 159, 208, 159, 208, 159, 208, 159, 208, 159, 208, 153, 253, 9, 245, 0, 249, 9, 253, 9, 0, 10, 249, 9, 0, 10, 249, 9, 0, 170, 250, 9, 10, 251, 9, 170, 251, 9, 175, 192, 160, 0, 175, 144, 153, 0, 175, 144, 159, 208, 159, 208, 159, 208, 159, 208, 159, 208, 159, 208, 144, 0, 0, 153, 159, 224, 159, 224, 159, 224, 159, 224, 159, 208, 153, 253, 9, 253, 9, 244, 0, 9, 251, 9, 9, 248, 15, 73, 9, 248, 9, 144, 0, 153, 248, 9, 144, 0, 159, 144, 144, 0, 153, 248, 9, 244, 9, 159, 96, 153, 245, 15, 137, 0, 247, 159, 240, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 253, 9, 253, 9, 253, 9, 255, 15, 96, 244, 160, 9, 244, 10, 170, 244, 10, 170, 0, 10, 175, 128, 160, 0, 175, 128, 153, 248, 9, 253, 9, 245, 9, 247, 9, 245, 9, 247, 9, 253, 9, 253, 9, 245, 10, 247, 9, 246, 10, 175, 80, 159, 80, 249, 10, 169, 251, 10, 9, 159, 144, 170, 0, 153, 248, 10, 244, 9, 247, 10, 175, 192, 175, 208, 175, 192, 170, 246, 0, 249, 9, 253, 9, 251, 9, 153, 244, 15, 137, 255, 15, 240, 255, 15, 240, 0, 249, 9, 253, 9, 159, 208, 159, 208, 159, 208, 153, 253, 9, 153, 253, 9, 254, 0, 255, 15, 240, 255, 15, 240, 255, 15, 144, 153, 159, 208, 153, 159, 144, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 0, 10, 175, 112, 159, 80, 170, 245, 9, 159, 96, 170, 160, 9, 159, 160, 170, 175, 176, 153, 170, 248, 9, 153, 0, 170, 245, 9, 153, 245, 10, 15, 89, 247, 10, 0, 0, 175, 80, 159, 112, 170, 0, 9, 159, 128, 160, 0, 159, 144, 160, 0, 159, 144, 175, 208, 175, 208, 175, 208, 175, 160, 246, 10, 253, 10, 252, 10, 175, 192, 175, 192, 170, 252, 10, 253, 10, 253, 10, 249, 0, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 244, 15, 73, 254, 15, 105, 255, 15, 240, 255, 15, 240, 255, 0, 246, 160, 0, 254, 9, 153, 244, 15, 121, 0, 245, 159, 240, 255, 15, 240, 255, 15, 240, 0, 244, 15, 233, 255, 15, 240, 255, 15, 240, 255, 15, 240, 244, 0, 252, 10, 253, 10, 253, 10, 253, 10, 249, 10, 160, 10, 249, 10, 160, 10, 248, 10, 170, 0, 175, 112, 170, 160, 0, 160, 0, 10, 253, 10, 253, 10, 253, 10, 253, 10, 253, 10, 0, 10, 170, 248, 10, 244, 10, 175, 112, 175, 80, 160, 0, 244, 10, 253, 10, 253, 10, 253, 10, 253, 10, 246, 10, 170, 244, 10, 246, 10, 10, 245, 10, 245, 10, 10, 245, 10, 175, 64, 160, 160, 255, 15, 64, 249, 175, 96, 160, 0, 175, 144, 175, 64, 175, 144, 170, 0, 10, 175, 128, 170, 160, 10, 251, 10, 170, 254, 0, 254, 15, 106, 255, 15, 96, 175, 192, 170, 251, 10, 160, 175, 160, 160, 10, 175, 144, 160, 0, 249, 160, 170, 0, 0, 244, 175, 80, 160, 10, 170, 248, 10, 0, 175, 144, 170, 249, 15, 122, 245, 10, 160, 10, 0, 10, 244, 10, 160, 10, 248, 10, 160, 170, 175, 128, 244, 175, 112, 255, 15, 240, 251, 10, 252, 10, 170, 249, 15, 90, 248, 15, 74, 10, 247, 10, 10, 0, 10, 245, 15, 74, 244, 0, 10, 160, 170, 248, 15, 74, 10, 248, 10, 170, 10, 249, 10, 0, 175, 192, 175, 64, 170, 246, 10, 0, 10, 160, 175, 96, 160, 10, 160, 10, 0, 10, 170, 0, 175, 64, 160, 244, 160, 246, 10, 170, 0, 10, 247, 10, 175, 64, 175, 112, 170, 244, 10, 247, 10, 175, 64, 175, 96, 170, 0, 245, 175, 64, 170, 160, 170, 0, 170, 0, 170, 160, 170, 245, 15, 122, 247, 10, 244, 10, 245, 10, 247, 10, 245, 10, 175, 96, 170, 245, 10, 247, 10, 245, 10, 0, 175, 64, 175, 80, 160, 10, 244, 10, 0, 10, 170, 247, 15, 90, 10, 250, 10, 160, 160, 0, 246, 10, 244, 10, 248, 10, 160, 0, 175, 144, 170, 0, 175, 160, 160, 10, 250, 10, 160, 175, 176, 170, 175, 192, 170, 255, 0, 175, 208, 170, 253, 10, 175, 128, 170, 160, 10, 175, 96, 170, 245, 10, 170, 0, 10, 175, 144, 170, 175, 240, 255, 0, 0, 0, 170, 246, 15, 74, 0, 10, 175, 128, 175, 64, 175, 112, 245, 160, 175, 112, 160, 0, 170, 175, 112, 170, 255, 15, 240, 252, 0, 244, 175, 160, 170, 252, 10, 253, 10, 253, 10, 255, 15, 240, 255, 15, 160, 10, 0, 10, 170, 245, 10, 10, 10, 170, 246, 10, 0, 160, 175, 128, 170, 10, 175, 128, 160, 0, 170, 247, 10, 175, 240, 255, 15, 224, 10, 175, 80, 248, 175, 240, 255, 15, 240, 255, 15, 240, 255, 15, 96, 0, 10, 175, 128, 175, 208, 175, 240, 255, 15, 240, 250, 10, 255, 15, 208, 247, 10, 160, 170, 249, 10, 0, 175, 160, 160, 10, 249, 10, 160, 170, 247, 15, 106, 244, 15, 138, 255, 15, 240, 244, 0
};

const uint8_t PROGMEM dungeons_room0_0[] = {
    1, // number of entities

    // entity 0, BLOB
    1,
    56, //x
    26  //y
};



const uint8_t PROGMEM dungeons_room0_1[] = {
    0 // number of entities
};



const uint8_t PROGMEM dungeons_room0_2[] = {
    0 // number of entities
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