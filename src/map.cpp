#include "map.h"
#include "state.h"
#include "strings.h"
#include "tileBitmaps.h"
#include "renderer.h"

extern Renderer renderer;

const uint8_t MAX_NUM_VISITED_ROOMS = 8 * 8;

void Map::render(uint8_t currentRoomX, uint8_t currentRoomY, uint8_t mapWidthInRooms) {
    const uint8_t dungeonIndex = State::gameState.currentDungeon;

    if (dungeonIndex > 3) {
        return;
    }

    // "MAP" label
    renderer.drawString(0, 2, map_string);

    for (uint8_t roomIndex = 0; roomIndex < MAX_NUM_VISITED_ROOMS; ++roomIndex) {
        const uint8_t roomY = roomIndex / mapWidthInRooms;
        const uint8_t roomX = roomIndex % mapWidthInRooms;

        const uint8_t byteToGrab = roomIndex >> 3;
        const uint8_t bitToGrab = roomIndex % 8;
        const uint8_t bitMask = 1 << bitToGrab;

        const bool hasVisited = State::gameState.mapStates[dungeonIndex][byteToGrab] & bitMask;

        int8_t frame = 0;
        if (roomX == currentRoomX && roomY == currentRoomY) {
            frame = 1;
        } else if (hasVisited) {
            frame = 2;
        }

        renderer.drawOverwrite(2 + roomX * 4, 8 + roomY * 4, squareIcon_tiles, frame);
    }
}

void Map::visitRoom(uint8_t roomX, uint8_t roomY, uint8_t mapWidthInRooms) {
    const uint8_t dungeonIndex = State::gameState.currentDungeon;

    if (dungeonIndex > 3) {
        return;
    }

    const uint8_t roomIndex = roomY * mapWidthInRooms + roomX;
    const uint8_t byteToSet = roomIndex >> 3;
    const uint8_t bitToSet = roomIndex % 8;
    const uint8_t bitMask = 1 << bitToSet;

    State::gameState.mapStates[dungeonIndex][byteToSet] |= bitMask;
}

