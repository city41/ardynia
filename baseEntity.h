#ifndef baseEntity_h
#define baseEntity_h

#include <Arduino.h>
#include <Arduboy2.h>

class BaseEntity {
    public:
        char x;
        char y;
        char delta;

        BaseEntity(char x, char y, char delta):
            x(x),
            y(y),
            delta(delta)
        {}

        virtual void update(Arduboy2* arduboy, byte frame) = 0;
        virtual void render(Arduboy2* arduboy, byte frame) = 0;
};

#endif

