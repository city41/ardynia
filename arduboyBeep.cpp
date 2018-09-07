/**
 * @file arduboyBeep.cpp
 * \brief
 * Classes to generate simple square wave tones on the Arduboy speaker pins.
 */

#include <Arduino.h>
#include "arduboyBeep.h"

// Speaker pin 1, Timer 3A, Port C bit 6, Arduino pin 5

uint8_t BeepPin1::duration = 0;

void BeepPin1::begin()
{
  TCCR3A = 0;
  TCCR3B = (bit(WGM32) | bit(CS31)); // CTC mode. Divide by 8 clock prescale
}

void BeepPin1::tone(uint16_t count, uint8_t dur)
{
  duration = dur;
  tone(count);
}

void BeepPin1::tone(uint16_t count)
{
  TCCR3A = bit(COM3A0); // set toggle on compare mode (which connects the pin)
  OCR3A = count; // load the count (16 bits), which determines the frequency
}

void BeepPin1::timer()
{
  if (duration && --duration == 0) {
    noTone();
  }
}

void BeepPin1::noTone()
{
  TCCR3A = 0; // set normal mode (which disconnects the pin)
}


// Speaker pin 2, Timer 4A, Port C bit 7, Arduino pin 13

uint8_t BeepPin2::duration = 0;

void BeepPin2::begin()
{
  TCCR4A = 0; // normal mode. Disable PWM
  TCCR4B = bit(CS43); // Divide by 128 clock prescale
  TCCR4D = 0; // normal mode
  TC4H = 0;  // toggle pin at count = 0
  OCR4A = 0; //  "
}

void BeepPin2::tone(uint16_t count, uint8_t dur)
{
  duration = dur;
  tone(count);
}

void BeepPin2::tone(uint16_t count)
{
  TCCR4A = bit(COM4A0); // set toggle on compare mode (which connects the pin)
  TC4H = highByte(count); // load the count (10 bits),
  OCR4C = lowByte(count); //  which determines the frequency
}

void BeepPin2::timer()
{
  if (duration && --duration == 0) {
    noTone();
  }
}

void BeepPin2::noTone()
{
  TCCR4A = 0; // set normal mode (which disconnects the pin)
}
