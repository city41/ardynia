#include "nemesis.h"
#include "../util.h"

NemesisMode Nemesis::mode = Hold;
Entity Nemesis::sword;

EntityType Nemesis::update(Entity* me, Entity& player, uint8_t frame) {
    sword.update(*me, frame);

    if (mode == Attacking && sword.type == UNSET) {
        mode = Hold;
        me->duration = 30;
    }

    switch (Nemesis::mode) {
        case Hold:
            me->duration -= 1;
            if (me->duration == 0) {
                mode = Teleport;
            }
            break;
        case Pursue:
            if (frame % 3 == 1) {
                me->moveTowardsOtherEntity(player, 1);
            }
            if (abs(me->x - player.x) < 24 && abs(me->y - player.y) < 24) {
                mode = StartAttack;
            }
            break;
        case StartAttack:
            loadEntity(Nemesis::sword, SWORD);
            mode = Attacking;
            break;
        case Teleport:
            int16_t nx = random(0, 101);
            int16_t ny = random(0, 51);
            me->moveTo(nx, ny);
            me->stunCount = random(20, 61);
            me->tookDamageCount = me->stunCount;
            mode = Pursue;
            break;
    }

    bool attacking = sword.type == SWORD;

    me->mirror = 0;
    if (me->stunCount || mode == Hold) {
        me->currentFrame = 7;
    } else {
        switch (me->dir) {
            case LEFT:
                me->currentFrame = attacking ? 4 : 0;
                break;
            case RIGHT:
                me->currentFrame = attacking ? 4 : 0;
                me->mirror = MIRROR_HORIZONTAL;
                break;
            case UP:
                me->currentFrame = attacking ? 5 : 2;
                break;
            case DOWN:
                me->currentFrame = attacking ? 6 : 3;
                break;
        }
    }

    return UNSET;
}

EntityType Nemesis::onCollide(Entity* me, Entity& other, Entity& player) {
    if (other.type == PROJECTILE) {
        me->duration = 100;
        mode = Hold;
    }

    if (other.type == SWORD && mode == Hold && me->tookDamageCount == 0) {
        me->health -= 1;
        me->tookDamageCount = 100;
        me->bounceBack(other, player);

        if (me->health == 0) {
            me->type = UNSET;
            sword.type = UNSET;
        }
    }

    return UNSET;
}
