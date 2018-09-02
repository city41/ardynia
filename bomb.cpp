#include "bomb.h"

EntityType Bomb::spawn(Entity* me, BaseEntity* player) {
    me->x = player->x;
    me->y = player->y - 4;
    me->currentFrame = 2;
    me->tookDamageCount = 0;
    me->mirror = 0;

    return UNSET;
}

EntityType Bomb::update(Entity* me, BaseEntity* player, Arduboy2* arduboy, uint8_t frame) {
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

