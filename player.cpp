#include "player.h"
#include "bitmaps.h"

void Player::render(Renderer *renderer, byte frame) {
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

    if (movedThisFrame && ((frame / 6) % 2) == 0) {
        ++spriteIndex;
    }

    renderer->drawExternalMask(x - 8, y - 8, playerWalk_tiles, playerWalk_mask_tiles, spriteIndex, spriteIndex);
    /* renderer->drawOverwrite(x - 8, y - 8, playerWalk_tiles, spriteIndex); */
}

EntityType Player::update(Arduboy2* arduboy, byte frame) {
    int16_t newX = x, newY = y;

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

    movedThisFrame = false;
    if (newX != x || newY != y) {
        movedThisFrame = true;
        moveTo(newX, newY);
    }

    return PLAYER;
}

void Player::onCollide(uint8_t tile) {
    if ((tile & SOLID_MASK) == SOLID_MASK) {
        undoMove();
    }
}

void Player::onCollide(BaseEntity* other) {
}


