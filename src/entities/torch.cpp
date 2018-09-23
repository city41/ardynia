#include "torch.h"
#include "../state.h"
#include "../game.h"

EntityType Torch::update(Entity* me, Entity* player, Arduboy2Base& arduboy, uint8_t frame) {
    me->mirror = frame < 31 ? MIRROR_HORIZONTAL : 0;
    return UNSET;
}

EntityType Torch::onCollide(Entity* me, Entity& other, Entity& player, Game& game) {
    if (other.type == PLAYER) {
        other.undoMove();
    }

    if (other.type == PROJECTILE) {
        me->currentFrame = 1;

        // HACK! in the overworld, lit torches unlock doors
        if (State::gameState.currentDungeon == 0) {
            game.removeAllTriggerDoors();
        }
    }

    return UNSET;
}
