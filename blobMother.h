#ifndef blobMother_h
#define blobMother_h

#include "baseEntity.h"
#include <Arduboy2.h>
#include "entity.h"
#include "entityTypes.h"

struct BlobMother {
    static EntityType update(Entity* me, BaseEntity* player, Arduboy2* arduboy, uint8_t frame);
};

#endif

