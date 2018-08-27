#include "entity.h"

EntityType Entity::render(Renderer* renderer, uint8_t renderFrame) {
    EntityType result = UNSET;
    if (renderPtr != NULL) {
        result = renderPtr(this, renderer, renderFrame);
    } else if (tiles != NULL && maskTiles != NULL) {
        renderer->drawExternalMask(x, y, tiles, maskTiles, currentFrame);
    } else {
        renderer->drawOverwrite(x, y, tiles, currentFrame);
    }

#ifdef DRAW_HITBOXES
    renderer->drawRect(x, y, w, h, BLACK);
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
    if (updatePtr != NULL) {
        return updatePtr(this, player, arduboy, frame);
    }

    return UNSET;
}

EntityType Entity::onCollide(BaseEntity* other) {
    if (collideOtherEntityPtr != NULL) {
        return collideOtherEntityPtr(this, other);
    }

    return UNSET;
}

EntityType Entity::onCollide(uint8_t tile) { return UNSET; }
