#include <SPI.h>
#include <EEPROM.h>
#include <Arduboy2.h>
#include <math.h>

#include "gameScene.h"
#include "renderer.h"
#include "util.h"
#include "state.h"

Arduboy2 arduboy;
Renderer renderer(&arduboy);
GameScene gameScene(&arduboy, &renderer);

void setup() {
    arduboy.begin();
    arduboy.setFrameRate(60);

#ifdef SERIAL_LOG
    Serial.begin(9600);
    delay(1500);
#endif

    delay(500);
    State::load();

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

    gameScene.update(loopCounter);
    gameScene.render(loopCounter);
    arduboy.display();
}

