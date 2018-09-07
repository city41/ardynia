#include "entityTemplates.h"
#include "util.h"

void loadEntity(Entity& entity, EntityType entityType) {
    if (entityType == UNSET) {
        return;
    }

    entity.type = entityType;
    entity.currentFrame = 0;

    uint8_t* start = entityProperties + (entityType * NUM_ENTITY_PROPS);

    const uint8_t widthAndHeight = (uint8_t)pgm_read_byte(start++);
    const uint8_t healthAndDamage = (uint8_t)pgm_read_byte(start++);
    entity.duration = pgm_read_byte(start++);

    entity.width = (widthAndHeight >> 4) + 1;
    entity.height = (widthAndHeight & 0xF) + 1;
    entity.health = healthAndDamage >> 4;
    entity.damage = healthAndDamage & 0xF;

    void** pStart = entityPointers + (entityType * NUM_ENTITY_POINTERS);

    entity.tiles = (uint8_t*)pgm_read_word(pStart++);
    entity.updatePtr = (Entity::EntityUpdatePtr)pgm_read_word(pStart++);
    entity.collideOtherEntityPtr = (Entity::EntityCollideOtherEntityPtr)pgm_read_word(pStart++);
}

