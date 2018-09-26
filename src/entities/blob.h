#ifndef blob_h
#define blob_h

#include <Arduboy2.h>
#include "../entity.h"
#include "../entityTypes.h"

class Game;

struct Blob {
    static EntityType update(Entity* me, Entity& player, Game& game, Arduboy2Base& arduboy, uint8_t frame);
    static EntityType onCollide(Entity* me, Entity& other, Entity& player, Game& game);
};

#endif

