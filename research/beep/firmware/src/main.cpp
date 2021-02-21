#include <Arduino.h>
#include <gestures.h>

const int buzzerPin = 0;
const int buttonPin = 27;
const int pwmChannel = 0;
bool buttonPressed = false;
void handleButtonInterrupt();

void setup() {
  // Because we want to detect a "FALLING" change on the button, we use
  // the ESP32's internal pullup resistors
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(buttonPin, handleButtonInterrupt, FALLING);
  Serial.begin(115200);
}

void loop() {
  // We use a state variable to ensure that the ISR (interrupt service routine), 
  // the function handling the interrupt, executes as quickly as possible.
  if (buttonPressed == true)
  {
    Serial.println("interrupt triggered.");
    gestureHello(buzzerPin, pwmChannel);
    buttonPressed = false;
  }
}

// IRAM_ATTR puts the function in Internal RAM (IRAM) as opposed to flash, which
// is much faster.
void IRAM_ATTR handleButtonInterrupt() {
  buttonPressed = true;
}