#ifndef blob_h
#define blob_h

#include "baseEntity.h"
#include <Arduboy2.h>
#include "entity.h"
#include "entityTypes.h"

struct Blob {
    static EntityType onCollide(Entity* me, BaseEntity* other);
    static EntityType update(Entity* me, void* parent, Arduboy2* arduboy, uint8_t frame);
};

#endif

