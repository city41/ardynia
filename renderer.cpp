#include "renderer.h"

void Renderer::fillRect(int16_t x, int16_t y, uint8_t w, uint8_t h, uint8_t color = WHITE) {
    arduboy->fillRect(x + translateX, y + translateY, w, h, color);
}

void Renderer::drawRect(int16_t x, int16_t y, uint8_t w, uint8_t h, uint8_t color = WHITE) {
    arduboy->drawRect(x + translateX, y + translateY, w, h, color);
}

void Renderer::drawOverwrite(int16_t x, int16_t y, const uint8_t* bitmap, uint8_t frame) {
    sprite.drawOverwrite(x + translateX, y + translateY, bitmap, frame);
}

void Renderer::drawErase(int16_t x, int16_t y, const uint8_t* bitmap, uint8_t frame) {
    sprite.drawErase(x + translateX, y + translateY, bitmap, frame);
}

void Renderer::print(int16_t x, int16_t y, const __FlashStringHelper* msg) {
    arduboy->setCursor(x + translateX, y + translateY);
    arduboy->print(msg);
}

