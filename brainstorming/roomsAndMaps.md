# Rooms and Maps

## Goals
* create rooms in Tiled
* create maps in Tiled (maybe?)
* render a room with any tileset, basically each tileset provides a "theme"
* take Tiled output and automatically generate code. should be able to:
    * edit in Tiled, save to map.json and tiles.json
    * run `genArduZelMapCode map.json tiles.json 
    * build ArduZel
    * run it: new tiles/rooms load and can be played
* no longer need Tile constants, ie STONE_WALL

## challenges

* storing that the tile is solid/walkable
-- SOLVED: can add custom properties to tiles in Tiled
* storing enemies/items along with the map
-- SOLVED: using Tiled objects


## Flow
new TileRoom(tileset, roomLayout)

tileset = {
    8,8
    // first tile, say sandy ground
    0xff, 0xff, ...
    ...
}

// they are basically simple numbers 1, 2, 3, ANDED with SOLID_MASK or TELEPORTER_MASK as appropriate
uint8_t roomLayout[16*8] = {
    0b1000001,
    0b0100010,
    ...
}


