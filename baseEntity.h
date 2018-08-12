#ifndef baseEntity_h
#define baseEntity_h

#include <Arduino.h>
#include <Arduboy2.h>
#include "direction.h"
#include "tiles.h"

enum EntityType {
    PLAYER,
    ENEMY,
    ITEM
};

class BaseEntity {
    public:
        EntityType type;
        char x;
        char y;
        char v;
        Direction d;
        char prevX;
        char prevY;

        BaseEntity(EntityType type, char x, char y, char v, Direction d):
            type(type),
            x(x),
            y(y),
            v(v),
            d(d),
            prevX(x),
            prevY(y)
        {}

        virtual void render(Arduboy2* arduboy, byte frame) = 0;
        virtual void update(Arduboy2* arduboy, byte frame) {}

        virtual void moveTo(char newX, char newY) {
            prevX = x;
            prevY = y;
            x = newX;
            y = newY;
        }

        virtual void undoMove() {
            x = prevX;
            y = prevY;
        }

        virtual void onCollide(BaseEntity* other) {}
        virtual void onCollide(Tiles tile) {}
};

#endif

