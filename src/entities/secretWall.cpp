#include "secretWall.h"
#include "../tileRoom.h"
#include "../state.h"
#include "../util.h"

EntityType SecretWall::onCollide(Entity* me, Entity& other, Entity& player) {
    if (other.type == EXPLOSION) {
        me->health = 0;
        me->currentFrame = 1;

        State::setCurrentRoomTriggered();
    }

    return UNSET;
}
