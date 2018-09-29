#ifndef commonEnemy_h
#define commonEnemy_h

#include <Arduboy2.h>
#include "../entity.h"
#include "../entityTypes.h"

class Game;

struct CommonEnemy {
    static EntityType onCollide(Entity* me, Entity& other, Entity& player, Game& game);
};

#endif

