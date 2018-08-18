#include "inGameMenu.h"
#include "util.h"

const char pauseMsg[] PROGMEM = "pause";
const char quitMsg[] PROGMEM = "quit";

const char* const menuMessages[] PROGMEM = { pauseMsg, quitMsg };

void InGameMenu::update(Arduboy2* arduboy, byte frame) {
    if (arduboy->justPressed(UP_BUTTON)) {
        decision = clamp(decision - 1, 0, MAX_DECISION);
    }

    if (arduboy->justPressed(UP_BUTTON)) {
        decision = clamp(decision + 1, 0, MAX_DECISION);
    }
}

void InGameMenu::render(Renderer* renderer, byte frame) {
    __FlashStringHelper* pauseM = pgm_read_word(menuMessages);
    __FlashStringHelper* quitM = pgm_read_word(menuMessages + 1);

    renderer->print(10, 10, pauseM);
    renderer->print(10, 20, quitM);
}
