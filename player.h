#ifndef player_h
#define player_h

#include "baseEntity.h"

class Player: public BaseEntity {
    private:
        bool movedThisFrame;

    public:
        Player(char x, char y):
            BaseEntity(PLAYER, x, y, 2, DOWN),
            movedThisFrame(false)
        {}

        virtual void render(Renderer* renderer, byte frame) override;
        virtual void update(Arduboy2* arduboy, byte frame) override;
        virtual void onCollide(uint8_t tile) override;
};

#endif

