#ifndef blob_h
#define blob_h

#include <Arduboy2.h>
#include "../entity.h"
#include "../entityTypes.h"

struct Blob {
    static EntityType update(Entity* me, Entity& player, Arduboy2Base& arduboy, uint8_t frame);
};

#endif

