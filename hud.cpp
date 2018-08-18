#include "hud.h"

void drawDots(Renderer* renderer, uint8_t x, uint8_t y, uint8_t count) {
    uint8_t origX = x;

    for (uint8_t i = 0; i < count; ++i) {
        renderer->fillRect(x, y, 2, 2, WHITE);
        x += 3;

        if (i == 5) {
            y += 3;
            x = origX;
        }
    }
}

void Hud::render(Renderer* renderer, uint8_t frame) {
    renderer->fillRect(0, 0, 16, 64, BLACK);

    // health dots
    drawDots(renderer, 2, 1, 9);

    renderer->drawOverwrite(1, 7, weaponsAndItemIconsBmp, 0);
    renderer->drawOverwrite(1, 23, weaponsAndItemIconsBmp, 2);

    // item dots
    drawDots(renderer, 2, 40, 3);

    renderer->print(3, 54, F("87"));
}
