#ifndef overworldMap_h
#define overworldMap_h

#include "rooms.h"

struct MapRoomDef {
    const RoomDef* roomDef;
    const uint8_t up;
    const uint8_t down;
    const uint8_t left;
    const uint8_t right;
};

const MapRoomDef overworldMap[] = {
    {
        NULL,
        0,
        0,
        0,
        0
    },
    {
        &firstRoomDef,
        0,
        2,
        3,
        0
    },
    {
        &secondRoomDef,
        1,
        0,
        0,
        0
    },
    {
        &leftRoomDef,
        0,
        0,
        0,
        1
    }
};

#endif

