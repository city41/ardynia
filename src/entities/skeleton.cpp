#include "skeleton.h"
#include "../util.h"
#include "../state.h"
#include "../game.h"

const uint8_t SKELETON_VEL_COUNT = 5;

const int8_t PROGMEM skeleton_vels[] =  {
    0, 0,
    0, 1,
    0, -1,
    1, 0,
    -1, 0
};

EntityType Skeleton::update(Entity* me, Entity& player, uint8_t frame) {
    // have current dungeon influence how difficult they are to deal with
    const uint8_t factor = State::gameState.currentDungeon + 1;

    if (frame % (30 / factor) == 0) {
        me->mirror = 1 - me->mirror;
    }

    if (frame % 5 != 0) {
        return UNSET;
    }

    if (me->duration == 0) {
        me->duration = 16 / factor;
        uint8_t roll = random(0, SKELETON_VEL_COUNT);
        me->vx = (int16_t)pgm_read_word(skeleton_vels + roll * 2) * factor;
        me->vy = (int16_t)pgm_read_word(skeleton_vels + roll * 2 + 1) * factor;
    }

    me->duration -= 1;

    int16_t nx = Util::clamp(me->x + me->vx, 2, WIDTH - 16 - 2 - me->width);
    int8_t ny = Util::clamp(me->y + me->vy, 2, HEIGHT - 2 - me->height);
    me->moveTo(nx, ny);

    return UNSET;
}

