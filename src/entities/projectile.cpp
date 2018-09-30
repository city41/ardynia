#include "projectile.h"
#include "../sfx.h"

const int8_t PROJECTILE_VELOCITY = 2;

const int8_t PROGMEM spawnData[] = {
    // LEFT
    -18, -4, -PROJECTILE_VELOCITY, 0,
    // RIGHT
    11, -4, PROJECTILE_VELOCITY, 0,
    // UP
    -5, -20, 0, -PROJECTILE_VELOCITY,
    // DOWN
    -1, 6, 0, PROJECTILE_VELOCITY
};

EntityType Projectile::update(Entity* me, Entity& player, Game& game, Arduboy2Base& arduboy, uint8_t frame) {
    int16_t px = player.x;
    int16_t py = player.y;

    // initial duration? then "spawn"
    if (me->duration == 20) {
        int8_t* offset = spawnData + (player.dir * 4);
        me->x = px + (int8_t)pgm_read_byte(offset++);
        me->y = py + (int8_t)pgm_read_byte(offset++);
        me->vx = (int8_t)pgm_read_byte(offset++);
        me->vy = (int8_t)pgm_read_byte(offset++);
        Sfx::play(Sfx::boomerang);
    }

    // move
    me->duration -= 1;
    me->x += me->vx;
    me->y += me->vy;
    me->rotateViaMirror(frame);

    // fizzle out
    if (me->duration == 0) {
        me->type = UNSET;
    }

    return UNSET;
}
