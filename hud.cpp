#include "hud.h"

void drawDots(Renderer* renderer, uint8_t x, uint8_t y, uint8_t count, uint8_t maxCount, uint8_t frame) {
    uint8_t origX = x;

    for (uint8_t i = 0; i < maxCount; ++i) {
        if (i < count || (frame % 2) == 1) {
            renderer->fillRect(x, y, 2, 2, WHITE);
        }
        x += 3;

        if (i == 4) {
            y += 3;
            x = origX;
        }
    }
}

void Hud::render(Renderer* renderer, uint8_t frame, Player& player, uint8_t roomX, uint8_t roomY) {
    renderer->fillRect(0, 0, 16, 64, BLACK);

    // health dots
    drawDots(renderer, 2, 1, player.health, player.totalHealth, frame);

    renderer->drawOverwrite(1, 7, weaponsAndItemIcons_tiles, 1);
    renderer->drawOverwrite(1, 23, weaponsAndItemIcons_tiles, 3);

    // item dots
    drawDots(renderer, 2, 40, 3, 3, frame);

    renderer->print(3, 54, 88);

    // draw current room coord
    renderer->print(3, 45, roomX);
    renderer->print(11, 45, roomY);
}
