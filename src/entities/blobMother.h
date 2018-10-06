#ifndef blobMother_h
#define blobMother_h

#include "../entity.h"
#include "../entityTypes.h"

struct BlobMother {
    static EntityType update(Entity* me, Entity& player, uint8_t frame);
};

#endif

