# Tile Spec

## Tile Defintions
the overworld and dungeons both have the same tile definition

blank              = 0
upper left corner  = 1
lower left corner  = 2
upper right corner = 3
lower right corner = 4
left wall          = 5
lower wall         = 6
upper wall         = 7
right wall         = 8
stone              = 9
ladder             = 10
water              = 11
door               = 12
RESERVED           = 13
RESERVED           = 14
RESERVED           = 15
compression        = 16 (0xF)

There is room for four more tiles, and they will likely get used.

The compression tile is a marker to indicate the start of a RLE run (see tileRoom::render)

## Tile Sprites

To save space, tiles use mirroring. The tile sprite only has these tiles in it

blank
upper left corner
left wall
lower wall
stone
ladder
water

When rendering, the needed tile is accomplished with mirroring

Tile                 Mirror
===========================
blank              = 0
upper left corner  = 0
lower left corner  = V(upper left corner)
upper right corner = H(upper left corner)
lower right corner = V|H(upper left corner)
left wall          = 0
lower wall         = 0
upper wall         = V(lower wall)
right wall         = H(left wall)
stone              = 0
ladder             = 0
water              = 0

## Tiled
In Tiled, a full tile sprite sheet is used to make Tiled not a nightmare, these sprites are stored in the Tiled directory
