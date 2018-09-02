#ifndef sword_h
#define sword_h

#include <Arduboy2.h>
#include "entity.h"
#include "entityTypes.h"

struct Sword {
    static EntityType update(Entity* me, BaseEntity* player, Arduboy2* arduboy, uint8_t frame);
};

#endif

