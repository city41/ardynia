#include "blob.h"
#include "util.h"
#include "drawBitmap.h"
#include "player.h"
#include "state.h"

EntityType Blob::onCollide(Entity* me, BaseEntity* other, BaseEntity* player) {
    if (other->damage > 0) {
        me->health -= other->damage;

        if (me->health <= 0) {
            me->type = UNSET;
            return DEATH;
        } else {
            me->bounceBack();
            me->tookDamageCount = 20;
            return UNSET;
        }
    } else if (other->type == BOOMERANG) {
        me->stunCount = 100;
        return UNSET;
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
            me->mirror = 0;
        } else if (nx - px < 0) {
            nx += 1;
            me->mirror = MIRROR_HORIZONTAL;
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

    return UNSET;
}
