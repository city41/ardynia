#include "sword.h"
#include "../util.h"

EntityType Sword::update(Entity* me, Entity& player, Arduboy2Base& arduoboy, uint8_t frame) {
    int16_t px = player.x;
    int16_t py = player.y;

    // initial duration? then "spawn"
    /* if (me->duration == 20) { */
        switch (player.dir) {
            case LEFT:
                me->x = px - 18;
                me->y = py - 4;
                me->currentFrame = 0;
                me->mirror = 0;
                break;
            case RIGHT:
                me->x = px + 11;
                me->y = py - 4;
                me->currentFrame = 0;
                me->mirror = MIRROR_HORIZONTAL;
                break;
            case UP:
                me->x = px - 5;
                me->y = py - 20;
                me->currentFrame = 1;
                me->mirror = MIRROR_VERTICAL;
                break;
            case DOWN:
                me->x = px - 1;
                me->y = py + 6;
                me->currentFrame = 1;
                me->mirror = 0;
                break;
        /* } */
    }

    me->duration -= 1;

    if (me->duration == 0) {
        me->type = UNSET;
    }

    return UNSET;
}
