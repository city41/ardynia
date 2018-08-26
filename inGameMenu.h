#ifndef ingamemenu_h
#define ingamemenu_h

#include <Arduboy2.h>
#include "renderer.h"

typedef uint8_t Decision;

const Decision Pause = 0;
const Decision Quit = 1;

const uint8_t NUM_DECISIONS = 2;

class InGameMenu {
    public:
        uint8_t decision;

        InGameMenu():
            decision(Pause)
        {}

        void update(Arduboy2* arduboy, byte frame);
        void render(Renderer* renderer, byte frame);
};

#endif

