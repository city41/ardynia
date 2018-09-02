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
const EntityType HEART_CONTAINER = 6;
const EntityType CHEST = 7;

// enemies, to be named
const EntityType BLOB = 8;
const EntityType BAT = 9;
const EntityType SPIKE = 10;
const EntityType SKULL = 11;
const EntityType OCTO = 12;
const EntityType GHOST = 13;

// bosses, to be named
const EntityType BLOB_WHISPERER = 14;
const EntityType NECROMANCER = 15;
const EntityType NEMESIS = 16;

// things related to navigating maps
// and interacting with the world
const EntityType TELEPORTER = 17; // aka a door
const EntityType BUSH = 18;
const EntityType LOCK = 19;

// projectiles
const EntityType FLAME = 20;
const EntityType PROJECTILE = 21;
const EntityType EXPLOSION = 22;

// misc

// prevents the user from going to the first dungeon if they
// haven't yet found the sword. This is required because the game
// assumes the player acquires the items in order: sword->boomerang->bombs->candle
const EntityType OLD_MAN = 23;
// this is the little "poof" as an enemy dies
// it also randomly leaves behind a heart for the player
const EntityType DEATH = 24;

const EntityType PLAYER = 127;

// player isn't really an "entity"
// TODO: can we kill PLAYER EntityType?
const uint8_t NUM_ENTITIES = DEATH + 1;

#endif

