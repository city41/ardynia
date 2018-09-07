/**
 * @file arduboyBeep.h
 * \brief
 * Classes to generate simple square wave tones on the Arduboy speaker pins.
 */

#ifndef arduboyBeep_h
#define arduboyBeep_h

class BeepPin1
{
 public:

  static uint8_t duration;

  static void begin();

  static void tone(uint16_t count, uint8_t dur);

  static void tone(uint16_t count);

  static void timer();

  static void noTone();

  static constexpr uint16_t freq(const float hz)
  {
    return (uint16_t) (((F_CPU / 8 / 2) + (hz / 2)) / hz) - 1;
  }
};

class BeepPin2
{
 public:

  static uint8_t duration;

  static void begin();

  static void tone(uint16_t count, uint8_t dur);

  static void tone(uint16_t count);

  static void timer();

  static void noTone();

  static constexpr uint16_t freq(const float hz)
  {
    return (uint16_t) (((F_CPU / 128 / 2) + (hz / 2)) / hz) - 1;
  }
};

#endif
