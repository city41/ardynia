#ifndef snake_h
#define snake_h

#include "../entity.h"
#include "../entityTypes.h"

struct Snake {
    static EntityType update(Entity* me, Entity& player, uint8_t frame);
};

#endif

