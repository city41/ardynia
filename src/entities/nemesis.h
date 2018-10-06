#ifndef nemesis_h
#define nemesis_h

#include "../entity.h"
#include "../entityTypes.h"

void loadEntity(Entity& entity, EntityType entityType);

enum NemesisMode: uint8_t {
    Pursue,
    StartAttack,
    Attacking,
    Teleport,
    Hold
};

struct Nemesis {
    static NemesisMode mode;
    static Entity sword;
    static EntityType update(Entity* me, Entity& player, uint8_t frame);
    static EntityType onCollide(Entity* me, Entity& other, Entity& player);
};

#endif

