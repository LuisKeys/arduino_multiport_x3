#include "liquid_crystal_utils.h"
#include "leds_utils.h"
#include "midi_utils.h"

byte valOld = 0;

void setup() {
  initSystem();
  initLeds();
  initLCD();
}

void loop() {
  MIDI.read();
}
