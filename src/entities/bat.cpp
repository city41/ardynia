#include "bat.h"
#include "../util.h"
#include "../game.h"

EntityType Bat::onCollide(Entity* me, Entity& other, Entity& player, Game& game) {
    if (other.damage > 0 || other.type == BOOMERANG) {
        if (other.type == BOOMERANG) {
            other.duration = 0;
        }
        me->type = UNSET;
        return ITEM_DROP;
    }

    return UNSET;
}

EntityType Bat::update(Entity* me, Entity& player, Arduboy2Base& arduboy, uint8_t frame) {
    if (me->duration == 0 || Util::isOffScreen(me->x, me->y)) {
        if (frame < 24) {
            me->prevX = me->prevY = 0;
        } else {
            me->prevX = random(-1, 2);
            me->prevY = random(-1, 2);
        }

        me->duration = random(30, 180);
    }

    if (me->duration > 0 && (frame % 5) == 0) {
        me->duration -= 1;
        me->x += me->prevX;
        me->y += me->prevY;

        if (me->prevX || me->prevY) {
            me->currentFrame = 1 - me->currentFrame;
        }
    }

    return UNSET;
}
