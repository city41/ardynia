#include "gameScene.h"

void GameScene::updatePlayer(void) {
    char x = player.x;
    char y = player.y;
    char delta = player.delta;

    if (arduboy->pressed(DOWN_BUTTON)) {
        y += delta;
    }

    if (arduboy->pressed(UP_BUTTON)) {
        y -= delta;
    }

    if (arduboy->pressed(LEFT_BUTTON)) {
        x -= delta;
    }

    if (arduboy->pressed(RIGHT_BUTTON)) {
        x += delta;
    }

    Tiles tile = currentRoom->getTileAt(x, y);

    if (tile == WALL) {
        return;
    }

    player.x = x;
    player.y = y;

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
}

Scene GameScene::update(byte frame) {
    if (arduboy->pressed(B_BUTTON)) {
        return TITLE;
    }

    updatePlayer();

    return GAME;
}

void GameScene::render(byte frame) {
    currentRoom->render(arduboy, frame);
    player.render(arduboy, frame);
}
