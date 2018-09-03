#include "hud.h"
#include "spriteBitmaps.h"
#include "tileBitmaps.h"
#include "state.h"
#include "util.h"

void drawDots(Renderer* renderer, uint8_t x, uint8_t y, uint8_t count, uint8_t maxCount, uint8_t frame, bool useFillRect) {
    uint8_t origX = x;

    for (uint8_t i = 0; i < maxCount; ++i) {
        if (useFillRect) {
            renderer->fillRect(x, y, 3, 3, WHITE);
        } else {
            renderer->drawPlusMask(x, y, heartDot_plus_mask, i < count ? 0 : 1);
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
        renderer->drawPlusMask(x, y, key_plus_mask, 0, 0, true);
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
    drawDots(renderer, 1, 1, player.health, State::gameState.totalHealth, frame, false);

    // secondary item
    renderer->drawOverwrite(1, 13, hudBFrame_tiles, 0);
    if (player.bButtonEntityType != UNSET) {
        renderer->drawPlusMask(4, 13, itemIcons_plus_mask, player.bButtonEntityType, 0, true);
    }

    // draw bomb count
    if (State::gameState.numAcquiredItems > 1) {
        renderer->drawPlusMask(0, 31, itemIcons_plus_mask, BOMB, 0, true);
        renderer->print(11, 38, player.numBombs);
    }

    // draw keys count
    renderer->drawPlusMask(0, 49, itemIcons_plus_mask, KEY, 0, true);
    renderer->print(11, 56, State::gameState.numKeys);
}
