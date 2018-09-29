#include "blob.h"
#include "../util.h"
#include "../state.h"
#include "../game.h"

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

