#include <SPI.h>
#include <EEPROM.h>
#include <Arduboy2.h>
#include <math.h>

#include "scenes.h"
#include "sceneManager.h"
#include "renderer.h"
#include "util.h"

Arduboy2 arduboy;
Renderer renderer(&arduboy);
SceneManager sceneManager(&arduboy, &renderer, TITLE);

void setup() {
    randomSeed(analogRead(0));

    arduboy.begin();
    arduboy.setFrameRate(60);

#ifdef SERIAL_LOG
    Serial.begin(9600);
    delay(2000);
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

    sceneManager.update(loopCounter);
    arduboy.display();
}

