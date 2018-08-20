#ifndef player_h
#define player_h

#include <Arduino.h>
#include "baseEntity.h"

class Player: public BaseEntity {
    private:
        bool movedThisFrame;
        uint8_t ignoreMovementCount;

        void bounceBack(void);

    public:
        uint8_t health;

        Player(int16_t x, int16_t y, uint8_t health):
            BaseEntity(PLAYER, x, y, 16, 16, 2, DOWN),
            movedThisFrame(false),
            ignoreMovementCount(0),
            health(health)
        {}

        virtual void render(Renderer* renderer, uint8_t frame) override;
        virtual EntityType update(Arduboy2* arduboy, uint8_t frame) override;
        virtual void onCollide(uint8_t tile) override;
        virtual void onCollide(BaseEntity* other) override;
};

#endif

