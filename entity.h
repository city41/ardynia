#ifndef entity_h
#define entity_h

#include "baseEntity.h"

class Entity: public BaseEntity {
    typedef EntityType (*EntityUpdatePtr)(Entity* entity, Arduboy2* arduboy, uint8_t frame);
    typedef void (*EntityRenderPtr)(Entity* entity, Renderer* renderer, uint8_t frame);

    public:
        EntityUpdatePtr updatePtr;
        EntityRenderPtr renderPtr;
        uint8_t* tiles;

        Entity():
            BaseEntity(),
            updatePtr(NULL),
            renderPtr(NULL)
        {}

        virtual void render(Renderer* renderer, uint8_t frame) override;
        virtual EntityType update(Arduboy2* arduboy, uint8_t frame) override;
        virtual void onCollide(BaseEntity* other) override;
        virtual void onCollide(uint8_t tile) override;

};

#endif

