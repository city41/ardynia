#ifndef secretWall_h
#define secretWall_h

#include "../entity.h"
#include "../entityTypes.h"

struct SecretWall {
    static EntityType onCollide(Entity* me, Entity& other, Entity& player);
};

#endif

