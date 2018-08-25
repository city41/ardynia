#ifndef blob_h
#define blob_h

#include "baseEntity.h"
#include "entity.h"
#include "entityTypes.h"

struct Blob {
    static EntityType onCollide(Entity* me, BaseEntity* other);
};

#endif

