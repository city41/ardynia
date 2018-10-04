#include "hud.h"
#include "spriteBitmaps.h"
#include "tileBitmaps.h"
#include "state.h"
#include "util.h"
#include "itemSprites.h"
#include "tileRoom.h"
#include "renderer.h"

extern Renderer renderer;

void Hud::drawHealth(uint8_t x, uint8_t y, uint8_t count, uint8_t maxCount) {
    for (uint8_t i = 0; i < maxCount; ++i) {
        renderer.drawOverwrite(x, y, heartDot_tiles, i < count ? 0 : 1);

        x += 4;

        if (i == 3) {
            y += 4;
            x -= 16;
        }
    }
}

void Hud::drawItemCount(const uint8_t* bmp, uint8_t x, uint8_t y, uint8_t count) {
    for (uint8_t i = 0; i < count; ++i) {
        renderer.drawPlusMask(x, y, bmp, 0, 0, Invert);
        x += 4;

        if (i == 2) {
            y += 8;
            x -= 12;
        }
    }
}

void Hud::render(Player& player) {
    renderer.fillRect(0, 0, 16, 64, BLACK);

    drawHealth(1, 1, player.health, State::gameState.totalHealth);

    // secondary item
    if (player.bButtonEntityType != UNSET) {
        renderer.drawPlusMask(7, 15, (const uint8_t*)pgm_read_word(secondaryItem_sprites + player.bButtonEntityType), 0, 0, Invert);
    }

    // the little 'B' indicator
    renderer.drawOverwrite(1, 13, hudBFrame_tiles, 0);

    drawItemCount(key_plus_mask, 1, 48, State::gameState.numKeys[State::gameState.currentDungeon]);
    drawItemCount(bomb_plus_mask, 0, 30, player.numBombs);

    if (State::gameState.bossKeys[State::gameState.currentDungeon]) {
        renderer.drawPlusMask(0, 23, bossKey_plus_mask, 0, 0, Invert);
    }
}

