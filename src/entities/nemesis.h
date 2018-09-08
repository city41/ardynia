#ifndef nemesis_h
#define nemesis_h

#include <Arduboy2.h>
#include "../entity.h"
#include "../entityTypes.h"

class Game;
void loadEntity(Entity& entity, EntityType entityType);

typedef uint8_t NemesisMode;
const NemesisMode PURSUE = 0;
const NemesisMode START_ATTACK = 1;
const NemesisMode ATTACKING = 2;
const NemesisMode TELEPORT = 3;
const NemesisMode HOLD = 4;

struct Nemesis {
    static NemesisMode mode;
    static Entity sword;
    static EntityType update(Entity* me, Entity& player, Arduboy2& arduboy, uint8_t frame);
    static EntityType onCollide(Entity* me, Entity& other, Entity& player, Game& game);
};

#endif

