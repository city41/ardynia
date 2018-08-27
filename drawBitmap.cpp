#include "drawBitmap.h"
#include <Arduboy2.h>
/**
 * draw a bitmap with an optional mask and optional mirroring
 *
 * This code is a combination of Arduboy2's Sprite::drawExternalMask() and Ardbitmap's drawBitmap()
 *
 * This method can accomplish the same effect as most of Sprite's methods:
 * drawOverwrite: pass in a mask of NULL
 * drawExternalMask: pass in a separate mask
 * drawSelfMasked: pass in the same pointer for bitmap and mask
 *
 * To mirror the sprite, pass in MIRROR_HORIZONTAL or MIRROR_VERTICAL as the mirror parameter.
 * To mirrow both ways at once, pass in MIRROR_HORIZONTAL | MIRROR_VERTICAL as the parameter
 */
void drawBitmap(int16_t x, int16_t y, const uint8_t* bitmap, const uint8_t* mask, uint8_t frame, uint8_t mirror, bool invert) {
    if (bitmap == NULL)
        return;

    uint16_t frame_offset;

    // if using the same bitmap pointer for masking (to accomplish a self mask)
    // then need to move the mask pointer past the width/height bites, otherwise assume
    // the mask does not have the widht/height header
    if (mask == bitmap) {
        mask += 2;
    }
  
    const bool hasMask = mask != NULL;

    uint8_t w = pgm_read_byte(bitmap++);
    uint8_t h = pgm_read_byte(bitmap++);

    // no need to draw at all if we're offscreen
    if (x + w <= 0 || x > WIDTH - 1 || y + h <= 0 || y > HEIGHT - 1)
        return;

    if (frame > 0) {
        frame_offset = (w * ( h / 8 + ( h % 8 == 0 ? 0 : 1)));
        mask += frame * frame_offset;
        bitmap += frame * frame_offset;
    }

    // xOffset technically doesn't need to be 16 bit but the math operations
    // are measurably faster if it is
    uint16_t xOffset, ofs;
    int8_t yOffset = abs(y) % 8;
    int8_t sRow = y / 8;
    uint8_t loop_h, start_h, rendered_width;

    if (y < 0 && yOffset > 0) {
        sRow--;
        yOffset = 8 - yOffset;
    }

    // if the left side of the render is offscreen skip those loops
    if (x < 0) {
        xOffset = abs(x);
    } else {
        xOffset = 0;
    }

    // if the right side of the render is offscreen skip those loops
    if (x + w > WIDTH - 1) {
        rendered_width = ((WIDTH - x) - xOffset);
    } else {
        rendered_width = (w - xOffset);
    }

    // if the top side of the render is offscreen skip those loops
    if (sRow < -1) {
        start_h = abs(sRow) - 1;
    } else {
        start_h = 0;
    }

    loop_h = h / 8 + (h % 8 > 0 ? 1 : 0); // divide, then round up

    // if (sRow + loop_h - 1 > (HEIGHT/8)-1)
    if (sRow + loop_h > (HEIGHT / 8)) {
        loop_h = (HEIGHT / 8) - sRow;
    }

    // prepare variables for loops later so we can compare with 0
    // instead of comparing two variables
    loop_h -= start_h;

    sRow += start_h;
    ofs = (sRow * WIDTH) + x + xOffset;

    uint8_t *bofs = bitmap + (start_h * w) + xOffset;
    uint8_t *mask_ofs = mask + (start_h * w) + xOffset;

    if (mirror & MIRROR_HORIZONTAL)  {
        bofs += rendered_width - 1;
        mask_ofs += rendered_width - 1;
        if (x < 0){
            bofs -= w - rendered_width;
            mask_ofs -= w - rendered_width;
        } else{
            bofs += w - rendered_width;
            mask_ofs += w - rendered_width;
        }
    }

    if (mirror & MIRROR_VERTICAL) {
        bofs += (loop_h - 1) * w;
        mask_ofs += (loop_h - 1) * w;
        if (y < 0) {
            bofs -=  (start_h * w);
            mask_ofs -=  (start_h * w);
        }
    }

    uint8_t data;
    uint8_t mul_amt = 1 << yOffset;
    uint16_t bitmap_data;
    uint16_t mask_data;

    // really if yOffset = 0 you have a faster case here that could be
    // optimized
    for (uint8_t a = 0; a < loop_h; a++) {
        for (uint8_t iCol = 0; iCol < rendered_width; iCol++) {
            data = pgm_read_byte(bofs);
            mask_data = hasMask ? pgm_read_byte(mask_ofs) : 0xFF;

            if (invert) {
                data = ~data & mask_data;
            }

            if (mirror & MIRROR_VERTICAL) {
                //reverse bits
                data = (data & 0xF0) >> 4 | (data & 0x0F) << 4;
                data = (data & 0xCC) >> 2 | (data & 0x33) << 2;
                data = (data & 0xAA) >> 1 | (data & 0x55) << 1;

                mask_data = (mask_data & 0xF0) >> 4 | (mask_data & 0x0F) << 4;
                mask_data = (mask_data & 0xCC) >> 2 | (mask_data & 0x33) << 2;
                mask_data = (mask_data & 0xAA) >> 1 | (mask_data & 0x55) << 1;
            }

            bitmap_data = data * mul_amt;
            mask_data = ~(mask_data * mul_amt);

            if (sRow >= 0) {
                data = Arduboy2Base::sBuffer[ofs];
                data &= (uint8_t)(mask_data);
                data |= (uint8_t)(bitmap_data);
                Arduboy2Base::sBuffer[ofs] = data;
            }

            if (yOffset != 0 && sRow < 7) {
                data = Arduboy2Base::sBuffer[ofs + WIDTH];
                data &= (*((unsigned char *) (&mask_data) + 1));
                data |= (*((unsigned char *) (&bitmap_data) + 1));
                Arduboy2Base::sBuffer[ofs + WIDTH] = data;
            }

            ofs++;

            if (mirror & MIRROR_HORIZONTAL) {
                bofs--;
                mask_ofs--;
            } else{
                bofs++;
                mask_ofs++;
            }
        }
        sRow++;

        if (mirror & MIRROR_HORIZONTAL) {
            bofs += w + rendered_width;
            mask_ofs += w + rendered_width;
        } else{
            bofs += w - rendered_width;
            mask_ofs += w - rendered_width;
        }

        if (mirror & MIRROR_VERTICAL) {
            bofs -= 2 * w;
            mask_ofs -= 2 * w;
        }
        ofs += WIDTH - rendered_width;
    }
}

