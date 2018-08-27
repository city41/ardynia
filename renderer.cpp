#include "renderer.h"

void Renderer::fillRect(int16_t x, int16_t y, uint8_t w, uint8_t h, uint8_t color = WHITE) {
    arduboy->fillRect(x + translateX, y + translateY, w, h, color);
}

void Renderer::drawRect(int16_t x, int16_t y, uint8_t w, uint8_t h, uint8_t color = WHITE) {
    arduboy->drawRect(x + translateX, y + translateY, w, h, color);
}

void Renderer::fillCircle(int16_t x, int16_t y, uint8_t r, uint8_t color = WHITE) {
    arduboy->fillCircle(x + translateX, y + translateY, r, color);
}

void Renderer::drawOverwrite(int16_t x, int16_t y, const uint8_t* bitmap, uint8_t frame, MirrorMode mirror = 0, bool invert = false) {
    drawBitmap(x + translateX, y + translateY, bitmap, NULL, frame, mirror, invert);
}

void Renderer::drawExternalMask(int16_t x, int16_t y, const uint8_t* bitmap, const uint8_t* mask, uint8_t frame, MirrorMode mirror = 0, bool invert = false) {
    drawBitmap(x + translateX, y + translateY, bitmap, mask, frame, mirror, invert);
}

void Renderer::drawSelfMasked(int16_t x, int16_t y, const uint8_t* bitmap, uint8_t frame, MirrorMode mirror = 0, bool invert = false) {
    drawBitmap(x + translateX, y + translateY, bitmap, bitmap, 0, mirror, invert);
}

void Renderer::print(int16_t x, int16_t y, const __FlashStringHelper* msg) {
    arduboy->setCursor(x + translateX, y + translateY);
    arduboy->print(msg);
}

void Renderer::print(int16_t x, int16_t y, int16_t num) {
    arduboy->setCursor(x + translateX, y + translateY);
    arduboy->print(num);
}

