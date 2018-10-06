#ifndef skeleton_h
#define skeleton_h

#include "../entity.h"
#include "../entityTypes.h"

struct Skeleton {
    static EntityType update(Entity* me, Entity& player, uint8_t frame);
};

#endif

