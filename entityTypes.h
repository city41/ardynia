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
const EntityType ENEMY2 = 9;
const EntityType ENEMY3 = 10;
const EntityType ENEMY4 = 11;
const EntityType ENEMY5 = 12;
const EntityType ENEMY6 = 13;

// bosses, to be named
const EntityType BOSS1 = 14;
const EntityType BOSS2 = 15;
const EntityType BOSS3 = 16;

// things related to navigating maps
// and interacting with the world
const EntityType BUMPER = 17;
const EntityType TELEPORTER = 18; // aka a door
const EntityType BUSH = 19;
const EntityType LOCK = 20;

// projectiles
const EntityType FLAME = 21;
const EntityType PROJECTILE = 22;

// misc
const EntityType OLD_MAN = 23;

const EntityType PLAYER = 127;

#endif

