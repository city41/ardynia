#ifndef tileRoom_h
#define tileRoom_h

#include <Arduino.h>
#include <Arduboy2.h>
#include "renderer.h"
#include "dungeons.h"

enum TileDef: uint8_t {
    Blank = 0,
    UpperLeftCorner = 1,
    LeftWall = 2,
    LowerWall = 3,
    Stone = 4,
    Ladder = 5,
    Water = 6,
    Door = 7,
    LeftFlavor = 8,
    RightFlavor = 9,

    // these tiles are mirrors of the above sprites
    LowerLeftCorner = 10,
    UpperRightCorner = 11,
    LowerRightCorner = 12,
    UpperWall = 13,
    RightWall = 14,
    Compression = 15
};

const uint8_t TILE_SIZE = 16;
const uint8_t TILES_PER_ROW = (WIDTH - 16) / TILE_SIZE;
const uint8_t TILES_PER_COLUMN = HEIGHT / TILE_SIZE;
const uint8_t TILES_PER_ROOM = TILES_PER_ROW * TILES_PER_COLUMN;

struct TileRoom {
        static const uint8_t* map;
        static uint8_t rooms[TILES_PER_ROOM * 2];
        static uint8_t x;
        static uint8_t y;
        static uint8_t currentRoomOffset;
        static uint8_t nextRoomOffset;

        static void renderTile(Renderer& renderer, uint8_t x, uint8_t y, uint8_t tileId, uint8_t seed);
        static uint8_t getRoomIndex(uint8_t x, uint8_t y);
        static uint8_t getTileAt(uint8_t px, uint8_t py);

        static void renderRoom(Renderer& renderer, uint8_t offset);

        static void loadRoom(uint8_t roomX, uint8_t roomY, uint8_t offset);
        static void loadCurrentRoom(uint8_t roomX, uint8_t roomY);
        static void loadNextRoom(uint8_t roomX, uint8_t roomY);
        static void swapRooms(void);
};

#endif

