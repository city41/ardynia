#ifndef baseScene_h
#define baseScene_h

#include "scenes.h"

class BaseScene {
    public:
        virtual Scene update(byte frame) = 0;
        virtual void render(void) = 0;
        ~BaseScene() {}
};

#endif
