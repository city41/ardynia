#include "loadEntity.h"
#include "entityTemplates.h"
#include "util.h"
#include "tileBitmaps.h"

void loadEntity(Entity& entity, EntityType entityType) {
    if (entityType == UNSET) {
        return;
    }

    entity.type = entityType;
    entity.currentFrame = 0;
    entity.mirror = 0;
    entity.tookDamageCount = 0;
    entity.stunCount = 0;
    entity.prevX = 0;
    entity.prevY = 0;
    entity.vx = 0;
    entity.vy = 0;

    const uint8_t* start = entityProperties + (entityType * NUM_ENTITY_PROPS);

    const uint8_t widthAndHeight = (uint8_t)pgm_read_byte(start++);
    const uint8_t healthAndDamage = (uint8_t)pgm_read_byte(start++);
    entity.duration = pgm_read_byte(start++);
    entity.needsMask = pgm_read_byte(start++);

    entity.width = (widthAndHeight >> 4) + 1;
    entity.height = (widthAndHeight & 0xF) + 1;
    entity.health = healthAndDamage >> 4;
    entity.damage = healthAndDamage & 0xF;

    const void* const* pStart = entityPointers + (entityType * NUM_ENTITY_POINTERS);

    entity.tiles = (const uint8_t*)pgm_read_word(pStart++);
    entity.updatePtr = (Entity::EntityUpdatePtr)pgm_read_word(pStart++);
    entity.collideOtherEntityPtr = (Entity::EntityCollideOtherEntityPtr)pgm_read_word(pStart++);
}

