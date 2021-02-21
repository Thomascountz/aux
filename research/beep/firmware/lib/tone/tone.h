// licensed from: https://github.com/lbernstone/Tone32
// see: LICENSE.md

#include <arduino.h>

void tone(uint8_t pin, uint8_t frequency, ulong duration = 0, uint8_t channel);
void noTone(uint8_t pin, uint8_t channel);