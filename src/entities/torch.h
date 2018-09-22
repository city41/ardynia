#ifndef torch_h
#define torch_h

#include <Arduboy2.h>
#include "../entity.h"
#include "../entityTypes.h"

struct Torch {
    static EntityType update(Entity* me, Entity* player, Arduboy2Base& arduboy, uint8_t frame);
    static EntityType onCollide(Entity* me, Entity& other, Entity& player, Game& game);
};

#endif
