#include "tileRoom.h"
#include "bitmaps.h"

const uint8_t MAP_HEADER_SIZE = 3;


void TileRoom::render(Renderer* renderer, byte frame) {
    render(renderer, frame, x, y);
}

void TileRoom::render(Renderer* renderer, byte frame, uint8_t roomX, uint8_t roomY) {
    uint8_t mapWidth = pgm_read_byte(map);
    // the map height is at map + 1
    uint8_t tileSize = pgm_read_byte(map + 2);
    uint8_t tilesPerRow = ((WIDTH - 16) / tileSize) / 2;
    uint8_t tilesPerColumn = HEIGHT / tileSize;


    for (uint8_t tx = 0; tx < tilesPerRow; ++tx) {
        for (uint8_t ty = 0; ty < tilesPerColumn; ++ty) {
            uint16_t tileIndex = 
                (mapWidth * tilesPerRow * tilesPerColumn * roomY) + 
                (tilesPerRow * roomX) +
                (mapWidth * tilesPerRow * ty) +
                tx +
                MAP_HEADER_SIZE;

            uint8_t tileNibbles = pgm_read_byte(map + tileIndex);
            uint8_t upperTile = (tileNibbles >> 4) & 0x0F;
            uint8_t lowerTile = tileNibbles & 0x0F;

            renderer->drawOverwrite((tx * 2) * tileSize, ty * tileSize, tiles, upperTile);
            renderer->drawOverwrite((tx * 2 + 1) * tileSize, ty * tileSize, tiles, lowerTile);
        }
    }
}

uint8_t TileRoom::getTileAt(char px, char py) const {
    return 0;
}


