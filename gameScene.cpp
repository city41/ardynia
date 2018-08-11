#include "gameScene.h"

Scene GameScene::update(byte frame) {
    if (arduboy->pressed(UP_BUTTON)) {
        return TITLE;
    }

    return GAME;
}

void GameScene::render(void) {
    arduboy->print(F("arduzel game scene"));
}
