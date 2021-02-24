# MQTT
Aux communicates via MQTT (Message Queuing Telemetry Transport) over WIFI. 

## [Firmware](/research/temp_and_humidity/firmware/)
This MQTT prototype is written in Arduino-compatible C++ using the [PlatformIO IDE](https://platformio.org/). The MQTT client is built using the [knolleary/pubsubclient](https://github.com/knolleary/pubsubclient/tree/master/examples) library. The broker is built using the cloud-based managed tool [MyQttHub](https://myqtthub.com/).

## Hardware
This prototype doesn't require a schematic. The onboard `BUILTIN_LED` is toggled via an MQTT topic.

## Resources
- https://support.asplhosting.com/t/connecting-with-pubsubclient-with-myqtthub-arduino-client-for-mqtt/278
- https://learn.sparkfun.com/tutorials/introduction-to-mqtt/all