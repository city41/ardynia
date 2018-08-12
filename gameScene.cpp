#include "gameScene.h"

void GameScene::detectTileCollisions(void) {
    Tiles tile = currentRoom->getTileAt(player.x, player.y);
    player.onCollide(tile);

    if (tile == DOOR) {
        if (currentRoom == &room1) {
            currentRoom = &room2;
            player.moveTo(50, 14);
        } else {
            currentRoom = &room1;
            player.moveTo(50, 50);
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
