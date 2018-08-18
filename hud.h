#ifndef hud_h
#define hud_h

#include <Arduino.h>
#include "bitmaps.h"
#include "renderer.h"

class Hud {
    public:
        void render(Renderer* renderer, uint8_t frame);
};

#endif

