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
    // 'H' and 'I'
    0x60,0xb,0x6b,0xf0,
    // 'K' and 'L'
    0x0,0x7d,0x7a,0x76,
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
    // 'Y' and '!'
    0xd8,0xb3,0xdb,0xe8,
};

const uint8_t PROGMEM font_tiles_upper_mask[] = {
    0x0f, 0x0f, 0x0f, 0x0f
};

const uint8_t PROGMEM font_tiles_lower_mask[] = {
    0xf0, 0xf0, 0xf0, 0xf0
};


// "NEW GAME"
const uint8_t newGame_string[9] PROGMEM = {
    13, 5, 22, 0, 7, 1, 12, 5, 0xFF
};


// "CONTINUE"
const uint8_t continue_string[9] PROGMEM = {
    3, 14, 13, 19, 9, 13, 20, 5, 0xFF
};


// "DELETE SAVE"
const uint8_t deleteSave_string[12] PROGMEM = {
    4, 5, 11, 5, 19, 5, 0, 18, 1, 21, 5, 0xFF
};


// "SFX!"
const uint8_t sfxOn_string[5] PROGMEM = {
    18, 6, 23, 25, 0xFF
};


// "SFX"
const uint8_t sfxOff_string[4] PROGMEM = {
    18, 6, 23, 0xFF
};


// "GAME OVER"
const uint8_t gameOver_string[10] PROGMEM = {
    7, 1, 12, 5, 0, 14, 21, 5, 17, 0xFF
};


// "QUIT"
const uint8_t quitFromGameOver_string[5] PROGMEM = {
    16, 20, 9, 19, 0xFF
};


// "EQUIP"
const uint8_t equip_string[6] PROGMEM = {
    5, 16, 20, 9, 15, 0xFF
};


// "MAP"
const uint8_t map_string[4] PROGMEM = {
    12, 1, 15, 0xFF
};


// "CONGRATS"
const uint8_t congrats_string[9] PROGMEM = {
    3, 14, 13, 7, 17, 1, 19, 18, 0xFF
};


// "YOU GOT THE SWORD"
const uint8_t gotSword_string[18] PROGMEM = {
    24, 14, 20, 0, 7, 14, 19, 0, 19, 8, 5, 0, 18, 22, 14, 17, 4, 0xFF
};


// "YOU GOT A HEART"
const uint8_t gotHeartContainer_string[16] PROGMEM = {
    24, 14, 20, 0, 7, 14, 19, 0, 1, 0, 8, 5, 1, 17, 19, 0xFF
};


// "YOU GOT THE BOOMERANG"
const uint8_t gotBoomerang_string[22] PROGMEM = {
    24, 14, 20, 0, 7, 14, 19, 0, 19, 8, 5, 0, 2, 14, 14, 12, 5, 17, 1, 13, 7, 0xFF
};


// "YOU GOT THE BOMBS"
const uint8_t gotBombs_string[18] PROGMEM = {
    24, 14, 20, 0, 7, 14, 19, 0, 19, 8, 5, 0, 2, 14, 12, 2, 18, 0xFF
};


// "YOU GOT THE MAGIC RING"
const uint8_t gotRing_string[23] PROGMEM = {
    24, 14, 20, 0, 7, 14, 19, 0, 19, 8, 5, 0, 12, 1, 7, 9, 3, 0, 17, 9, 13, 7, 0xFF
};


// "YOU GOT A KEY"
const uint8_t gotKey_string[14] PROGMEM = {
    24, 14, 20, 0, 7, 14, 19, 0, 1, 0, 10, 5, 24, 0xFF
};


// "YOU GOT THE BOSS KEY"
const uint8_t gotBossKey_string[21] PROGMEM = {
    24, 14, 20, 0, 7, 14, 19, 0, 19, 8, 5, 0, 2, 14, 18, 18, 0, 10, 5, 24, 0xFF
};

#endif
