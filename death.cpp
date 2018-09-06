#include "death.h"
#include "state.h"
#include "player.h"

/**
 * an entity that shows a death "splat" then rolls dice to
 * see if the player gets an item drop. originally the item drop considered
 * the player's health and bomb levels, but that cost way more bytes than the value
 * it provided
 */
EntityType Death::update(Entity* me, Entity* player, Arduboy2* arduboy, uint8_t frame) {
    if (me->duration > 0) {
        me->duration -= 1;
    } else {
        me->type = UNSET;

        bool willAward = random(0, 3) == 1;

        if (!willAward) {
            return UNSET;
        }

        if (random(0, 2) == 0) {
            return BOMB;
        } else {
            return HEART;
        }
    }

    return UNSET;
}
