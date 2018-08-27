#ifndef boomerang_h
#define boomerang_h

#include <Arduboy2.h>
#include "entity.h"
#include "entityTypes.h"
#include "renderer.h"

struct Boomerang {
    static const uint8_t v = 3;
    static EntityType spawn(Entity* me, void* parent);
    static EntityType update(Entity* me, void* parent, Arduboy2* arduboy, uint8_t frame);
    static EntityType render(Entity* me, Renderer* renderer, uint8_t frame);
};

#endif

