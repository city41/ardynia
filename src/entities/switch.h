#ifndef switch_h
#define switch_h

#include <Arduboy2.h>
#include "../entity.h"
#include "../entityTypes.h"

struct Switch {
    static EntityType onCollide(Entity* me, Entity& other, Entity& player);
};

#endif

