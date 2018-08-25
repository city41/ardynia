#include "sword.h"
#include "baseEntity.h"
#include "util.h"

EntityType Sword::spawn(Entity* me, void* parent) {
    BaseEntity* player = (BaseEntity*)parent;
    int16_t px = player->x;
    int16_t py = player->y;

    switch (player->dir) {
        case LEFT:
            me->x = px - 16;
            me->y = py - 8;
            me->currentFrame = 2;
            break;
        case RIGHT:
            me->x = px + 16;
            me->y = py + 8;
            me->currentFrame = 6;
            break;
        case UP:
            me->x = px + 16;
            me->y = py - 16;
            me->currentFrame = 4;
            break;
        case DOWN:
            me->x = px - 16;
            me->y = py + 16;
            me->currentFrame = 0;
            break;
    }
}

EntityType Sword::update(Entity* me, void* parent, Arduboy2* arduoboy, uint8_t frame) {
    BaseEntity* player = (BaseEntity*)parent;
    int16_t px = player->x;
    int16_t py = player->y;

    me->duration -= 1;

    if (me->duration == 16) {
        switch (player->dir) {
            case LEFT:
                me->x = px - 16;
                me->y = py + 4;
                break;
            case RIGHT:
                me->x = px + 16;
                me->y = py + 4;
                break;
            case UP:
                me->x = px;
                me->y = py - 16;
                break;
            case DOWN:
                me->x = px;
                me->y = py + 16;
                break;
        }

        me->currentFrame += 1;
    }

    if (me->duration == 12) {
        me->tiles = NULL;
        me->maskTiles = NULL;
    }

    if (me->duration == 0) {
        me->type = UNSET;
    }

    return UNSET;
}
