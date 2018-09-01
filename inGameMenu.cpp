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
    // draw the sword
    if (State::gameState.numAcquiredItems > 0) {
        renderer->drawPlusMask(3, 8, itemIcons_plus_mask, 0, 0, true);
    }

    // draw key count
    renderer->drawPlusMask(0, 49, itemIcons_plus_mask, KEY, 0, true);
    renderer->print(11, 56, State::gameState.numKeys);

    const uint8_t x = 20;

    renderer->print(x, 0, F("ITEMS"));
    // boundary rectangle
    renderer->drawRect(x, 7, 21, HEIGHT - 7, WHITE);

    const int8_t maxRows = max(State::gameState.numAcquiredItems - 1, 0);

    // items
    for (uint8_t i = 0; i < maxRows; ++i) {

        if (i == row) {
            renderer->drawPlusMask(x + 3, 9 + 18 * i, hudBFrame_plus_mask, 0);
        }

        renderer->drawPlusMask(x + 6, 9 + 18 * i, itemIcons_plus_mask, i + 1, 0, true);
    }

}
