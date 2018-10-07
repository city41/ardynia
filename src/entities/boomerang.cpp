#include "boomerang.h"
#include "player.h"
#include "../sfx.h"
#include "../game.h"
#include "../util.h"
#include "../state.h"

extern Game game;

EntityType Boomerang::update(Entity* me, Entity& player, uint8_t frame) {
    int16_t px = player.x;
    int16_t py = player.y;
    
    // initial duration? then "spawn"
    if (me->duration == 20) {
        me->dir = player.dir;
        me->x = player.x;
        me->y = player.y - 6;
        Sfx::play(Sfx::boomerang);

        if (game.roomType == THREE_SWITCHES_ONE_BOOMERANG) {
            game.setAllSwitches(0);
        }
    }

    int16_t nx = me->x;
    int16_t ny = me->y;

    if (me->duration > 0) {
        me->duration -= 1;

        switch (me->dir) {
            case LEFT:
                nx -= Boomerang::v;
                break;
            case RIGHT:
                nx += Boomerang::v;
                break;
            case UP:
                ny -= Boomerang::v;
                break;
            case DOWN:
                ny += Boomerang::v;
                break;
        }
    } else {
        if (abs(px - me->x) < 3 && abs(py - me->y) < 3) {
            me->type = UNSET;
        } else {
            if (me->x > px) {
                nx -= Boomerang::v;
            }
            else if (me->x < px) {
                nx += Boomerang::v;
            }
            if (me->y > py) {
                ny -= Boomerang::v;
            } else if (me->y < py) {
                ny += Boomerang::v;
            }
        }
    }

    me->x = nx;
    me->y = ny;

    me->rotateViaMirror(frame);

    return UNSET;
}

EntityType Boomerang::onCollide(Entity* me, Entity& other, Entity& player) {
    EntityType otherType = other.type;

    // hit something the user can collect? collect it and keep going
    if (otherType >= BOMB && otherType <= KEY && otherType != CHEST) {
        return player.onCollide(other, player);
    }

    // hit an enemy? then begin returning to the player
    if (otherType >= BLOB && otherType <= NEMESIS) {
        me->duration = 0;
    }

    return UNSET;
}
