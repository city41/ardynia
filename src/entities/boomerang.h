#ifndef boomerang_h
#define boomerang_h

#include "../entity.h"
#include "../entityTypes.h"

struct Boomerang {
    static const uint16_t v = 3;
    static EntityType update(Entity* me, Entity& player, uint8_t frame);
    static EntityType onCollide(Entity* me, Entity& other, Entity& player);
};

#endif

