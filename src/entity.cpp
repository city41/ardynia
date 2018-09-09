#include "entity.h"
#include "util.h"
#include "tileRoom.h"
#include "spriteBitmaps.h"
#include "tileBitmaps.h"

const uint8_t BOUNCE_AMOUNT = 16;

const EntityType PROGMEM itemDropItems[] = {
    UNSET,
    HEART,
    BOMB
};

void Entity::moveTowardsOtherEntity(Entity& other, uint8_t amount) {
    int16_t ox = other.x;
    int16_t oy = other.y;

    int16_t nx = x;
    int16_t ny = y;

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

void Entity::bounceBack(Entity& bounceAwayFrom) {
    int8_t diffX = x - bounceAwayFrom.x;
    int8_t diffY = y - bounceAwayFrom.y;

    int8_t bounceXAmount = 0;
    int8_t bounceYAmount = 0;

    if (abs(diffX) > abs(diffY)) {
        bounceXAmount = diffX > 0 ? BOUNCE_AMOUNT : -BOUNCE_AMOUNT;
    } else {
        bounceYAmount = diffY > 0 ? BOUNCE_AMOUNT : -BOUNCE_AMOUNT;
    }

    Direction curDir = dir;
    moveTo(Util::clamp(x + bounceXAmount, 0, WIDTH - 13 - width), Util::clamp(y + bounceYAmount, 0, HEIGHT - height - 1));
    dir = curDir;
}

void Entity::render(Renderer& renderer, uint8_t renderFrame) {
    if (type == UNSET) {
        return;
    }

    if (tookDamageCount > 0) {
        tookDamageCount -= 1;

        if (tookDamageCount % 3 == 1) {
            return;
        }
    }

    bool invert = TileRoom::isInDungeon();

    if (needsMask) {
        bool isNemesis = type == NEMESIS;
        int16_t offsetX = isNemesis ? -4 : 0;
        int16_t offsetY = isNemesis ? -8 : 0;
        renderer.drawPlusMask(x + offsetX, y + offsetY, tiles, currentFrame, mirror, invert);
    } else {
        renderer.drawOverwrite(x, y, tiles, currentFrame, mirror, invert);
    }

#ifdef DRAW_HITBOXES
    renderer.drawRect(x, y, width, height, BLACK);
#endif
}

EntityType Entity::update(Entity& player, Arduboy2Base& arduboy, uint8_t frame) {
    if (type == UNSET) {
        return UNSET;
    }

    if (stunCount > 0) {
        stunCount -= 1;
        return UNSET;
    }

    if (updatePtr != NULL) {
        return updatePtr(this, player, arduboy, frame);
    }

    return UNSET;
}

EntityType Entity::onCollide(Entity& other, Entity& player, Game& game) {
    if (type == UNSET) {
        return UNSET;
    }

    if (collideOtherEntityPtr != NULL) {
        EntityType result = collideOtherEntityPtr(this, other, player, game);

        if (result == ITEM_DROP) {
            uint8_t diceRoll = random(0, 3);
            return pgm_read_byte(itemDropItems + diceRoll);
        } else {
            return result;
        }
    }

    return UNSET;
}

