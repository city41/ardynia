#include "torch.h"
#include "../state.h"
#include "../game.h"
#include "../sfx.h"

extern Game game;

EntityType Torch::update(Entity* me, Entity* player, uint8_t frame) {
    if (me->health == 0) {
        me->currentFrame = frame & 1;
    } 

    return UNSET;
}

EntityType Torch::onCollide(Entity* me, Entity& other, Entity& player) {
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
            Sfx::play(Sfx::pickUpItem);
        }
    }

    return UNSET;
}
