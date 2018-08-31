# ardusprites

A simple tool that converts pngs into sprite data for ArduBoy programs.

This is basically a command line version of Team A.R.G.'s [arduboy-sprite-converter](https://teamarg.github.io/arduboy-sprite-converter/). The main code that converts the data was taken from their tool.

## how to use

1. Create a sprite image containing all your tiles. It needs to be vertically oriented. You must name it `<name>_<width>x<height>.png`
2. `npm install -g @city41/ardusprites`
2. `ardusprites -s <src directory of pngs> -o <dest file to write the sprite data to>`

ie: `ardusprites -s myGame/myPngs -o myGame/mySprites.h`

## How to create masks

When drawing your sprites, any pixel that is not pure white (255,255,255,255) and not pure black (0,0,0,255) will be part of the mask. I tend to make my sprites be white, black and a grey for the mask.

## Generated data

This tool will generate three arrays per png: the sprites, the masks for the sprites, and the sprites and masks combined into one. If you don't need all three, no worries, just don't use the ones you don't need. When building your sketch, GCC won't include any unused arrays, so no worries about bloating your Sketch size.

## how to use the resulting code in an ArduBoy program
You need to use the `Sprites` class as provided by [Arduboy2](https://github.com/MLXXXp/Arduboy2). For example, if you want to render a sprite from mySprites.h

```c++
#include <SPI.h>
#include <EEPROM.h>
#include <Arduboy2.h>

#include "mySprites.h"

Sprites sprites;


void setup() {
    arduboy.begin();
    arduboy.setFrameRate(60);
}


void loop() {
    if (!arduboy.nextFrame()) {
        return;
    }

    arduboy.clear();

    sprites.drawOverwrite(
        /* x coord in pixels      */  0,
        /* y coord in pixels      */  0,
        /* pointer to sprite data */  myGameSprite_tiles,
        /* which frame to draw    */  0
    );

    arduboy.display();
}
```

