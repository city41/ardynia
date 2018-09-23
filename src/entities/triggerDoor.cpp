#include "triggerDoor.h"
#include "../tileBitmaps.h"

EntityType TriggerDoor::update(Entity* me, Entity& player, Arduboy2Base& arduboy, uint8_t frame) {
    if (me->duration < 20) {
        me->health = 1;
        me->tiles = triggerDoor_tiles;
    } else {
        me->duration -= 1;
    }

    return UNSET;
}

EntityType TriggerDoor::onCollide(Entity* me, Entity& other, Entity& player, Game& game) {
    if (other.type == PLAYER) {
        if (me->health == 0) {
            me->duration += 1;
        } else {
            other.undoMove();
        }
    }

    return UNSET;
}

