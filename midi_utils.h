#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();
#define NOTEON 0b1001
#define NOTEOFF 0b1000
#define MONOPRESSURE 0b1101
#define POLYPRESSURE 0b1010
#define PROGRAMCHANGE 0b1100
#define PITCHBEND 0b1110
#define CONTROLCHANGE 0b1011

void handleNoteOn(byte channel, byte pitch, byte velocity) {
  byte cmd = NOTEON * 16 + 0;
  
  if(channel > 0 && channel <= 5) {
    turnOnLed(PORT_1);
    Serial1.write(cmd);
    Serial1.write(pitch);
    Serial1.write(velocity);
  }

  if(channel > 5 && channel <= 10) {
    turnOnLed(PORT_2);
    Serial2.write(cmd);
    Serial2.write(pitch);
    Serial2.write(velocity);
  }

  if(channel > 10 && channel <= 16) {
    turnOnLed(PORT_3);
    Serial3.write(cmd);
    Serial3.write(pitch);
    Serial3.write(velocity);
  }
}

void handleNoteOff(byte channel, byte pitch, byte velocity) {
  byte cmd = NOTEOFF * 16 + 0;
  
  if(channel > 0 && channel <= 5) {
    turnOnLed(PORT_1);
    Serial1.write(cmd);
    Serial1.write(pitch);
    Serial1.write(velocity);
  }

  if(channel > 5 && channel <= 10) {
    turnOnLed(PORT_2);
    Serial2.write(cmd);
    Serial2.write(pitch);
    Serial2.write(velocity);
  }

  if(channel > 10 && channel <= 16) {
    turnOnLed(PORT_3);
    Serial3.write(cmd);
    Serial3.write(pitch);
    Serial3.write(velocity);
  }
}

void initSystem() {  
  Serial1.begin(31250);
  while (!Serial1) { delay(50);}  

  Serial2.begin(31250);
  while (!Serial2) { delay(50);}  

  Serial3.begin(31250);
  while (!Serial3) { delay(50);}  

  MIDI.begin(MIDI_CHANNEL_OMNI);
  
  Serial.begin(115200);
  
  while (!Serial) { delay(50);}  

  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
  
  initLeds();
}
