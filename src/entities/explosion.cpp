#include "explosion.h"

EntityType Explosion::update(Entity* me, Entity* player, uint8_t frame) {
    if (me->duration == 20) {
        me->height += 5;
    }

    // cheap way to get flicker
    me->tookDamageCount = frame;
    me->currentFrame = 0;

    if (me->duration > 0) {
        me->duration -= 1;

        me->mirror = frame % 4;
    } else {
        me->type = UNSET;
    }

    return UNSET;
}
