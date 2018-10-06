#ifndef renderer_h
#define renderer_h

#include <Arduino.h>
#include <Arduboy2.h>
#include "drawBitmap.h"

class Renderer {
    private:
        Arduboy2Base& arduboy;
        SpritesB sprite;

    public:
        Renderer(Arduboy2Base& arduboy):
            arduboy(arduboy),
            translateX(0),
            translateY(0)
        {}

        int16_t translateX;
        int8_t translateY;

        void fillRect(int16_t x, int16_t y, uint8_t w, uint8_t h, uint8_t color = WHITE);
        void drawRect(int16_t x, int16_t y, uint8_t w, uint8_t h, uint8_t color = WHITE);
        void drawOverwrite(int16_t x, int16_t y, const uint8_t* bitmap, uint8_t frame, MirrorMode mirror = 0, DrawMode drawMode = Normal);
        void drawPlusMask(int16_t x, int16_t y, const uint8_t* bitmap, uint8_t frame, MirrorMode mirror = 0, DrawMode drawMode = Normal);
        void drawString(int8_t x, int8_t y, const uint8_t* str);
};

#endif

