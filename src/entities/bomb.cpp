#include "bomb.h"
#include "../sfx.h"

EntityType Bomb::update(Entity* me, Entity& player, uint8_t frame) {
    // health is being used for "is dormant"
    // health=0 -> dormant item drop
    // health=1 -> active bomb that will explode
    if (me->health == 0) {
        return UNSET;
    }

    if (me->duration > 0) {
        me->duration -= 1;

        if (me->duration == 59) {
            me->tookDamageCount = 60;
        }

        return UNSET;
    } else {
        Sfx::play(Sfx::boomerang);
        return EXPLOSION;
    }
}

