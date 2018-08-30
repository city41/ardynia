#ifndef ingamemenu_h
#define ingamemenu_h

#include <Arduboy2.h>
#include "renderer.h"
#include "entityTypes.h"

typedef uint8_t Decision;

const Decision Pause = 11;
const Decision Save = 12;
const Decision Load = 13;
const Decision Gap = 14;
const Decision DeleteSave = 15;

const uint8_t NUM_DECISION_COLUMNS = 2;
const uint8_t NUM_DECISION_ROWS = 5;

class InGameMenu {
    public:
        Decision decisions[NUM_DECISION_COLUMNS][NUM_DECISION_ROWS] = {
            { Pause, Save, Load, Gap, DeleteSave  },
            { BOMB, BOOMERANG, CANDLE }
        };

        uint8_t column;
        uint8_t row;
        Decision decision;

        InGameMenu():
            column(1),
            row(0),
            decision(decisions[column][row])
        {}

        void update(Arduboy2* arduboy, byte frame);
        void render(Renderer* renderer, byte frame);
};

#endif

