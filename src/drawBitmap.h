#ifndef drawBitmap_h
#define drawBitmap_h

#include <Arduino.h>
#include "mirrorMode.h"

void drawBitmap(int16_t x, int16_t y, const uint8_t* bitmap, const uint8_t* mask, bool plusMask, uint8_t frame, MirrorMode mirror, bool invert, uint8_t maskFrame = 255);

#endif

