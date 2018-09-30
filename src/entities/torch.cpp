#include "torch.h"
#include "../state.h"
#include "../game.h"
#include "../sfx.h"

EntityType Torch::update(Entity* me, Entity* player, Game& game, Arduboy2Base& arduboy, uint8_t frame) {
    if (me->health == 0) {
        me->currentFrame = frame & 1;
    } 

    return UNSET;
}

EntityType Torch::onCollide(Entity* me, Entity& other, Entity& player, Game& game) {
    if (other.type == PLAYER) {
        other.undoMove();
    }

    if (other.type == PROJECTILE) {
        if (me->health == 0) {
            return UNSET;
        }

        me->health = 0;

        if (game.roomType == LAST_TORCH_OPENS_DOORS && game.areAllTorchesLit()) {
            game.removeAllTriggerDoors();
            Sfx::play(Sfx::successJingle);
        }
    }

    return UNSET;
}
