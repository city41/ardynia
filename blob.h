#ifndef blob_h
#define blob_h

#include "baseEntity.h"
#include <Arduboy2.h>
#include "entity.h"
#include "entityTypes.h"

struct Blob {
    static EntityType update(Entity* me, BaseEntity* player, Arduboy2* arduboy, uint8_t frame);
    static EntityType onCollide(Entity* me, BaseEntity* other, BaseEntity* player);
};

#endif

