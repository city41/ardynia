#include "blob.h"
#include "../util.h"
#include "../state.h"
#include "../game.h"

EntityType Blob::onCollide(Entity* me, Entity& other, Entity& player, Game& game) {
    if (other.damage > 0 && me->tookDamageCount == 0) {
        me->health -= other.damage;

        if (me->health <= 0) {
            if (me->type == BLOB_MOTHER) {
                State::setCurrentRoomTriggered();
                game.removeAllTriggerDoors();
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

EntityType Blob::update(Entity* me, Entity& player, Game& game, Arduboy2Base& arduboy, uint8_t frame) {
    if (frame == random(0, 61)) {
        me->moveTowardsOtherEntity(player, 1);
        me->currentFrame = 1;
        me->duration = 10;
    }

    if (me->duration > 0) {
        me->duration -= 1;
        if (me->duration == 0) {
            me->currentFrame = 0;
        }
    }

    return UNSET;
}
