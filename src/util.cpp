#include "util.h"
#include <Arduboy2.h>

uint8_t Util::clamp(int8_t val, int8_t minVal, int8_t maxVal) {
    return min(max(val, minVal), maxVal);
}

bool Util::isOffScreen(int16_t x, int8_t y, uint8_t margin) {
    return x < 0 || y < 0 || x + margin >= WIDTH - 16 || y + margin >= HEIGHT;
}
