#ifndef strings_h
#define strings_h

const uint8_t PROGMEM font_tiles[] =  {
    // width, height
    4, 8,
    // ' ' and 'A'
    0xf,0xaf,0xaf,0xf,
    // 'B' and 'C'
    0x0,0x64,0x64,0x61,
    // 'D' and 'E'
    0x0,0x46,0x46,0x69,
    // 'G' and 'I'
    0x60,0x6,0x66,0xf2,
    // 'L' and 'M'
    0x0,0xe7,0xc7,0x7,
    // 'N' and 'O'
    0x0,0x6d,0x6b,0x0,
    // 'P' and 'Q'
    0x0,0x6a,0x2a,0x8,
    // 'R' and 'S'
    0x40,0x4a,0x22,0x28,
    // 'T' and 'U'
    0xe,0x70,0x7e,0xe,
    // 'V' and 'W'
    0x8,0x77,0x37,0x8,
    // 'Y' and ':'
    0xf8,0x53,0xfb,0xf8,
};

const uint8_t PROGMEM font_tiles_upper_mask[] = {
    0x0f, 0x0f, 0x0f, 0x0f
};

const uint8_t PROGMEM font_tiles_lower_mask[] = {
    0xf0, 0xf0, 0xf0, 0xf0
};


// "NEW GAME"
const uint8_t newGame_string[9] PROGMEM = {
    10, 5, 19, 0, 6, 1, 9, 5, 0xFF
};


// "CONTINUE"
const uint8_t continue_string[9] PROGMEM = {
    3, 11, 10, 16, 7, 10, 17, 5, 0xFF
};


// "DELETE SAVE"
const uint8_t deleteSave_string[12] PROGMEM = {
    4, 5, 8, 5, 16, 5, 0, 15, 1, 18, 5, 0xFF
};


// "GAME OVER"
const uint8_t gameOver_string[10] PROGMEM = {
    6, 1, 9, 5, 0, 11, 18, 5, 14, 0xFF
};


// "A: CONTINUE"
const uint8_t continueFromGameOver_string[12] PROGMEM = {
    1, 21, 0, 3, 11, 10, 16, 7, 10, 17, 5, 0xFF
};


// "B: QUIT"
const uint8_t quitFromGameOver_string[8] PROGMEM = {
    2, 21, 0, 13, 17, 7, 16, 0xFF
};


// "PAUSED: PRESS B TO PLAY"
const uint8_t paused_string[24] PROGMEM = {
    12, 1, 17, 15, 5, 4, 21, 0, 12, 14, 5, 15, 15, 0, 2, 0, 16, 11, 0, 12, 8, 1, 20, 0xFF
};


// "EQUIP"
const uint8_t equip_string[6] PROGMEM = {
    5, 13, 17, 7, 12, 0xFF
};


// "MAP"
const uint8_t map_string[4] PROGMEM = {
    9, 1, 12, 0xFF
};

#endif
