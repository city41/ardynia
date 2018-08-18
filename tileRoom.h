#ifndef tileRoom_h
#define tileRoom_h

#include <Arduino.h>
#include <Arduboy2.h>
#include "renderer.h"


class TileRoom {
    private:
        const uint8_t* map;
        const uint8_t* tiles;
        const uint8_t roomX;
        const uint8_t roomY;

    public:
        TileRoom(const uint8_t* map, const uint8_t* tiles, uint8_t roomX, uint8_t roomY):
            map(map),
            tiles(tiles),
            roomX(roomX),
            roomY(roomY)
        {}

        void render(Renderer *renderer, byte frame);
        uint8_t getTileAt(char px, char py) const;
};

#endif

