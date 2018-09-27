#include "triggerDoor.h"
#include "../tileBitmaps.h"

EntityType TriggerDoor::update(Entity* me, Entity& player, Game& game, Arduboy2Base& arduboy, uint8_t frame) {
    // if the door just spawned on top of the player, wait
    // for the player to move out of the way before coming on line
    if (me->health == 0 && !player.overlaps(*me)) {
        me->tiles = me->width == 8 ? verticalTriggerDoor_tiles : horizontalTriggerDoor_tiles;
        me->health = 1;
    }

    return UNSET;
}

EntityType TriggerDoor::onCollide(Entity* me, Entity& other, Entity& player, Game& game) {
    if (other.type == PLAYER && me->health) {
        other.undoMove();
    }

    return UNSET;
}

