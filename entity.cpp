#include "entity.h"
#include "util.h"
#include "tileRoom.h"
#include "spriteBitmaps.h"

const uint8_t BOUNCE_AMOUNT = 16;

boolean Entity::overlaps(Entity* other) {
    return !(
        other->x                 >= x + width  ||
        other->x + other->width  <= x          ||
        other->y                 >= y + height ||
        other->y + other->height <= y
    );
}

void Entity::bounceBack(Entity* bounceAwayFrom) {
    int8_t diffX = x - bounceAwayFrom->x;
    int8_t diffY = y - bounceAwayFrom->y;

    int8_t bounceXAmount = 0;
    int8_t bounceYAmount = 0;

    if (abs(diffX) > abs(diffY)) {
        bounceXAmount = diffX > 0 ? BOUNCE_AMOUNT : -BOUNCE_AMOUNT;
    } else {
        bounceYAmount = diffY > 0 ? BOUNCE_AMOUNT : -BOUNCE_AMOUNT;
    }

    Direction curDir = dir;
    moveTo(clamp(x + bounceXAmount, 0, WIDTH - 13 - width), clamp(y + bounceYAmount, 0, HEIGHT - height - 1));
    dir = curDir;
}

EntityType Entity::render(Renderer* renderer, uint8_t renderFrame) {
    if (type == UNSET) {
        return UNSET;
    }

    if (tookDamageCount > 0) {
        tookDamageCount -= 1;

        if (tookDamageCount % 3 == 1) {
            return UNSET;
        }
    }

    EntityType result = UNSET;
    if (renderPtr != NULL) {
        result = renderPtr(this, renderer, renderFrame);
    } else if (tiles) {
        bool invert = TileRoom::isInDungeon();
        renderer->drawPlusMask(x, y, tiles, currentFrame, mirror, invert);
    }

#ifdef DRAW_HITBOXES
    renderer->drawRect(x, y, width, height, BLACK);
#endif

    return result;
}

EntityType Entity::update(Entity* player, Arduboy2* arduboy, uint8_t frame) {
    if (stunCount > 0) {
        stunCount -= 1;
        return UNSET;
    }

    if (updatePtr != NULL) {
        return updatePtr(this, player, arduboy, frame);
    }

    return UNSET;
}

EntityType Entity::onCollide(Entity* other, Entity* player) {
    if (type == UNSET) {
        return UNSET;
    }

    if (collideOtherEntityPtr != NULL) {
        return collideOtherEntityPtr(this, other, player);
    }

    return UNSET;
}

