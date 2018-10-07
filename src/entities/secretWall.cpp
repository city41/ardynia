#include "secretWall.h"
#include "../tileRoom.h"
#include "../state.h"
#include "../util.h"
#include "../sfx.h"

EntityType SecretWall::onCollide(Entity* me, Entity& other, Entity& player) {
    if (other.type == EXPLOSION) {
        me->health = 0;
        me->tiles = NULL;

        State::setCurrentRoomTriggered();
        TileRoom::setTileAt(me->x, me->y, TileRoom::currentRoomOffset, Blank);
    }

    return UNSET;
}
