#include "blob.h"
#include "util.h"

EntityType Blob::onCollide(Entity* me, BaseEntity* other) {
    if (other->type == SWORD) {
        me->health -= other->damage;

        if (me->health <= 0) {
            me->type = UNSET;
        }
    }

    return UNSET;
}

EntityType Blob::update(Entity* me, void* parent, Arduboy2* arduboy, uint8_t frame) {
}
