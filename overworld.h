#ifndef overworld_h
#define overworld_h


const uint8_t PROGMEM overworld_map[2614] = {
    // array length (16 bit, little endian), map width, map height (in rooms), tile size (in pixels)
    54, 10, 12, 8, 8,
    // room indices (16 bit, little endian), 192 bytes
    0, 0, 33, 0, 55, 0, 95, 0, 122, 0, 140, 0, 162, 0, 191, 0, 206, 0, 223, 0, 238, 0, 255, 0, 33, 1, 67, 1, 92, 1, 129, 1, 157, 1, 173, 1, 188, 1, 206, 1, 239, 1, 10, 2, 41, 2, 55, 2, 98, 2, 120, 2, 140, 2, 174, 2, 204, 2, 228, 2, 248, 2, 10, 3, 33, 3, 75, 3, 101, 3, 121, 3, 151, 3, 185, 3, 215, 3, 250, 3, 32, 4, 44, 4, 73, 4, 95, 4, 111, 4, 132, 4, 163, 4, 203, 4, 216, 4, 244, 4, 0, 5, 19, 5, 37, 5, 55, 5, 104, 5, 126, 5, 142, 5, 163, 5, 175, 5, 191, 5, 209, 5, 249, 5, 28, 6, 59, 6, 85, 6, 105, 6, 151, 6, 165, 6, 188, 6, 214, 6, 226, 6, 238, 6, 12, 7, 35, 7, 54, 7, 81, 7, 102, 7, 121, 7, 157, 7, 194, 7, 229, 7, 3, 8, 23, 8, 43, 8, 85, 8, 108, 8, 145, 8, 177, 8, 198, 8, 219, 8, 231, 8, 251, 8, 24, 9, 43, 9, 64, 9, 84, 9,
    // compressed room data, 2417 bytes
    143, 208, 160, 17, 250, 8, 32, 1, 2, 7, 111, 64, 143, 112, 84, 244, 8, 128, 47, 64, 63, 80, 136, 246, 2, 63, 64, 168, 252, 8, 175, 160, 48, 252, 2, 47, 112, 47, 224, 16, 0, 32, 47, 240, 249, 2, 0, 2, 47, 240, 244, 1, 255, 15, 64, 47, 176, 34, 249, 1, 0, 2, 0, 31, 160, 32, 1, 0, 2, 34, 244, 2, 0, 170, 0, 47, 96, 32, 42, 160, 2, 244, 7, 111, 64, 160, 2, 244, 5, 79, 112, 32, 1, 244, 0, 34, 252, 2, 47, 64, 47, 112, 47, 64, 249, 18, 244, 1, 248, 2, 244, 1, 253, 1, 253, 1, 47, 192, 17, 34, 47, 64, 255, 15, 208, 17, 253, 15, 65, 254, 1, 17, 253, 15, 65, 253, 15, 65, 254, 0, 249, 1, 31, 192, 245, 31, 192, 17, 255, 15, 240, 252, 1, 17, 247, 15, 65, 0, 15, 113, 244, 0, 254, 15, 65, 250, 1, 0, 15, 145, 0, 17, 31, 144, 31, 64, 17, 15, 113, 0, 247, 31, 80, 17, 31, 80, 17, 254, 1, 16, 0, 255, 15, 240, 252, 15, 241, 31, 128, 244, 31, 240, 255, 15, 160, 17, 255, 15, 240, 252, 15, 145, 245, 1, 31, 112, 247, 31, 192, 31, 240, 252, 0, 255, 15, 240, 255, 15, 144, 170, 247, 31, 224, 247, 31, 240, 253, 0, 255, 15, 192, 160, 15, 250, 255, 15, 240, 249, 15, 97, 253, 15, 97, 0, 0, 244, 10, 161, 246, 160, 255, 170, 170, 15, 122, 26, 0, 246, 160, 245, 160, 246, 160, 245, 160, 15, 90, 15, 122, 15, 74, 0, 247, 160, 160, 1, 15, 122, 0, 138, 252, 8, 130, 251, 10, 247, 2, 244, 1, 143, 96, 63, 80, 26, 2, 249, 1, 8, 169, 0, 31, 128, 136, 170, 154, 160, 47, 80, 143, 106, 245, 10, 160, 0, 1, 255, 0, 0, 63, 80, 244, 31, 64, 47, 240, 245, 2, 255, 0, 0, 48, 63, 208, 35, 42, 163, 254, 160, 1, 244, 2, 47, 64, 31, 128, 34, 0, 1, 0, 32, 159, 64, 34, 247, 8, 1, 251, 8, 247, 7, 96, 51, 249, 5, 64, 48, 8, 245, 1, 247, 9, 246, 7, 96, 112, 246, 1, 0, 245, 47, 96, 17, 246, 7, 111, 80, 17, 31, 64, 84, 247, 1, 31, 224, 17, 31, 240, 31, 192, 96, 10, 250, 0, 255, 15, 240, 255, 15, 240, 250, 15, 65, 253, 15, 97, 253, 1, 245, 0, 255, 15, 240, 255, 15, 240, 255, 15, 240, 246, 1, 31, 160, 17, 16, 252, 1, 31, 240, 255, 15, 240, 252, 15, 81, 248, 1, 244, 1, 31, 208, 31, 112, 251, 1, 16, 17, 249, 1, 0, 1, 17, 245, 1, 31, 96, 244, 16, 17, 250, 1, 17, 252, 1, 17, 249, 1, 16, 15, 81, 245, 1, 0, 15, 65, 0, 255, 15, 112, 17, 31, 144, 245, 31, 112, 17, 0, 1, 246, 1, 31, 64, 31, 80, 17, 246, 1, 253, 1, 252, 1, 246, 0, 251, 1, 31, 160, 244, 31, 144, 16, 1, 248, 1, 16, 0, 31, 96, 17, 245, 1, 245, 1, 247, 1, 244, 1, 248, 1, 0, 17, 249, 1, 0, 251, 1, 17, 255, 15, 240, 255, 15, 240, 255, 15, 240, 248, 0, 26, 0, 16, 244, 160, 170, 0, 170, 17, 31, 138, 0, 244, 175, 65, 170, 244, 10, 161, 245, 10, 175, 64, 170, 175, 96, 175, 96, 170, 245, 10, 246, 1, 10, 244, 10, 175, 80, 16, 10, 244, 10, 0, 249, 15, 83, 244, 1, 248, 3, 255, 15, 64, 51, 245, 3, 63, 240, 0, 31, 240, 255, 15, 112, 16, 245, 63, 144, 246, 63, 144, 245, 63, 128, 63, 240, 244, 1, 255, 15, 240, 249, 3, 63, 128, 244, 47, 96, 84, 5, 0, 34, 0, 31, 80, 118, 16, 34, 245, 1, 16, 84, 0, 47, 160, 160, 15, 66, 251, 1, 2, 253, 2, 47, 160, 245, 47, 80, 16, 64, 170, 250, 7, 106, 160, 10, 247, 5, 79, 90, 247, 15, 90, 251, 10, 170, 251, 10, 175, 144, 32, 10, 244, 15, 114, 247, 2, 245, 2, 248, 1, 253, 1, 252, 1, 253, 1, 252, 1, 31, 192, 31, 96, 31, 96, 16, 0, 17, 31, 96, 245, 31, 64, 248, 1, 17, 250, 1, 251, 1, 31, 160, 17, 250, 1, 31, 176, 17, 255, 15, 240, 250, 0, 247, 1, 254, 1, 253, 1, 254, 1, 253, 1, 31, 208, 31, 208, 17, 253, 1, 0, 244, 1, 0, 17, 0, 1, 16, 0, 16, 17, 249, 1, 17, 251, 1, 255, 15, 240, 255, 15, 240, 247, 0, 31, 80, 31, 96, 16, 31, 64, 31, 64, 17, 0, 15, 65, 244, 1, 247, 1, 16, 0, 31, 144, 244, 31, 64, 31, 64, 16, 16, 17, 0, 17, 244, 1, 17, 0, 244, 31, 80, 31, 96, 17, 0, 251, 1, 253, 1, 244, 15, 161, 0, 17, 248, 1, 17, 1, 249, 1, 1, 31, 160, 16, 1, 249, 1, 253, 1, 244, 0, 255, 15, 240, 255, 15, 240, 250, 1, 250, 15, 65, 248, 1, 31, 64, 31, 64, 17, 31, 80, 244, 1, 0, 10, 170, 10, 245, 1, 245, 15, 74, 244, 1, 248, 10, 0, 1, 253, 1, 250, 1, 1, 31, 160, 16, 31, 176, 17, 252, 0, 249, 1, 255, 15, 64, 32, 32, 34, 47, 112, 32, 32, 2, 248, 2, 34, 0, 47, 128, 32, 32, 2, 0, 1, 16, 0, 16, 32, 34, 47, 96, 17, 252, 0, 249, 7, 111, 192, 84, 1, 245, 1, 252, 7, 111, 192, 84, 245, 1, 247, 7, 111, 64, 118, 246, 5, 71, 96, 5, 79, 128, 84, 246, 0, 245, 15, 98, 250, 2, 47, 144, 245, 32, 118, 118, 118, 244, 2, 34, 5, 69, 69, 64, 16, 51, 47, 64, 118, 0, 244, 63, 64, 16, 84, 252, 7, 111, 192, 84, 247, 2, 245, 2, 247, 2, 245, 2, 247, 2, 245, 2, 247, 2, 47, 64, 39, 111, 96, 32, 0, 34, 84, 247, 15, 82, 118, 0, 10, 160, 2, 32, 0, 84, 0, 245, 175, 82, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 255, 15, 240, 250, 1, 252, 1, 31, 176, 17, 16, 0, 17, 246, 1, 1, 0, 17, 31, 80, 16, 16, 0, 16, 31, 80, 16, 16, 0, 252, 1, 248, 1, 244, 1, 31, 96, 17, 252, 1, 31, 192, 31, 192, 17, 252, 1, 252, 1, 31, 128, 255, 15, 208, 17, 31, 208, 17, 31, 224, 248, 31, 224, 31, 240, 253, 0, 251, 1, 1, 250, 1, 31, 192, 31, 192, 17, 249, 15, 65, 244, 15, 97, 255, 15, 240, 246, 0, 31, 128, 31, 80, 17, 246, 1, 247, 1, 16, 0, 31, 64, 31, 80, 17, 1, 0, 1, 31, 112, 245, 31, 144, 247, 31, 112, 17, 255, 15, 64, 1, 1, 17, 247, 1, 1, 31, 128, 244, 16, 31, 112, 16, 1, 0, 1, 244, 1, 16, 0, 16, 0, 16, 0, 31, 80, 245, 16, 1, 245, 1, 246, 1, 31, 80, 31, 96, 31, 96, 16, 31, 240, 255, 15, 240, 255, 15, 240, 255, 15, 240, 246, 0, 31, 208, 31, 208, 31, 208, 31, 160, 16, 1, 31, 128, 17, 0, 1, 247, 1, 245, 1, 31, 80, 31, 112, 17, 0, 1, 31, 80, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 255, 15, 240, 255, 15, 240, 252, 15, 81, 248, 1, 16, 0, 31, 128, 31, 64, 31, 112, 255, 15, 240, 251, 1, 252, 1, 31, 176, 17, 251, 1, 31, 192, 31, 208, 16, 0, 255, 15, 192, 31, 208, 31, 192, 17, 252, 1, 252, 1, 31, 192, 31, 192, 16, 0, 16, 1, 244, 1, 1, 0, 1, 1, 16, 0, 16, 1, 245, 1, 0, 1, 16, 1, 245, 1, 0, 1, 0, 1, 245, 1, 0, 16, 0, 31, 80, 17, 0, 16, 0, 31, 80, 16, 1, 0, 1, 245, 1, 16, 31, 64, 31, 64, 16, 0, 1, 31, 192, 17, 251, 1, 31, 192, 17, 251, 1, 1, 250, 1, 1, 251, 1, 31, 208, 31, 192, 255, 15, 240, 255, 15, 144, 31, 208, 31, 192, 17, 252, 1, 253, 1, 0, 255, 15, 240, 248, 1, 31, 192, 17, 251, 1, 1, 251, 1, 31, 192, 17, 251, 1, 1, 0, 0, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 246, 1, 31, 208, 244, 31, 224, 17, 31, 240, 255, 15, 240, 255, 15, 160, 255, 15, 240, 252, 1, 31, 224, 17, 253, 1, 31, 192, 153, 31, 192, 144, 31, 112, 0, 1, 16, 17, 249, 15, 65, 250, 1, 1, 251, 1, 17, 0, 1, 17, 245, 1, 16, 0, 17, 1, 9, 0, 1, 16, 1, 246, 144, 0, 17, 25, 153, 0, 1, 31, 64, 16, 159, 112, 255, 15, 64, 17, 31, 144, 17, 0, 17, 248, 1, 244, 1, 244, 1, 153, 17, 244, 1, 16, 1, 16, 244, 159, 64, 244, 16, 17, 16, 153, 159, 224, 153, 159, 64, 17, 244, 1, 247, 1, 245, 1, 247, 1, 244, 1, 31, 112, 31, 64, 31, 208, 17, 245, 1, 247, 1, 17, 0, 17, 31, 128, 244, 16, 31, 224, 250, 1, 253, 1, 252, 1, 31, 192, 31, 208, 31, 112, 17, 16, 1, 31, 64, 16, 17, 15, 65, 245, 1, 17, 251, 0, 249, 1, 31, 176, 17, 252, 1, 252, 1, 252, 1, 31, 176, 17, 251, 1, 31, 192, 31, 144, 16, 1, 0, 1, 244, 1, 1, 17, 244, 1, 0, 1, 0, 17, 245, 1, 0, 1, 1, 31, 80, 17, 0, 16, 1, 246, 1, 0, 1, 1, 247, 1, 0, 16, 1, 246, 1, 16, 16, 1, 247, 1, 0, 16, 1, 0, 17, 252, 1, 255, 15, 240, 255, 15, 240, 255, 15, 240, 247, 0, 251, 1, 253, 1, 253, 1, 252, 1, 16, 0, 17, 31, 96, 31, 96, 248, 31, 192, 245, 31, 160, 16, 1, 248, 1, 1, 250, 1, 16, 31, 160, 16, 1, 250, 1, 1, 251, 1, 1, 251, 1, 31, 176, 17, 31, 80, 250, 31, 64, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 244, 9, 145, 31, 176, 144, 31, 176, 144, 1, 251, 9, 1, 251, 9, 0, 31, 160, 144, 1, 31, 144, 144, 0, 31, 144, 144, 0, 17, 0, 244, 1, 153, 250, 1, 25, 251, 1, 159, 192, 25, 252, 9, 159, 192, 145, 252, 9, 31, 192, 145, 249, 0, 250, 9, 159, 208, 153, 159, 208, 159, 240, 255, 15, 240, 0, 1, 247, 15, 113, 247, 0, 255, 15, 208, 159, 224, 153, 253, 1, 153, 31, 160, 17, 9, 153, 17, 247, 1, 0, 9, 153, 17, 31, 80, 31, 80, 153, 1, 255, 15, 240, 255, 15, 96, 245, 159, 96, 244, 159, 128, 153, 159, 144, 153, 159, 144, 153, 159, 176, 0, 1, 31, 192, 31, 208, 31, 160, 254, 144, 0, 31, 208, 31, 208, 31, 208, 31, 160, 245, 1, 1, 0, 1, 246, 1, 17, 0, 1, 31, 96, 17, 16, 0, 31, 112, 17, 244, 1, 0, 15, 105, 244, 1, 246, 1, 0, 244, 145, 252, 15, 89, 250, 15, 65, 253, 1, 252, 1, 31, 160, 17, 31, 144, 17, 16, 1, 246, 1, 17, 0, 1, 16, 0, 245, 16, 0, 17, 0, 17, 16, 1, 0, 1, 16, 15, 73, 1, 0, 1, 16, 0, 31, 128, 17, 252, 1, 31, 176, 17, 31, 176, 17, 16, 0, 31, 96, 17, 31, 64, 31, 96, 16, 31, 64, 31, 80, 17, 1, 244, 1, 244, 1, 16, 1, 244, 0, 246, 1, 16, 15, 65, 246, 1, 252, 1, 31, 176, 17, 31, 176, 16, 1, 250, 1, 0, 31, 128, 17, 0, 1, 248, 1, 245, 1, 245, 0, 244, 31, 224, 246, 31, 208, 244, 31, 208, 17, 253, 1, 253, 1, 252, 1, 31, 176, 17, 0, 255, 15, 176, 17, 250, 1, 17, 250, 1, 31, 192, 31, 192, 31, 192, 17, 252, 1, 246, 0, 247, 9, 0, 1, 0, 245, 16, 9, 0, 1, 31, 80, 17, 9, 244, 1, 246, 1, 25, 244, 1, 247, 1, 144, 10, 160, 31, 96, 25, 10, 160, 1, 247, 9, 170, 0, 1, 246, 10, 170, 244, 1, 0, 9, 31, 144, 255, 170, 169, 245, 175, 80, 254, 160, 170, 9, 170, 16, 170, 0, 255, 175, 250, 253, 160, 31, 80, 31, 112, 161, 244, 1, 248, 1, 244, 1, 247, 10, 170, 0, 1, 31, 96, 170, 175, 64, 17, 245, 10, 175, 96, 17, 16, 0, 244, 175, 96, 244, 26, 249, 15, 73, 244, 1, 247, 9, 159, 64, 31, 96, 153, 245, 1, 244, 9, 159, 112, 16, 9, 159, 144, 25, 153, 249, 9, 153, 248, 9, 153, 17, 249, 9, 253, 0, 145, 31, 176, 153, 253, 1, 153, 159, 192, 17, 153, 159, 208, 31, 73, 31, 208, 153, 255, 15, 208, 0, 1, 253, 1, 253, 1, 253, 1, 251, 1, 17, 250, 9, 153, 253, 15, 105, 253, 15, 89, 0, 255, 15, 240, 255, 15, 240, 255, 15, 240, 255, 15, 112, 0, 15, 73, 17, 31, 144, 17, 153, 159, 224, 244, 159, 208, 159, 240, 255, 15, 240, 251, 0, 17, 0, 1, 244, 1, 244, 15, 65, 245, 1, 1, 31, 160, 17, 16, 153, 159, 224, 153, 159, 208, 153, 159, 208, 244, 159, 224, 153, 144, 17, 246, 1, 31, 64, 31, 128, 17, 254, 1, 31, 224, 31, 240, 255, 15, 192, 159, 208, 251, 1, 252, 1, 252, 1, 16, 0, 245, 16, 1, 17, 248, 1, 17, 255, 15, 240, 255, 15, 64, 247, 1, 31, 224, 17, 254, 1, 31, 240, 252, 10, 175, 160, 244, 175, 128, 246, 175, 192, 170, 245, 10, 169, 17, 0, 17, 0, 10, 160, 153, 1, 17, 244, 10, 160, 9, 15, 138, 0, 15, 250, 246, 160, 251, 160, 255, 175, 250, 160
};

const uint8_t PROGMEM overworld_room0_0[] = {
    2, // number of entities

    // entity 0, BLOB
    1,
    43, //x
    39, //y

    // entity 1, BLOB
    1,
    77, //x
    44  //y
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
    1,
    20, //x
    47, //y

    // entity 1, BLOB
    1,
    35, //x
    45, //y

    // entity 2, BLOB
    1,
    60, //x
    44  //y
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

    // entity 0, OVERWORLD_DOOR
    0x2,
    57, //x
    20  //y
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
    0, 1
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