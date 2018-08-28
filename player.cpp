#include "player.h"
#include "bitmaps.h"
#include "entityTemplates.h"
#include "drawBitmap.h"
#include "util.h"

const uint8_t PLAYER_VELOCITY = 2;

void Player::useSword(void) {
    // currently swinging the sword? do nothing
    if (entities[0].type != UNSET) {
        return;
    }

    loadEntity(entities[0], SWORD);
    entities[0].spawn(this);
}

void Player::bButtonAction(void) {
    if (entities[1].type != UNSET || bButtonEntityType == UNSET) {
        return;
    }

    loadEntity(entities[1], bButtonEntityType);
    entities[1].spawn(this);
}

EntityType Player::render(Renderer *renderer, byte frame) {
    // recovering from damage? "flash" the player every third frame
    if (tookDamageCount > 0 && tookDamageCount % 3 == 1) {
        return UNSET;
    }

    uint8_t spriteIndex;
    MirrorMode mirror = 0;
    bool attacking = entities[0].type == SWORD || entities[1].type == BOOMERANG;

    switch (dir) {
        case LEFT:
            spriteIndex = attacking ? 4 : 0;
            break;
        case RIGHT:
            spriteIndex = attacking ? 4 : 0;
            mirror = MIRROR_HORIZONTAL;
            break;
        case UP:
            spriteIndex = attacking ? 5 : 2;
            break;
        case DOWN:
            spriteIndex = attacking ? 6 : 3;
            break;
    }

    if (movedThisFrame && ((frame / 6) % 2) == 0) {
        if (dir == LEFT || dir == RIGHT) {
            ++spriteIndex;
        } else {
            mirror = MIRROR_HORIZONTAL;
        }
    }

    renderer->drawExternalMask(x - 4, y - 8, playerWalk_tiles, playerWalk_mask, spriteIndex, mirror);

#ifdef DRAW_HITBOXES
    renderer->drawRect(x, y, w, h, BLACK);
#endif

    return UNSET;
}

EntityType Player::update(BaseEntity* player, Arduboy2* arduboy, byte frame) {
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
        useSword();
    }

    if (arduboy->justPressed(B_BUTTON)) {
        bButtonAction();
    }

    movedThisFrame = false;
    boolean attackingWithSword = entities[0].type == SWORD;

    if (!attackingWithSword && (newX != x || newY != y)) {
        movedThisFrame = true;
        moveTo(newX, newY);
    }

    return UNSET;
}

EntityType Player::onCollide(BaseEntity* other, BaseEntity* player) {
    if (other->damage && tookDamageCount == 0) {
        health -= other->damage;
        bounceBack();
        tookDamageCount = 30;
    }

    if (other->type == KEY) {
        other->type = UNSET;
        keyCount = clamp(keyCount + 1, 0, MAX_KEYS);
    }

    if (other->type == HEART) {
        other->type = UNSET;
        health = clamp(health + 1, 0, totalHealth);
    }

    return UNSET;
}


