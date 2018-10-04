#ifndef entityTypes_h
#define entityTypes_h

typedef uint8_t EntityType;

// max of 32 entities, and max of 8 ids per room
const EntityType ENTITY_MASK = 0b00011111;
const EntityType ENTITY_MISC_MASK = 0b00000111;

// items the player can use, anything with ID less than 8
// can be stored in a chest
const EntityType SWORD = 0;
const EntityType BOOMERANG = 1;
const EntityType BOMB = 2;
const EntityType KEY = 3;
const EntityType HEART = 4;
const EntityType CHEST = 5;

// enemies, to be named
const EntityType BLOB = 6;
const EntityType BAT = 7;
const EntityType SKELETON = 8;

// bosses
const EntityType GIANT_BAT = 9;
const EntityType BLOB_MOTHER = 10;
const EntityType NEMESIS = 11;

// things related to navigating maps
// and interacting with the world
const EntityType TELEPORTER = 12; // aka a door
const EntityType LOCK = 13;
const EntityType BOSS_LOCK = 14;

// projectiles
const EntityType PROJECTILE = 15;
const EntityType EXPLOSION = 16; 
// misc
const EntityType SECRET_WALL = 17;
const EntityType TRIGGER_DOOR = 18;
const EntityType SWITCH = 19;
const EntityType POT = 20;
const EntityType SUNKEN_BRIDGE = 21;
const EntityType TORCH = 22;

const uint8_t NUM_ENTITIES = TORCH + 1;

// these are entities in a sense, but they don't fully participate
// in the entity system
const EntityType ITEM_DROP = 253;
const EntityType PLAYER = 254;
const EntityType UNSET = 255;

const EntityType RING = 5;
const EntityType BOSS_KEY = 6;
const EntityType SAD_FACE = 7;
const EntityType HAPPY_FACE = 8;

enum RoomType: uint8_t {
    NORMAL,
    SLAM_SHUT,
    LAST_ENEMY_HAS_KEY,
    LAST_ENEMY_HAS_HEART_CONTAINER,
    LAST_ENEMY_HAS_BOSS_KEY,
    THREE_SWITCHES_ONE_BOOMERANG,
    OPEN_CHESTS_IN_RIGHT_ORDER,
    LAST_TORCH_OPENS_DOORS
};

#endif

