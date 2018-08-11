#include <SPI.h>
#include <EEPROM.h>
#include <Arduboy2.h>
#include <math.h>

#include "scenes.h"
#include "sceneManager.h"

Arduboy2 arduboy;
SceneManager sceneManager(&arduboy, TITLE);


void setup() {
    randomSeed(analogRead(0));

    arduboy.begin();
    arduboy.setFrameRate(60);
}

char loopCounter = 1;

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

    sceneManager.update(loopCounter);

    arduboy.display();
}

