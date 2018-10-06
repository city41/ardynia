#include <Arduboy2.h>
#include "inGameMenu.h"
#include "spriteBitmaps.h"
#include "tileBitmaps.h"
#include "util.h"
#include "state.h"
#include "strings.h"
#include "hud.h"
#include "itemSprites.h"
#include "renderer.h"

extern Renderer renderer;
extern Arduboy2Base arduboy;

void InGameMenu::update(byte frame) {
    const int8_t maxRows = State::gameState.numAcquiredItems;

    if (maxRows == 0) {
        return;
    }

    if (arduboy.justPressed(UP_BUTTON)) {
        row = max(row - 1, 0);
    }

    if (arduboy.justPressed(DOWN_BUTTON)) {
        row = min(row + 1, maxRows - 1);
    }

    chosenItem = row + 1;
}

void InGameMenu::render(Player& player, uint8_t frame) {
    renderer.translateX = WIDTH - 16;
    renderer.translateY = 0;
    Hud::render(player);
    renderer.translateX = 0;

    const uint8_t x = 20;

    renderer.drawString(x, 0, equip_string);

    // boundary rectangle
    // by using fillRect instead of drawRect, keep
    // drawRect out of the binary and save a ton of bytes
    renderer.fillRect(x, 6, 1, 40, WHITE);
    renderer.fillRect(x, 6, 21, 1, WHITE);
    renderer.fillRect(x + 20, 6, 1, 40, WHITE);
    renderer.fillRect(x, 46, 21, 1, WHITE);

    // sword
    if (State::gameState.hasSword) {
        renderer.drawPlusMask(6, 10, swordIcon_plus_mask, 0, 0, Invert);
    }

    // items
    for (uint8_t i = 0; i < State::gameState.numAcquiredItems; ++i) {


        if (i == row) {
            renderer.drawOverwrite(x + 3, 9 + 12 * i, hudBFrame_tiles, 0);
        }

        const uint8_t* itemBmp = pgm_read_ptr(secondaryItem_sprites + i + 1);
        renderer.drawPlusMask(x + 10, 9 + 12 * i, itemBmp, 0, 0, Invert);
    }

}
