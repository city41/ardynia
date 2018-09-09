#include "hud.h"
#include "spriteBitmaps.h"
#include "tileBitmaps.h"
#include "state.h"
#include "util.h"
#include "itemSprites.h"

void Hud::drawDots(Renderer& renderer, uint8_t x, uint8_t y, uint8_t count, uint8_t maxCount, uint8_t frame, bool useFillRect) {
    uint8_t origX = x;

    for (uint8_t i = 0; i < maxCount; ++i) {
        if (useFillRect) {
            renderer.fillRect(x, y, 3, 3, WHITE);
        } else {
            renderer.drawOverwrite(x, y, heartDot_tiles, i < count ? 0 : 1);
        }

        x += 4;

        if (i == 3) {
            y += 4;
            x = origX;
        }
    }
}

void drawItemCount(Renderer& renderer, const uint8_t* bmp, uint8_t x, uint8_t y, uint8_t count) {
    for (uint8_t i = 0; i < count; ++i) {
        renderer.drawPlusMask(x, y, bmp, 0, 0, true);
        x += 5;

        if (i == 2) {
            y += 8;
            x -= 15;
        }
    }
}

void Hud::render(Renderer& renderer, uint8_t frame, Player& player, uint8_t roomX, uint8_t roomY) {
    renderer.fillRect(0, 0, 16, 64, BLACK);

    // health dots
    drawDots(renderer, 1, 1, player.health, State::gameState.totalHealth, frame, false);

    // secondary item
    if (player.bButtonEntityType != UNSET) {
        renderer.drawPlusMask(7, 15, (const uint8_t*)pgm_read_word(secondaryItem_sprites + player.bButtonEntityType - 1), 0, 0, true);
    }
    renderer.drawOverwrite(1, 13, hudBFrame_tiles, 0);

    // draw keys and bombs count
    drawItemCount(renderer, key_plus_mask, 1, 48, State::gameState.numKeys);
    drawItemCount(renderer, bomb_plus_mask, 0, 30, player.numBombs);
}

