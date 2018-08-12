#ifndef tiles_h
#define tiles_h

#define TILE_SIZE 8
#define ROOM_TILE_WIDTH 16
#define ROOM_TILE_HEIGHT 8

/*
 * enums on arduino are 16 bits (essentially uint16)
 *
 * Tiles encode data/properties into the enum value
 *
 * 0bSTNNNNNN
 *
 * S: 1 = solid, 0 = walkable
 * T: 1 = teleporter, 0 = regular
 * NNNNNN: the number of the tile, for a max of 63 tiles
 */
const uint8_t NO_TILE          = 0b00000000;
const uint8_t SOLID_MASK       = 0b10000000;
const uint8_t TELEPORTER_MASK  = 0b01000000;
const uint8_t PLAIN_FLOOR      = 0b00000001; // walkable; number 1
const uint8_t DIRT_FLOOR       = 0b00000010; // walkable; number 2
const uint8_t STONE_WALL       = 0b10000011; // solid; number 3
const uint8_t UNLOCKED_DOOR    = 0b01000100; // walkable; teleporter; number 4
const uint8_t LOCKED_DOOR      = 0b10000101; // solid; number 5

#endif

