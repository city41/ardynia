#ifndef boomerang_h
#define boomerang_h

#include <Arduboy2.h>
#include "entity.h"
#include "entityTypes.h"

struct Boomerang {
    static const uint8_t v = 3;
    static EntityType update(Entity* me, Entity& player, Arduboy2& arduboy, uint8_t frame);
    static EntityType onCollide(Entity* me, Entity& other, Entity& player);
};

#endif

