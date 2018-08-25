#include "tileRoom.h"
#include "bitmaps.h"
#include "util.h"

const uint8_t MAP_HEADER_SIZE = 5;
const uint8_t COMPRESSION_TILE = 0xF;


void TileRoom::render(Renderer* renderer, byte frame) {
    render(renderer, frame, x, y);
}

uint8_t TileRoom::getTileAt(char px, char py) const {
    return 0;
}

void TileRoom::render(Renderer* renderer, byte frame, uint8_t roomX, uint8_t roomY) {
    uint16_t lengthOfMap = pgm_read_word(map);
    uint8_t mapWidth = pgm_read_byte(map + 2);
    uint8_t mapHeight = pgm_read_byte(map + 3);
    uint8_t numRooms = mapWidth * mapHeight;
    uint8_t tileSize = pgm_read_byte(map + 4);
    uint8_t tilesPerRow = (WIDTH - 16) / tileSize;
    uint8_t tilesPerColumn = HEIGHT / tileSize;
    uint8_t tilesPerRoom = tilesPerRow * tilesPerColumn;

    // how far into the dungeon is this room?
    uint8_t roomNumber = mapWidth * roomY + roomX;

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

        if (nibble == COMPRESSION_TILE) {
            uint8_t nextRawTileByte = pgm_read_byte(map + roomIndex + ((curNibbleIndex + 1) >> 1));
            uint8_t count = ((curNibbleIndex + 1) & 1) ? nextRawTileByte & 0xF : nextRawTileByte >> 4;
            uint8_t nextNextRawTileByte = pgm_read_byte(map + roomIndex + ((curNibbleIndex + 2) >> 1));
            uint8_t tileId = ((curNibbleIndex + 2) & 1) ? nextNextRawTileByte & 0xF : nextNextRawTileByte >> 4;

            for (uint8_t c = 0; c < count; ++c) {
                // render tileId at appropriate tx/ty
                uint8_t tx = (curTileIndex + c) % tilesPerRow;
                uint8_t ty = (curTileIndex + c) / tilesPerRow;

                renderer->drawOverwrite(tx * tileSize, ty * tileSize, tiles, tileId);
            }

            curTileIndex += count;
            curNibbleIndex += 3;
        } else {
            // render curTile at appropriate tx/ty
            uint8_t tx = curTileIndex % tilesPerRow;
            uint8_t ty = curTileIndex / tilesPerRow;
            renderer->drawOverwrite(tx * tileSize, ty * tileSize, tiles, nibble);

            curNibbleIndex += 1;
            curTileIndex += 1;
        }
    }
}

