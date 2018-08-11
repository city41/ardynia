#include "player.h"

void Player::update(Arduboy2* arduboy, byte frame) {
    if (arduboy->pressed(DOWN_BUTTON)) {
        y += 1;
    }

    if (arduboy->pressed(UP_BUTTON)) {
        y -= 1;
    }

    if (arduboy->pressed(LEFT_BUTTON)) {
        x -= 1;
    }

    if (arduboy->pressed(RIGHT_BUTTON)) {
        x += 1;
    }
}

void Player::render(Arduboy2* arduboy, byte frame) {
    arduboy->fillCircle(x, y, 4, BLACK);
    arduboy->drawCircle(x, y, 4, WHITE);
}
