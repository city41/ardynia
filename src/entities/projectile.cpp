#include "projectile.h"


EntityType Projectile::update(Entity* me, Entity& player, Game& game, Arduboy2Base& arduboy, uint8_t frame) {
    int16_t px = player.x;
    int16_t py = player.y;

    // initial duration? then "spawn"
    if (me->duration == 20) {
        switch (player.dir) {
            case LEFT:
                me->x = px - 18;
                me->y = py - 4;
                me->prevX = -v;
                me->prevY = 0;
                break;
            case RIGHT:
                me->x = px + 11;
                me->y = py - 4;
                me->prevX = v;
                me->prevY = 0;
                break;
            case UP:
                me->x = px - 5;
                me->y = py - 20;
                me->prevX = 0;
                me->prevY = -v;
                break;
            case DOWN:
                me->x = px - 1;
                me->y = py + 6;
                me->prevX = 0;
                me->prevY = v;
                break;
        }
    }

    // move
    me->duration -= 1;
    me->x += me->prevX;
    me->y += me->prevY;
    me->rotateViaMirror(frame);

    // fizzle out
    if (me->duration == 0) {
        me->type = UNSET;
    }

    return UNSET;
}
