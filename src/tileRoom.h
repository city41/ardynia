#ifndef tileRoom_h
#define tileRoom_h

#include <Arduino.h>
#include <Arduboy2.h>
#include "renderer.h"
#include "dungeons.h"

typedef uint8_t TileDef;

// these tiles have their own sprites
const TileDef Blank = 0;
const TileDef UpperLeftCorner = 1;
const TileDef LeftWall = 2;
const TileDef LowerWall = 3;
const TileDef Stone = 4;
const TileDef Ladder = 5;
const TileDef Water = 6;
const TileDef Door = 7;
const TileDef LeftFlavor = 8;
const TileDef RightFlavor = 9;

// these tiles are mirrors of the above sprites
const TileDef LowerLeftCorner = 10;
const TileDef UpperRightCorner = 11;
const TileDef LowerRightCorner = 12;
const TileDef UpperWall = 13;
const TileDef RightWall = 14;
const TileDef Compression = 0xF;

typedef uint8_t MapType;
const MapType OVERWORLD = 0;
const MapType DUNGEON = 1;

class TileRoom {
    private:
        static void renderTile(Renderer& renderer, uint8_t x, uint8_t y, uint8_t tileId, uint8_t roomIndex, uint8_t seed, uint8_t uniqueSeed);

    public:
        static MapType mapType;
        static const uint8_t* map;

        static uint8_t x;
        static uint8_t y;

        static boolean isInDungeon() { return mapType == DUNGEON; }
        static uint8_t getRoomIndex(uint8_t x, uint8_t y);
        static uint8_t getTileAt(uint8_t rx, uint8_t ry, uint8_t px, uint8_t py);
        static void render(Renderer& renderer, byte frame, uint8_t roomX, uint8_t roomY);
        static void render(Renderer& renderer, byte frame);
};

#endif

