#ifndef lock_h
#define lock_h

#include <Arduboy2.h>
#include "entity.h"
#include "entityTypes.h"
#include "renderer.h"

struct Lock {
    static EntityType onCollide(Entity* me, Entity* other, Entity* player);
};

#endif

