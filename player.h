#ifndef player_h
#define player_h

#include "baseEntity.h"

class Player: public BaseEntity {
    public:
        Player(char x, char y):
            BaseEntity(x, y)
        {}

        virtual void update(Arduboy2* arduboy, byte frame);
        virtual void render(Arduboy2* arduboy, byte frame);
};

#endif

