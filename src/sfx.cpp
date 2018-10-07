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

const PROGMEM uint8_t sword_sfx[] = {
    startNote(0),
    MIDDLE_A - 60,
    delayHigh(0),
    delayLow(20),
    startNote(1),
    MIDDLE_A - 30,
    delayHigh(0),
    delayLow(40),
    startNote(0),
    MIDDLE_A,
    delayHigh(0),
    delayLow(20),
    stopNote(1),
    stopNote(0),
    endOfScore
};

const uint8_t* Sfx::sword = sword_sfx;

const PROGMEM uint8_t boomerang_sfx[] = {
    startNote(0),
    MIDDLE_A - 30,
    delayHigh(0),
    delayLow(40),
    startNote(1),
    MIDDLE_A - 40,
    delayHigh(0),
    delayLow(40),
    stopNote(0),
    delayHigh(0),
    delayLow(40),
    stopNote(1),
    startNote(0),
    MIDDLE_A - 30,
    delayHigh(0),
    delayLow(40),
    startNote(1),
    MIDDLE_A - 40,
    delayHigh(0),
    delayLow(40),
    stopNote(0),
    delayHigh(0),
    delayLow(40),
    stopNote(1),
    startNote(0),
    MIDDLE_A - 30,
    delayHigh(0),
    delayLow(40),
    startNote(1),
    MIDDLE_A - 40,
    delayHigh(0),
    delayLow(40),
    stopNote(0),
    delayHigh(0),
    delayLow(40),
    stopNote(1),
    startNote(0),
    MIDDLE_A - 30,
    delayHigh(0),
    delayLow(40),
    startNote(1),
    MIDDLE_A - 40,
    delayHigh(0),
    delayLow(40),
    stopNote(0),
    stopNote(1),
    endOfScore
};

const uint8_t* Sfx::boomerang = boomerang_sfx;

const PROGMEM uint8_t playerDamage_sfx[] = {
    startNote(0),
    MIDDLE_A - 45,
    delayHigh(0),
    delayLow(200),
    stopNote(0),
    endOfScore
};

const uint8_t* Sfx::playerDamage = playerDamage_sfx;

const PROGMEM uint8_t successJingle_sfx[] = {
    startNote(0),
    MIDDLE_A - 2,
    delayHigh(0),
    delayLow(150),
    stopNote(0),
    delayHigh(0),
    delayLow(50),
    startNote(0),
    MIDDLE_A - 2,
    startNote(1),
    MIDDLE_A + 5,
    delayHigh(1),
    delayLow(200),
    stopNote(0),
    stopNote(1),
    endOfScore
};

const uint8_t* Sfx::successJingle = successJingle_sfx;

const PROGMEM uint8_t pickUpItem_sfx[] = {
    startNote(0),
    MIDDLE_A,
    delayHigh(0),
    delayLow(30),
    stopNote(0),
    endOfScore
};

const uint8_t* Sfx::pickUpItem = pickUpItem_sfx;

const PROGMEM uint8_t bossRoar_sfx[] = {
    startNote(0),
    MIDDLE_A - 30,
    delayHigh(0),
    delayLow(200),
    startNote(1),
    MIDDLE_A - 20,
    delayHigh(6),
    delayLow(0),
    stopNote(1),
    delayHigh(0),
    delayLow(100),
    stopNote(0),
    endOfScore
};
const uint8_t* Sfx::bossRoar = bossRoar_sfx;

const PROGMEM uint8_t metalCling_sfx[] = {
    startNote(0),
    MIDDLE_A + 40,
    delayHigh(0),
    delayLow(15),
    stopNote(0),
    endOfScore
};

const uint8_t* Sfx::metalCling = metalCling_sfx;

const PROGMEM uint8_t doorCrash_sfx[] = {
    startNote(0),
    MIDDLE_A - 40,
    delayHigh(0),
    delayLow(100),
    stopNote(0),
    endOfScore
};

const uint8_t* Sfx::doorCrash = doorCrash_sfx;

void Sfx::init(ArduboyPlaytune* t) {
    tones = t;
    tones->initChannel(PIN_SPEAKER_1);
    tones->initChannel(PIN_SPEAKER_2);
}

void Sfx::play(const uint8_t* sfx) {
    tones->stopScore();
    tones->playScore(sfx);
}

void Sfx::stop() {
    tones->stopScore();
}
