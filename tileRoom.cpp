#include "tileRoom.h"

void TileRoom::render(Arduboy2* arduboy, byte frame) {
    for (char y = 0; y < ROOM_TILE_HEIGHT; ++y) {
        for (char x = 0; x < ROOM_TILE_WIDTH; ++x) {
            switch (layout[y][x]) {
                case NO_TILE:
                    break;
                case FLOOR:
                    arduboy->fillRect(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, WHITE);
                    break;
                case WALL:
                    arduboy->fillRect(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, WHITE);
                    arduboy->drawRect(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLACK);
                    break;
                case DOOR:
                    arduboy->fillRect(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLACK);
                    break;
            }

        }
    }
}

Tiles TileRoom::getTileAt(char px, char py) const {
    return layout[py >> 3][px >> 3];
}


