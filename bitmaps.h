#ifndef bitmaps_h
#define bitmaps_h

const uint8_t PROGMEM blob_tiles[] = {
// width, height,
8, 8,
// TILE 00
0x00, 0x3c, 0x66, 0x7e, 0x66, 0x7e, 0x3c, 0x00, 
// TILE 01
0x00, 0x78, 0x48, 0x78, 0x48, 0x78, 0x78, 0x00, 
};

const uint8_t PROGMEM blob_mask_tiles[] = {
// TILE 00
0x3c, 0x7e, 0xff, 0xff, 0xff, 0xff, 0x7e, 0x3c, 
// TILE 01
0x78, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x78, 
};

const uint8_t PROGMEM dungeon_tiles[] = {
// width, height,
16, 16,
// TILE 00
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// TILE 01
0x00, 0xfc, 0xf8, 0xf2, 0xe6, 0x0e, 0x9e, 0x1e, 0x5e, 0xde, 0xc0, 0xde, 0xde, 0x1e, 0xde, 0xde, 
0x00, 0xdf, 0xdf, 0xdf, 0xdf, 0x00, 0xfb, 0xfb, 0xfa, 0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 
// TILE 02
0x00, 0xdf, 0xdf, 0xdf, 0xdf, 0x00, 0xfb, 0xfb, 0xfb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0xdf, 0xdf, 0xdf, 0xdf, 0x00, 0xfb, 0xfb, 0xfb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// TILE 03
0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 
0x7b, 0x7b, 0x03, 0x7b, 0x7b, 0x78, 0x7b, 0x7b, 0x7b, 0x7b, 0x03, 0x7b, 0x7b, 0x78, 0x7b, 0x7b, 
// TILE 04
0xff, 0xff, 0x0f, 0x0f, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x0f, 0x0f, 0xff, 0xff, 
0xff, 0xff, 0xfc, 0xfc, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xfc, 0xfc, 0xff, 0xff, 
// TILE 05
0x00, 0x44, 0x44, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0x44, 0x44, 0x00, 
0x00, 0x44, 0x44, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0x44, 0x44, 0x00, 
// TILE 06
0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 
0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0x00, 0x00, 0xc0, 0xc0, 
// TILE 07
0xce, 0x6e, 0x06, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x06, 0x6e, 0xce, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const uint8_t PROGMEM dungeon_mask_tiles[] = {
// TILE 00
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// TILE 01
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// TILE 02
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// TILE 03
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// TILE 04
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// TILE 05
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// TILE 06
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// TILE 07
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
};

const uint8_t PROGMEM hudBFrame_tiles[] = {
// width, height,
16, 16,
// TILE 00
0x1f, 0x15, 0x0a, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x00, 
0x40, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x00, 
};

const uint8_t PROGMEM hudBFrame_mask_tiles[] = {
// TILE 00
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
};

const uint8_t PROGMEM itemIcons_tiles[] = {
// width, height,
16, 16,
// TILE 00
0x00, 0x00, 0x00, 0xc0, 0x20, 0x10, 0x08, 0x88, 0x48, 0x48, 0x48, 0x48, 0x48, 0x30, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x1f, 0x20, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// TILE 01
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xb0, 0xa8, 0x48, 0x88, 0x10, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x10, 0x17, 0x1f, 0x1f, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 
// TILE 02
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xd8, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x08, 0x18, 0x18, 0x1f, 0x18, 0x1f, 0x18, 0x1c, 0x12, 0x0c, 0x00, 0x00, 0x00, 
};

const uint8_t PROGMEM itemIcons_mask_tiles[] = {
// TILE 00
0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf8, 0xf8, 0x78, 0x78, 0x78, 0x78, 0x78, 0x30, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x1f, 0x3f, 0x3f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// TILE 01
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xf0, 0xe8, 0xc8, 0x88, 0x10, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 
// TILE 02
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xd8, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x08, 0x18, 0x18, 0x1f, 0x1f, 0x1f, 0x18, 0x1c, 0x1e, 0x0c, 0x00, 0x00, 0x00, 
};

const uint8_t PROGMEM overworld_tiles[] = {
// width, height,
16, 16,
// TILE 00
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// TILE 01
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// TILE 02
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// TILE 03
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
// TILE 04
0x00, 0x00, 0xf0, 0xf0, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xf0, 0xf0, 0x00, 0x00, 
0x00, 0x00, 0x03, 0x03, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x03, 0x03, 0x00, 0x00, 
// TILE 05
0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 
0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 
// TILE 06
0xcf, 0xcf, 0xcf, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 
0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xf3, 0xf3, 0xf3, 0xff, 0xff, 0x3f, 0x3f, 
};

const uint8_t PROGMEM overworld_mask_tiles[] = {
// TILE 00
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// TILE 01
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// TILE 02
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// TILE 03
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// TILE 04
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// TILE 05
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// TILE 06
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
};

const uint8_t PROGMEM overworld_door_tiles[] = {
// width, height,
16, 16,
// TILE 00
0xff, 0x1f, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x1f, 0xff, 
0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
};

const uint8_t PROGMEM overworld_door_mask_tiles[] = {
// TILE 00
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
};

const uint8_t PROGMEM playerWalk_tiles[] = {
// width, height,
16, 16,
// TILE 00
0x00, 0xf8, 0x24, 0x42, 0xf1, 0x81, 0xe1, 0xf1, 0xe1, 0x01, 0x35, 0x19, 0x02, 0x04, 0xf8, 0x00, 
0x00, 0x00, 0x01, 0x3e, 0x60, 0xd9, 0x99, 0x9d, 0x86, 0x86, 0x9a, 0x9c, 0xe0, 0x10, 0x0f, 0x00, 
// TILE 01
0x00, 0xf0, 0x48, 0x84, 0xe2, 0x02, 0xc2, 0xe2, 0xc2, 0x02, 0x6a, 0x32, 0x04, 0x08, 0xf0, 0x00, 
0x00, 0x01, 0x1a, 0xe4, 0x99, 0x83, 0x9b, 0x9b, 0x9d, 0x9c, 0x9c, 0x80, 0x98, 0xd8, 0x27, 0x18, 
// TILE 02
0x00, 0xe0, 0x18, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x18, 0xe0, 0x00, 
0x00, 0x07, 0x78, 0x88, 0x90, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0x90, 0x90, 0xc0, 0x32, 0x0d, 0x00, 
// TILE 03
0xf0, 0x08, 0x04, 0x62, 0x81, 0x81, 0x01, 0x81, 0x81, 0x01, 0x81, 0x81, 0x62, 0x04, 0xf8, 0x00, 
0x0f, 0x10, 0x6c, 0x86, 0x91, 0x9b, 0x9a, 0xbb, 0xbb, 0xa2, 0x9b, 0x99, 0xee, 0x10, 0x0f, 0x00, 
// TILE 04
0xf0, 0x48, 0x84, 0xe2, 0x02, 0xc2, 0xe2, 0xc2, 0x02, 0x6a, 0x32, 0x04, 0x08, 0xf0, 0x00, 0x00, 
0x25, 0x26, 0x44, 0x41, 0x9b, 0x83, 0x9b, 0x9d, 0x9c, 0x9c, 0x98, 0x80, 0x98, 0x5f, 0x24, 0x18, 
// TILE 05
0x00, 0xf0, 0x0c, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x0c, 0xf0, 0x00, 
0x00, 0x07, 0x18, 0x20, 0x40, 0x90, 0xb0, 0xb0, 0xb0, 0xb0, 0x90, 0x90, 0xc0, 0x32, 0x0d, 0x00, 
// TILE 06
0xe0, 0x10, 0x08, 0xc4, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0xc4, 0x08, 0xf0, 0x00, 
0x07, 0x08, 0x18, 0x2c, 0x53, 0x57, 0x54, 0xb7, 0xb7, 0xb4, 0x17, 0x03, 0x00, 0xf0, 0x0f, 0x00, 
};

const uint8_t PROGMEM playerWalk_mask_tiles[] = {
// TILE 00
0x00, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0x00, 
0x00, 0x00, 0x01, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x0f, 0x00, 
// TILE 01
0x00, 0xf0, 0xf8, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xf8, 0xf0, 0x00, 
0x00, 0x01, 0x1b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x18, 
// TILE 02
0x00, 0xe0, 0xf8, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xf8, 0xe0, 0x00, 
0x00, 0x07, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x0d, 0x00, 
// TILE 03
0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0x00, 
0x0f, 0x1f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x0f, 0x00, 
// TILE 04
0xf0, 0xf8, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xf8, 0xf0, 0x00, 0x00, 
0x3d, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3c, 0x18, 
// TILE 05
0x00, 0xf0, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf0, 0x00, 
0x00, 0x07, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x0d, 0x00, 
// TILE 06
0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xf8, 0xf0, 0x00, 
0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x00, 
};

const uint8_t PROGMEM sword_tiles[] = {
// width, height,
16, 16,
// TILE 00
0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 
// TILE 01
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const uint8_t PROGMEM sword_mask_tiles[] = {
// TILE 00
0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xc0, 0x80, 0x80, 
0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x03, 0x01, 0x01, 
// TILE 01
0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0xfc, 0xff, 0xff, 0xfc, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x7f, 0x7f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

#endif