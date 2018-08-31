#include "entity.h"
#include "util.h"
#include "tileRoom.h"
#include "spriteBitmaps.h"

EntityType Entity::render(Renderer* renderer, uint8_t renderFrame) {
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
        boolean invert = invertInDungeon == 1 && TileRoom::isInDungeon();
        renderer->drawPlusMask(x, y, tiles, currentFrame, mirror, invert);
    }

#ifdef DRAW_HITBOXES
    renderer->drawRect(x, y, width, height, WHITE);
#endif

    return result;
}

EntityType Entity::spawn(BaseEntity* player) {
    if (spawnPtr != NULL) {
        return spawnPtr(this, player);
    }

    return UNSET;
}

EntityType Entity::update(BaseEntity* player, Arduboy2* arduboy, uint8_t frame) {
    if (stunCount > 0) {
        stunCount -= 1;
        return UNSET;
    }

    if (updatePtr != NULL) {
        return updatePtr(this, player, arduboy, frame);
    }

    return UNSET;
}

EntityType Entity::onCollide(BaseEntity* other, BaseEntity* player) {
    if (collideOtherEntityPtr != NULL) {
        return collideOtherEntityPtr(this, other, player);
    }

    return UNSET;
}

