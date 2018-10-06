#ifndef sfx_h
#define sfx_h

#include <Arduino.h>
#include <Arduboy2.h>
#include <ArduboyPlaytune.h>

struct Sfx {
    static ArduboyPlaytune* tones;

    static const uint8_t* sword;
    static const uint8_t* boomerang;
    static const uint8_t* playerDamage;
    static const uint8_t* successJingle;
    static const uint8_t* pickUpItem;
    static const uint8_t* bossRoar;
    static const uint8_t* metalCling;
    static const uint8_t* doorCrash;

    static void play(const uint8_t* sfx);
    static void stop(void);
    static void init(ArduboyPlaytune* tones);
};

#endif
