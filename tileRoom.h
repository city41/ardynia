#ifndef tileRoom_h
#define tileRoom_h

#include <Arduino.h>
#include <Arduboy2.h>
#include "renderer.h"

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
        uint8_t getTileAt(char px, char py) const;
};

#endif

