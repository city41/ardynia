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
void drawBitmap(int16_t x, int8_t y, const uint8_t* bitmap, const uint8_t* mask, bool plusMask, uint8_t frame, uint8_t mirror, DrawMode drawMode, uint8_t maskFrame) {
    if (bitmap == NULL)
        return;

    if (maskFrame == 255) {
        maskFrame = frame;
    } else {
        maskFrame = 0;
    }

    uint8_t w = pgm_read_byte(bitmap++);
    uint8_t h = pgm_read_byte(bitmap++);

    // no need to draw at all if we're offscreen
    if (x + w <= 0 || x > WIDTH - 1 || y + h <= 0 || y > HEIGHT - 1)
        return;

    if (plusMask) {
        mask = bitmap;
    }
    const boolean hasMask = mask != NULL;

    uint16_t frame_offset = (w * ( h / 8 + ( h % 8 == 0 ? 0 : 1)));

    if (frame > 0) {
        mask += maskFrame * frame_offset;
        bitmap += frame * frame_offset;
        
        // plusMask means the sprite is frame,mask,frame,mask
        // jump ahead one more time to get to the correct frame
        if (plusMask) {
            mask += maskFrame * frame_offset;
            bitmap += frame * frame_offset;
        }
    }

    if (plusMask) {
        mask += frame_offset;
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

    const uint8_t *bofs = bitmap + (start_h * w) + xOffset;
    const uint8_t *mask_ofs = mask + (start_h * w) + xOffset;

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

            if (drawMode != Normal) {
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

            if (drawMode == Xor) {
                if (sRow >= 0) {
                    data = Arduboy2Base::sBuffer[ofs];
                    Arduboy2Base::sBuffer[ofs] = data ^ bitmap_data;
                }

                if (yOffset != 0 && sRow < 7) {
                    data = Arduboy2Base::sBuffer[ofs + WIDTH];
                    Arduboy2Base::sBuffer[ofs + WIDTH] = data ^ (*((unsigned char *) (&bitmap_data) + 1));
                }
            } else {
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

