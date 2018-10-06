#include "blobMother.h"
#include "../util.h"

EntityType BlobMother::update(Entity* me, Entity& player, uint8_t frame) {
    if (frame % 2 == 1 || frame % 3 == 2) {
        return UNSET;
    }

    if (me->duration == 10) {
        me->dir = static_cast<Direction>(frame & 1);
        me->duration = UP;
    }

    int16_t nx = me->x;
    int16_t ny = me->y;

    if (me->dir == LEFT) {
        nx -= 1;
    } else {
        nx += 1;
    }
 
    if (me->duration == UP ) {
        ny -= 1;
    } else {
        ny += 1;
    }

    me->moveTo(nx, ny);

    bool shouldUndo = false;

    if (ny < 0 || ny >= HEIGHT - 14) {
        shouldUndo = true;

        // flip UP<->DOWN
        me->duration = 5 - me->duration;
    }

    if (nx < 0 || nx >= WIDTH - 30) {
        shouldUndo = true;

        // flip LEFT<->RIGHT
        me->dir = static_cast<Direction>(1 - me->dir);
    }

    me->mirror = me->x < player.x ? MIRROR_HORIZONTAL : 0;

    if (shouldUndo) {
        me->undoMove();
    }

    if (random(0, 50) == 0) {
        return BLOB;
    }

    return UNSET;
}
