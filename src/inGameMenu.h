#ifndef ingamemenu_h
#define ingamemenu_h

#include <Arduboy2.h>
#include "renderer.h"
#include "entityTypes.h"
#include "entities/player.h"

typedef uint8_t Decision;

class InGameMenu {
    public:
        uint8_t row;
        EntityType chosenItem;

        InGameMenu():
            row(0),
            chosenItem(UNSET)
        {}

        void update(Arduboy2Base& arduboy, uint8_t frame);
        void render(Renderer& renderer, Player& player, uint8_t frame);
};

#endif

