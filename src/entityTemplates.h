#ifndef entityTemplates_h
#define entityTemplates_h

#include <Arduino.h>
#include "entityTypes.h"
#include "entity.h"
#include "spriteBitmaps.h"
#include "tileBitmaps.h"

#include "entities/blob.h"
#include "entities/bat.h"
#include "entities/skeleton.h"
#include "entities/sword.h"
#include "entities/boomerang.h"
#include "entities/bomb.h"
#include "entities/explosion.h"
#include "entities/secretWall.h"
#include "entities/blobMother.h"
#include "entities/lock.h"
#include "entities/nemesis.h"
#include "entities/pot.h"

const uint8_t NUM_ENTITY_PROPS = 4;
const uint8_t NUM_ENTITY_POINTERS = 3;

/**
 * Packs width and height into one byte. Since nibbles have a range of 0-15,
 * it first subtracts one from the value. When unpacking, need to add 1 back on
 */
constexpr uint8_t widthAndHeight(uint8_t width, uint8_t height) {
    return (width - 1) << 4 | (height - 1);
}

/**
 * Packs health and damage into one byte
 */
constexpr uint8_t healthAndDamage(uint8_t health, uint8_t damage) {
    return (health << 4) | damage;
}

const uint8_t PROGMEM entityProperties[NUM_ENTITIES * NUM_ENTITY_PROPS] = {
    // 0 SWORD
    widthAndHeight(16, 16),
    healthAndDamage(0, 1),
    20,             // duration
    true,           // needsMask

    // 1, BOOMERANG
    widthAndHeight(8, 8),
    healthAndDamage(0, 0),
    20,
    true,

    // 2, BOMB
    widthAndHeight(8, 8),
    healthAndDamage(0, 0),
    150,
    true,

    // 3, KEY
    widthAndHeight(8, 8),
    healthAndDamage(0, 0),
    0,
    true,

    // 4, HEART
    widthAndHeight(8, 8),
    healthAndDamage(0, 0),
    180,
    true,

    // 5, BOSS_KEY
    widthAndHeight(8, 8),
    healthAndDamage(0, 0),
    0,
    true,

    // 6, CHEST
    widthAndHeight(14, 8),
    healthAndDamage(0, 0),
    0,
    false,

    // 7, BLOB
    widthAndHeight(8, 8),
    healthAndDamage(2, 1),
    0,          // duration
    true,       // needsMask

    // 8, SPIKE
    widthAndHeight(8, 8),
    healthAndDamage(0, 0),
    0,
    false,

    // 9, BAT
    widthAndHeight(8, 8),
    healthAndDamage(1, 1),
    0,
    true,

    // 10, SKELETON
    widthAndHeight(16, 16),
    healthAndDamage(2, 1),
    0,
    true,

    // 11, BLOB_MOTHER
    widthAndHeight(16, 16),
    healthAndDamage(6, 1),
    10,
    true,

    // 12, NEMESIS
    widthAndHeight(8, 8),
    healthAndDamage(15, 0),
    30,
    true,

    // 13, TELEPORTER
    widthAndHeight(16, 16),
    healthAndDamage(0, 0),
    0,
    false,

    // 14, LOCK
    widthAndHeight(16, 8),
    healthAndDamage(1, 0),
    0,
    false,

    // 15, BOSS_LOCK
    widthAndHeight(16, 16),
    healthAndDamage(1, 0),
    0,
    false,

    // 16, PROJECTILE
    widthAndHeight(0, 0),
    healthAndDamage(0 , 0),
    0,
    true,

    // 17, EXPLOSION
    widthAndHeight(16, 16),
    healthAndDamage(0 , 1),
    20,
    false,

    // 18, SECRET_WALL
    widthAndHeight(16, 16),
    healthAndDamage(1, 0),
    0,
    false,

    // 19, TRIGGER_DOOR
    widthAndHeight(16, 8),
    healthAndDamage(1, 0),
    0,
    false,

    // 20, SWITCH
    widthAndHeight(8, 8),
    healthAndDamage(0, 0),
    0,
    false,

    // 21, POT
    widthAndHeight(8, 8),
    healthAndDamage(0, 0),
    0,
    false,

    // 22, SUNKEN_BRIDGE
    widthAndHeight(0, 0),
    healthAndDamage(0, 0),
    0,
    false,
};

const void* const PROGMEM entityPointers[NUM_ENTITIES * NUM_ENTITY_POINTERS] = {
    // 0, SWORD
    sword_plus_mask,    // tiles
    (void*)Sword::update,      // update
    NULL,               // onCollide


    // 1, BOOMERANG
    boomerang_plus_mask,
    (void*)Boomerang::update,
    (void*)Boomerang::onCollide,

    // 2, BOMB
    bomb_plus_mask,
    (void*)Bomb::update,
    NULL,

    // 3, KEY
    key_plus_mask,
    NULL,
    NULL,

    // 4, HEART
    heart_plus_mask,
    NULL,
    NULL,

    // 5, BOSS_KEY
    bossKey_plus_mask,
    NULL,
    NULL,

    // 6, CHEST
    chest_tiles,
    NULL,
    NULL,

    // 7, BLOB
    blob_plus_mask,
    (void*)Blob::update,
    (void*)Blob::onCollide,

    // 8, SPIKE
    spike_tiles,
    NULL,
    NULL,

    // 9, BAT
    bat_plus_mask,
    (void*)Bat::update,
    (void*)Bat::onCollide,

    // 10, SKELETON
    skeleton_plus_mask,
    (void*)Skeleton::update,
    (void*)Skeleton::onCollide,

    // 11, BLOB_MOTHER
    blobMother_plus_mask,
    (void*)BlobMother::update,
    (void*)Blob::onCollide,

    // 12, NEMESIS
    player_plus_mask,
    (void*)Nemesis::update,
    (void*)Nemesis::onCollide,

    // 13, TELEPORTER
    NULL,
    NULL,
    NULL,

    // 14, LOCK
    lock_tiles,
    NULL,
    (void*)Lock::onCollide,

    // 15, BOSS_LOCK
    bossLock_tiles,
    NULL,
    (void*)Lock::onCollide,

    // 16, PROJECTILE
    NULL,
    NULL,
    NULL,

    // 17, EXPLOSION
    explosion_tiles,
    (void*)Explosion::update,
    NULL,

    // 18, SECRET_WALL
    secretWall_tiles,
    NULL,
    (void*)SecretWall::onCollide,

    // 19, TRIGGER_DOOR
    triggerDoor_tiles,
    NULL,
    NULL,

    // 20, SWITCH
    switch_tiles,
    NULL,
    NULL,

    // 21, POT
    pot_tiles,
    NULL,
    (void*)Pot::onCollide,

    // 22, SUNKEN_BRIDGE
    NULL,
    NULL,
    NULL,
};

void loadEntity(Entity& entity, EntityType entityType);

#endif

