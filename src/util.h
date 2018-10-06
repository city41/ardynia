#ifndef util_h
#define util_h

#include <Arduino.h>
#include "math.h"

struct Util {
    static uint8_t clamp(int8_t val, int8_t minVal, int8_t maxVal);
    static bool isOffScreen(int16_t x, int8_t y, uint8_t margin = 0);
};

#define LOG(msg) \
    do { if (SERIAL_LOG) Serial.println(msg); } while (0)

#define LOGV(var) \
    do { if (SERIAL_LOG) Serial.print(#var); Serial.print(": "); Serial.println(var); } while (0)
#endif

