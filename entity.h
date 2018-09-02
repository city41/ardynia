#ifndef entity_h
#define entity_h

#include "baseEntity.h"

class Entity: public BaseEntity {
    public:
        typedef EntityType (*EntitySpawnPtr)(Entity* me, BaseEntity* spawner, BaseEntity* player);
        typedef EntityType (*EntityUpdatePtr)(Entity* me, BaseEntity* player, Arduboy2* arduboy, uint8_t frame);
        typedef EntityType (*EntityRenderPtr)(Entity* me, Renderer* renderer, uint8_t frame);
        typedef EntityType (*EntityCollideOtherEntityPtr)(Entity* me, BaseEntity* other, BaseEntity* player);

        EntitySpawnPtr spawnPtr;
        EntityUpdatePtr updatePtr;
        EntityRenderPtr renderPtr;
        EntityCollideOtherEntityPtr collideOtherEntityPtr;

        int8_t health;
        uint8_t invertInDungeon;

        Entity():
            BaseEntity(),
            spawnPtr(NULL),
            updatePtr(NULL),
            renderPtr(NULL),
            collideOtherEntityPtr(NULL),
            health(0),
            invertInDungeon(false)
        {}

        EntityType spawn(BaseEntity* spawner, BaseEntity* player);

        virtual EntityType render(Renderer* renderer, uint8_t frame) override;
        virtual EntityType update(BaseEntity* player, Arduboy2* arduboy, uint8_t frame) override;
        virtual EntityType onCollide(BaseEntity* other, BaseEntity* player) override;
};

#endif

