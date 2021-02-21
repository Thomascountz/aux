#include "Adafruit_Si7021.h"
#include <Arduino.h>

bool enableHeater = false;
uint8_t loopCnt = 0;
float temperature;
float humidity;

Adafruit_Si7021 sensor = Adafruit_Si7021();

void setup() {
  Serial.begin(115200);

  // wait for serial port to open
  while (!Serial) {
    delay(10);
  }
  if (!sensor.begin()) {
    while (true);
  }
}

void loop() {
  temperature = sensor.readTemperature();
  humidity = sensor.readHumidity();
  Serial.print("Humidity:    ");
  Serial.print(humidity, 2);
  Serial.print("\tTemperature: ");
  Serial.println(temperature, 2);
  delay(1000);

  // Toggle heater enabled state every 30 seconds
  // An ~1.8 degC temperature increase can be noted when heater is enabled
  if (++loopCnt == 30) {
    enableHeater = !enableHeater;
    sensor.heater(enableHeater);
    if (sensor.isHeaterEnabled())
      Serial.println("HEATER ENABLED");
    else
      Serial.println("HEATER DISABLED");
       
    loopCnt = 0;
  }
}