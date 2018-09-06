#include "renderer.h"
#include "strings.h"

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
    drawBitmap(x + translateX, y + translateY, bitmap, NULL, false, frame, mirror, invert);
}

void Renderer::drawPlusMask(int16_t x, int16_t y, const uint8_t* bitmap, uint8_t frame, MirrorMode mirror = 0, bool invert = false) {
    drawBitmap(x + translateX, y + translateY, bitmap, NULL, true, frame, mirror, invert);
}

void Renderer::drawString(int16_t x, int16_t y, const uint8_t* str) {
    uint8_t ch = pgm_read_byte(str++);

    while (ch != 0xFF) {
        const uint8_t frame = ch >> 1;
        const int16_t offset = ch & 1 ? -4 : 0; 
        const uint8_t* mask = offset ? font_tiles_lower_mask : font_tiles_upper_mask;

        drawBitmap(x + translateX, y + offset + translateY, font_tiles, mask, false, frame, 0, true, 0);

        ch = pgm_read_byte(str++);
        x += 5;
    }
}
