#include "player.h"
#include "bitmaps.h"
#include "entityTemplates.h"

const uint8_t BOUNCE_AMOUNT = 8;
const uint8_t PLAYER_VELOCITY = 2;

void Player::aButtonAction(void) {
    // don't have anything equiped on A, or whatever is equipped is
    // currently active? then nothing to do here
    if (aButtonEntityType == UNSET || entities[0].type != UNSET) {
        return;
    }

    entities[0] = entityTemplates[aButtonEntityType];
    entities[0].spawn(this);
}

void Player::bButtonAction(void) {
}

EntityType Player::render(Renderer *renderer, byte frame) {
    // recovering from damage? "flash" the player every third frame
    if (tookDamageCount > 0 && tookDamageCount % 3 == 1) {
        return UNSET;
    }

    // Direction is LRUD and so are the player sprites
    uint8_t spriteIndex = dir << 1;

    // choose the other walking frame to cause walking animation
    // TODO: see if this can be generalized to "progress player's current animation"
    if (movedThisFrame && ((frame / 6) % 2) == 0) {
        ++spriteIndex;
    }

    renderer->drawExternalMask(x, y, playerWalk_tiles, playerWalk_mask_tiles, spriteIndex, spriteIndex);

#ifdef DRAW_HITBOXES
    renderer->drawRect(x, y, w, h, BLACK);
#endif

    return UNSET;
}

EntityType Player::update(void* parent, Arduboy2* arduboy, byte frame) {
    if (tookDamageCount > 0) {
        tookDamageCount -= 1;
    }

    int16_t newX = x, newY = y;

    if (arduboy->pressed(DOWN_BUTTON)) {
        newY += PLAYER_VELOCITY;
    }

    if (arduboy->pressed(UP_BUTTON)) {
        newY -= PLAYER_VELOCITY;
    }

    if (arduboy->pressed(LEFT_BUTTON)) {
        newX -= PLAYER_VELOCITY;
    }

    if (arduboy->pressed(RIGHT_BUTTON)) {
        newX += PLAYER_VELOCITY;
    }

    if (arduboy->justPressed(A_BUTTON)) {
        aButtonAction();
    }

    if (arduboy->justPressed(B_BUTTON)) {
        bButtonAction();
    }

    movedThisFrame = false;
    if (tookDamageCount == 0 && (newX != x || newY != y)) {
        movedThisFrame = true;
        moveTo(newX, newY);
    }

    return UNSET;
}

EntityType Player::onCollide(uint8_t tile) {
    if ((tile & SOLID_MASK) == SOLID_MASK) {
        undoMove();
    }

    return UNSET;
}

void Player::bounceBack(void) {
    int16_t nx, ny;
    switch (dir) {
        case UP:
            nx = x;
            ny = y + BOUNCE_AMOUNT;
            break;
        case DOWN:
            nx = x;
            ny = y - BOUNCE_AMOUNT;
            break;
        case LEFT:
            nx = x + BOUNCE_AMOUNT;
            ny = y;
            break;
        case RIGHT:
            nx = x - BOUNCE_AMOUNT;
            ny = y;
            break;
    }

    Direction curDir = dir;
    moveTo(nx, ny);
    dir = curDir;
}

EntityType Player::onCollide(BaseEntity* other) {
    if (other->type == BLOB) {
        health -= 1;
        bounceBack();
        tookDamageCount = 30;
    }

    return UNSET;
}


