#ifndef gameScene_h
#define gameScene_h

#include <Arduino.h>
#include <Arduboy2.h>

#include "baseScene.h"
#include "scenes.h"

class GameScene: public BaseScene {
    private:
        Arduboy2* arduboy;

    public:
        GameScene(Arduboy2* arduboy): arduboy(arduboy) {}

        Scene update(byte frame);
        void render(void);
};

#endif

