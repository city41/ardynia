#ifndef entityExpressions_h
#define entityExpressions_h

constexpr uint8_t xy(uint8_t x, uint8_t y) {
    return ((x / 8) << 4) | (y / 4);
}

constexpr uint8_t miscAndEntityType(uint8_t misc, EntityType entityType) {
    return (misc << 5) | entityType;
}

#endif
