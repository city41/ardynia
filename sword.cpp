#include "sword.h"
#include "baseEntity.h"
#include "util.h"

EntityType Sword::spawn(Entity* me, BaseEntity* player) {
    int16_t px = player->x;
    int16_t py = player->y;

    me->invert = true;

    switch (player->dir) {
        case LEFT:
            me->x = px - 14;
            me->y = py + 4;
            me->currentFrame = 0;
            me->mirror = 0;
            break;
        case RIGHT:
            me->x = px + 14;
            me->y = py + 4;
            me->currentFrame = 0;
            me->mirror = MIRROR_HORIZONTAL;
            break;
        case UP:
            me->x = px - 3;
            me->y = py - 12;
            me->currentFrame = 1;
            me->mirror = MIRROR_VERTICAL;
            break;
        case DOWN:
            me->x = px + 3;
            me->y = py + 14;
            me->currentFrame = 1;
            me->mirror = 0;
            break;
    }
}

EntityType Sword::update(Entity* me, BaseEntity* player, Arduboy2* arduoboy, uint8_t frame) {
    int16_t px = player->x;
    int16_t py = player->y;

    me->duration -= 1;

    if (me->duration == 0) {
        me->type = UNSET;
    }

    return UNSET;
}
