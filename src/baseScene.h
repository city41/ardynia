#ifndef baseScene_h
#define baseScene_h

#include <Arduino.h>
#include <Arduboy2.h>
#include "renderer.h"
#include "scenes.h"

class BaseScene {
    protected:
        Arduboy2* arduboy;
        Renderer* renderer;

    public:
        BaseScene(Arduboy2 *arduboy, Renderer* renderer):
            arduboy(arduboy),
            renderer(renderer)
            {}

        virtual Scene update(byte frame) = 0;
        virtual void render(byte frame) = 0;
        ~BaseScene() {}
};

#endif
