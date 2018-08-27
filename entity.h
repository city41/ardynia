#ifndef entity_h
#define entity_h

#include "baseEntity.h"

class Entity: public BaseEntity {
    public:
        typedef EntityType (*EntitySpawnPtr)(Entity* me, BaseEntity* player);
        typedef EntityType (*EntityUpdatePtr)(Entity* me, BaseEntity* player, Arduboy2* arduboy, uint8_t frame);
        typedef EntityType (*EntityRenderPtr)(Entity* me, Renderer* renderer, uint8_t frame);
        typedef EntityType (*EntityCollideOtherEntityPtr)(Entity* me, BaseEntity* other);

        EntitySpawnPtr spawnPtr;
        EntityUpdatePtr updatePtr;
        EntityRenderPtr renderPtr;
        EntityCollideOtherEntityPtr collideOtherEntityPtr;

        Entity():
            BaseEntity(),
            spawnPtr(NULL),
            updatePtr(NULL),
            renderPtr(NULL),
            collideOtherEntityPtr(NULL)
        {}

        Entity(
            EntityType type,
            uint8_t width,
            uint8_t height,
            Direction dir,
            uint8_t* tiles,
            uint8_t* maskTiles,
            int8_t health,
            int8_t damage,
            uint8_t duration,
            EntitySpawnPtr spawnPtr,
            EntityUpdatePtr updatePtr,
            EntityRenderPtr renderPtr, 
            EntityCollideOtherEntityPtr collideOtherEntityPtr
        ):
            BaseEntity(
                type,
                width,
                height,
                dir,
                tiles,
                maskTiles,
                health,
                damage,
                duration
            ),
            spawnPtr(spawnPtr),
            updatePtr(updatePtr),
            renderPtr(renderPtr),
            collideOtherEntityPtr(collideOtherEntityPtr)
        {}

        EntityType spawn(BaseEntity* player);

        virtual EntityType render(Renderer* renderer, uint8_t frame) override;
        virtual EntityType update(BaseEntity* player, Arduboy2* arduboy, uint8_t frame) override;
        virtual EntityType onCollide(BaseEntity* other) override;
        virtual EntityType onCollide(uint8_t tile) override;

};

#endif

