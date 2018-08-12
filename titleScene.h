#ifndef titleScene_h
#define titleScene_h

#include "baseScene.h"
#include "scenes.h"

class TitleScene: public BaseScene {
    public:
        TitleScene(Arduboy2* arduboy, Renderer* renderer): BaseScene(arduboy, renderer) {}
        Scene update(byte frame);
        void render(byte frame);
};

#endif
