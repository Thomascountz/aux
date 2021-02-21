#include <Arduino.h>
#include <pitches.h>

const int buzzerPin = 0;
const int buttonPin = 27;
const int channel = 0;
void gestureHello();

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    gestureHello();
  }
}
 
 void gestureHello() {
   Serial.println("triggered");
   ledcAttachPin(buzzerPin, channel);
   ledcWriteTone(channel, NOTE_C6);
   delay(100);
   ledcWriteTone(channel, NOTE_D6);
   delay(100);
   ledcWriteTone(channel, NOTE_G6);
   delay(100);
   ledcWriteTone(channel, NOTE_E6);
   delay(100);
   ledcDetachPin(buzzerPin);
   ledcWrite(channel, 0);
 }