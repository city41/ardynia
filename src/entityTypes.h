#ifndef entityTypes_h
#define entityTypes_h

typedef int8_t EntityType;

// max of 32 entities, and max of 8 ids per room
const EntityType ENTITY_MASK = 0b00011111;
const EntityType ENTITY_ID_MASK = 0b00000111;

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
const EntityType BAT = 9;
const EntityType SKELETON = 9;

// bosses
const EntityType BLOB_MOTHER = 11;
const EntityType NEMESIS = 12;

// things related to navigating maps
// and interacting with the world
const EntityType TELEPORTER = 13; // aka a door
const EntityType LOCK = 14;

// projectiles
const EntityType PROJECTILE = 15;
const EntityType EXPLOSION = 16;

// misc
const EntityType SECRET_WALL = 17;
const EntityType TRIGGER_DOOR = 18;
const EntityType SWITCH = 19;

const uint8_t NUM_ENTITIES = SWITCH + 1;

// these are entities in a sense, but they don't fully participate
// in the entity system
const EntityType ITEM_DROP = 126;
const EntityType PLAYER = 127;
#endif

