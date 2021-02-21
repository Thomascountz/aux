#include "gestures.h"

void gestureHello(uint8_t pin, uint8_t channel) {
  ledcAttachPin(pin, channel);
  ledcWriteTone(channel, NOTE_C6);
  delay(100);
  ledcWriteTone(channel, NOTE_D6);
  delay(100);
  ledcWriteTone(channel, NOTE_G6);
  delay(100);
  ledcWriteTone(channel, NOTE_E6);
  delay(100);
  ledcDetachPin(pin);
  ledcWrite(channel, 0);
}