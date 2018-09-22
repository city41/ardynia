#include "pot.h"

EntityType Pot::onCollide(Entity* me, Entity& other, Entity& player, Game& game) {
    if (other.type == PLAYER) {
        other.undoMove();
    }

    if (other.type == SWORD || other.type == EXPLOSION) {
        me->type = UNSET;

        if (me->health > 0) {
            return me->health;
        }
    }

    return UNSET;
}
