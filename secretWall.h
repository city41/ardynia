#ifndef secretWall_h
#define secretWall_h

#include <Arduboy2.h>
#include "entity.h"
#include "entityTypes.h"
#include "renderer.h"

struct SecretWall {
    static void render(Entity* me, Renderer& renderer, uint8_t frame);
    static EntityType onCollide(Entity* me, Entity& other, Entity& player);
};

#endif

