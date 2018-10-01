#include "bat.h"
#include "../util.h"
#include "../game.h"

/**
 * bats just fly all over the screen. They pick a direction and go that way for a while, then pick
 * another direction. Every time they pick a new direction, there's a chance they choose to rest
 * instead.
 *
 * Giant Bat moves in the same way except it never rests
 * Having Bat and Giant Bat use the same update is messy code but great byte savings
 */
EntityType Bat::update(Entity* me, Entity& player, Game& game, Arduboy2Base& arduboy, uint8_t frame) {
    // just finished a direction or went off screen? pick a new way to go
    if (me->duration == 0
            || Util::isOffScreen(me->x, me->y, 12)
            || (me->type == GIANT_BAT && me->y >= 18)
        ) {
        // was just moving? take a break
        if (frame < 20 && (me->vx || me->vy) && me->type != GIANT_BAT) {
            me->vx = me->vy = 0;
        } else {
            me->vx = random(-1, 2);
            me->vy = random(-1, 2);
            
            // did both end up zero? that means the bat will rest, don't want that
            // TODO: better way to do this?
            if (!me->vx && !me->vy) {
                me->vy = 1;
            }
        }

        // cheap way to get a little randomness
        me->duration = 30 + frame;
    }

    if (me->duration > 0 && (frame % 5) == 0) {
        me->duration -= 1;
        me->moveTo(me->x + me->vx, me->y + me->vy);

        if (me->vx || me->vy) {
            me->currentFrame = 1 - me->currentFrame;
        }
    }

    me->mirror = (MirrorMode)(player.x < me->x);

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

        // the magic ring does two damage, but bats only have one health,
        // and the player does not have the magic ring at the giant bat boss fight
        // so hardcoding to one saves the bytes
        me->health -= 1;

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
