#ifndef commonEnemy_h
#define commonEnemy_h

#include "../entity.h"
#include "../entityTypes.h"

struct CommonEnemy {
    static EntityType onCollide(Entity* me, Entity& other, Entity& player);
};

#endif

