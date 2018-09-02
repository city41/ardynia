#include "death.h"
#include "state.h"

EntityType Death::update(Entity* me, BaseEntity* player, Arduboy2* arduboy, uint8_t frame) {
    if (me->duration > 0) {
        me->duration -= 1;
    } else {
        me->type = UNSET;

        if (State::gameState.health < State::gameState.totalHealth && random(0, 3) == 1) {
            return HEART;
        } else {
            return UNSET;
        }
    }
}
