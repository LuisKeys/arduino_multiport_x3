#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();
#define NOTEON 0b1001
#define NOTEOFF 0b1000
#define MONOPRESSURE 0b1101
#define POLYPRESSURE 0b1010
#define PROGRAMCHANGE 0b1100
#define PITCHBEND 0b1110
#define CONTROLCHANGE 0b1011

#define SONGPOSITION 0xF2
#define SONGSELECT 0xF3
#define CLOCK 0xF8
#define START 0xFA
#define CONTINUE 0xFB
#define STOP 0xFC

void sendMidiMessage(byte command, byte channel, byte value1, byte value2) {
  byte cmd = command * 16 + 0;
  
  if(channel > 0 && channel <= 5) {
    turnOnLed(PORT_1);
    Serial1.write(cmd);
    Serial1.write(value1);
    Serial1.write(value2);
  }

  if(channel > 5 && channel <= 10) {
    turnOnLed(PORT_2);
    Serial2.write(cmd);
    Serial2.write(value1);
    Serial2.write(value2);
  }

  if(channel > 10 && channel <= 16) {
    turnOnLed(PORT_3);
    Serial3.write(cmd);
    Serial3.write(value1);
    Serial3.write(value2);
  }
}

void sendMidiShortMessage(byte command, byte channel, byte value) {
  byte cmd = command * 16 + 0;
  
  if(channel > 0 && channel <= 5 || channel > 16) {
    turnOnLed(PORT_1);
  }

  if(channel > 5 && channel <= 10 || channel > 16) {
    turnOnLed(PORT_2);
  }

  if(channel > 10 && channel <= 16 || channel > 16) {
    turnOnLed(PORT_3);
  }
}

void sendMidiClockMessage(byte cmd) {
    Serial1.write(cmd);
    Serial2.write(cmd);
    Serial3.write(cmd);
    turnOnLed(PORT_1);
    turnOnLed(PORT_2);
    turnOnLed(PORT_3);
}

void handleControlChange(byte channel, byte number, byte value) {
  sendMidiMessage(CONTROLCHANGE, channel, number, value);
}

void handleNoteOn(byte channel, byte pitch, byte velocity) {
  sendMidiMessage(NOTEON, channel, pitch, velocity);
}

void handleNoteOff(byte channel, byte pitch, byte velocity) {
  sendMidiMessage(NOTEOFF, channel, pitch, velocity);
}

void handleAfterTouchPoly(byte channel, byte note, byte pressure) {
  sendMidiMessage(POLYPRESSURE, channel, note, pressure);
}

void handleProgramChange(byte channel, byte number) {
  sendMidiShortMessage(PROGRAMCHANGE, channel, number);
}

void handleAfterTouchChannel(byte channel, byte pressure) {
  sendMidiShortMessage(MONOPRESSURE, channel, pressure);
}

void handlePitchBend(byte channel, int bend) {
  sendMidiMessage(PITCHBEND, channel, bend >> 7, bend & 0x7F);
}

void handleTimeCodeQuarterFrame(byte data) {
  sendMidiShortMessage(0, 100, data);
}

void handleSongPosition(unsigned int beats) {
  sendMidiMessage(0, 100, beats >> 7, beats & 0xFF);
}

void handleSongSelect(byte songnumber) {
  sendMidiShortMessage(SONGSELECT, 100, songnumber);
}

void handleClock(void) {
  sendMidiClockMessage(CLOCK);
}

void handleStart(void) {
  sendMidiClockMessage(START);
}

void handleContinue(void) {
  sendMidiClockMessage(CONTINUE);
}

void handleStop(void) {
  sendMidiClockMessage(STOP);
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

  MIDI.setHandleControlChange(handleControlChange);
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);

  MIDI.setHandleAfterTouchPoly(handleAfterTouchPoly);
  MIDI.setHandleControlChange(handleControlChange);
  MIDI.setHandleProgramChange(handleProgramChange);
  MIDI.setHandleAfterTouchChannel(handleAfterTouchChannel);
  MIDI.setHandlePitchBend(handlePitchBend);
  MIDI.setHandleTimeCodeQuarterFrame(handleTimeCodeQuarterFrame);
  MIDI.setHandleSongPosition(handleSongPosition);
  MIDI.setHandleSongSelect(handleSongSelect);
  MIDI.setHandleClock(handleClock);
  MIDI.setHandleStart(handleStart);
  MIDI.setHandleContinue(handleContinue);
  MIDI.setHandleStop(handleStop);

  initLeds();
}
