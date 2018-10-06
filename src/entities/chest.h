#ifndef chest_h
#define chest_h

#include "../entity.h"
#include "../entityTypes.h"

struct Chest {
    static EntityType update(Entity* me, Entity& player, uint8_t frame);
};

#endif

