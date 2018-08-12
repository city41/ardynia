#ifndef tileRoom_h
#define tileRoom_h

#include <Arduino.h>
#include <Arduboy2.h>
#include "tiles.h"


class TileRoom {
    private:
        const uint8_t (*layout)[ROOM_TILE_WIDTH];

    public:
        TileRoom(const uint8_t (*layout)[ROOM_TILE_WIDTH]): layout(layout)
        {}

        void render(Arduboy2* arduboy, byte frame);
        uint8_t getTileAt(char px, char py) const;
};

#endif

