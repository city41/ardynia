#include "inGameMenu.h"
#include "spriteBitmaps.h"
#include "tileBitmaps.h"
#include "util.h"
#include "state.h"
#include "strings.h"
#include "hud.h"
#include "itemSprites.h"

void InGameMenu::update(Arduboy2Base& arduboy, byte frame) {
    const int8_t maxRows = State::gameState.numAcquiredItems;

    if (maxRows == 0) {
        return;
    }

    if (arduboy.justPressed(UP_BUTTON)) {
        row = Util::clamp(row - 1, 0, maxRows - 1);
    }

    if (arduboy.justPressed(DOWN_BUTTON)) {
        row = Util::clamp(row + 1, 0, maxRows - 1);
    }

    chosenItem = row + 1;
}

void InGameMenu::render(Renderer& renderer, Player& player, uint8_t frame) {
    renderer.translateX = WIDTH - 16;
    renderer.translateY = 0;
    Hud::render(renderer, player);
    renderer.translateX = 0;

    const uint8_t x = 20;

    renderer.drawString(x, 0, equip_string);
    // boundary rectangle
    renderer.drawRect(x, 6, 21, 40, WHITE);

    // sword
    if (State::gameState.hasSword) {
        renderer.drawPlusMask(3, 10, swordIcon_plus_mask, 0, 0, true);
    }

    // items
    for (uint8_t i = 0; i < State::gameState.numAcquiredItems; ++i) {


        if (i == row) {
            renderer.drawOverwrite(x + 3, 9 + 12 * i, hudBFrame_tiles, 0);
        }

        const uint8_t* itemBmp = pgm_read_ptr(secondaryItem_sprites + i + 1);
        renderer.drawPlusMask(x + 10, 9 + 12 * i, itemBmp, 0, 0, true);
    }

}
