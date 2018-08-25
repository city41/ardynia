# Map Compression

Maps take up a *ton* of room in flash memory. They are already nicely compressed by defining tiles in nibbles instead of bytes. Now, if we could also do a simple run length encoding, we'd save even more.

## RLE

1. define a tile as the "compression tile", it will likely be 0xF
2. compress runs of tiles into <compression tile><count><tile>
    * ie "1,1,1,1,1,1,1,1" becomes "0xF,8,1"
    * min run is 4 (3 breaks even and less than 3 is a loss)
    * max run is 16 (since the count is stored in a nibble)

## Challenges

Compressing the map makes rendering it and determining tile at (x,Y) much more difficult

* can't simply index into the data to find the tile, there could be any number of compressions in front of the tile
* compression runs that span across rooms will be hard to deal with (at least, I think)

## possible solutions

### walk the whole map each time
say we want to render the room at x:1, y:1.

* Figure out the starting tile without compression
* walk the tile data from the start until we hit the compressed location of that tile
* from the compression starting location, render the tiles, accounting for compression runs as you go

ADVANTAGES
no need for a room header
compression across rooms isn't really a concern
best compression possible with nibble based RLE
easier to implement in maptool

DISADVANTAGES
walking the whole data each render might be too expensive
challenging when you find out the starting tile is in the middle of a compression run

### room location header
add a header to the front of the data that contains the starting index of each room

* determine the starting index from the header
* go to that index, render the room, accounting for any compression runs encountered

ADVANTAGES
for sure faster (but this may not matter)
simpler to implement

DISADVANTAGES
header eats up some of the compression win
    * each room location would probably take up an entire byte, a nibble is too small, and trying to do say 7 bits is more trouble than it's likely worth
can't compress across rooms
harder to implement in maptool

