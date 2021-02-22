# MQTT
Aux communicates via MQTT (Message Queuing Telemetry Transport) over WIFI. 

## [Firmware](/research/temp_and_humidity/firmware/)
This MQTT prototype is written in Arduino-compatible C++ using the [PlatformIO IDE](https://platformio.org/). The MQTT client is built using the [knolleary/pubsubclient](https://github.com/knolleary/pubsubclient/tree/master/examples) library. The broker is built using the cloud-based managed tool [MyQttHub](https://myqtthub.com/).

## Hardware
This prototype doesn't require a schematic. The onboard `BUILTIN_LED` is toggled via an MQTT topic.

## Resources
- https://github.com/adafruit/Adafruit_Si7021
- https://learn.adafruit.com/adafruit-si7021-temperature-plus-humidity-sensor
- https://learn.sparkfun.com/tutorials/si7021-humidity-and-temperature-sensor-hookup-guide