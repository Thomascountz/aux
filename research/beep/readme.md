# Beep
Aux communicates to the user via tone gestures. Think of the sound your phone or laptop makes when you plug in the charger or the sound your computer makes when theres an error. These tones are generated via a piezoelectric buzzer.

## [Firmware](/research/beep/firmware/)
This beep prototype is written in Arduino-compatible C++ using the [PlatformIO IDE](https://platformio.org/). Pressing the button plays the [hello](gestures/hello.mp3) gesture.

## [Gestures](/research/beep/gestures/)
I designed the monophonic gestures using beepbox.co/. It's a simple tool to quickly prototype and export mp3. All gestures have C as the tonal center, this will hopefully allow major and minor notes convey positive and negative feedback. For example, the "alert" tone is a repetition of E♭. Without a C instantly present, it may not feel minor, but as the relationship with the device builds, I hope that the tonal center will be reinforced and allow for the E♭ to be felt as minor on its own.

- [hello.mp3](gestures/hello.mp3)
- [goodbye.mp3](gestures/goodbye.mp3)
- [well_done.mp3](gestures/well_done.mp3)
- [success.mp3](gestures/success.mp3)
- [systems_ok.mp3](gestures/systems_ok.mp3)
- [melancholy.mp3](gestures/melancholy.mp3)
- [shrug.mp3](gestures/shrug.mp3)
- [sorry.mp3](gestures/sorry.mp3)
- [alert.mp3](gestures/alert.mp3)
- [danger.mp3](gestures/danger.mp3)

## [Hardware](/research/beep/hardware/)
The circuit is designed with [KiCAD](https://kicad.org/) and consists the ESP32 dev board, a passive piezoelectric buzzer, and a momentary tactile button switch.


## Sources
- https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/
- https://github.com/r0oland/ESP32_mini_KiCad_Library
- https://github.com/lbernstone/Tone32