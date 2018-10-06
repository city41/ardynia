#ifndef lock_h
#define lock_h

#include "../entity.h"
#include "../entityTypes.h"

class Player;

struct Lock {
    static EntityType onCollide(Entity* me, Entity& other, Player& player);
};

#endif

