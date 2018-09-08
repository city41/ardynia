#include <SPI.h>
#include <EEPROM.h>
#include <Arduboy2.h>
#include <Arduboy2Beep.h>
#include <Arduboy2Audio.h>
#include <math.h>

#include "game.h"
#include "renderer.h"
#include "util.h"
#include "sfx.h"
#include "tileBitmaps.h"

Arduboy2 arduboy;
Renderer renderer(arduboy);
Game game(arduboy, renderer);
Sprites sprites;

void setup() {
    arduboy.boot();
    Arduboy2Audio::begin();
    arduboy.setFrameRate(60);
    Sfx::init();

#ifdef SERIAL_LOG
    Serial.begin(9600);
    delay(1500);
#endif
    LOG("setup done");
}

uint8_t loopCounter = 1;

void loop() {
    if (!arduboy.nextFrame()) {
        return;
    }

    loopCounter += 1;

    if (loopCounter == 61) {
        loopCounter = 1;
    }

    arduboy.clear();
    arduboy.pollButtons();
    
    Sfx::update();
    game.update(loopCounter);
    game.render(loopCounter);
    /* sprites.drawOverwrite(20, 20, secretWall_tiles, 0); */
    /* renderer.drawOverwrite(20, 20, secretWall_tiles, 0); */
    arduboy.display();
}

