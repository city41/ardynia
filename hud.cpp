#include "hud.h"

void Hud::render(Renderer* renderer, uint8_t frame) {
    renderer->fillRect(0, 0, 16, 64, BLACK);
    renderer->drawOverwrite(0, 0, weaponsAndItemIconsBmp, 0);
    renderer->drawOverwrite(0, 16, weaponsAndItemIconsBmp, 2);
}
