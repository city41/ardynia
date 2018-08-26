#include "inGameMenu.h"
#include "bitmaps.h"
#include "util.h"

const int8_t pauseLabel[] PROGMEM = "pause";
const int8_t saveLabel[] PROGMEM = " save";
const int8_t loadLabel[] PROGMEM = " load";

const int8_t* const menuLabels[] PROGMEM = { pauseLabel, saveLabel, loadLabel };

void InGameMenu::update(Arduboy2* arduboy, byte frame) {
    if (arduboy->justPressed(UP_BUTTON)) {
        row = clamp(row - 1, 0, NUM_DECISION_ROWS - 1);
    }

    if (arduboy->justPressed(DOWN_BUTTON)) {
        row = clamp(row + 1, 0, NUM_DECISION_ROWS - 1);
    }

    if (arduboy->justPressed(LEFT_BUTTON)) {
        column = clamp(column - 1, 0, NUM_DECISION_COLUMNS - 1);
    }

    if (arduboy->justPressed(RIGHT_BUTTON)) {
        column = clamp(column + 1, 0, NUM_DECISION_COLUMNS - 1);
    }

    decision = decisions[column][row];
}

void InGameMenu::render(Renderer* renderer, byte frame) {
    // first column, text
    for (uint8_t i = 0; i < NUM_DECISION_ROWS; ++i) {
        __FlashStringHelper* label = pgm_read_word(menuLabels + i);
        renderer->print(12, 17 + 12 * i, label);

        if (i == row && column == 0) {
            renderer->drawRect(4, 16 + 11 * i, 40, 12, WHITE);
        }
    }

    // second column, items
    for (uint8_t i = 0; i < NUM_DECISION_ROWS; ++i) {
        renderer->drawOverwrite(60, 4 + 20 * i, itemIcons_tiles, i);

        if (i == row && column == 1) {
            renderer->drawSelfMasked(60, 4 + 20 * i, hudBFrame_tiles, 0);
        }
    }
}
