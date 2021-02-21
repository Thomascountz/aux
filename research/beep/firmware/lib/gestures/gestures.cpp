#include <gestures.h>
#include <tone.h>

void gestureHello(uint8_t pin, uint8_t channel) {
  tone(pin, NOTE_C6, 100, channel);
  tone(pin, NOTE_D6, 100, channel);
  tone(pin, NOTE_G6, 100, channel);
  tone(pin, NOTE_E6, 100, channel);
  noTone(pin, channel);
}