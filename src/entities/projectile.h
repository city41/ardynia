#ifndef projectile_h
#define projectile_h

#include "../entity.h"
#include "../entityTypes.h"

struct Projectile {
    static const uint8_t v = 2;
    static EntityType update(Entity* me, Entity& player, uint8_t frame);
};

#endif

