#include "explosion.h"

EntityType Explosion::update(Entity* me, BaseEntity* player, Arduboy2* arduboy, uint8_t frame) {
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
