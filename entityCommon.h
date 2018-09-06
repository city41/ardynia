#ifndef entityCommon_h
#define entityCommon_h

#include "entity.h"

struct EntityCommon {
    static void moveTowardsOtherEntity(Entity* me, Entity* otherEntity, uint8_t amount);

    inline static bool isOffScreen(int16_t x, int16_t y) {
        return x < 0 || y < 0 || x >= WIDTH - 16 || y >= HEIGHT;
    }
};

#endif

