#ifndef baseEntity_h
#define baseEntity_h

#include <Arduino.h>
#include <Arduboy2.h>
#include "renderer.h"
#include "direction.h"
#include "tiles.h"

enum EntityType {
    PLAYER,
    ENEMY,
    ITEM
};

class BaseEntity {
    protected:
        Direction determineDirection(char px, char py, char x, char y, Direction pd) {
            if (px == x && py == y) {
                return pd;
            }

            if (px == x) {
                if (py > y) {
                    return UP;
                }
                return DOWN;
            } else {
                if (px > x) {
                    return LEFT;
                }
                return RIGHT;
            }
        }

    public:
        EntityType type;
        int16_t x;
        int16_t y;
        int8_t v;
        Direction d;
        int16_t prevX;
        int16_t prevY;

        BaseEntity(EntityType type, int16_t x, int16_t y, int8_t v, Direction d):
            type(type),
            x(x),
            y(y),
            v(v),
            d(d),
            prevX(x),
            prevY(y)
        {}

        virtual void render(Renderer* renderer, byte frame) = 0;
        virtual void update(Arduboy2* arduboy, byte frame) {}

        virtual void moveTo(int16_t newX, int16_t newY) {
            prevX = x;
            prevY = y;
            x = newX;
            y = newY;

            d = determineDirection(prevX, prevY, x, y, d);
        }

        virtual void undoMove() {
            x = prevX;
            y = prevY;
        }

        virtual void onCollide(BaseEntity* other) {}
        virtual void onCollide(uint8_t tile) {}
};

#endif

