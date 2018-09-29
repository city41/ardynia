#ifndef chest_h
#define chest_h

#include <Arduboy2.h>
#include "../entity.h"
#include "../entityTypes.h"

class Game;

struct Chest {
    static EntityType update(Entity* me, Entity& player, Game& game, Arduboy2Base& arduboy, uint8_t frame);
};

#endif
