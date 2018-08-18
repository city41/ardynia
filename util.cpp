#include "util.h"

uint8_t clamp(uint8_t val, uint8_t minVal, uint8_t maxVal) {
    return min(max(val, minVal), maxVal);
}
