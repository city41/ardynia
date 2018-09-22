#include "pot.h"

EntityType Pot::onCollide(Entity* me, Entity& other, Entity& player, Game& game) {
    if (other.type == SWORD || other.type == BOOMERANG || other.type == EXPLOSION) {
        me->type = UNSET;
        return me->health;
    }

    return UNSET;
}
