#include "tileRoom.h"
#include "bitmaps.h"


void TileRoom::render(Renderer* renderer, byte frame) {
    render(renderer, frame, x, y);
}

void TileRoom::render(Renderer* renderer, byte frame, uint8_t roomX, uint8_t roomY) {
    uint8_t mapWidth = pgm_read_byte(map);

    for (uint8_t tx = 0; tx < TILES_PER_ROW; ++tx) {
        for (uint8_t ty = 0; ty < TILES_PER_COLUMN; ++ty) {
            uint16_t tileIndex = 
                (mapWidth * TILES_PER_ROW * TILES_PER_COLUMN * roomY) + 
                (TILES_PER_ROW * roomX) +
                (mapWidth * TILES_PER_ROW * ty) +
                tx +
                2;

            uint8_t tileNumber = pgm_read_byte(map + tileIndex);
            renderer->drawOverwrite(tx * TILE_SIZE, ty * TILE_SIZE, tiles, tileNumber);
        }
    }


}

uint8_t TileRoom::getTileAt(char px, char py) const {
    return 0;
}


