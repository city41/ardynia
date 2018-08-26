#ifndef drawBitmap_h
#define drawBitmap_h

#include <Arduino.h>

typedef uint8_t MirrorMode;
const MirrorMode MIRROR_HORIZONTAL = 1;
const MirrorMode MIRROR_VERTICAL = 1 << 1;

void drawBitmap(int16_t x, int16_t y, const uint8_t* bitmap, const uint8_t* mask, uint8_t frame, MirrorMode mirror);

#endif

