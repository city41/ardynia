#ifndef bomb_h
#define bomb_h

#include <Arduboy2.h>
#include "entity.h"
#include "baseEntity.h"
#include "entityTypes.h"

struct Bomb {
    static EntityType spawn(Entity* me, BaseEntity* spawner, BaseEntity* player);
    static EntityType update(Entity* me, BaseEntity* player, Arduboy2* arduboy, uint8_t frame);
};

#endif

