#include "inGameMenu.h"
#include "spriteBitmaps.h"
#include "tileBitmaps.h"
#include "util.h"
#include "state.h"
#include "strings.h"
#include "hud.h"

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
    // draw the sword
    renderer.drawPlusMask(3, 8, itemIcons_plus_mask, 0, 0, true);

    // draw bomb count
    if (State::gameState.numAcquiredItems > 1) {
        renderer.drawPlusMask(0, 27, itemIcons_plus_mask, BOMB, 0, true);
        Hud::drawDots(renderer, 0, 27, player.numBombs, player.numBombs, 0, true);
    }

    // draw key count
    renderer.drawPlusMask(0, 49, itemIcons_plus_mask, KEY, 0, true);
    Hud::drawDots(renderer, 11, 56, State::gameState.numKeys, State::gameState.numKeys, 0, true);

    const uint8_t x = 20;

    renderer.drawString(x, 0, equip_string);
    // boundary rectangle
    renderer.drawRect(x, 7, 21, HEIGHT - 7, WHITE);

    // items
    for (uint8_t i = 0; i < State::gameState.numAcquiredItems; ++i) {

        if (i == row) {
            renderer.drawOverwrite(x + 3, 9 + 18 * i, hudBFrame_tiles, 0);
        }

        renderer.drawPlusMask(x + 6, 9 + 18 * i, itemIcons_plus_mask, i + 1, 0, true);
    }

}
