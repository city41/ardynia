#include "inGameMenu.h"
#include "util.h"

const char pauseMsg[] PROGMEM = "pause";
const char quitMsg[] PROGMEM = "quit";

const char* const menuMessages[] PROGMEM = { pauseMsg, quitMsg };

void InGameMenu::update(Arduboy2* arduboy, byte frame) {
    if (arduboy->justPressed(UP_BUTTON)) {
        decision = clamp(decision - 1, 0, NUM_DECISIONS - 1);
    }

    if (arduboy->justPressed(DOWN_BUTTON)) {
        decision = clamp(decision + 1, 0, NUM_DECISIONS - 1);
    }
}

void InGameMenu::render(Renderer* renderer, byte frame) {
    for (uint8_t i = 0; i < NUM_DECISIONS; ++i) {
        __FlashStringHelper* msg = pgm_read_word(menuMessages + i);
        renderer->print(16, 12 * i, msg);

        if (i == decision) {
            renderer->fillCircle(8, 12 * i + 4, 2, WHITE);
        }
    }
}
