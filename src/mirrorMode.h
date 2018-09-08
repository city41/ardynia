#ifndef mirrorMode_h
#define mirrorMode_h

#include <Arduino.h>

typedef uint8_t MirrorMode;

// these are bit masks, not enums
const MirrorMode MIRROR_HORIZONTAL = 1;
const MirrorMode MIRROR_VERTICAL = 2;

#endif
