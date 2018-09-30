#include "sfx.h"

ArduboyPlaytune* Sfx::tones;

// ArduboyPlayTunes streaming format

// 0x9T start note on generator T
// this must always be followed by note
// example startNote(1), note(69) == play middle A on generator 1
constexpr uint8_t startNote(uint8_t generator) {
    return (0x9 << 4) | generator;
}
constexpr uint8_t note(uint8_t n) {
    return n;
}

// 0x8T stop playing the note on generator T
constexpr uint8_t stopNote(uint8_t generator) {
    return (0x8 << 4) | generator;
}

const uint8_t endOfScore = 0xF0;
const uint8_t endOfScoreLoop = 0xE0;

// the high byte for delay, max value of 127
constexpr uint8_t delayHigh(const uint8_t amount) {
    return amount & 0x7F;
}

// the low byte of the delay, any value
constexpr uint8_t delayLow(const uint8_t amount) {
    return amount;
}

// notes
const uint8_t MIDDLE_A = 69;

const PROGMEM uint8_t sword[] = {startNote(PIN_SPEAKER_1), note(MIDDLE_A), delayHigh(1), delayLow(255), endOfScore};
const uint8_t* Sfx::sword = sword;

const uint8_t* Sfx::boomerang = NULL;
const uint8_t* Sfx::playerDamage = NULL;
const uint8_t* Sfx::successJingle = NULL;
const uint8_t* Sfx::pickUpItem = NULL;
const uint8_t* Sfx::bossRoar = NULL;

void Sfx::init(ArduboyPlaytune* t) {
    tones = t;
    tones->initChannel(PIN_SPEAKER_1);
    tones->initChannel(PIN_SPEAKER_2);
}

void Sfx::play(const uint8_t* sfx) {
    tones->playScore(sfx);
}
