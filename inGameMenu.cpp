#include "inGameMenu.h"
#include "spriteBitmaps.h"
#include "util.h"
#include "state.h"

void InGameMenu::update(Arduboy2* arduboy, byte frame) {
    const int8_t maxRows = max(State::gameState.numAcquiredItems - 1, 0);

    if (maxRows == 0) {
        return;
    }

    if (arduboy->justPressed(UP_BUTTON)) {
        row = clamp(row - 1, 0, maxRows - 1);
    }

    if (arduboy->justPressed(DOWN_BUTTON)) {
        row = clamp(row + 1, 0, maxRows - 1);
    }

    chosenItem = row + 1;
}

void InGameMenu::render(Renderer* renderer, uint8_t frame) {
    const int8_t maxRows = max(State::gameState.numAcquiredItems - 1, 0);

    // second column, items
    for (uint8_t i = 0; i < maxRows; ++i) {

        if (i == row) {
            renderer->drawPlusMask(4, 4 + 20 * i, hudBFrame_plus_mask, 0);
        }

        renderer->drawPlusMask(7, 4 + 20 * i, itemIcons_plus_mask, i + 1, 0, true);
    }

}
