#include "torch.h"

EntityType Torch::update(Entity* me, Entity* player, Arduboy2Base& arduboy, uint8_t frame) {
    me->mirror = frame < 31 ? MIRROR_HORIZONTAL : 0;
    return UNSET;
}

EntityType Torch::onCollide(Entity* me, Entity& other, Entity& player, Game& game) {
    if (other.type == PROJECTILE) {
        me->currentFrame = 1;
    }

    return UNSET;
}
