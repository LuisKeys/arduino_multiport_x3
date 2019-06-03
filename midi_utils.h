#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

void handleNoteOn(byte channel, byte pitch, byte velocity) {
  writeLCD(channel, pitch, velocity);
}

void handleNoteOff(byte channel, byte pitch, byte velocity) {
  writeLCD(channel, pitch, velocity);
}

void initSystem() {
  MIDI.begin(MIDI_CHANNEL_OMNI);
  Serial.begin(115200);
  while (!Serial) { delay(50);}  

  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
}
