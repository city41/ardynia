#ifndef toast_h
#define toast_h

#include "renderer.h"

struct Toast {
    static uint8_t duration;
    static __FlashStringHelper* msg;

    static void toast(__FlashStringHelper* msg, uint8_t duration = 30);
    static void render(Renderer* renderer);
};

#endif
