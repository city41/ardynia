#include "util.h"

uint8_t clamp(int8_t val, int8_t minVal, int8_t maxVal) {
    return min(max(val, minVal), maxVal);
}
