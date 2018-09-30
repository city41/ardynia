#include "switch.h"
#include "../game.h"
#include "../state.h"
#include "../sfx.h"

EntityType Switch::onCollide(Entity* me, Entity& other, Entity& player, Game& game) {
    if (me->mirror == MIRROR_HORIZONTAL) {
        return UNSET;
    }

    if (other.type == BOOMERANG || other.type == SWORD || other.type == PROJECTILE) {
        me->mirror = MIRROR_HORIZONTAL;

        if (other.type == BOOMERANG && game.roomType == THREE_SWITCHES_ONE_BOOMERANG) {
            if (game.areAllSwitchesTriggered()) {
                game.spawnChest(KEY);
                State::setCurrentRoomTriggered();
                game.roomType = NORMAL;
            }
        } else {
            game.removeAllTriggerDoors();
            game.emergeAllBridges();
        }

        Sfx::stop();
        Sfx::play(Sfx::successJingle);
    }

    return UNSET;
}

