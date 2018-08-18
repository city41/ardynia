#include "inGameMenu.h"
#include "util.h"

void InGameMenu::update(Arduboy2* arduboy, byte frame) {
    if (arduboy->justPressed(UP_BUTTON)) {
        decision = clamp(decision - 1, 0, MAX_DECISION);
    }

    if (arduboy->justPressed(UP_BUTTON)) {
        decision = clamp(decision + 1, 0, MAX_DECISION);
    }
}

void InGameMenu::render(Renderer* renderer, byte frame) {
    renderer->print(10, 10, F("pause"));
    renderer->print(10, 20, F("quit"));
}
