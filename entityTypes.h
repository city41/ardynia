#ifndef entityTypes_h
#define entityTypes_h

typedef int8_t EntityType;

// max of 32 entities, and max of 8 ids per room
const EntityType ENTITY_MASK = 0b00011111;
const EntityType ENTITY_ID_MASK = 0b11100000;

const EntityType UNSET = -1;


// items the player can use, anything with ID less than 8
// can be stored in a chest
const EntityType SWORD = 0;
const EntityType BOOMERANG = 1;
const EntityType BOMB = 2;
const EntityType CANDLE = 3;
const EntityType KEY = 4;
const EntityType HEART = 5;
const EntityType CHEST = 6;

// enemies, to be named
const EntityType BLOB = 7;
const EntityType SPIKE = 8;
const EntityType ENEMY3 = 9;

// bosses
const EntityType BLOB_MOTHER = 10;
const EntityType NEMESIS = 11;

// things related to navigating maps
// and interacting with the world
const EntityType TELEPORTER = 12; // aka a door
const EntityType LOCK = 13;

// projectiles
const EntityType PROJECTILE = 14;
const EntityType EXPLOSION = 15;

// misc

// prevents the user from going to the first dungeon if they
// haven't yet found the sword. This is required because the game
// assumes the player acquires the items in order: sword->boomerang->bombs->candle
// this is the little "poof" as an enemy dies
// it also randomly leaves behind a heart for the player
const EntityType DEATH = 16;
const EntityType SECRET_WALL = 17;

const EntityType PLAYER = 127;

// player isn't really an "entity"
// TODO: can we kill PLAYER EntityType?
const uint8_t NUM_ENTITIES = SECRET_WALL + 1;

#endif

