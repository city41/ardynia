#ifndef baseEntity_h
#define baseEntity_h

#include <Arduino.h>
#include <Arduboy2.h>

class BaseEntity {
    protected:
        char x;
        char y;

    public:
        BaseEntity(char x, char y):
            x(x),
            y(y)
        {}

        virtual void update(Arduboy2* arduboy, byte frame) = 0;
        virtual void render(Arduboy2* arduboy, byte frame) = 0;
};

#endif

