#include "skeleton.h"
#include "../util.h"
#include "../state.h"
#include "../game.h"

const uint8_t SKELETON_VEL_COUNT = 5;

const int16_t PROGMEM skeleton_vels[] =  {
    0, 0,
    0, 1,
    0, -1,
    1, 0,
    -1, 0
};

EntityType Skeleton::update(Entity* me, Entity& player, Game& game, Arduboy2Base& arduboy, uint8_t frame) {
    if (frame % 20 == 0) {
        me->mirror = 1 - me->mirror;
    }

    if (frame % 3 != 0) {
        return UNSET;
    }

    if (me->duration == 0) {
        me->duration = 14;
        uint8_t roll = random(0, SKELETON_VEL_COUNT);
        me->vx = (int16_t)pgm_read_word(skeleton_vels + roll * 2) * (State::gameState.currentDungeon + 1);
        me->vy = (int16_t)pgm_read_word(skeleton_vels + roll * 2 + 1) * (State::gameState.currentDungeon + 1);
    }

    me->duration -= 1;

    int16_t nx = Util::clamp(me->x + me->vx, 2, WIDTH - 16 - 2 - me->width);
    int16_t ny = Util::clamp(me->y + me->vy, 2, HEIGHT - 2 - me->height);
    me->moveTo(nx, ny);

    return UNSET;
}

EntityType Skeleton::onCollide(Entity* me, Entity& other, Entity& player, Game& game) {
    if (other.damage > 0 && me->tookDamageCount == 0) {
        me->health -= other.damage;

        if (me->health <= 0) {
            me->type = UNSET;
            return ITEM_DROP;
        } else {
            me->bounceBack(other, player);
            me->tookDamageCount = 20;
        }
    } else if (other.type == BOOMERANG) {
        me->stunCount = 100;
    }

    return UNSET;
}
