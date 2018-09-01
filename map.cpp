#include "map.h"
#include "state.h"

uint8_t Map::visitedRooms[VISITED_ROOMS_BYTE_COUNT];

void Map::render(Renderer* renderer, uint8_t mapWidthInRooms, uint8_t mapHeightInRooms, uint8_t currentRoomX, uint8_t currentRoomY) {
    // boundary rectangle
    renderer->print(0, 0, F("MAP"));

    if (mapHeightInRooms > 0) {
        renderer->drawRect(0, 6, mapWidthInRooms * 4 + 3, mapHeightInRooms * 4 + 3, WHITE);
    }

    for (uint8_t roomIndex = 0; roomIndex < MAX_NUM_VISITED_ROOMS; ++roomIndex) {
        const uint8_t roomY = roomIndex / mapWidthInRooms;
        const uint8_t roomX = roomIndex % mapWidthInRooms;

        const uint8_t byteToGrab = roomIndex >> 3;
        const uint8_t bitToGrab = roomIndex % 8;
        const uint8_t bitMask = 1 << bitToGrab;

        const bool hasVisited = visitedRooms[byteToGrab] & bitMask;

        if (roomX == currentRoomX && roomY == currentRoomY) {
            renderer->drawRect(2 + roomX * 4, 8 + roomY * 4, 3, 3, WHITE);
        } else if (hasVisited) {
            renderer->fillRect(2 + roomX * 4, 8 + roomY * 4, 3, 3, WHITE);
        }
    }
}

void Map::visitRoom(uint8_t roomX, uint8_t roomY, uint8_t mapWidthInRooms) {
    const uint8_t roomIndex = roomY * mapWidthInRooms + roomX;
    const uint8_t byteToSet = roomIndex >> 3;
    const uint8_t bitToSet = roomIndex % 8;
    const uint8_t bitMask = 1 << bitToSet;

    visitedRooms[byteToSet] |= bitMask;
}

void Map::reset() {
    memset(visitedRooms, 0, VISITED_ROOMS_BYTE_COUNT);
}
