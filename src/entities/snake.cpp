#include "snake.h"
#include "../util.h"

enum SnakeMode: uint8_t {
    Leisure,
    Pursue
};

const uint8_t PROGMEM SnakeMirrors[] = {
    MIRROR_HORIZONTAL,
    0,
    0,
    0
};

EntityType Snake::update(Entity* me, Entity& player, Arduboy2Base& arduboy, uint8_t frame) {
    if (frame % 6 != 0) {
        return UNSET;
    }


    if (me->duration == 11) {
        me->vx = frame & 1;
        me->vy = !me->vx;
        me->duration = Leisure;
    }

    if (me->duration == Leisure) {
        // being leisurely when intersect with player
        if (me->vx && player.x > me->x && player.x < me->x + 13) {
            me->duration = Pursue;
            me->vx = 0;
            me->vy = me->y > player.y ? -2 : 2;
        }

        if (me->vy && player.y > me->y && player.y < me->y + 13) {
            me->duration = Pursue;
            me->vy = 0;
            me->vx = me->x > player.x ? -2 : 2;
        }
    }

    if (Util::isOffScreen(me->x, me->y, 8)) {
        me->undoMove();

        if (me->duration == Leisure) {
            me->vx *= -1;
            me->vy *= -1;
        } else {
            me->vx = !me->vx;
            me->vy = !me->vy;
        }
    }

    me->moveTo(me->x + me->vx, me->y + me->vy);

    me->mirror = pgm_read_byte(SnakeMirrors + me->dir);
    me->currentFrame = frame % 10 == 0 ? 1 - me->currentFrame : me->currentFrame;

    return UNSET;
}
