#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_APDS9960.h>

// APDS-9600
Adafruit_APDS9960 apds;
void handleGesture(uint8_t gesture);

// OLED
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  Serial.println("TEST");

  // Initialize display
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  display.clearDisplay();

  if (!apds.begin()) {
    Serial.println("failed to initialize device! Please check your wiring.");
  } else {
     Serial.println("Device initialized!");
  }

  //gesture mode will be entered once proximity mode senses something close
  apds.enableProximity(true);
  apds.enableGesture(true);
}

void loop() {
  uint8_t gesture = apds.readGesture();
  handleGesture(gesture);
}

void handleGesture(uint8_t gesture) {
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
  switch (gesture) {
  case APDS9960_UP:
    Serial.println("UP");
    display.clearDisplay();
    display.println(F("DOWN"));
    break;
  case APDS9960_DOWN:
    Serial.println("DOWN");
    display.clearDisplay();
    display.println(F("UP"));
    break;
  case APDS9960_LEFT:
    Serial.println("LEFT");
    display.clearDisplay();
    display.println(F("RIGHT"));
    break;
  case APDS9960_RIGHT:
    Serial.println("RIGHT");
    display.clearDisplay();
    display.println(F("LEFT"));
    break;
  default:
    // Serial.println("NONE");
    // display.println(F("NONE"));
    break;
  }
  display.display();
}