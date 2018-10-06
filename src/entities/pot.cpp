#include "pot.h"

EntityType Pot::onCollide(Entity* me, Entity& other, Entity& player) {
    if (other.type == PLAYER) {
        other.undoMove();
    }

    if (other.type == SWORD || other.type == PROJECTILE || other.type == EXPLOSION) {
        me->type = UNSET;

        if (me->health > 0) {
            return me->health;
        } else {
            return ITEM_DROP;
        }
    }

    return UNSET;
}
