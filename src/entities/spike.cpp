#include "spike.h"
#include "../sfx.h"

enum SpikeMode: uint8_t {
    Idle,
    Pursue,
    Retreat
};

const int8_t PursueVelocity = 2;
const int8_t RetreatVelocity = 1;

EntityType Spike::update(Entity* me, Entity& player, uint8_t frame) {
    if (frame % 2 == 0) {
        return UNSET;
    }

    if (me->duration == 11) {
        me->duration = 0;
        me->health = Idle;
        me->vy = 0;
    }

    switch (me->health) {
        case Idle:
            if (
                (player.x >= me->x) &&
                (player.x <= me->x + 8)
            ) {
                me->health = Pursue;
                me->vy = me->y < (HEIGHT / 2) ? PursueVelocity : -PursueVelocity;
            }
            break;

        case Pursue:
            if (
                (me->y >= (HEIGHT - 8)) ||
                (me->y <= 0)
            ) {
                me->health = Retreat;
                me->vy = me->vy > 0 ? -RetreatVelocity : RetreatVelocity;
            }
            break;

        case Retreat:
            if (me->y <= 0 || me->y >= (HEIGHT - 8)) {
                me->health = Idle;
                me->vy = 0;
            }
            break;
    }

    me->y += me->vy;

    return UNSET;
}

EntityType Spike::onCollide(Entity* me, Entity& other, Entity& player) {
    if (me->health != Pursue) {
        return UNSET;
    }

    if (other.type == PLAYER || other.type == SPIKE) {
        me->health = Retreat;
        me->vy = me->vy > 0 ? -RetreatVelocity : RetreatVelocity;

        if (other.type == SPIKE) {
            Sfx::play(Sfx::metalCling);
        }
    }

    return UNSET;
}
