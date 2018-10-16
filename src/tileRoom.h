#ifndef tileRoom_h
#define tileRoom_h

#include <Arduino.h>
#include <Arduboy2.h>
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

    // these tiles are mirrors of the above sprites
    LowerLeftCorner = 8,
    UpperRightCorner = 9,
    LowerRightCorner = 10,
    UpperWall = 11,
    RightWall = 12,
    Compression = 15
};

const uint8_t TILE_SIZE = 16;
const uint8_t TILES_PER_ROW = (WIDTH - 16) / TILE_SIZE;
const uint8_t TILES_PER_COLUMN = HEIGHT / TILE_SIZE;
const uint8_t TILES_PER_ROOM = TILES_PER_ROW * TILES_PER_COLUMN;

struct TileRoom {
        static const uint8_t* map;
        static TileDef rooms[TILES_PER_ROOM * 2];
        static uint8_t x;
        static uint8_t y;
        static uint8_t currentRoomOffset;
        static uint8_t nextRoomOffset;

        static void renderTile(uint8_t x, uint8_t y, TileDef tileId, uint8_t seed);
        static uint8_t getRoomIndex(uint8_t x, uint8_t y);
        static TileDef getTileAt(uint8_t px, uint8_t py);
        static void setTileAt(uint8_t px, uint8_t py, uint8_t offset, TileDef tile);

        static void renderRoom(uint8_t offset);

        static void loadRoom(uint8_t roomX, uint8_t roomY, uint8_t offset);
        static void loadCurrentRoom(uint8_t roomX, uint8_t roomY);
        static void loadNextRoom(uint8_t roomX, uint8_t roomY);
        static void swapRooms(void);
};

#endif

