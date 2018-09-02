#include "secretWall.h"
#include "tileBitmaps.h"
#include "tileRoom.h"
#include "state.h"

EntityType SecretWall::render(Entity* me, Renderer* renderer, uint8_t frame) {
    if (me->health == 1) {
        renderer->drawOverwrite(me->x, me->y, overworld_tiles, Stone);
    } else {
        renderer->drawOverwrite(me->x, me->y, secretOpening_tiles, 0);
    }
}

EntityType SecretWall::onCollide(Entity* me, BaseEntity* other, BaseEntity* player) {
    if (other->type == EXPLOSION) {
        me->health = 0;
        me->currentFrame = 11;

        const uint8_t roomIndex = TileRoom::getRoomIndex(TileRoom::x, TileRoom::y);
        State::setTriggered(roomIndex);
        State::saveToEEPROM();
    }

    return UNSET;
}
