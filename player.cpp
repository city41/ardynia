#include "player.h"
#include "bitmaps.h"

const uint8_t BOUNCE_AMOUNT = 8;

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

    renderer->drawExternalMask(x, y, playerWalk_tiles, playerWalk_mask_tiles, spriteIndex, spriteIndex);

#ifdef DRAW_HITBOXES
    renderer->drawRect(x, y, w, h, BLACK);
#endif
}

EntityType Player::update(Arduboy2* arduboy, byte frame) {
    if (ignoreMovementCount > 0) {
        ignoreMovementCount -= 1;
    }

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
    if (ignoreMovementCount == 0 && (newX != x || newY != y)) {
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

void Player::bounceBack(void) {
    switch (d) {
        case UP:
            moveTo(x, y + BOUNCE_AMOUNT);
            break;
        case DOWN:
            moveTo(x, y - BOUNCE_AMOUNT);
            break;
        case LEFT:
            moveTo(x + BOUNCE_AMOUNT, y);
            break;
        case RIGHT:
            moveTo(x - BOUNCE_AMOUNT, y);
            break;
    }

    ignoreMovementCount = 30;
}

void Player::onCollide(BaseEntity* other) {
    if (other-> type == BLOB) {
        health -= 1;
        bounceBack();
    }
}


