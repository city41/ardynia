#ifndef tileRoom_h
#define tileRoom_h

#include <Arduino.h>
#include <Arduboy2.h>
#include "renderer.h"

#define TILES_PER_ROW 14
#define TILES_PER_COLUMN 8
#define TILE_SIZE 8

class TileRoom {
    private:
        const uint8_t* map;
        const uint8_t* tiles;

    public:
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
        uint8_t getTileAt(char px, char py) const;
};

#endif

