# ardumap

This is a small node program that takes maps from the [Tiled Map Editor](https://www.mapeditor.org/) and converts them into data for ArduBoy games.

## how to use

1. `npm install -g @city41/ardumap`
2. Export your map from Tiled as JSON
3. `ardumap -s <path to the JSON map file> -o <path to write the header file to>`

ie: `ardumap -s ../myGame/myMap.json -o ../myGame/myMap.h`

## The resulting data file

It's just a uint8 array containing the Tiled data, something like:

```
#ifndef mymap_h
#define mymap_h

const uint8_t PROGMEM mymap_map[] {
    // map width, map height (in rooms)
    4, 4,
    8, 0, 0, 0, 1, 2, 0, 0, 0, 8,
    ...
};

#endif
```

The array starts with a small two byte "header" of the map size in rooms. Currently this is hardcoded for my game, but I can make this generic if anyone else uses this tool.

