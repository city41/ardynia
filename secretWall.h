#ifndef secretWall_h
#define secretWall_h

#include <Arduboy2.h>
#include "entity.h"
#include "baseEntity.h"
#include "entityTypes.h"
#include "renderer.h"

struct SecretWall {
    static EntityType render(Entity* me, Renderer* renderer, uint8_t frame);
    static EntityType onCollide(Entity* me, BaseEntity* other, BaseEntity* player);
};

#endif

