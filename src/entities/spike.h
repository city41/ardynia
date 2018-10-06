#ifndef spike_h
#define spike_h

#include "../entity.h"
#include "../entityTypes.h"

struct Spike {
    static EntityType update(Entity* me, Entity& player, uint8_t frame);
    static EntityType onCollide(Entity* me, Entity& other, Entity& player);
};

#endif

