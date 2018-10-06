#ifndef player_h
#define player_h

#include <Arduino.h>
#include "../entity.h"
#include "../spriteBitmaps.h"

const uint8_t MAX_PLAYER_ENTITIES = 2;
const uint8_t MAX_BOMB_COUNT = 6;

class Game;

class Player: public Entity {
    private:

        void useSword(void);
        void bButtonAction(void);
        int8_t receiveX;
        int8_t receiveY;
        Game* game;

    public:
        bool movedThisFrame;
        uint8_t receiveItemCount;
        EntityType receivedItem;
        Entity entities[MAX_PLAYER_ENTITIES];
        EntityType bButtonEntityType;
        uint8_t numBombs;
        void receiveItemFromChest(Entity& chest);
        void reset();

        Player(int16_t px, int16_t py, Game* game):
            Entity(),
            game(game),
            movedThisFrame(false),
            receiveItemCount(0),
            receivedItem(UNSET),
            bButtonEntityType(UNSET),
            numBombs(0)
        {
            this->type = PLAYER;
            this->width = 8;
            this->height = 8;
            this->tiles = player_plus_mask;

            moveTo(px, py, true);
        }

        virtual void render(uint8_t frame) override;
        virtual EntityType update(Entity& player, uint8_t frame) override;
        virtual EntityType onCollide(Entity& other, Entity& player) override;
};

#endif

