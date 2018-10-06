#ifndef map_h
#define map_h

#include <Arduino.h>

struct Map {
    static void render(uint8_t currentRoomX, uint8_t currentRoomY, uint8_t mapWidthInRooms);
    static void visitRoom(uint8_t roomX, uint8_t roomY, uint8_t mapWidthInRooms);
};


#endif

