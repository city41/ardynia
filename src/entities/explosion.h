#ifndef explosion_h
#define explosion_h

#include <Arduboy2.h>
#include "../entity.h"
#include "../entityTypes.h"

struct Explosion {
    static EntityType update(Entity* me, Entity* player, Game& game, Arduboy2Base& arduboy, uint8_t frame);
};

#endif
