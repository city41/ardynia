#ifndef death_h
#define death_h

#include <Arduboy2.h>
#include "entity.h"
#include "entityTypes.h"

struct Death {
    static EntityType update(Entity* me, Entity* player, Arduboy2* arduboy, uint8_t frame);
};

#endif

