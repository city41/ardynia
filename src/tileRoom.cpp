#include "tileRoom.h"
#include "tileBitmaps.h"
#include "util.h"
#include "drawBitmap.h"
#include "state.h"
#include "renderer.h"

extern Renderer renderer;

// header consists of
// length of the data (two bytes)
// map width (one byte)
// map height (one byte)
// for a total of 4 bytes
const uint8_t MAP_HEADER_SIZE = 4;

const uint8_t* TileRoom::map = NULL;
TileDef TileRoom::rooms[TILES_PER_ROOM * 2];
uint8_t TileRoom::x = 0;
uint8_t TileRoom::y = 0;
uint8_t TileRoom::currentRoomOffset = 0;
uint8_t TileRoom::nextRoomOffset = TILES_PER_ROOM;

const uint8_t PROGMEM mirroredTiles[] = {
    UpperLeftCorner,
    MIRROR_VERTICAL,
    UpperLeftCorner,
    MIRROR_HORIZONTAL,
    UpperLeftCorner,
    MIRROR_HORIZONTAL | MIRROR_VERTICAL,
    LowerWall,
    MIRROR_VERTICAL,
    LeftWall,
    MIRROR_HORIZONTAL
};

void TileRoom::renderTile(uint8_t x, uint8_t y, TileDef tileId, uint8_t seed) {   
    // algorithmically draw "flavor" in blank spots. this gets us flowers in the overworld
    // without wasting a tile. Only doing this in the overworld as flavor in the dungeons
    // doesn't look good
    if (tileId == 0 && !State::isInDungeon() && (seed % 7 == 1)) {
        renderer.drawOverwrite(x, y, map_tiles, 8, seed);
        return;
    }

    TileDef tile = tileId < 8 ? tileId : (TileDef)pgm_read_byte(mirroredTiles + (tileId - LowerLeftCorner) * 2);
    MirrorMode mirror = tileId < 8 ? 0 : pgm_read_byte(mirroredTiles + (tileId - LowerLeftCorner) * 2 + 1);
    bool dontInvert = !State::isInDungeon() || (tileId >= 5 && tileId <= 7);
    DrawMode drawMode = dontInvert ? Normal : Invert;
    renderer.drawOverwrite(x, y, map_tiles, tile, mirror, drawMode);
}

uint8_t TileRoom::getRoomIndex(uint8_t rx, uint8_t ry) {
    const uint8_t mapWidth = pgm_read_byte(TileRoom::map + 2);

    return mapWidth * ry + rx;
}

TileDef TileRoom::getTileAt(uint8_t px, uint8_t py) {
    const uint8_t targetTileIndex = (py / TILE_SIZE) * TILES_PER_ROW + (px / TILE_SIZE);
    return (TileDef)rooms[currentRoomOffset + targetTileIndex];
}

void TileRoom::setTileAt(uint8_t px, uint8_t py, uint8_t offset, TileDef tile) {
    const uint8_t targetTileIndex = (py / TILE_SIZE) * TILES_PER_ROW + (px / TILE_SIZE);
    rooms[offset + targetTileIndex] = tile;
}

void TileRoom::renderRoom(uint8_t offset) {
    TileDef* tiles = rooms + offset;
    uint8_t seed = 0;

    for (uint8_t ti = 0; ti < TILES_PER_ROOM; ++ti) {
        uint8_t tx = ti % TILES_PER_ROW;
        uint8_t ty = ti / TILES_PER_ROW;
        TileDef tileId = tiles[ti];
        seed += tileId + 1;

        renderTile(tx * TILE_SIZE, ty * TILE_SIZE, tileId, seed);
    }
}

/**
 * Load a compressed room from progmem into RAM
 *
 * maps are compressed in two ways:
 *
 * * two tiles per byte, as there are less than 16 tiles
 * * run length encoding is employed to remove long runs of the same tile
 *
 * The RLE is done per room, and there is a header section containing the starting
 * index of each room. This is because with RLE compression, each room will have a different
 * number of bytes
 *
 * The general decompression approach:
 * 1) convert the roomX and roomY coordinate into a linear coordinate
 * 2) with linear coordinate in hand, dive into the room indices part of the header
 * and grab the starting index of the room. This starting index does NOT account for the header!
 * 3) grab the starting index of the next room, that way we can figure out how many bytes 
 * are for the current room
 * 4) iterate over the room's bytes, one nibble at a time.
 *   -- if the nibble is just a regular tile, then dump it
 *   -- if the nibble is the compression indicator (0xF, ie 16), then read the next nibble
 *      to get the count (how many times the tile will be repeated). Then read the next nibble
 *      to learn what the tile to render is
 *      dump that tile count times
 */
void TileRoom::loadRoom(uint8_t roomX, uint8_t roomY, uint8_t offset) {
    uint16_t lengthOfMap = pgm_read_word(map);
    uint8_t mapWidth = pgm_read_byte(map + 2);
    uint8_t mapHeight = pgm_read_byte(map + 3);
    uint8_t numRooms = mapWidth * mapHeight;

    // how far into the map is this room?
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
    uint8_t maxOffset = offset + TILES_PER_ROOM;

    while (curNibbleIndex < numNibbles) {
        uint8_t rawTileByte = pgm_read_byte(map + roomIndex + (curNibbleIndex >> 1));
        uint8_t nibble = (curNibbleIndex & 1) ? rawTileByte & 0xF : rawTileByte >> 4;

        if (nibble == Compression) {
            uint8_t nextRawTileByte = pgm_read_byte(map + roomIndex + ((curNibbleIndex + 1) >> 1));

            // a count nibble can be either at the top or bottom of a byte, basically compression treats
            // nibbles as first class
            uint8_t count = ((curNibbleIndex + 1) & 1) ? nextRawTileByte & 0xF : nextRawTileByte >> 4;
            uint8_t nextNextRawTileByte = pgm_read_byte(map + roomIndex + ((curNibbleIndex + 2) >> 1));
            TileDef tileId = static_cast<TileDef>(((curNibbleIndex + 2) & 1) ? nextNextRawTileByte & 0xF : nextNextRawTileByte >> 4);

            for (uint8_t c = 0; c < count + 4; ++c) {
                rooms[offset++] = tileId;
            }

            // jump past the compression block of <compression nibble><count nibble><template nibble>
            curNibbleIndex += 3;
        } else {
            // need to make sure don't go beyond the room offset in the case of when a compression
            // run leaves a dead nibble at the end of the room, otherwise will clobber other memory
            if (offset < maxOffset) {
                rooms[offset++] = (TileDef)nibble;
            }

            curNibbleIndex += 1;
        }
    }
}

void TileRoom::swapRooms() {
    uint8_t temp = currentRoomOffset;
    currentRoomOffset = nextRoomOffset;
    nextRoomOffset = temp;
}
