#include "snake.h"
#include "../util.h"
#include "../state.h"
#include "../tileRoom.h"

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

const uint8_t LeisureVelocity = 1;
const uint8_t PursueVelocity = 3;

EntityType Snake::update(Entity* me, Entity& player, uint8_t frame) {
    if ((frame % 4) != 0) {
        return UNSET;
    }


    if (me->duration == 11) {
        me->vx = LeisureVelocity;
        me->duration = Leisure;
    }

    if (me->duration == Leisure) {
        // being leisurely when intersect with player
        if (me->vx && player.x > me->x && player.x < me->x + 13) {
            me->duration = Pursue;
            me->vx = 0;
            me->vy = me->y > player.y ? -PursueVelocity : PursueVelocity;
        }
    }

    TileDef currentTile = TileRoom::getTileAt(me->x, me->y);
    if (Util::isOffScreen(me->x, me->y, 8) || currentTile== Stone || currentTile == Water) {
        me->undoMove();

        if (me->duration == Leisure) {
            me->vx *= -1;
            me->vy *= -1;
        } else {
            me->vx = !me->vx;
            me->vy = !me->vy;
            me->duration = Leisure;
        }
    }

    me->moveTo(me->x + me->vx, me->y + me->vy);

    me->mirror = pgm_read_byte(SnakeMirrors + me->dir);
    me->currentFrame = (frame - 1) / 30;

    return UNSET;
}
