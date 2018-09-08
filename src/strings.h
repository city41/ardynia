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
    // 'F' and 'G'
    0x0,0x6a,0x6a,0x2e,
    // 'I' and 'L'
    0x6,0x70,0x76,0x7f,
    // 'M' and 'N'
    0x0,0xde,0xbc,0x0,
    // 'O' and 'P'
    0x0,0xa6,0xa6,0x80,
    // 'Q' and 'R'
    0x0,0xa6,0x22,0x80,
    // 'S' and 'T'
    0xe4,0x4,0xe2,0xe2,
    // 'U' and 'V'
    0x80,0x77,0x77,0x80,
    // 'W' and 'X'
    0x60,0x97,0x93,0x60,
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
    11, 5, 20, 0, 7, 1, 10, 5, 0xFF
};


// "CONTINUE"
const uint8_t continue_string[9] PROGMEM = {
    3, 12, 11, 17, 8, 11, 18, 5, 0xFF
};


// "DELETE SAVE"
const uint8_t deleteSave_string[12] PROGMEM = {
    4, 5, 9, 5, 17, 5, 0, 16, 1, 19, 5, 0xFF
};


// "SFX ARE ON"
const uint8_t sfxOn_string[11] PROGMEM = {
    16, 6, 21, 0, 1, 15, 5, 0, 12, 11, 0xFF
};


// "SFX ARE OFF"
const uint8_t sfxOff_string[12] PROGMEM = {
    16, 6, 21, 0, 1, 15, 5, 0, 12, 6, 6, 0xFF
};


// "GAME OVER"
const uint8_t gameOver_string[10] PROGMEM = {
    7, 1, 10, 5, 0, 12, 19, 5, 15, 0xFF
};


// "A: CONTINUE"
const uint8_t continueFromGameOver_string[12] PROGMEM = {
    1, 23, 0, 3, 12, 11, 17, 8, 11, 18, 5, 0xFF
};


// "B: QUIT"
const uint8_t quitFromGameOver_string[8] PROGMEM = {
    2, 23, 0, 14, 18, 8, 17, 0xFF
};


// "PAUSED: PRESS B TO PLAY"
const uint8_t paused_string[24] PROGMEM = {
    13, 1, 18, 16, 5, 4, 23, 0, 13, 15, 5, 16, 16, 0, 2, 0, 17, 12, 0, 13, 9, 1, 22, 0xFF
};


// "EQUIP"
const uint8_t equip_string[6] PROGMEM = {
    5, 14, 18, 8, 13, 0xFF
};


// "MAP"
const uint8_t map_string[4] PROGMEM = {
    10, 1, 13, 0xFF
};

#endif
