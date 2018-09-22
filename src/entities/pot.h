#ifndef pot_h
#define pot_h

#include <Arduboy2.h>
#include "../entity.h"
#include "../entityTypes.h"

class Game;

struct Pot {
    static EntityType onCollide(Entity* me, Entity& other, Entity& player, Game& game);
};

#endif

