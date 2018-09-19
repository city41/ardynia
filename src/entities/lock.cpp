#include "lock.h"
#include "../state.h"
#include "../tileRoom.h"
#include "../sfx.h"

EntityType Lock::onCollide(Entity* me, Entity* other, Entity* player) {
    if (other == player && State::gameState.numKeys > 0) {
        State::gameState.numKeys -= 1;

        State::setCurrentRoomTriggered();

        me->type = UNSET;
        Sfx::successJingle();
    }

    return UNSET;
}
