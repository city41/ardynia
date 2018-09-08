#ifndef entity_h
#define entity_h

#include "mirrorMode.h"
#include "direction.h"
#include "entityTypes.h"
#include "util.h"
#include "renderer.h"

class Entity {
    protected:
        Direction determineDirection(int16_t px, int16_t py, int16_t x, int16_t y, Direction prevDir) {
            if (px == x && py == y) {
                return prevDir;
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
        typedef EntityType (*EntityUpdatePtr)(Entity* me, Entity& player, Arduboy2& arduboy, uint8_t frame);
        typedef EntityType (*EntityCollideOtherEntityPtr)(Entity* me, Entity& other, Entity& player);

        EntityUpdatePtr updatePtr;
        EntityCollideOtherEntityPtr collideOtherEntityPtr;

        EntityType type;
        int16_t x;
        int16_t y;
        int16_t prevX;
        int16_t prevY;
        uint8_t width;
        uint8_t height;
        Direction dir;
        const uint8_t* tiles;
        int8_t health;
        int8_t damage;
        uint8_t duration;
        uint8_t currentFrame;
        MirrorMode mirror;
        uint8_t tookDamageCount;
        uint8_t stunCount;
        bool needsMask;

        void moveTowardsOtherEntity(Entity& otherEntity, uint8_t amount);

        Entity():
            updatePtr(NULL),
            collideOtherEntityPtr(NULL),
            type(UNSET),
            x(0),
            y(0),
            prevX(0),
            prevY(0),
            width(0),
            height(0),
            dir(DOWN),
            tiles(NULL),
            health(0),
            damage(0),
            duration(0),
            currentFrame(0),
            mirror(0),
            tookDamageCount(0),
            stunCount(0),
            needsMask(true)
        {}

        /**
         * Move the entity to a new location
         * @param {uint8_t} x new x location
         * @param {uint8_t} y new y location
         * @param {boolean} resetPrev whether to clear out prevX/prevY, this is needed
         * if the entity is moving to an entirely new location, ie from overworld->dungeon
         */ 
        inline virtual void moveTo(int16_t newX, int16_t newY, boolean resetPrev = false) {
            if (resetPrev) {
                prevX = newX;
                prevY = newY;
            } else if (prevX != x || prevY != y) {
                prevX = x;
                prevY = y;
            }

            x = newX;
            y = newY;

            dir = determineDirection(prevX, prevY, x, y, dir);
        }

        inline void stayInside(uint8_t minX, uint8_t maxX, uint8_t minY, uint8_t maxY) {
            x = Util::clamp(x, minX, maxX);
            y = Util::clamp(y, minY, maxY);
        }

        inline bool isOffScreen() {
            return x < 0 || y < 0 || x >= WIDTH - 16 || y >= HEIGHT;
        }

        virtual void undoMove() {
            x = prevX;
            y = prevY;
        }

        virtual void render(Renderer& renderer, uint8_t frame);
        virtual EntityType update(Entity& player, Arduboy2& arduboy, uint8_t frame);
        virtual EntityType onCollide(Entity& other, Entity& player);

        bool overlaps(Entity& other);
        void bounceBack(Entity& bounceAwayFrom);
};

#endif

