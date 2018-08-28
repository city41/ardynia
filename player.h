#ifndef player_h
#define player_h

#include <Arduino.h>
#include "baseEntity.h"
#include "entity.h"
#include "bitmaps.h"

const uint8_t MAX_PLAYER_ENTITIES = 2;
const uint8_t MAX_KEYS = 6;

class Player: public BaseEntity {
    private:
        boolean movedThisFrame;

        void useSword(void);
        void bButtonAction(void);

    public:
        uint8_t receiveItemCount;
        EntityType receivedItem;
        int8_t totalHealth;
        Entity entities[MAX_PLAYER_ENTITIES];
        EntityType bButtonEntityType;

        uint8_t keyCount;

        void receiveItemFromChest(BaseEntity* chest);


        Player(int16_t x, int16_t y, int8_t health, int8_t totalHealth):
            BaseEntity(
                PLAYER,
                8,  // width
                8,  // height
                DOWN,
                playerWalk_tiles,
                playerWalk_mask,
                health,
                0,   // damage
                0    // duration
            ),
            movedThisFrame(false),
            receiveItemCount(0),
            receivedItem(UNSET),
            totalHealth(totalHealth),
            bButtonEntityType(UNSET),
            keyCount(0)
        {
            this->prevX = this->x = x;
            this->prevY = this->y = y;
        }

        virtual EntityType render(Renderer* renderer, uint8_t frame) override;
        virtual EntityType update(BaseEntity* player, Arduboy2* arduboy, uint8_t frame) override;
        virtual EntityType onCollide(BaseEntity* other, BaseEntity* player) override;
};

#endif

