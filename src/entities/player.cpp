#include "player.h"
#include "../entityTemplates.h"
#include "../util.h"
#include "../tileRoom.h"
#include "../state.h"
#include "../sfx.h"
#include "../itemSprites.h"
#include "../game.h"
#include "../renderer.h"

extern Renderer renderer;

const uint8_t PLAYER_VELOCITY = 2;

void Player::reset() {
    moveTo(WIDTH / 2 - width, HEIGHT / 2 - height, true);
    dir = DOWN;
    tookDamageCount = 0;
    numBombs = 0;
    health = 2;
    receiveItemCount = 0;

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
    if (State::gameState.hasSword == 0 || entities[0].type != UNSET) {
        return;
    }

    loadEntity(entities[0], SWORD);
    Sfx::play(Sfx::sword);
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

    EntityType entityToLoad = bButtonEntityType;
    if (entityToLoad == RING) {
        entityToLoad = PROJECTILE;
    }

    loadEntity(entities[1], entityToLoad);

    if (bButtonEntityType == BOMB) {
        // send a hint this is an active bomb
        // instead of an item drop
        entities[1].health = 1;
        entities[1].x = x;
        entities[1].y = y - 4;
    }
}

const uint8_t PROGMEM playerSpriteIndexAndMirror[] = {
    // LEFT
    0, 4, 0,
    // RIGHT
    0, 4, MIRROR_HORIZONTAL,
    // UP
    2, 5, 0,
    // DOWN
    3, 6, 0
};

void Player::render(uint8_t frame) {
    // recovering from damage? "flash" the player every third frame
    // TODO: this is duplicated in Entity::render, DRY?
    if (tookDamageCount > 0 && tookDamageCount % 3 == 1) {
        return;
    }

    uint8_t spriteIndex;
    MirrorMode mirror = 0;

    if (receiveItemCount > 0) {
        spriteIndex = 2;
        const uint8_t* itemBmp = pgm_read_ptr(secondaryItem_sprites + receivedItem);
        renderer.drawPlusMask(receiveX, receiveY - (6 - receiveItemCount/8), itemBmp, 0, 0, (DrawMode)State::isInDungeon());
    } else {
        // for the boomerang and magic ring, only want to hold the attack pose as long as they don't move
        // as soon as they start moving, they should go into normal movement frames
        bool attacking = entities[0].type == SWORD ||
            ((entities[1].type == BOOMERANG || entities[1].type == PROJECTILE) && !movedThisFrame);

        const uint8_t* offset = playerSpriteIndexAndMirror + (dir * 3) + attacking;
        spriteIndex = pgm_read_byte(offset);
        mirror = (MirrorMode)pgm_read_byte(offset + (attacking ? 1 : 2));

        if (movedThisFrame && ((frame / 6) % 2) == 0) {
            if (dir == LEFT || dir == RIGHT) {
                ++spriteIndex;
            } else {
                mirror = MIRROR_HORIZONTAL;
            }
        }
    }

    renderer.drawPlusMask(x - 4, y - 8, player_plus_mask, spriteIndex, mirror);

#ifdef DRAW_HITBOXES
    renderer.drawRect(x, y, w, h, BLACK);
#endif
}

EntityType Player::update(Entity& player, Game& game, Arduboy2Base& arduboy, byte frame) {
    if (tookDamageCount > 0) {
        tookDamageCount -= 1;
    }

    if (receiveItemCount > 0) {
        receiveItemCount -= 1;
        return UNSET;
    }

    int16_t newX = x, newY = y;

    if (arduboy.pressed(DOWN_BUTTON)) {
        newY += PLAYER_VELOCITY;
    }

    if (arduboy.pressed(UP_BUTTON)) {
        newY -= PLAYER_VELOCITY;
    }

    if (arduboy.pressed(LEFT_BUTTON)) {
        newX -= PLAYER_VELOCITY;
    }

    if (arduboy.pressed(RIGHT_BUTTON)) {
        newX += PLAYER_VELOCITY;
    }

    if (arduboy.justPressed(A_BUTTON)) {
        useSword();
    }

    if (arduboy.justPressed(B_BUTTON)) {
        bButtonAction();
    }

    movedThisFrame = false;
    bool attackingWithSword = entities[0].type == SWORD;

    if (!attackingWithSword && (newX != x || newY != y)) {
        movedThisFrame = true;
        moveTo(newX, newY);
    }

    return UNSET;
}

EntityType Player::onCollide(Entity& other, Entity& player, Game& game) {
    if (other.type == CHEST) {
        undoMove();
        receiveItemFromChest(other, game);
        return UNSET;
    }

    if (other.damage && tookDamageCount == 0) {
        health = max(health - other.damage, 0);
        bounceBack(*this, other);
        Sfx::play(Sfx::playerDamage);

        /* // hack: make the sword bounce back too, in case we */
        /* // were hit while attacking. If not attacking and sword */
        /* // is UNSET, then this is basically a noop */
        /* entities[0].dir = dir; */
        /* entities[0].bounceBack(*this, other); */

        tookDamageCount = 30;
    }

    if (other.type == HEART) {
        other.type = UNSET;
        health = min(health + 1, State::gameState.totalHealth);
        Sfx::play(Sfx::pickUpItem);
    }

    if (other.type == BOMB) {
        other.type = UNSET;
        numBombs = min(numBombs + 3, MAX_BOMB_COUNT);
        Sfx::play(Sfx::pickUpItem);
    }

    if (other.type == KEY) { 
        other.type = UNSET;
        State::gameState.numKeys[State::gameState.currentDungeon] += 1;
        State::setCurrentRoomTriggered();
        Sfx::play(Sfx::pickUpItem);
    }

    return UNSET;
}

void Player::receiveItemFromChest(Entity& chest, Game& game) {
    if (
        // hardcoding chest height saves 4 bytes, win!
        y >= (chest.y + 8) &&
        chest.currentFrame == 0
    ) {
        chest.currentFrame = 1;
        receiveItemCount = 60;
        receiveX = chest.x + 2;
        receiveY = chest.y - 10;

        if (game.roomType == OPEN_CHESTS_IN_RIGHT_ORDER) {
            // THIS RECIPE RELIES ON buildEntityArrays placing the chests
            // in the proper order.
            // OR!!! it can just rely on the random ordering that buildEntityArrays gets
            // it will be consistent for a given build of the game, so this might work, but
            // would need to make sure it's not always just the left most chest, center chest, right chest
            // but that should be easy to ensure

            const uint8_t chestState = game.chestOpeningOrderState();

            if (chestState == AllChestsOpenCorrectly) {
                receivedItem = KEY;
            } else if (chestState == ChestsOpenCorrectlySoFar) {
                Sfx::play(Sfx::successJingle);
                receivedItem = HAPPY_FACE;
                return;
            } else {
                receivedItem = SAD_FACE;
                Sfx::play(Sfx::playerDamage);
                health = max(0, health - 1);
                bounceBack(*this, chest);
                game.closeAllChests();
                return;
            }
        } else {
            receivedItem = chest.health;
        }


        if (receivedItem == BOMB) {
            numBombs = min(numBombs + 3, MAX_BOMB_COUNT);
        }

        if (receivedItem == SWORD) {
            State::gameState.hasSword = 1;
        }

        if (
            (receivedItem > SWORD && receivedItem < KEY) ||
            receivedItem == RING
        ) {
            State::gameState.numAcquiredItems = min(3, State::gameState.numAcquiredItems + 1);

            bButtonEntityType = receivedItem;
        }

        if (receivedItem == HEART) {
            State::gameState.totalHealth += 1;
            health = State::gameState.totalHealth;
        }

        if (receivedItem == KEY) { 
            State::gameState.numKeys[State::gameState.currentDungeon] += 1;
        }

        if (receivedItem == BOSS_KEY) {
            State::gameState.bossKeys[State::gameState.currentDungeon] += 1;
        }

        Sfx::play(Sfx::successJingle);
        State::setCurrentRoomTriggered();
    }
}

