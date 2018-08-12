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
        &upperCenterRoomDef,
        0,
        2,
        3,
        6
    },
    {
        &lowerCenterRoomDef,
        1,
        0,
        5,
        4
    },
    {
        &upperLeftRoomDef,
        0,
        5,
        0,
        1
    },
    {
        &lowerRightRoomDef,
        6,
        0,
        2,
        0
    },
    {
        &lowerLeftRoomDef,
        3,
        0,
        0,
        2
    },
    {
        &upperRightRoomDef,
        0,
        4,
        1,
        0
    },
};

#endif

