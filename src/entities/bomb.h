#ifndef bomb_h
#define bomb_h

#include "../entity.h"
#include "../entityTypes.h"

struct Bomb {
    static EntityType update(Entity* me, Entity& player, uint8_t frame);
};

#endif

