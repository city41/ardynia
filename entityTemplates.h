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

const uint8_t NUM_ENTITY_PROPS = 5;
const uint8_t NUM_ENTITY_POINTERS = 4;

const uint8_t PROGMEM entityProperties[NUM_ENTITIES * NUM_ENTITY_PROPS] = {
    // 0 SWORD
    16,           // width
    16,           // height
    0,            // health
    1,            // damage
    20,           // duration

    // 1, BOOMERANG
    16,
    16,
    0,
    0,
    20,

    // 2, BOMB
    11,
    16,
    0,
    0,
    150,

    // 3, CANDLE
    0,
    0,
    0,
    0,
    0,

    // 4, KEY
    8,
    8,
    0,
    0,
    0,

    // 5, HEART
    8,
    8,
    0,
    0,
    180,

    // 6, CHEST
    16,
    16,
    0,
    0,
    0,

    // 7, BLOB
    8,
    8,
    2, // health
    1, // damage
    0, // duration

    // 8, SPIKE
    8,
    8,
    255,
    1,
    0,

    // 9, ENEMY3
    16,
    16,
    1,
    2,
    0,

    // 10, BLOB_MOTHER
    16,
    16,
    6,
    1,
    10,

    // 11, NEMESIS
    0,
    0,
    0,
    0,
    0,

    // 12, TELEPORTER
    18,
    8,
    0,
    0,
    0,

    // 13, LOCK
    18,
    8,
    1,
    0,
    0,

    // 14, PROJECTILE
    0,
    0,
    0,
    0,
    20,

    // 15, EXPLOSION
    16,
    16,
    0,
    1,
    20,

    // 16, DEATH
    8,
    8,
    0,
    0,
    24,

    // 17, SECRET_WALL
    16,
    16,
    1,
    0,
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

