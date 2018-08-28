#ifndef entityTypes_h
#define entityTypes_h

typedef uint8_t EntityType;

// max of 32 entities, and max of 8 ids per room
const EntityType ENTITY_MASK = 0b00011111;
const EntityType ENTITY_ID_MASK = 0b11100000;

const EntityType UNSET = -1;
const EntityType SWORD = 0;
const EntityType BLOB = 1;
const EntityType OVERWORLD_DOOR = 2;
const EntityType BUMPER = 3;
const EntityType BOOMERANG = 4;
const EntityType BOMB = 5;
const EntityType CANDLE = 6;
const EntityType CHEST = 7;
const EntityType KEY = 8;
const EntityType LOCK = 9;
const EntityType BUSH = 10;
const EntityType ENEMY2 = 11;
const EntityType ENEMY3 = 12;
const EntityType ENEMY4 = 13;
const EntityType ENEMY5 = 14;
const EntityType ENEMY6 = 15;
const EntityType BOSS1 = 16;
const EntityType BOSS2 = 17;
const EntityType BOSS3 = 18;
const EntityType HEART = 19;
const EntityType HEART_CONTAINER = 20;

const EntityType PLAYER = 255;

#endif

