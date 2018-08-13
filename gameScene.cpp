#include "gameScene.h"

# define ROOM_TRANSITION_VELOCITY 4

bool isOffscreen(int16_t x, int16_t y) {
    return x < 0 || y < 0 || x > WIDTH || y > HEIGHT;
}

void GameScene::detectTileCollisions(void) {
    uint8_t tile = tileRoom->getTileAt(player.x, player.y);
    player.onCollide(tile);
}

void GameScene::goToNextRoom(int16_t x, int16_t y) {
    int8_t newRoomIndex = -1;
    int16_t newVerticalRoomTransitionCount = 0;
    int16_t newHorizontalRoomTransitionCount = 0;

    if (y > HEIGHT) {
        newRoomIndex = map[currentRoomIndex].down;
        newVerticalRoomTransitionCount = HEIGHT;
    } else if (y < 0) {
        newRoomIndex = map[currentRoomIndex].up;
        newVerticalRoomTransitionCount = -HEIGHT;
    } else if (x < 0) {
        newRoomIndex = map[currentRoomIndex].left;
        newHorizontalRoomTransitionCount = -WIDTH;
        /* player.moveTo(WIDTH - 1, player.y); */
    } else if (x > WIDTH) {
        newRoomIndex = map[currentRoomIndex].right;
        newHorizontalRoomTransitionCount = WIDTH;
        /* player.moveTo(1, player.y); */
    }

    if (newRoomIndex > 0) {
        nextRoomIndex = newRoomIndex;
        nextRoom = new TileRoom(map[nextRoomIndex].roomDef);

        if (newVerticalRoomTransitionCount != 0) {
            verticalRoomTransitionCount = newVerticalRoomTransitionCount;
        }

        if (newHorizontalRoomTransitionCount != 0) {
            horizontalRoomTransitionCount = newHorizontalRoomTransitionCount;
        }
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
    tileRoom->render(renderer, frame);

    if (goingToRoomBelow) {
        renderer->translateY = verticalRoomTransitionCount;
    } else {
        renderer->translateY = verticalRoomTransitionCount;
    }

    nextRoom->render(renderer, frame);

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
        delete tileRoom;
        tileRoom = nextRoom;
        currentRoomIndex = nextRoomIndex;
        nextRoomIndex = 0;
        nextRoom = NULL;

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
        renderer->translateX = horizontalRoomTransitionCount - WIDTH;
    } else {
        renderer->translateX = WIDTH + horizontalRoomTransitionCount;
    }
    tileRoom->render(renderer, frame);

    if (goingToRoomToRight) {
        renderer->translateX = horizontalRoomTransitionCount;
    } else {
        renderer->translateX = horizontalRoomTransitionCount;
    }

    nextRoom->render(renderer, frame);

    if (goingToRoomToRight) {
        renderer->translateX = horizontalRoomTransitionCount - WIDTH;
    } else {
        renderer->translateX = WIDTH + horizontalRoomTransitionCount;
    }

    player.render(renderer, frame);

    if (goingToRoomToRight) {
        horizontalRoomTransitionCount -= ROOM_TRANSITION_VELOCITY;
    } else {
        horizontalRoomTransitionCount += ROOM_TRANSITION_VELOCITY;
    }

    if (horizontalRoomTransitionCount == 0) {
        renderer->translateX = 0;
        delete tileRoom;
        tileRoom = nextRoom;
        currentRoomIndex = nextRoomIndex;
        nextRoomIndex = 0;
        nextRoom = NULL;

        if (goingToRoomToRight) {
            player.moveTo(1, player.y);
        } else {
            player.moveTo(WIDTH - 1, player.y);
        }
    }
}

void GameScene::render(uint8_t frame) {
    if (verticalRoomTransitionCount != 0) {
        renderVerticalRoomTransition(frame);
    } else if (horizontalRoomTransitionCount != 0) {
        renderHorizontalRoomTransition(frame);
    } else {
        tileRoom->render(renderer, frame);
        player.render(renderer, frame);
    }
}
