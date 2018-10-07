#include "lock.h"
#include "../state.h"
#include "../sfx.h"
#include "player.h"

void triggerLock(Entity* me) {
    State::setCurrentRoomTriggered();
    me->type = UNSET;
    Sfx::play(Sfx::pickUpItem);
}

EntityType Lock::onCollide(Entity* me, Entity& other, Player& player) {
    if (other.type == PLAYER) {
        if (me->type == LOCK && State::gameState.numKeys[State::gameState.currentDungeon] > 0) {
            State::gameState.numKeys[State::gameState.currentDungeon] -= 1;
            triggerLock(me);
        } else if (me->type == BOSS_LOCK && State::gameState.bossKeys[State::gameState.currentDungeon] > 0) {
            triggerLock(me);
        }
    }

    return UNSET;
}
