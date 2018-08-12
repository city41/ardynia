#include "player.h"
#include "bitmaps.h"

Sprites sprites;

void Player::render(Arduboy2* arduboy, byte frame) {
    char spriteIndex = 0;

    switch(d) {
        case LEFT:
            spriteIndex = 0;
            break;
        case DOWN:
            spriteIndex = 2;
            break;
        case UP:
            spriteIndex = 4;
            break;
        case RIGHT:
            spriteIndex = 6;
            break;
    }

    if (frame > 30) {
        ++spriteIndex;
    }

    sprites.drawErase(x - 8, y - 8, playerWalkBmp, spriteIndex);
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

void Player::onCollide(uint8_t tile) {
    if ((tile & SOLID_MASK) == SOLID_MASK) {
        undoMove();
    }
}


