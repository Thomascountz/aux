# Temp and Humidity
Aux sense local temperature and humidity (via a temperature & humidity sensor) as well as query for outdoor conditions via WIFI.

## [Firmware](/research/temp_and_humidity/firmware/)
This temperature and humidity prototype is written in Arduino-compatible C++ using the [PlatformIO IDE](https://platformio.org/). Readings are read out through the serial port.

## [Hardware](/research/temp_and_humidity/hardware/)
The circuit is designed with [KiCAD](https://kicad.org/) and consists the ESP32 dev board and a S17021 (a.k.a. SHT71, HTU21, or GY21) sensor module.

## Resources
- https://github.com/adafruit/Adafruit_Si7021
- https://learn.adafruit.com/adafruit-si7021-temperature-plus-humidity-sensor
- https://learn.sparkfun.com/tutorials/si7021-humidity-and-temperature-sensor-hookup-guide
- https://revspace.nl/CJMCU-810
- https://learn.sparkfun.com/tutorials/ccs811-air-quality-breakout-hookup-guide