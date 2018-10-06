#ifndef blob_h
#define blob_h

#include "../entity.h"
#include "../entityTypes.h"

struct Blob {
    static EntityType update(Entity* me, Entity& player, uint8_t frame);
};

#endif

