#ifndef explosion_h
#define explosion_h

#include "../entity.h"
#include "../entityTypes.h"

struct Explosion {
    static EntityType update(Entity* me, Entity* player, uint8_t frame);
};

#endif
