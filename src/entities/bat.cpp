#include "bat.h"
#include "../util.h"
#include "../game.h"

EntityType Bat::update(Entity* me, Entity& player, Game& game, Arduboy2Base& arduboy, uint8_t frame) {
    if (me->duration == 0
            || Util::isOffScreen(me->x, me->y, 8)
            || (me->type == GIANT_BAT && me->y >= 18)
        ) {
        if (frame < 24 && (me->vx || me->vy) && me->type != GIANT_BAT) {
            me->vx = me->vy = 0;
        } else {
            me->vx = random(-1, 2);
            me->vy = random(-1, 2);
        }

        me->duration = random(30, 180);
    }

    if (me->duration > 0 && (frame % 5) == 0) {
        me->duration -= 1;
        me->x += me->vx;
        me->y += me->vy;

        if (me->vx || me->vy) {
            me->currentFrame = 1 - me->currentFrame;
        }
    }

    if (me->type == GIANT_BAT && (frame == 1)) {
        return BAT;
    } else {
        return UNSET;
    }
}

EntityType Bat::onCollide(Entity* me, Entity& other, Entity& player, Game& game) {
    if (other.damage > 0 || other.type == BOOMERANG) {
        if (other.type == BOOMERANG) {
            other.duration = 0;
        }
        me->health -= other.damage || 1;

        if (me->health == 0) {
            if (me->type == GIANT_BAT) {
                game.emergeAllBridges();
            }

            me->type = UNSET;
            return ITEM_DROP;
        } else {
            me->bounceBack(other, player);
            me->tookDamageCount = 20;
        }
    }

    return UNSET;
}
