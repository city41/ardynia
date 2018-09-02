#include "bomb.h"

EntityType Bomb::spawn(Entity* me, BaseEntity* spawner, BaseEntity* player) {
    me->x = spawner->x;
    me->y = spawner->y - 4;
    me->currentFrame = 2;
    me->tookDamageCount = 0;
    me->mirror = 0;

    // an enemy spawned this bomb? then it's an item drop
    // make it dormant
    if (spawner != player) {
        // reuse health for "dormant"
        me->health = 1;
    }

    return UNSET;
}

EntityType Bomb::update(Entity* me, BaseEntity* player, Arduboy2* arduboy, uint8_t frame) {
    // health is being used for "is dormant", see above in spawn
    if (me->health == 1) {
        return UNSET;
    }

    if (me->duration > 0) {
        me->duration -= 1;

        if (me->duration == 59) {
            me->tookDamageCount = 60;
        }

        return UNSET;
    } else {
        me->type = UNSET;
        return EXPLOSION;
    }
}

