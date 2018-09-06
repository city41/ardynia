#include "entityCommon.h"

void EntityCommon::moveTowardsOtherEntity(Entity* me, Entity* other, uint8_t amount) {
    int16_t ox = other->x;
    int16_t oy = other->y;

    int16_t nx = me->x;
    int16_t ny = me->y;

    if (nx - ox > 0) {
        nx -= amount;
        me->mirror = 0;
    } else if (nx - ox < 0) {
        nx += amount;
        me->mirror = MIRROR_HORIZONTAL;
    }

    if (ny - oy > 0) {
        ny -= amount;
    } else if (ny - oy < 0) {
        ny += amount;
    }

    me->moveTo(nx, ny);
}

