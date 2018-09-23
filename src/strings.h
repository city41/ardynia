#ifndef strings_h
#define strings_h

const uint8_t PROGMEM font_tiles[] =  {
    // width, height
    4, 8,
    // ' ' and 'A'
    0xf,0xaf,0xaf,0xf,
    // 'C' and 'D'
    0x0,0x66,0x66,0x96,
    // 'E' and 'F'
    0x0,0xa4,0xa4,0xe6,
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
};

const uint8_t PROGMEM font_tiles_upper_mask[] = {
    0x0f, 0x0f, 0x0f, 0x0f
};

const uint8_t PROGMEM font_tiles_lower_mask[] = {
    0xf0, 0xf0, 0xf0, 0xf0
};


// "NEW GAME"
const uint8_t newGame_string[9] PROGMEM = {
    10, 4, 19, 0, 6, 1, 9, 4, 0xFF
};


// "CONTINUE"
const uint8_t continue_string[9] PROGMEM = {
    2, 11, 10, 16, 7, 10, 17, 4, 0xFF
};


// "DELETE SAVE"
const uint8_t deleteSave_string[12] PROGMEM = {
    3, 4, 8, 4, 16, 4, 0, 15, 1, 18, 4, 0xFF
};


// "SOUND IS ON"
const uint8_t sfxOn_string[12] PROGMEM = {
    15, 11, 17, 10, 3, 0, 7, 15, 0, 11, 10, 0xFF
};


// "SOUND IS OFF"
const uint8_t sfxOff_string[13] PROGMEM = {
    15, 11, 17, 10, 3, 0, 7, 15, 0, 11, 5, 5, 0xFF
};


// "GAME OVER"
const uint8_t gameOver_string[10] PROGMEM = {
    6, 1, 9, 4, 0, 11, 18, 4, 14, 0xFF
};


// "CONTINUE"
const uint8_t continueFromGameOver_string[9] PROGMEM = {
    2, 11, 10, 16, 7, 10, 17, 4, 0xFF
};


// "QUIT"
const uint8_t quitFromGameOver_string[5] PROGMEM = {
    13, 17, 7, 16, 0xFF
};


// "EQUIP"
const uint8_t equip_string[6] PROGMEM = {
    4, 13, 17, 7, 12, 0xFF
};


// "MAP"
const uint8_t map_string[4] PROGMEM = {
    9, 1, 12, 0xFF
};

#endif
