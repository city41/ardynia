#include "commonEnemy.h"
#include "../state.h"

EntityType CommonEnemy::onCollide(Entity* me, Entity& other, Entity& player) {
    if ((other.type == EXPLOSION
            || (me->type != BLOB_MOTHER && other.damage > 0))
            && me->tookDamageCount == 0
    ) {
        me->health -= other.damage;

        if (me->health <= 0) {
            if (me->type == BLOB_MOTHER) {
                State::setCurrentRoomTriggered();
            } 

            me->type = UNSET;

            return ITEM_DROP;
        } else {
            me->bounceBack(other, player);
            me->tookDamageCount = 20;
        }
    } else if (other.type == BOOMERANG) {
        me->stunCount = 100;
    }

    return UNSET;
}
