#include "hud.h"

void drawDots(Renderer* renderer, uint8_t x, uint8_t y, uint8_t count, uint8_t maxCount, uint8_t frame) {
    uint8_t origX = x;

    for (uint8_t i = 0; i < maxCount; ++i) {
        if (i < count) {
            renderer->fillRect(x, y, 3, 3, WHITE);
        } else {
            renderer->drawRect(x, y, 3, 3, WHITE);
        }

        x += 4;

        if (i == 3) {
            y += 4;
            x = origX;
        }
    }
}

void Hud::render(Renderer* renderer, uint8_t frame, Player& player, uint8_t roomX, uint8_t roomY) {
    renderer->fillRect(0, 0, 16, 64, BLACK);

    // health dots
    drawDots(renderer, 1, 1, player.health, player.totalHealth, frame);

    renderer->drawOverwrite(1, 9, itemIcons_tiles, 1);

    // item dots
    drawDots(renderer, 1, 26, 3, 3, frame);

    // draw current room coord
    renderer->print(3, 47, roomX);
    renderer->print(3, 56, roomY);
}
