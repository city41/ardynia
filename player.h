#ifndef player_h
#define player_h

#include <Arduino.h>
#include "baseEntity.h"
#include "entity.h"
#include "bitmaps.h"

const uint8_t MAX_PLAYER_ENTITIES = 2;

class Player: public BaseEntity {
    private:

        void useSword(void);
        void bButtonAction(void);

    public:
        boolean movedThisFrame;
        uint8_t receiveItemCount;
        EntityType receivedItem;
        Entity entities[MAX_PLAYER_ENTITIES];
        EntityType bButtonEntityType;

        void receiveItemFromChest(Entity* chest);

        Player(int16_t x, int16_t y):
            BaseEntity(
                PLAYER,
                8,  // width
                8,  // height
                DOWN,
                playerWalk_tiles,
                playerWalk_mask,
                0,   // damage
                0    // duration
            ),
            movedThisFrame(false),
            receiveItemCount(0),
            receivedItem(UNSET),
            bButtonEntityType(UNSET)
        {
            this->prevX = this->x = x;
            this->prevY = this->y = y;
        }

        virtual EntityType render(Renderer* renderer, uint8_t frame) override;
        virtual EntityType update(BaseEntity* player, Arduboy2* arduboy, uint8_t frame) override;
        virtual EntityType onCollide(BaseEntity* other, BaseEntity* player) override;
};

#endif

