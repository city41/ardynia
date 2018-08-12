#ifndef tileRoom_h
#define tileRoom_h

#include <Arduino.h>
#include <Arduboy2.h>
#include "rooms.h"
#include "tiles.h"


class TileRoom {
    private:
        const RoomDef* roomDef;

    public:
        TileRoom(const RoomDef* roomDef):
            roomDef(roomDef)
        {}

        void render(Arduboy2* arduboy, byte frame);
        uint8_t getTileAt(char px, char py) const;
};

#endif

