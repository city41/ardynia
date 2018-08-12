#include "player.h"
#include "bitmaps.h"

Sprites sprites;

void Player::render(Arduboy2* arduboy, byte frame) {
    sprites.drawOverwrite(x - 12, y - 8, playerAttackBmp, 0);
}

void Player::update(Arduboy2* arduboy, byte frame) {
    char newX = x, newY = y;

    if (arduboy->pressed(DOWN_BUTTON)) {
        newY += v;
    }

    if (arduboy->pressed(UP_BUTTON)) {
        newY -= v;
    }

    if (arduboy->pressed(LEFT_BUTTON)) {
        newX -= v;
    }

    if (arduboy->pressed(RIGHT_BUTTON)) {
        newX += v;
    }

    moveTo(newX, newY);
}

void Player::onCollide(Tiles tile) {
    if (tile == WALL) {
        undoMove();
    }
}


