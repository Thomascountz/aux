# CO2 & VOC
Aux can sense eCO2 (equivalent carbon dioxide) concentrations and TVOC (total volatile organic compound) levels. Together with [temp_and_humidity](research/temp_and_humidity/), this makes up Aux's sense of indoor environment quality.

## [Firmware](/research/co2_and_vcc/firmware/)
This beep prototype is written in Arduino-compatible C++ using the [PlatformIO IDE](https://platformio.org/). Readings are read out through the serial port.

## [Hardware](/research/co2_and_vcc/hardware/)
The circuit is designed with [KiCAD](https://kicad.org/) and consists the ESP32 dev board and a S17021 (a.k.a. SHT71, HTU21, or GY21) sensor module.

## Resources
- https://learn.adafruit.com/adafruit-ccs811-air-quality-sensor/overview