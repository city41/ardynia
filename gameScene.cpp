#include "gameScene.h"

Scene GameScene::update(byte frame) {
    if (arduboy->pressed(B_BUTTON)) {
        return TITLE;
    }

    player.update(arduboy, frame);

    Tiles tile = currentRoom->getTileAt(player.x, player.y);

    if (tile == DOOR) {
        if (currentRoom == &room1) {
            currentRoom = &room2;
            player.x = 40;
            player.y = 14;
        } else {
            currentRoom = &room1;
            player.x = 40;
            player.y = 50;
        }
    }

    return GAME;
}

void GameScene::render(byte frame) {
    currentRoom->render(arduboy, frame);
    player.render(arduboy, frame);
}
