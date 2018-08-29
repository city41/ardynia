#ifndef entityTemplates_h
#define entityTemplates_h

#include <Arduino.h>
#include "entityTypes.h"
#include "entity.h"
#include "bitmaps.h"
#include "blob.h"
#include "sword.h"
#include "boomerang.h"

const uint8_t TRUE = 1;
const uint8_t FALSE = 0;

const uint8_t PROGMEM entityProperties[] = {
    // 0 SWORD
    16,           // width
    16,           // height
    DOWN,         // direction
    0,            // health
    2,            // damage
    20,           // duration
    TRUE,         // invertInDungeon

    // 1, BOMB
    16,
    16,
    DOWN,
    0,
    1,
    120,
    TRUE,

    // 2, BOOMERANG
    16,
    16,
    DOWN,
    0,
    0,
    20,
    TRUE,

    // 3, CANDLE
    0,
    0,
    DOWN,
    0,
    0,
    0,
    FALSE,

    // 4, KEY
    8,
    8,
    DOWN,
    0,
    0,
    0,
    FALSE,

    // 5, HEART
    8,
    8,
    DOWN,
    0,
    0,
    180,
    TRUE,

    // 6, HEART_CONTAINER
    0,
    0,
    DOWN,
    0,
    0,
    0,
    FALSE,

    // 7, CHEST
    16,
    16,
    DOWN,
    0,
    0,
    0,
    FALSE,

    // 8, BLOB
    8,
    8,
    DOWN,
    2, // health
    1, // damage
    0, // duration
    TRUE, // invertInDungeon

    // 9, ENEMY2
    0,
    0,
    DOWN,
    0,
    0,
    0,
    FALSE,

    // 10, ENEMY3
    0,
    0,
    DOWN,
    0,
    0,
    0,
    FALSE,

    // 11, ENEMY4
    0,
    0,
    DOWN,
    0,
    0,
    0,
    FALSE,

    // 12, ENEMY5
    0,
    0,
    DOWN,
    0,
    0,
    0,
    FALSE,

    // 13, ENEMY6
    0,
    0,
    DOWN,
    0,
    0,
    0,
    FALSE,

    // 14, BOSS1
    0,
    0,
    DOWN,
    0,
    0,
    0,
    FALSE,

    // 15, BOSS2
    0,
    0,
    DOWN,
    0,
    0,
    0,
    FALSE,

    // 16, BOSS3
    0,
    0,
    DOWN,
    0,
    0,
    0,
    FALSE,

    // 17, BUMPER
    0,
    0,
    DOWN,
    0,
    0,
    0,
    FALSE,

    // 18, TELEPORTER
    4,
    4,
    DOWN,
    0,
    0,
    0,
    FALSE,

    // 19, BUSH
    0,
    0,
    DOWN,
    0,
    0,
    0,
    FALSE,

    // 20, LOCK
    0,
    0,
    DOWN,
    0,
    0,
    0,
    FALSE,

    // 21, FLAME
    0,
    0,
    DOWN,
    0,
    0,
    0,
    FALSE,

    // 22, PROJECTILE
    0,
    0,
    DOWN,
    0,
    0,
    0,
    FALSE,
};

const void* const PROGMEM entityPointers[] = {
    // 0, SWORD
    sword_tiles,        // tiles
    sword_mask,         // masks
    Sword::spawn,       // spawn
    Sword::update,      // update
    NULL,               // render
    NULL,               // onCollide

    // 1, BOMB
    itemIcons_tiles,
    itemIcons_mask,
    NULL,
    NULL,
    NULL,
    NULL,

    // 2, BOOMERANG
    itemIcons_tiles,
    itemIcons_mask,
    Boomerang::spawn,
    Boomerang::update,
    NULL,
    Boomerang::onCollide,

    // 3, CANDLE
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 4, KEY
    key_tiles,
    key_mask,
    NULL,
    NULL,
    NULL,
    NULL,

    // 5, HEART
    heart_tiles,
    heart_mask,
    NULL,
    NULL,
    NULL,
    NULL,

    // 6, HEART_CONTAINER
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 7, CHEST
    chest_tiles,
    chest_mask,
    NULL,
    NULL,
    NULL,
    NULL,

    // 8, BLOB
    blob_tiles,
    blob_mask,
    NULL,
    Blob::update,
    NULL,
    Blob::onCollide,

    // 9, ENEMY2
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 10, ENEMY3
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 11, ENEMY4
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 12, ENEMY5
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 13, ENEMY6
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 14, BOSS1
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 15, BOSS2
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 16, BOSS3
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 17, BUMPER
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 18, TELEPORTER
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 19, BUSH
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 20, LOCK
    lock_tiles,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 21, FLAME
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 22, PROJECTILE
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

void loadEntity(Entity& entity, EntityType entityType);

#endif

