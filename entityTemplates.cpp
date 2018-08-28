#include "entityTemplates.h"

void loadEntity(Entity& entity, EntityType entityType) {
    entity.type = entityType;
    entity.currentFrame = 0;

    uint8_t* start = entityProperties + (entityType * 6);

    entity.width = pgm_read_byte(start++);
    entity.height = pgm_read_byte(start++);
    entity.dir = pgm_read_byte(start++);
    entity.health = pgm_read_byte(start++);
    entity.damage = pgm_read_byte(start++);
    entity.duration = pgm_read_byte(start++);

    void** pStart = entityPointers + (entityType * 6);

    entity.tiles = (uint8_t*)pgm_read_word(pStart++);
    entity.maskTiles = (uint8_t*)pgm_read_word(pStart++);
    entity.spawnPtr = (Entity::EntitySpawnPtr)pgm_read_word(pStart++);
    entity.updatePtr = (Entity::EntityUpdatePtr)pgm_read_word(pStart++);
    entity.renderPtr = (Entity::EntityRenderPtr)pgm_read_word(pStart++);
    entity.collideOtherEntityPtr = (Entity::EntityCollideOtherEntityPtr)pgm_read_word(pStart++);
}

