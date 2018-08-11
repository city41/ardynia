#include "gameScene.h"

Scene GameScene::update(byte frame) {
    if (arduboy->pressed(B_BUTTON)) {
        return TITLE;
    }

    player.update(arduboy, frame);

    return GAME;
}

void GameScene::render(byte frame) {
    arduboy->print(F("arduzel game scene"));

    player.render(arduboy, frame);
}
