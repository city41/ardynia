#include "boomerang.h"
#include "player.h"
#include "../sfx.h"
#include "../game.h"
#include "../util.h"
#include "../state.h"

EntityType Boomerang::update(Entity* me, Entity& player, Game& game, Arduboy2Base& arduboy, uint8_t frame) {
    int16_t px = player.x;
    int16_t py = player.y;
    
    // initial duration? then "spawn"
    if (me->duration == 20) {
        me->dir = player.dir;
        me->x = player.x;
        me->y = player.y - 6;
        Sfx::boomerang();

        if (game.roomType == THREE_SWITCHES_ONE_BOOMERANG) {
            game.setAllSwitches(0);
        }
    }

    if (me->duration > 0) {
        me->duration -= 1;
        switch (me->dir) {
            case LEFT:
                me->moveTo(me->x - Boomerang::v, me->y);
                break;
            case RIGHT:
                me->moveTo(me->x + Boomerang::v, me->y);
                break;
            case UP:
                me->moveTo(me->x, me->y - Boomerang::v);
                break;
            case DOWN:
                me->moveTo(me->x, me->y + Boomerang::v);
                break;
        }
    } else {
        if (abs(px - me->x) < 3 && abs(py - me->y) < 3) {
            me->type = UNSET;
        } else {
            int16_t nx = me->x;
            int16_t ny = me->y;

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

            me->moveTo(nx, ny);
        }
    }

    me->rotateViaMirror(frame);

    return UNSET;
}

EntityType Boomerang::onCollide(Entity* me, Entity& other, Entity& player, Game& game) {
    EntityType otherType = other.type;

    // hit something the user can collect? collect it and keep going
    if ((otherType >= KEY && otherType <= BOSS_KEY) || otherType == BOMB) {
        return player.onCollide(other, player, game);
    }

    // hit an enemy? then begin returning to the player
    if (otherType >= BLOB && otherType <= NEMESIS) {
        me->duration = 0;
    }

    if (otherType == SWITCH) {
        other.mirror = MIRROR_HORIZONTAL;
        if (game.roomType == THREE_SWITCHES_ONE_BOOMERANG) {
            if (game.areAllSwitchesTriggered()) {
                game.spawnChest(KEY);
                State::setCurrentRoomTriggered();
                game.roomType = NORMAL;
            }
        } else {
            game.removeAllTriggerDoors();
            game.emergeAllBridges();
        }
    }

    return UNSET;
}
