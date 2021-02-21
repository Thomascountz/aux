#include <gestures.h>
#include <tone.h>
#include <pitches.h>

void gestureHello(uint8_t pin, uint8_t channel) {
  tone(pin, NOTE_C6, channel, 100);
  tone(pin, NOTE_D6, channel, 100);
  tone(pin, NOTE_G6, channel, 100);
  tone(pin, NOTE_E6, channel, 100);
  noTone(pin, channel);
}

void gestureHello2(uint8_t pin, uint8_t channel) {
  ledcAttachPin(pin, channel);
  ledcWriteNote(channel, NOTE_C, 6);
  delay(100);
  ledcWriteNote(channel, NOTE_D, 6);
  delay(100);
  ledcWriteNote(channel, NOTE_G, 6);
  delay(100);
  ledcWriteNote(channel, NOTE_E, 6);
  delay(100);
  ledcDetachPin(pin);
}