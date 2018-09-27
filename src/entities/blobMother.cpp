#include "blobMother.h"
#include "../util.h"

EntityType BlobMother::update(Entity* me, Entity& player, Game& game, Arduboy2Base& arduboy, uint8_t frame) {
    if (frame % 2 == 1 || frame % 3 == 2) {
        return UNSET;
    }

    if (me->duration == 10) {
        me->dir = random(0, 2);
        me->duration = UP;
    }

    int16_t nx = me->x;
    int16_t ny = me->y;

    switch (me->dir) {
        case LEFT:
            nx = nx - 1;
            break;
        case RIGHT:
            nx = nx + 1;
            break;
    }

    switch (me->duration) {
        case UP:
            ny = ny - 1;
            break;
        case DOWN:
            ny = ny + 1;
            break;
    }

    me->moveTo(nx, ny);

    bool shouldUndo = false;
    if (Util::isOffScreen(20, ny)) {
        shouldUndo = true;

        // flip UP<->DOWN
        me->duration = 5 - me->duration;
    }

    if (Util::isOffScreen(nx, 20)) {
        shouldUndo = true;

        // flip LEFT<->RIGHT
        me->dir = 1 - me->dir;
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
