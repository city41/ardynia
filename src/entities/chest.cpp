#include "chest.h"

EntityType Chest::update(Entity* me, Entity& player, Game& game, Arduboy2Base& arduboy, uint8_t frame) {
    if (me->duration == 20) {
        me->duration = 0;

        if (me->overlaps(player)) {
            me->x = player.x;
            me->y = player.y - me->height - 1;
        }
    }

    return UNSET;
}
