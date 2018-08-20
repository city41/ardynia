#ifndef baseEntity_h
#define baseEntity_h

#include <Arduino.h>
#include <Arduboy2.h>
#include "renderer.h"
#include "direction.h"
#include "tiles.h"

enum EntityType {
    UNSET = 0,
    PLAYER = 1,
    BLOB = 2
};

class BaseEntity {
    protected:
        Direction determineDirection(int16_t px, int16_t py, int16_t x, int16_t y, Direction pd) {
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
        uint8_t w;
        uint8_t h;
        int8_t v;
        Direction d;
        int16_t prevX;
        int16_t prevY;

        BaseEntity():
            type(UNSET),
            x(0),
            y(0),
            v(0),
            d(DOWN),
            prevX(0),
            prevY(0)
        {}

        BaseEntity(EntityType type, int16_t x, int16_t y, uint8_t w, uint8_t h, int8_t v, Direction d):
            type(type),
            x(x),
            y(y),
            w(w),
            h(h),
            v(v),
            d(d),
            prevX(x),
            prevY(y)
        {}

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

        virtual void render(Renderer* renderer, uint8_t frame) = 0;
        virtual EntityType update(Arduboy2* arduboy, uint8_t frame) = 0;
        virtual void onCollide(BaseEntity* other) = 0;
        virtual void onCollide(uint8_t tile) = 0;

        bool overlaps(BaseEntity* other);
};

#endif

