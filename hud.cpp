#include "hud.h"
#include "bitmaps.h"

void drawDots(Renderer* renderer, uint8_t x, uint8_t y, uint8_t count, uint8_t maxCount, uint8_t frame, bool useFillRect) {
    uint8_t origX = x;

    for (uint8_t i = 0; i < maxCount; ++i) {
        if (useFillRect) {
            renderer->fillRect(x, y, 3, 3, WHITE);
        } else {
            renderer->drawOverwrite(x, y, heartDot_tiles, i < count ? 0 : 1);
        }

        x += 4;

        if (i == 3) {
            y += 4;
            x = origX;
        }
    }
}

void drawKeys(Renderer* renderer, uint8_t x, uint8_t y, uint8_t count) {
    uint8_t origX = x;

    for (uint8_t i = 0; i < count; ++i) {
        renderer->drawExternalMask(x, y, key_tiles, key_mask, 0);
        x += 5;

        if (i == 2) {
            y += 9;
            x = origX;
        }
    }
}

void Hud::render(Renderer* renderer, uint8_t frame, Player& player, uint8_t roomX, uint8_t roomY) {
    renderer->fillRect(0, 0, 16, 64, BLACK);

    // health dots
    drawDots(renderer, 1, 1, player.health, player.totalHealth, frame, false);

    // secondary item
    if (player.bButtonEntityType != UNSET) {
        renderer->drawOverwrite(4, 13, itemIcons_tiles, player.bButtonEntityType - 4);
    }

    renderer->drawSelfMasked(1, 13, hudBFrame_tiles, 0);

    if (player.bButtonEntityType == BOMB) {
        drawDots(renderer, 1, 32, 8, 8, frame, true);
    }

    // keys
    renderer->fillRect(1, 44, 15, 18, WHITE);
    drawKeys(renderer, 1, 45, player.keyCount);
}
