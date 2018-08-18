#ifndef overworld_h
#define overworld_h


const uint8_t overworld_map[130] = {
    // map width, map height (in rooms)
    1, 1,
    0, 1, 2, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
const uint8_t PROGMEM overworld_tiles[42] = {
    // tile width, tile height
    8, 8,
    //Tile 0
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    //Tile 1
    0xff, 0xff, 0xff, 0x7d, 0x0, 0x7f, 0xff, 0xff,
    //Tile 2
    0xff, 0xff, 0x1d, 0x6e, 0x76, 0x79, 0xff, 0xff,
    //Tile 3
    0xff, 0xff, 0xbd, 0x66, 0x66, 0x91, 0xff, 0xff,
    //Tile 4
    0xff, 0xff, 0xe0, 0xef, 0xf, 0x0, 0xef, 0xff,
};

#endif