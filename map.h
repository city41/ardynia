#ifndef map_h
#define map_h

#include <Arduino.h>
#include "renderer.h"

const uint8_t MAX_NUM_VISITED_ROOMS = 12 * 7;
const uint8_t VISITED_ROOMS_BYTE_COUNT = MAX_NUM_VISITED_ROOMS / 8 + 1;

struct Map {
    static uint8_t visitedRooms[VISITED_ROOMS_BYTE_COUNT];

    static void render(Renderer& renderer, uint8_t mapWidthInRooms, uint8_t mapHeightInRooms, uint8_t currentRoomX, uint8_t currentRoomY);
    static void visitRoom(uint8_t roomX, uint8_t roomY, uint8_t mapWidthInRooms);
    static void reset();
};


#endif

