#include "death.h"
#include "state.h"
#include "player.h"

EntityType Death::update(Entity* me, BaseEntity* player, Arduboy2* arduboy, uint8_t frame) {
    if (me->duration > 0) {
        me->duration -= 1;
    } else {
        me->type = UNSET;

        // let's see if the player randomly earns an item
        uint8_t numBombs = ((Player*)player)->numBombs;
        uint8_t playerHealth = ((Player*)player)->health;
        bool playerIsFullHealth = State::gameState.totalHealth == playerHealth;
        bool playerIsFullBombs = numBombs == MAX_BOMB_COUNT;

        if (
            playerIsFullHealth
            && playerIsFullBombs) {

            // player has full health and bombs, we have nothing to offer them.
            // we do this because we don't want a heart/bomb to take up a precious
            // entity slot that could otherwise be used for projectiles and the like
            return UNSET;
        }

        bool willAward = random(0, 3) == 1;

        if (!willAward) {
            return UNSET;
        }

        // player doesn't need bombs, so heart it is
        if (playerIsFullBombs) {
            return HEART;
        }


        // player doesn't need health, so bomb it is
        if (playerIsFullHealth) {
            return BOMB;
        }
        
        // player needs both bomb and heart, so coin flip to pick
        if (random(0, 2) == 0) {
            return BOMB;
        } else {
            return HEART;
        }
    }

    return UNSET;
}
