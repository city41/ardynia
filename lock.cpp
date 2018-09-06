#include "lock.h"
#include "state.h"
#include "tileRoom.h"

EntityType Lock::onCollide(Entity* me, Entity* other, Entity* player) {
    if (other == player && State::gameState.numKeys > 0) {
        State::gameState.numKeys -= 1;

        const uint8_t roomIndex = TileRoom::getRoomIndex(TileRoom::x, TileRoom::y);
        State::setTriggered(roomIndex);
        State::saveToEEPROM();

        me->type = UNSET;
    }

    return UNSET;
}
