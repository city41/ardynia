#ifndef hud_h
#define hud_h

#include <Arduino.h>
#include "renderer.h"
#include "entities/player.h"

class Hud {
    public:
        static void drawExpendableItems(Renderer& renderer, Player& player);
        static void drawItemCount(Renderer& renderer, const uint8_t* bmp, uint8_t x, uint8_t y, uint8_t count);
        static void drawDots(Renderer& renderer, uint8_t x, uint8_t y, uint8_t count, uint8_t maxCount, bool useFillRect);
        static void render(Renderer& renderer, Player& player);
};

#endif

