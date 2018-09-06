#ifndef entityTemplates_h
#define entityTemplates_h

#include <Arduino.h>
#include "entityTypes.h"
#include "entity.h"
#include "spriteBitmaps.h"
#include "tileBitmaps.h"
#include "blob.h"
#include "sword.h"
#include "boomerang.h"
#include "bomb.h"
#include "explosion.h"
#include "death.h"
#include "secretWall.h"
#include "blobMother.h"
#include "lock.h"

const uint8_t NUM_ENTITY_PROPS = 3;
const uint8_t NUM_ENTITY_POINTERS = 4;

const uint8_t PROGMEM entityProperties[NUM_ENTITIES * NUM_ENTITY_PROPS] = {
    // 0 SWORD
    15 << 4 | 15,   // width - 1 | height - 1
    0 << 4 | 1,     // health | damage
    20,             // duration

    // 1, BOOMERANG
    15 << 4 | 15,
    0 << 4 | 0,
    20,

    // 2, BOMB
    10 << 4 | 15,
    0 << 4 | 0,
    150,

    // 3, CANDLE
    0,
    0 << 4 | 0,
    0,

    // 4, KEY
    7 << 4 | 7,
    0 << 4 | 0,
    0,

    // 5, HEART
    7 << 4 | 7,
    0 << 4 | 0,
    180,

    // 6, CHEST
    15 << 4 | 15,
    0 << 4 | 0,
    0,

    // 7, BLOB
    7 << 4 | 7, // width - 1 | height - 1
    2 << 4 | 1, // health | damage
    0,          // duration

    // 8, SPIKE
    7 << 4 | 7,
    0 << 4 | 0,
    0,

    // 9, ENEMY3
    0,
    0,
    0,

    // 10, BLOB_MOTHER
    15 << 4 | 15,
    6 << 4 | 1,
    10,

    // 11, NEMESIS
    0,
    0,
    0,

    // 12, TELEPORTER
    15 << 4 | 7,
    0,
    0,

    // 13, LOCK
    15 << 4 | 7,
    1 << 4 | 0,
    0,

    // 14, PROJECTILE
    0,
    0,
    0,

    // 15, EXPLOSION
    15 << 4 | 15,
    0 << 4 | 1,
    20,

    // 16, DEATH
    7 << 4 | 7,
    0 << 4 | 0,
    24,

    // 17, SECRET_WALL
    15 << 4 | 15,
    1 << 4 | 0,
    0,
};

const void* const PROGMEM entityPointers[NUM_ENTITIES * NUM_ENTITY_POINTERS] = {
    // 0, SWORD
    sword_plus_mask,    // tiles
    Sword::update,      // update
    NULL,               // render
    NULL,               // onCollide


    // 1, BOOMERANG
    itemIcons_plus_mask,
    Boomerang::update,
    NULL,
    Boomerang::onCollide,

    // 2, BOMB
    itemIcons_plus_mask,
    Bomb::update,
    NULL,
    NULL,

    // 3, CANDLE
    NULL,
    NULL,
    NULL,
    NULL,

    // 4, KEY
    key_plus_mask,
    NULL,
    NULL,
    NULL,

    // 5, HEART
    heart_plus_mask,
    NULL,
    NULL,
    NULL,

    // 6, CHEST
    chest_plus_mask,
    NULL,
    NULL,
    NULL,

    // 7, BLOB
    blob_plus_mask,
    Blob::update,
    NULL,
    Blob::onCollide,

    // 8, SPIKE
    spike_plus_mask,
    NULL,
    NULL,
    NULL,

    // 9, ENEMY3
    NULL,
    NULL,
    NULL,
    NULL,

    // 10, BLOB_MOTHER
    blobMother_plus_mask,
    BlobMother::update,
    NULL,
    Blob::onCollide,

    // 11, NEMESIS
    NULL,
    NULL,
    NULL,
    NULL,

    // 12, TELEPORTER
    NULL,
    NULL,
    NULL,
    NULL,

    // 13, LOCK
    lock_plus_mask,
    NULL,
    NULL,
    Lock::onCollide,

    // 14, PROJECTILE
    NULL,
    NULL,
    NULL,
    NULL,

    // 15, EXPLOSION
    explosion_plus_mask,
    Explosion::update,
    NULL,
    NULL,

    // 16, DEATH
    NULL,
    Death::update,
    NULL,
    NULL,

    // 17, SECRET_WALL
    NULL,
    NULL,
    SecretWall::render,
    SecretWall::onCollide,
};

void loadEntity(Entity& entity, EntityType entityType);

#endif

