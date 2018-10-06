#include "bat.h"
#include "../util.h"
#include "../game.h"
#include "../state.h"

extern Game game;

/**
 * bats just fly all over the screen. They pick a direction and go that way for a while, then pick
 * another direction.
 *
 * Giant Bat moves in the same way except it never rests
 * Having Bat and Giant Bat use the same update is messy code but great byte savings
 */
EntityType Bat::update(Entity* me, Entity& player, uint8_t frame) {
    // just finished a direction or went off screen? pick a new way to go
    if (me->duration == 0
            || Util::isOffScreen(me->x, me->y, 8)
            || (me->type == GIANT_BAT && me->y >= 18)
        ) {
        me->vx = random(-1, 2);
        me->vy = random(-1, 2);
        
        // did both end up zero? that means the bat will rest, don't want that
        // TODO: better way to do this?
        if (!me->vx && !me->vy) {
            me->vy = 1;
        }

        me->stayInside(1, WIDTH - 17, 1, HEIGHT - 1);

        // cheap way to get a little randomness
        me->duration = 30 + frame;
    } else if (frame % 5 == 0) {
        me->duration -= 1;
        me->moveTo(me->x + me->vx, me->y + me->vy);
        me->currentFrame = 1 - me->currentFrame;
    }

    me->mirror = (MirrorMode)(player.x < me->x);

    if (me->type == GIANT_BAT && (frame == 1)) {
        return BAT;
    } else {
        return UNSET;
    }
}

EntityType Bat::onCollide(Entity* me, Entity& other, Entity& player) {
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
                State::setCurrentRoomTriggered();
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
