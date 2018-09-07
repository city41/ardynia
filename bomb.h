#ifndef bomb_h
#define bomb_h

#include <Arduboy2.h>
#include "entity.h"
#include "entityTypes.h"

struct Bomb {
    static EntityType update(Entity* me, Entity& player, Arduboy2& arduboy, uint8_t frame);
};

#endif

