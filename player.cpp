#include "player.h"

void Player::update(Arduboy2* arduboy, byte frame) {
    if (arduboy->pressed(DOWN_BUTTON)) {
        y += delta;
    }

    if (arduboy->pressed(UP_BUTTON)) {
        y -= delta;
    }

    if (arduboy->pressed(LEFT_BUTTON)) {
        x -= delta;
    }

    if (arduboy->pressed(RIGHT_BUTTON)) {
        x += delta;
    }
}

void Player::render(Arduboy2* arduboy, byte frame) {
    arduboy->fillCircle(x, y, 4, BLACK);
}
