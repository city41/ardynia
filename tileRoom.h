#ifndef tileRoom_h
#define tileRoom_h

#include <Arduino.h>
#include <Arduboy2.h>
#include "renderer.h"

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

// these tiles are mirrors of the above sprites
const TileDef LowerLeftCorner = 8;
const TileDef UpperRightCorner = 9;
const TileDef LowerRightCorner = 10;
const TileDef UpperWall = 11;
const TileDef RightWall = 12;
const TileDef Compression = 0xF;

class TileRoom {
    public:
        const uint8_t* map;
        const uint8_t* tiles;

        uint8_t x;
        uint8_t y;

        TileRoom(const uint8_t* map, const uint8_t* tiles, const uint8_t x, const uint8_t y):
            map(map),
            tiles(tiles),
            x(x),
            y(y)
        {}

        void render(Renderer *renderer, byte frame, uint8_t roomX, uint8_t roomY);
        void render(Renderer *renderer, byte frame);
};

#endif

