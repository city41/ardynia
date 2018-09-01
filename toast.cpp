#include "toast.h"

uint8_t Toast::duration = 0;
__FlashStringHelper* Toast::msg = NULL;

void Toast::toast(__FlashStringHelper* msg, uint8_t duration = 30) {
    Toast::duration = duration;
    Toast::msg = msg;
}

void Toast::render(Renderer* renderer) {
    if (Toast::duration > 0 && Toast::msg != NULL) {
        Toast::duration -= 1;

        renderer->fillRect(0, HEIGHT - 5, WIDTH, 5, BLACK);
        renderer->print(0, HEIGHT - 4, Toast::msg);
    }
}
