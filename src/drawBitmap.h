#ifndef drawBitmap_h
#define drawBitmap_h

#include <Arduino.h>
#include "mirrorMode.h"

enum DrawMode: uint8_t {
    Normal,
    Invert,
    Xor
};

void drawBitmap(int16_t x, int8_t y, const uint8_t* bitmap, const uint8_t* mask, bool plusMask, uint8_t frame, MirrorMode mirror, DrawMode drawMode, uint8_t maskFrame = 255);

#endif

