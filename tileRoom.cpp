#include "tileRoom.h"
#include "bitmaps.h"
#include "util.h"
#include "drawBitmap.h"

const uint8_t TILE_SIZE = 16;
const uint8_t TILES_PER_ROW = (WIDTH - 16) / TILE_SIZE;
const uint8_t TILES_PER_COLUMN = HEIGHT / TILE_SIZE;
const uint8_t TILES_PER_ROOM = TILES_PER_ROW * TILES_PER_COLUMN;

const uint8_t MAP_HEADER_SIZE = 5;

uint8_t* TileRoom::map = NULL;
uint8_t* TileRoom::tiles = NULL;
uint8_t TileRoom::x = 0;
uint8_t TileRoom::y = 0;
uint8_t TileRoom::mapType = OVERWORLD;

void TileRoom::render(Renderer* renderer, byte frame) {
    render(renderer, frame, x, y);
}

void TileRoom::renderTile(Renderer* renderer, uint8_t x, uint8_t y, const uint8_t* tiles, uint8_t tileId, uint8_t roomIndex, uint8_t seed, uint8_t uniqueSeed) {   
    // algorithmically draw "flavor" in blank spots. this gets us flowers in the overworld
    // without wasting a tile. Only doing this in the overworld as flavor in the dungeons
    // doesn't look good
    if (tileId == 0 && (roomIndex + 1) % seed == 0 && mapType == OVERWORLD) {
        renderer->drawOverwrite(x, y, tiles, 8, uniqueSeed % 2);
        return;
    }

    if (tileId < 8) {
        renderer->drawOverwrite(x, y, tiles, tileId, 0);
        return;
    }

    switch (tileId) {
        case LowerLeftCorner:
            renderer->drawOverwrite(x, y, tiles, UpperLeftCorner, MIRROR_VERTICAL);
            break;
        case UpperRightCorner:
            renderer->drawOverwrite(x, y, tiles, UpperLeftCorner, MIRROR_HORIZONTAL);
            break;
        case LowerRightCorner:
            renderer->drawOverwrite(x, y, tiles, UpperLeftCorner, MIRROR_HORIZONTAL | MIRROR_VERTICAL);
            break;
        case UpperWall:
            renderer->drawOverwrite(x, y, tiles, LowerWall, MIRROR_VERTICAL);
            break;
        case RightWall:
            renderer->drawOverwrite(x, y, tiles, LeftWall, MIRROR_HORIZONTAL);
            break;
    }
}

uint8_t TileRoom::getRoomIndex(uint8_t rx, uint8_t ry) {
    const uint8_t mapWidth = pgm_read_byte(TileRoom::map + 2);

    return mapWidth * ry + rx;
}

uint8_t TileRoom::getTileAt(uint8_t roomX, uint8_t roomY, uint8_t px, uint8_t py) {
    const uint8_t targetTileIndex = (py / TILE_SIZE) * TILES_PER_ROW + (px / TILE_SIZE);

    uint16_t lengthOfMap = pgm_read_word(map);
    uint8_t mapWidth = pgm_read_byte(map + 2);
    uint8_t mapHeight = pgm_read_byte(map + 3);
    uint8_t numRooms = mapWidth * mapHeight;

    // how far into the dungeon is this room?
    uint8_t roomNumber = getRoomIndex(roomX, roomY);

    // grab its starting data index out of the room indices header
    // the stored index does not account for the headers, so tack them on
    // numRooms * 2 -> get past the room indice words
    // + MAP_HEADER_SIZE -> get past the map width, map height and tile size
    uint16_t roomIndex = pgm_read_word(map + MAP_HEADER_SIZE + roomNumber * 2) + (numRooms * 2) + MAP_HEADER_SIZE;
    uint16_t nextRoomIndex;

    if (roomNumber < numRooms - 1) {
        nextRoomIndex = pgm_read_word(map + MAP_HEADER_SIZE + (roomNumber * 2) + 2) + (numRooms * 2) + MAP_HEADER_SIZE;
    } else {
        nextRoomIndex = lengthOfMap;
    }

    uint8_t numNibbles = (nextRoomIndex - roomIndex) * 2;
    uint8_t curNibbleIndex = 0;
    uint8_t curTileIndex = 0;

    while (curNibbleIndex < numNibbles) {
        uint8_t rawTileByte = pgm_read_byte(map + roomIndex + (curNibbleIndex >> 1));
        uint8_t nibble = (curNibbleIndex & 1) ? rawTileByte & 0xF : rawTileByte >> 4;

        if (nibble == Compression) {
            uint8_t nextRawTileByte = pgm_read_byte(map + roomIndex + ((curNibbleIndex + 1) >> 1));
            uint8_t count = ((curNibbleIndex + 1) & 1) ? nextRawTileByte & 0xF : nextRawTileByte >> 4;
            uint8_t nextNextRawTileByte = pgm_read_byte(map + roomIndex + ((curNibbleIndex + 2) >> 1));
            uint8_t tileId = ((curNibbleIndex + 2) & 1) ? nextNextRawTileByte & 0xF : nextNextRawTileByte >> 4;

            if (targetTileIndex >= curTileIndex && targetTileIndex < (curTileIndex + count)) {
                return tileId;
            } else {
                curTileIndex += count;
                curNibbleIndex += 3;
            }
        } else if (curTileIndex == targetTileIndex) {
            return nibble;
        } else {
            curNibbleIndex += 1;
            curTileIndex += 1;
        }
    }
}

/**
 * maps are compressed in two ways:
 *
 * * two tiles per byte, as there are less than 16 tiles
 * * run length encoding is employed to remove long runs of the same tile
 *
 * The RLE is done per room, and there is a header section containing the starting
 * index of each room. This is because with RLE compression, each room will have a different
 * number of bytes
 *
 * The general render algorithm:
 * 1) convert the roomX and roomY coordinate into a linear coordinate
 * 2) with linear coordinate in hand, dive into the room indices part of the header
 * and grab the starting index of the room. This starting index does NOT account for the header!
 * 3) grab the starting index of the next room, that way we can figure out how many bytes 
 * are for the current room
 * 4) iterate over the room's bytes, one nibble at a time.
 *   -- if the nibble is just a regular tile, then render it
 *   -- if the nibble is the compression indicator (0xF, ie 16), then read the next nibble
 *      to get the count (how many times the tile will be repeated). Then read the next nibble
 *      to learn what the tile to render is
 *      render that tile count times
 */
void TileRoom::render(Renderer* renderer, byte frame, uint8_t roomX, uint8_t roomY) {
    uint16_t lengthOfMap = pgm_read_word(map);
    uint8_t mapWidth = pgm_read_byte(map + 2);
    uint8_t mapHeight = pgm_read_byte(map + 3);
    uint8_t numRooms = mapWidth * mapHeight;

    // how far into the dungeon is this room?
    uint8_t roomNumber = getRoomIndex(roomX, roomY);

    // grab its starting data index out of the room indices header
    // the stored index does not account for the headers, so tack them on
    // numRooms * 2 -> get past the room indice words
    // + MAP_HEADER_SIZE -> get past the map width, map height and tile size
    uint16_t roomIndex = pgm_read_word(map + MAP_HEADER_SIZE + roomNumber * 2) + (numRooms * 2) + MAP_HEADER_SIZE;
    uint16_t nextRoomIndex;

    if (roomNumber < numRooms - 1) {
        nextRoomIndex = pgm_read_word(map + MAP_HEADER_SIZE + (roomNumber * 2) + 2) + (numRooms * 2) + MAP_HEADER_SIZE;
    } else {
        nextRoomIndex = lengthOfMap;
    }

    uint8_t numNibbles = (nextRoomIndex - roomIndex) * 2;
    uint8_t curNibbleIndex = 0;
    uint8_t curTileIndex = 0;

    while (curNibbleIndex < numNibbles) {
        uint8_t rawTileByte = pgm_read_byte(map + roomIndex + (curNibbleIndex >> 1));
        uint8_t nibble = (curNibbleIndex & 1) ? rawTileByte & 0xF : rawTileByte >> 4;

        if (nibble == Compression) {
            uint8_t nextRawTileByte = pgm_read_byte(map + roomIndex + ((curNibbleIndex + 1) >> 1));
            uint8_t count = ((curNibbleIndex + 1) & 1) ? nextRawTileByte & 0xF : nextRawTileByte >> 4;
            uint8_t nextNextRawTileByte = pgm_read_byte(map + roomIndex + ((curNibbleIndex + 2) >> 1));
            uint8_t tileId = ((curNibbleIndex + 2) & 1) ? nextNextRawTileByte & 0xF : nextNextRawTileByte >> 4;

            for (uint8_t c = 0; c < count; ++c) {
                // render tileId at appropriate tx/ty
                uint8_t tx = (curTileIndex + c) % TILES_PER_ROW;
                uint8_t ty = (curTileIndex + c) / TILES_PER_ROW;

                renderTile(renderer, tx * TILE_SIZE, ty * TILE_SIZE, tiles, tileId, roomIndex, tx + ty + count, c);
            }

            curTileIndex += count;
            curNibbleIndex += 3;
        } else {
            // render curTile at appropriate tx/ty
            uint8_t tx = curTileIndex % TILES_PER_ROW;
            uint8_t ty = curTileIndex / TILES_PER_ROW;
            renderTile(renderer, tx * TILE_SIZE, ty * TILE_SIZE, tiles, nibble, roomIndex, tx + ty, tx);

            curNibbleIndex += 1;
            curTileIndex += 1;
        }
    }
}

