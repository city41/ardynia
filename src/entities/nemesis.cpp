#include "nemesis.h"
#include "../entityTemplates.h"
#include "../util.h"

NemesisMode Nemesis::mode = HOLD;
Entity Nemesis::sword;

EntityType Nemesis::update(Entity* me, Entity& player, Arduboy2& arduboy, uint8_t frame) {
    sword.update(*me, arduboy, frame);

    if (mode == ATTACKING && sword.type == UNSET) {
        mode = HOLD;
        me->duration = 30;
    }

    switch (Nemesis::mode) {
        case HOLD:
            me->duration -= 1;
            if (me->duration == 0) {
                mode = TELEPORT;
            }
            break;
        case PURSUE:
            if (frame % 3 == 1) {
                me->moveTowardsOtherEntity(player, 1);
            }
            if (abs(me->x - player.x) < 24 && abs(me->y - player.y) < 24) {
                mode = START_ATTACK;
            }
            break;
        case START_ATTACK:
            loadEntity(Nemesis::sword, SWORD);
            mode = ATTACKING;
            break;
        case TELEPORT:
            int16_t nx = random(0, 101);
            int16_t ny = random(0, 51);
            me->moveTo(nx, ny);
            me->stunCount = random(20, 61);
            me->tookDamageCount = me->stunCount;
            mode = PURSUE;
            break;
    }

    bool attacking = sword.type == SWORD;

    me->mirror = 0;
    if (me->stunCount || mode == HOLD) {
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

EntityType Nemesis::onCollide(Entity* me, Entity& other, Entity& player, Game& game) {
    if (other.type == BOOMERANG) {
        me->duration = 100;
        mode = HOLD;
    }

    if ((other.type == SWORD || other.type == BOMB) && mode == HOLD) {
        me->health -= 1;
        me->tookDamageCount = 100;
        me->bounceBack(other);

        if (me->health == 0) {
            me->type = UNSET;
            sword.type = UNSET;
        }
    }

    return UNSET;
}
