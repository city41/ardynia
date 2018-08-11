#ifndef titleScene_h
#define titleScene_h

#include <Arduino.h>
#include <Arduboy2.h>

#include "baseScene.h"
#include "scenes.h"

class TitleScene: public BaseScene {
    private:
        Arduboy2* arduboy;

    public:
        TitleScene(Arduboy2* arduboy): arduboy(arduboy) {}
        Scene update(byte frame);
        void render(byte frame);
};

#endif
