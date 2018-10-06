#include "renderer.h"
#include "strings.h"

void Renderer::fillRect(int16_t x, int16_t y, uint8_t w, uint8_t h, uint8_t color) {
    arduboy.fillRect(x + translateX, y + translateY, w, h, color);
}

void Renderer::drawRect(int16_t x, int16_t y, uint8_t w, uint8_t h, uint8_t color) {
    arduboy.drawRect(x + translateX, y + translateY, w, h, color);
}

void Renderer::drawOverwrite(int16_t x, int16_t y, const uint8_t* bitmap, uint8_t frame, MirrorMode mirror, DrawMode drawMode) {
    drawBitmap(x + translateX, y + translateY, bitmap, NULL, false, frame, mirror, drawMode);
}

void Renderer::drawPlusMask(int16_t x, int16_t y, const uint8_t* bitmap, uint8_t frame, MirrorMode mirror, DrawMode drawMode) {
    drawBitmap(x + translateX, y + translateY, bitmap, NULL, true, frame, mirror, drawMode);
}

void Renderer::drawString(int8_t x, int8_t y, const uint8_t* str) {
    uint8_t ch = pgm_read_byte(str++);

    while (ch != 0xFF) {
        const uint8_t frame = ch >> 1;
        const int8_t offset = ch & 1 ? -4 : 0; 
        const uint8_t* mask = offset ? font_tiles_lower_mask : font_tiles_upper_mask;

        drawBitmap(x + translateX, y + offset + translateY, font_tiles, mask, false, frame, 0, Invert, 0);

        ch = pgm_read_byte(str++);
        x += 5;
    }
}
