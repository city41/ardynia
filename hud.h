#ifndef hud_h
#define hud_h

#include <Arduino.h>
#include "renderer.h"
#include "player.h"

class Hud {
    public:
        static void drawDots(Renderer& renderer, uint8_t x, uint8_t y, uint8_t count, uint8_t maxCount, uint8_t frame, bool useFillRect);
        static void render(Renderer& renderer, uint8_t frame, Player& player, uint8_t roomX, uint8_t roomY);
};

#endif

