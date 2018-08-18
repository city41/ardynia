#ifndef ingamemenu_h
#define ingamemenu_h

#include <Arduboy2.h>
#include "renderer.h"

#define PAUSE 1
#define QUIT 2

#define MAX_DECISION 2

class InGameMenu {
    public:
        uint8_t decision;

        InGameMenu():
            decision(PAUSE)
        {}

        void update(Arduboy2* arduboy, byte frame);
        void render(Renderer* renderer, byte frame);
};

#endif

