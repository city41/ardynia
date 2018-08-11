#ifndef tileRoom_h
#define tileRoom_h

#include <Arduino.h>
#include <Arduboy2.h>
#include "tiles.h"

#define TILE_SIZE 8
#define ROOM_TILE_WIDTH 16
#define ROOM_TILE_HEIGHT 8

class TileRoom {
    private:
        const Tiles (*layout)[ROOM_TILE_WIDTH];

    public:
        TileRoom(const Tiles (*layout)[ROOM_TILE_WIDTH]): layout(layout)
        {}

        void render(Arduboy2* arduboy, byte frame);
};

#endif

