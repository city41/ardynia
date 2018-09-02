#ifndef boomerang_h
#define boomerang_h

#include <Arduboy2.h>
#include "entity.h"
#include "baseEntity.h"
#include "entityTypes.h"

struct Boomerang {
    static const uint8_t v = 3;
    static EntityType spawn(Entity* me, BaseEntity* spawner, BaseEntity* player);
    static EntityType update(Entity* me, BaseEntity* player, Arduboy2* arduboy, uint8_t frame);
    static EntityType onCollide(Entity* me, BaseEntity* other, BaseEntity* player);
};

#endif

