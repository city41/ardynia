#include "gameScene.h"

#define ROOM_TRANSITION_VELOCITY 2
const uint8_t ROOM_WIDTH = TILES_PER_ROW * TILE_SIZE;

bool isOffscreen(int16_t x, int16_t y) {
    return x < 0 || y < 0 || x > ROOM_WIDTH || y > HEIGHT;
}

void GameScene::detectTileCollisions(void) {
    uint8_t tile = tileRoom.getTileAt(player.x, player.y);
    player.onCollide(tile);
}

void GameScene::goToNextRoom(int16_t x, int16_t y) {
    if (x < 0) {
        nextRoomX = tileRoom.x - 1;
        nextRoomY = tileRoom.y;
        horizontalRoomTransitionCount = -ROOM_WIDTH;

    } else if (x > ROOM_WIDTH) {
        nextRoomX = tileRoom.x + 1;
        nextRoomY = tileRoom.y;
        horizontalRoomTransitionCount = ROOM_WIDTH;


    } else if (y < 0) {
        nextRoomX = tileRoom.x;
        nextRoomY = tileRoom.y - 1;
        verticalRoomTransitionCount = -HEIGHT;
    } else if (y > HEIGHT) {
        nextRoomX = tileRoom.x;
        nextRoomY = tileRoom.y + 1;
        verticalRoomTransitionCount = HEIGHT;
    }
}

Scene GameScene::update(byte frame) {
    if (verticalRoomTransitionCount != 0 || horizontalRoomTransitionCount != 0) {
        return GAME;
    }

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

void GameScene::renderVerticalRoomTransition(uint8_t frame) {
    bool goingToRoomBelow = verticalRoomTransitionCount > 0;

    if (goingToRoomBelow) {
        renderer->translateY = verticalRoomTransitionCount - HEIGHT;
    } else {
        renderer->translateY = HEIGHT + verticalRoomTransitionCount;
    }
    tileRoom.render(renderer, frame);

    if (goingToRoomBelow) {
        renderer->translateY = verticalRoomTransitionCount;
    } else {
        renderer->translateY = verticalRoomTransitionCount;
    }

    tileRoom.render(renderer, frame, nextRoomX, nextRoomY);

    if (goingToRoomBelow) {
        renderer->translateY = verticalRoomTransitionCount - HEIGHT;
    } else {
        renderer->translateY = HEIGHT + verticalRoomTransitionCount;
    }

    player.render(renderer, frame);

    if (goingToRoomBelow) {
        verticalRoomTransitionCount -= ROOM_TRANSITION_VELOCITY;
    } else {
        verticalRoomTransitionCount += ROOM_TRANSITION_VELOCITY;
    }

    if (verticalRoomTransitionCount == 0) {
        renderer->translateY = 0;
        tileRoom.x = nextRoomX;
        tileRoom.y = nextRoomY;

        if (goingToRoomBelow) {
            player.moveTo(player.x, 1);
        } else {
            player.moveTo(player.x, HEIGHT - 1);
        }
    }
}

void GameScene::renderHorizontalRoomTransition(uint8_t frame) {
    bool goingToRoomToRight = horizontalRoomTransitionCount > 0;

    if (goingToRoomToRight) {
        renderer->translateX = horizontalRoomTransitionCount - ROOM_WIDTH;
    } else {
        renderer->translateX = ROOM_WIDTH + horizontalRoomTransitionCount;
    }
    tileRoom.render(renderer, frame);

    if (goingToRoomToRight) {
        renderer->translateX = horizontalRoomTransitionCount;
    } else {
        renderer->translateX = horizontalRoomTransitionCount;
    }

    tileRoom.render(renderer, frame, nextRoomX, nextRoomY);

    if (goingToRoomToRight) {
        renderer->translateX = horizontalRoomTransitionCount - ROOM_WIDTH;
    } else {
        renderer->translateX = ROOM_WIDTH + horizontalRoomTransitionCount;
    }

    player.render(renderer, frame);

    if (goingToRoomToRight) {
        horizontalRoomTransitionCount -= ROOM_TRANSITION_VELOCITY;
    } else {
        horizontalRoomTransitionCount += ROOM_TRANSITION_VELOCITY;
    }

    if (horizontalRoomTransitionCount == 0) {
        renderer->translateX = 0;
        tileRoom.x = nextRoomX;
        tileRoom.y = nextRoomY;

        if (goingToRoomToRight) {
            player.moveTo(1, player.y);
        } else {
            player.moveTo(ROOM_WIDTH - 1, player.y);
        }
    }
}

void GameScene::render(uint8_t frame) {
    if (verticalRoomTransitionCount != 0) {
        renderVerticalRoomTransition(frame);
    } else if (horizontalRoomTransitionCount != 0) {
        renderHorizontalRoomTransition(frame);
    } else {
        tileRoom.render(renderer, frame);
        player.render(renderer, frame);
    }
}
