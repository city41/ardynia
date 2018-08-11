#include "titleScene.h"

Scene TitleScene::update(byte frame) {
    if (arduboy->pressed(A_BUTTON)) {
        return GAME;
    }

    return TITLE;
}

void TitleScene::render(void) {
    arduboy->print(F("press A"));
}
