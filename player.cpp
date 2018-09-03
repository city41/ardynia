#include "player.h"
#include "entityTemplates.h"
#include "drawBitmap.h"
#include "util.h"
#include "tileRoom.h"
#include "state.h"

const uint8_t PLAYER_VELOCITY = 2;

void Player::reset() {
    moveTo(WIDTH / 2 - width, HEIGHT / 2 - height, true);
    dir = DOWN;
    tookDamageCount = 0;
    numBombs = 0;
    health = 2;

    bButtonEntityType = UNSET;
    entities[0].type = UNSET;
    entities[1].type = UNSET;

    // if player found the boomerang, equip it. Can't save last equipped
    // item in EEPROM as it'd require a save on each equip change
    // this is a compromise, better than having nothing equipped, and the boomerang
    // is the most useful item
    if (State::gameState.numAcquiredItems > 0) {
        bButtonEntityType = BOOMERANG;
    }
}

void Player::useSword(void) {
    // currently swinging the sword or dont even have it yet? do nothing
    if (entities[0].type != UNSET) {
        return;
    }

    loadEntity(entities[0], SWORD);
}

void Player::bButtonAction(void) {
    if (entities[1].type != UNSET || bButtonEntityType == UNSET) {
        return;
    }

    if (bButtonEntityType == BOMB) {
        if (numBombs == 0) {
            return;
        } else {
            numBombs -= 1;
        }
    }

    loadEntity(entities[1], bButtonEntityType);

    if (bButtonEntityType == BOMB) {
        // send a hint this is an active bomb
        // instead of an item drop
        entities[1].health = 1;
        entities[1].x = x;
        entities[1].y = y - 4;
    }
}

EntityType Player::render(Renderer *renderer, byte frame) {
    // recovering from damage? "flash" the player every third frame
    if (tookDamageCount > 0 && tookDamageCount % 3 == 1) {
        return UNSET;
    }

    uint8_t spriteIndex;
    MirrorMode mirror = 0;

    if (receiveItemCount > 0) {
        spriteIndex = 2;
        /* renderer->fillRect(x - 4, y - 26, 16, 16, WHITE); */
        /* renderer->drawRect(x - 5, y - 27, 18, 18, BLACK); */
        renderer->drawPlusMask(x - 2, y - 24 - (6 - receiveItemCount/8), itemIcons_plus_mask, receivedItem, 0);
    } else {
        // for the boomerang, only want to hold the attack pose as long as they don't move
        // as soon as they start moving, they should go into normal movement frames
        bool attacking = entities[0].type == SWORD || (entities[1].type == BOOMERANG && !movedThisFrame);

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
    }

    renderer->drawPlusMask(x - 4, y - 8, player_plus_mask, spriteIndex, mirror);

#ifdef DRAW_HITBOXES
    renderer->drawRect(x, y, w, h, BLACK);
#endif

    return UNSET;
}

EntityType Player::update(BaseEntity* player, Arduboy2* arduboy, byte frame) {
    if (tookDamageCount > 0) {
        tookDamageCount -= 1;
    }

    if (receiveItemCount > 0) {
        receiveItemCount -= 1;
        return UNSET;
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
    if (other->type == CHEST) {
        undoMove();
        receiveItemFromChest(other);
        return UNSET;
    }

    if (other->damage && tookDamageCount == 0) {
        health = clamp(health - other->damage, 0, State::gameState.totalHealth);
        bounceBack();

        // hack: make the sword bounce back too, in case we
        // were hit while attacking. If not attacking and sword
        // is UNSET, then this is basically a noop
        entities[0].dir = dir;
        entities[0].bounceBack();

        tookDamageCount = 30;
    }

    if (other->type == KEY) {
        other->type = UNSET;
        State::gameState.numKeys = clamp(State::gameState.numKeys + 1, 0, MAX_KEYS);
    }

    if (other->type == HEART) {
        other->type = UNSET;
        health = clamp(health + 1, 0, State::gameState.totalHealth);
    }

    if (other->type == BOMB) {
        other->type = UNSET;
        numBombs = clamp(numBombs + 2, 0, MAX_BOMB_COUNT);
    }

    return UNSET;
}

void Player::receiveItemFromChest(Entity* chest) {
    if (
        // hardcoding chest height saves 4 bytes, win!
        y >= (chest->y + 8) &&
        chest->currentFrame == 0
    ) {
        EntityType item = chest->health;
        chest->currentFrame = 1;

        if (item == KEY) {
            State::gameState.numKeys = clamp(State::gameState.numKeys + 1, 0, MAX_KEYS);
        }

        if (item >= SWORD && item <= HEART) {
            receiveItemCount = 60;
            receivedItem = item;

            if (receivedItem > SWORD && receivedItem < KEY) {
                bButtonEntityType = receivedItem;
            }

            if (receivedItem == BOMB) {
                numBombs = 3;
            }

            if (receivedItem < KEY) {
                State::gameState.numAcquiredItems += 1;
            }

            if (receivedItem == HEART) {
                State::gameState.totalHealth += 1;
                health = State::gameState.totalHealth;
            }
        }

        const uint8_t roomIndex = TileRoom::getRoomIndex(TileRoom::x, TileRoom::y);
        State::setTriggered(roomIndex);
        State::saveToEEPROM();
    }
}

