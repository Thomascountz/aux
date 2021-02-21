// licensed from: https://github.com/lbernstone/Tone32
// see: LICENSE.md

#include <tone.h>

void tone(uint8_t pin, uint8_t frequency, ulong duration, uint8_t channel) {
    if (ledcRead(channel)) {
        return;
    }
    ledcAttachPin(pin, channel);
    ledcWriteTone(channel, frequency);
    if (duration) {
        delay(duration);
        noTone(pin, channel);
    }
}

void noTone(uint8_t pin, uint8_t channel) {
    ledcDetachPin(pin);
    ledcWrite(channel, 0);
}