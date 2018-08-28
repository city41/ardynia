#ifndef baseEntity_h
#define baseEntity_h

#include <Arduino.h>
#include <Arduboy2.h>
#include "renderer.h"
#include "direction.h"
#include "entityTypes.h"
#include "drawBitmap.h"


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
        int16_t prevX;
        int16_t prevY;
        uint8_t width;
        uint8_t height;
        Direction dir;
        uint8_t* tiles;
        uint8_t* maskTiles;
        int8_t health;
        int8_t damage;
        uint8_t duration;
        uint8_t currentFrame;
        MirrorMode mirror;
        bool invert;
        uint8_t tookDamageCount;
        uint8_t stunCount;

        BaseEntity():
            type(UNSET),
            x(0),
            y(0),
            prevX(0),
            prevY(0),
            width(0),
            height(0),
            dir(DOWN),
            tiles(NULL),
            maskTiles(NULL),
            health(0),
            damage(0),
            duration(0),
            currentFrame(0),
            mirror(0),
            invert(false),
            tookDamageCount(0),
            stunCount(0)
        {}

        BaseEntity(
            EntityType type,
            uint8_t width,
            uint8_t height,
            Direction dir,
            uint8_t* tiles,
            uint8_t* maskTiles,
            int8_t health,
            int8_t damage,
            uint8_t duration
        ):
            type(type),
            x(-5000),
            y(-5000),
            prevX(-5000),
            prevY(-5000),
            width(width),
            height(height),
            dir(dir),
            tiles(tiles),
            maskTiles(maskTiles),
            health(health),
            damage(damage),
            duration(duration),
            currentFrame(0),
            mirror(0),
            invert(false),
            tookDamageCount(0),
            stunCount(0)
        {}

        virtual void moveTo(int16_t newX, int16_t newY) {
            prevX = x;
            prevY = y;
            x = newX;
            y = newY;

            dir = determineDirection(prevX, prevY, x, y, dir);
        }

        virtual void undoMove() {
            x = prevX;
            y = prevY;
        }

        virtual EntityType render(Renderer* renderer, uint8_t frame) = 0;
        virtual EntityType update(BaseEntity* player, Arduboy2* arduboy, uint8_t frame) = 0;
        virtual EntityType onCollide(BaseEntity* other) = 0;

        bool overlaps(BaseEntity* other);
        void bounceBack(void);
};

#endif

