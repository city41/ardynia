#include "gameScene.h"

void GameScene::detectTileCollisions(void) {
    uint8_t tile = currentRoom->getTileAt(player.x, player.y);
    player.onCollide(tile);

    if ((tile & TELEPORTER_MASK) == TELEPORTER_MASK) {
        if (currentRoom == &room1) {
            currentRoom = &room2;
        } else {
            currentRoom = &room1;
        }
    }
}

Scene GameScene::update(byte frame) {
    if (arduboy->pressed(B_BUTTON)) {
        return TITLE;
    }

    player.update(arduboy, frame);

    detectTileCollisions();

    return GAME;
}

void GameScene::render(byte frame) {
    currentRoom->render(arduboy, frame);
    player.render(arduboy, frame);
}
