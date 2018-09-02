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

const uint8_t NUM_ENTITY_PROPS = 6;
const uint8_t NUM_ENTITY_POINTERS = 4;

const uint8_t PROGMEM entityProperties[NUM_ENTITIES * NUM_ENTITY_PROPS] = {
    // 0 SWORD
    16,           // width
    16,           // height
    0,            // health
    1,            // damage
    20,           // duration
    true,         // invertInDungeon

    // 1, BOOMERANG
    16,
    16,
    0,
    0,
    20,
    true,

    // 2, BOMB
    11,
    16,
    0,
    0,
    150,
    true,

    // 3, CANDLE
    0,
    0,
    0,
    0,
    0,
    false,

    // 4, KEY
    8,
    8,
    0,
    0,
    0,
    false,

    // 5, HEART
    8,
    8,
    0,
    0,
    180,
    true,

    // 6, CHEST
    16,
    16,
    0,
    0,
    0,
    true,

    // 7, BLOB
    8,
    8,
    2, // health
    1, // damage
    0, // duration
    true, // invertInDungeon

    // 8, BAT
    8,
    8,
    1,
    1,
    0,
    true,

    // 9, SPIKE
    8,
    8,
    255,
    1,
    0,
    false,

    // 10, SKULL
    16,
    16,
    1,
    2,
    0,
    false,

    // 11, OCTO
    16,
    16,
    4,
    1,
    0,
    false,

    // 12, GHOST
    8,
    16,
    1,
    2,
    0,
    false,

    // 13, BLOB_MOTHER
    16,
    16,
    6,
    1,
    10,
    false,

    // 14, NECROMANCER
    0,
    0,
    0,
    0,
    0,
    false,

    // 15, NEMESIS
    0,
    0,
    0,
    0,
    0,
    false,

    // 16, TELEPORTER
    18,
    8,
    0,
    0,
    0,
    false,

    // 17, BUSH
    0,
    0,
    0,
    0,
    0,
    false,

    // 18, LOCK
    18,
    8,
    1,
    0,
    0,
    true,

    // 19, PROJECTILE
    0,
    0,
    0,
    0,
    20,
    false,

    // 20, EXPLOSION
    16,
    16,
    0,
    1,
    20,
    true,

    // 21, OLD_MAN
    11,
    HEIGHT, // whole screen, this guy is basically a total bumper
    0,
    0,
    0,
    false,

    // 22, DEATH
    8,
    8,
    0,
    0,
    24,
    true,

    // 23, SECRET_WALL
    16,
    16,
    1,
    0,
    0,
    false,
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

    // 8, BAT
    bat_plus_mask,
    NULL,
    NULL,
    NULL,

    // 9, SPIKE
    spike_plus_mask,
    NULL,
    NULL,
    NULL,

    // 10, SKULL
    NULL,
    NULL,
    NULL,
    NULL,

    // 11, OCTO
    NULL,
    NULL,
    NULL,
    NULL,

    // 12, GHOST
    ghost_plus_mask,
    NULL,
    NULL,
    NULL,

    // 13, BLOB_MOTHER
    blobMother_plus_mask,
    BlobMother::update,
    NULL,
    Blob::onCollide,

    // 14, NECROMANCER
    NULL,
    NULL,
    NULL,
    NULL,

    // 15, NEMESIS
    NULL,
    NULL,
    NULL,
    NULL,

    // 16, TELEPORTER
    NULL,
    NULL,
    NULL,
    NULL,

    // 17, BUSH
    NULL,
    NULL,
    NULL,
    NULL,

    // 18, LOCK
    lock_plus_mask,
    NULL,
    NULL,
    Lock::onCollide,

    // 19, PROJECTILE
    NULL,
    NULL,
    NULL,
    NULL,

    // 20, EXPLOSION
    explosion_plus_mask,
    Explosion::update,
    NULL,
    NULL,

    // 21, OLD_MAN
    oldMan_plus_mask,
    NULL,
    NULL,
    NULL,

    // 22, DEATH
    NULL,
    Death::update,
    NULL,
    NULL,

    // 23, SECRET_WALL
    NULL,
    NULL,
    SecretWall::render,
    SecretWall::onCollide,
};

void loadEntity(Entity& entity, EntityType entityType);

#endif

