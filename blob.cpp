#include "blob.h"
#include "util.h"

EntityType Blob::onCollide(Entity* me, BaseEntity* other) {
    if (other->type == SWORD) {
        me->health -= other->damage;

        if (me->health <= 0) {
            me->type = UNSET;
        } else {
            me->bounceBack();
        }
    }

    return UNSET;
}

EntityType Blob::update(Entity* me, BaseEntity* player, Arduboy2* arduboy, uint8_t frame) {
    int16_t px = player->x;
    int16_t py = player->y;

    if (frame == random(0, 61)) {
        int16_t nx = me->x;
        int16_t ny = me->y;

        if (nx - px > 0) {
            nx -= 1;
        } else if (nx - px < 0) {
            nx += 1;
        }

        if (ny - py > 0) {
            ny -= 1;
        } else if (ny - py < 0) {
            ny += 1;
        }

        me->moveTo(nx, ny);
        me->currentFrame = 1;
        me->duration = 10;
    }

    if (me->duration > 0) {
        me->duration -= 1;
        if (me->duration == 0) {
            me->currentFrame = 0;
        }
    }
}
