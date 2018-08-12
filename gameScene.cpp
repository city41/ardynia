#include "gameScene.h"

bool isOffscreen(int16_t x, int16_t y) {
    return x < 0 || y < 0 || x > WIDTH || y > HEIGHT;
}

void GameScene::detectTileCollisions(void) {
    uint8_t tile = tileRoom->getTileAt(player.x, player.y);
    player.onCollide(tile);
}

void GameScene::goToNextRoom(int16_t x, int16_t y) {
    int8_t newRoomIndex = -1;

    if (y > HEIGHT) {
        newRoomIndex = map[currentRoomIndex].down;
        player.moveTo(player.x, 1);
    } else if (y < 0) {
        newRoomIndex = map[currentRoomIndex].up;
        player.moveTo(player.x, HEIGHT - 1);
    } else if (x < 0) {
        newRoomIndex = map[currentRoomIndex].left;
        player.moveTo(WIDTH - 1, player.y);
    } else if (x > WIDTH) {
        newRoomIndex = map[currentRoomIndex].right;
        player.moveTo(1, player.y);
    }

    if (newRoomIndex > 0) {
        currentRoomIndex = newRoomIndex;
        delete tileRoom;
        tileRoom = new TileRoom(map[currentRoomIndex].roomDef);
    }
}

Scene GameScene::update(byte frame) {
    if (arduboy->pressed(B_BUTTON)) {
        return TITLE;
    }

    player.update(arduboy, frame);

    if (isOffscreen(player.x, player.y)) {
        goToNextRoom(player.x, player.y);
    } else {
        detectTileCollisions();
    }

    return GAME;
}

void GameScene::render(byte frame) {
    tileRoom->render(renderer, frame);
    player.render(renderer, frame);
}
