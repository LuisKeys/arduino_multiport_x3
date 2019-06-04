#include "leds_utils.h"
#include "midi_utils.h"

int counter = 0;

void setup() {
  initSystem();
}

void loop() {
  MIDI.read();

  if(counter > 1000) {
    turnOffLed(PORT_1);
    turnOffLed(PORT_2);
    turnOffLed(PORT_3);
    counter = 0;
  }

  counter++;
}
