#ifndef entityTemplates_h
#define entityTemplates_h

#include <Arduino.h>
#include "entityTypes.h"
#include "entity.h"
#include "spriteBitmaps.h"
#include "blob.h"
#include "sword.h"
#include "boomerang.h"
#include "bomb.h"
#include "explosion.h"
#include "death.h"

const uint8_t NUM_ENTITY_PROPS = 7;
const uint8_t NUM_ENTITY_POINTERS = 5;

const uint8_t PROGMEM entityProperties[NUM_ENTITIES * NUM_ENTITY_PROPS] = {
    // 0 SWORD
    16,           // width
    16,           // height
    DOWN,         // direction
    0,            // health
    1,            // damage
    20,           // duration
    true,         // invertInDungeon

    // 1, BOOMERANG
    16,
    16,
    DOWN,
    0,
    0,
    20,
    true,

    // 2, BOMB
    11,
    16,
    DOWN,
    0,
    0,
    150,
    true,

    // 3, CANDLE
    0,
    0,
    DOWN,
    0,
    0,
    0,
    false,

    // 4, KEY
    8,
    8,
    DOWN,
    0,
    0,
    0,
    false,

    // 5, HEART
    8,
    8,
    DOWN,
    0,
    0,
    180,
    true,

    // 6, HEART_CONTAINER
    0,
    0,
    DOWN,
    0,
    0,
    0,
    false,

    // 7, CHEST
    16,
    16,
    DOWN,
    0,
    0,
    0,
    false,

    // 8, BLOB
    8,
    8,
    DOWN,
    2, // health
    1, // damage
    0, // duration
    true, // invertInDungeon

    // 9, BAT
    8,
    8,
    DOWN,
    1,
    1,
    0,
    true,

    // 10, SPIKE
    8,
    8,
    DOWN,
    255,
    1,
    0,
    false,

    // 11, SKULL
    16,
    16,
    DOWN,
    1,
    2,
    0,
    false,

    // 12, OCTO
    16,
    16,
    DOWN,
    4,
    1,
    0,
    false,

    // 13, GHOST
    8,
    16,
    DOWN,
    1,
    2,
    0,
    false,

    // 14, BLOB_WHISPERER
    0,
    0,
    DOWN,
    0,
    0,
    0,
    false,

    // 15, NECROMANCER
    0,
    0,
    DOWN,
    0,
    0,
    0,
    false,

    // 16, NEMESIS
    0,
    0,
    DOWN,
    0,
    0,
    0,
    false,

    // 17, TELEPORTER
    18,
    8,
    DOWN,
    0,
    0,
    0,
    false,

    // 18, BUSH
    0,
    0,
    DOWN,
    0,
    0,
    0,
    false,

    // 19, LOCK
    0,
    0,
    DOWN,
    0,
    0,
    0,
    false,

    // 20, FLAME
    0,
    0,
    DOWN,
    0,
    0,
    0,
    false,

    // 21, PROJECTILE
    0,
    0,
    DOWN,
    0,
    0,
    20,
    false,

    // 22, EXPLOSION
    16,
    16,
    DOWN,
    0,
    1,
    20,
    true,

    // 23, OLD_MAN
    8,
    HEIGHT, // whole screen, this guy is basically a total bumper
    DOWN,
    0,
    0,
    0,
    false,

    // 24, DEATH
    8,
    8,
    DOWN,
    0,
    0,
    24,
    true
};

const void* const PROGMEM entityPointers[NUM_ENTITIES * NUM_ENTITY_POINTERS] = {
    // 0, SWORD
    sword_plus_mask,    // tiles
    Sword::spawn,       // spawn
    Sword::update,      // update
    NULL,               // render
    NULL,               // onCollide


    // 1, BOOMERANG
    itemIcons_plus_mask,
    Boomerang::spawn,
    Boomerang::update,
    NULL,
    Boomerang::onCollide,

    // 2, BOMB
    itemIcons_plus_mask,
    Bomb::spawn,
    Bomb::update,
    NULL,
    NULL,

    // 3, CANDLE
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 4, KEY
    key_plus_mask,
    NULL,
    NULL,
    NULL,
    NULL,

    // 5, HEART
    heart_plus_mask,
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

    // 7, CHEST
    chest_plus_mask,
    NULL,
    NULL,
    NULL,
    NULL,

    // 8, BLOB
    blob_plus_mask,
    NULL,
    Blob::update,
    NULL,
    Blob::onCollide,

    // 9, BAT
    bat_plus_mask,
    NULL,
    NULL,
    NULL,
    NULL,

    // 10, SPIKE
    spike_plus_mask,
    NULL,
    NULL,
    NULL,
    NULL,

    // 11, SKULL
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 12, OCTO
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 13, GHOST
    ghost_plus_mask,
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

    // 15, BOSS2
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

    // 17, TELEPORTER
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 18, BUSH
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 19, LOCK
    lock_plus_mask,
    NULL,
    NULL,
    NULL,
    NULL,

    // 20, FLAME
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 21, PROJECTILE
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

    // 22, EXPLOSION
    explosion_plus_mask,
    NULL,
    Explosion::update,
    NULL,
    NULL,

    // 23, OLD_MAN
    oldMan_plus_mask,
    NULL,
    NULL,
    NULL,
    NULL,

    // 24, DEATH
    death_plus_mask,
    NULL,
    Death::update,
    NULL,
    NULL,
};

void loadEntity(Entity& entity, EntityType entityType);

#endif

