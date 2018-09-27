#ifndef switch_h
#define switch_h

#include <Arduboy2.h>
#include "../entity.h"
#include "../entityTypes.h"

class Game;

struct Switch {
    static EntityType onCollide(Entity* me, Entity& other, Entity& player, Game& game);
};

#endif

