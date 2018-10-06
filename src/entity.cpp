#include "entity.h"
#include "util.h"
#include "tileRoom.h"
#include "spriteBitmaps.h"
#include "tileBitmaps.h"
#include "state.h"
#include "renderer.h"

extern Renderer renderer;

const uint8_t BOUNCE_AMOUNT = 16;

const EntityType PROGMEM itemDropItems[] = {
    UNSET,
    HEART,
    BOMB
};

void Entity::moveTowardsOtherEntity(Entity& other, uint8_t amount) {
    int16_t ox = other.x;
    int8_t oy = other.y;

    int16_t nx = x;
    int8_t ny = y;

    if (nx - ox > 0) {
        nx -= amount;
        mirror = 0;
    } else if (nx - ox < 0) {
        nx += amount;
        mirror = MIRROR_HORIZONTAL;
    }

    if (ny - oy > 0) {
        ny -= amount;
    } else if (ny - oy < 0) {
        ny += amount;
    }

    moveTo(nx, ny);
}

bool Entity::overlaps(Entity& other) {
    return !(
        other.x                 >= x + width  ||
        other.x + other.width  <= x          ||
        other.y                 >= y + height ||
        other.y + other.height <= y
    );
}

void Entity::bounceBack(Entity& bounceAwayFromA, Entity& bounceAwayFromB) {
    int8_t acx = bounceAwayFromA.x + bounceAwayFromA.width / 2;
    int8_t acy = bounceAwayFromA.y + bounceAwayFromA.height / 2;
    int8_t bcx = bounceAwayFromB.x + bounceAwayFromB.width / 2;
    int8_t bcy = bounceAwayFromB.y + bounceAwayFromB.height / 2;

    int8_t diffX = acx - bcx;
    int8_t diffY = acy - bcy;

    int8_t bounceXAmount = 0;
    int8_t bounceYAmount = 0;

    if (abs(diffX) > abs(diffY)) {
        bounceXAmount = diffX > 0 ? BOUNCE_AMOUNT : -BOUNCE_AMOUNT;
    } else {
        bounceYAmount = diffY > 0 ? BOUNCE_AMOUNT : -BOUNCE_AMOUNT;
    }

    Direction curDir = dir;
    moveTo(Util::clamp(x + bounceXAmount, 0, WIDTH - 17 - width), Util::clamp(y + bounceYAmount, 0, HEIGHT - height - 1));
    dir = curDir;
}

void Entity::rotateViaMirror(uint8_t frame) {
    MirrorMode newMirror = 0;

    if (frame > 49) {
        newMirror = MIRROR_HORIZONTAL | MIRROR_VERTICAL;
    } else if (frame > 39) {
        newMirror = MIRROR_HORIZONTAL;
    } else if (frame > 29) {
        newMirror = 0;
    } else if (frame > 19) {
        newMirror = MIRROR_HORIZONTAL | MIRROR_VERTICAL;
    } else if (frame > 9) {
        newMirror = MIRROR_HORIZONTAL;
    }

    mirror = newMirror;
}

void Entity::render(uint8_t renderFrame) {

    DrawMode drawMode = State::isInDungeon() ? (type == BAT ? Xor : Invert) : Normal;

    if (deathCount) {
        deathCount -= 1;
        renderer.drawPlusMask(x, y, deathPoof_plus_mask, 0, renderFrame & 1, drawMode);

    }

    if (type == UNSET) {
        return;
    }

    if (tookDamageCount > 0) {
        tookDamageCount -= 1;

        if (tookDamageCount % 3 == 1) {
            return;
        }
    }


    if (needsMask) {
        bool isNemesis = type == NEMESIS;
        int16_t offsetX = isNemesis ? -4 : 0;
        int8_t offsetY = isNemesis ? -8 : 0;
        renderer.drawPlusMask(x + offsetX, y + offsetY, tiles, currentFrame, mirror, drawMode);
    } else {
        renderer.drawOverwrite(x, y, tiles, currentFrame, mirror, drawMode);
    }

#ifdef DRAW_HITBOXES
    renderer.drawRect(x, y, width, height, BLACK);
#endif
}

EntityType Entity::update(Entity& player, uint8_t frame) {
    if (type == UNSET) {
        return UNSET;
    }

    if (stunCount > 0) {
        stunCount -= 1;
        return UNSET;
    }

    if (updatePtr != NULL) {
        return updatePtr(this, player, frame);
    }

    return UNSET;
}

EntityType Entity::onCollide(Entity& other, Entity& player) {
    if (type == UNSET) {
        return UNSET;
    }

    if (collideOtherEntityPtr != NULL) {
        EntityType result = collideOtherEntityPtr(this, other, player);

        if (type == UNSET) {
            deathCount = 10;
        }

        if (result == ITEM_DROP) {
            // in boss room, always drop something
            const uint8_t maxRoll = State::gameState.numAcquiredItems > 1 ? 3 : 2;

            uint8_t diceRoll = random(0, maxRoll);
            return pgm_read_byte(itemDropItems + diceRoll);
        } else {
            return result;
        }
    }

    return UNSET;
}

