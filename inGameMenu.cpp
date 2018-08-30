#include "inGameMenu.h"
#include "bitmaps.h"
#include "util.h"

const int8_t pauseLabel[] PROGMEM = " pause";
const int8_t saveLabel[] PROGMEM = "  save";
const int8_t loadLabel[] PROGMEM = "  load";
const int8_t gapLabel[] PROGMEM = "";
const int8_t deleteLabel[] PROGMEM = "delete";

const int8_t* const menuLabels[] PROGMEM = { pauseLabel, saveLabel, loadLabel, gapLabel, deleteLabel };

void InGameMenu::update(Arduboy2* arduboy, byte frame) {
    const uint8_t maxRows = column == 0 ? NUM_DECISION_ROWS : NUM_DECISION_ROWS - 1;

    if (arduboy->justPressed(UP_BUTTON)) {
        row = clamp(row - 1, 0, maxRows - 1);
    }

    if (arduboy->justPressed(DOWN_BUTTON)) {
        row = clamp(row + 1, 0, maxRows - 1);
    }

    if (arduboy->justPressed(LEFT_BUTTON)) {
        column = 0;
    }

    if (arduboy->justPressed(RIGHT_BUTTON)) {
        column = 1;

        // map the first column's four values into 
        // the second column's three values
        if (row == 2 || row == 3) {
            row = 1;
        }

        if (row == 4) {
            row = 2;
        }
    }

    decision = decisions[column][row];
}

void InGameMenu::render(Renderer* renderer, byte frame) {
    // first column, text
    for (uint8_t i = 0; i < NUM_DECISION_ROWS; ++i) {
        __FlashStringHelper* label = pgm_read_word(menuLabels + i);
        renderer->print(12, 1 + 12 * i, label);

        if (i == row && column == 0) {
            renderer->drawRect(4, 12 * i, 48, 12, WHITE);
        }
    }

    // second column, items
    for (uint8_t i = 0; i < NUM_DECISION_ROWS; ++i) {
        renderer->drawExternalMask(63, 4 + 20 * i, itemIcons_tiles, itemIcons_mask, i, 0, true);

        if (i == row && column == 1) {
            renderer->drawSelfMasked(60, 4 + 20 * i, hudBFrame_tiles, 0);
        }
    }
}
