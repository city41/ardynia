#ifndef hud_h
#define hud_h

#include <Arduino.h>
#include "entities/player.h"

class Hud {
    public:
        static void drawExpendableItems(Player& player);
        static void drawItemCount(const uint8_t* bmp, uint8_t x, uint8_t y, uint8_t count);
        static void drawHealth(uint8_t x, uint8_t y, uint8_t count, uint8_t maxCount);
        static void render(Player& player);
};

#endif

