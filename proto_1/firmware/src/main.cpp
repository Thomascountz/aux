#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <Adafruit_Si7021.h>
#include <Adafruit_CCS811.h>

// consts
const long thirty_seconds = 30000;
unsigned long last_message_at = 0;

// Beep
const int pwmChannel = 0;
const int buzzerPin = 26;

// WIFI
const char* ssid = "REDACTED";
const char* password = "REDACTED";

// MQTT Settings
void mqttHandler(char* topic, byte* payload, unsigned int length);
void gestureHello();
const char* mqtt_broker_address = "io.adafruit.com";
const char* client_id = "proto_1";
const char* client_user = "thomascountz";
const char* client_password = "REDACTED";
const int port = 1883;
WiFiClient wifi_client = WiFiClient();
PubSubClient client(mqtt_broker_address, port, mqttHandler, wifi_client);

const char* temperature_topic = "thomascountz/feeds/proto-1.temperature";
const char* humidity_topic = "thomascountz/feeds/proto-1.humidity";
const char* co2_topic = "thomascountz/feeds/proto-1.co2";
const char* voc_topic = "thomascountz/feeds/proto-1.voc";
const char* beep_topic = "thomascountz/feeds/proto-1.beep";
const char* did_beep_topic = "thomascountz/feeds/proto-1.did-beep";
const char* heartbeat_topic = "thomascountz/feeds/proto-1.heartbeat";
const char* error_topic = "thomascountz/feeds/proto-1.error";

char temperature_buffer[8];
char humidity_buffer[8];
char co2_buffer[8];
char voc_buffer[8];

// Temp & Humidity
Adafruit_Si7021 temp_sensor = Adafruit_Si7021();
float temperature;
float humidity;

// CO2 & VOC
Adafruit_CCS811 air_sensor = Adafruit_CCS811();;
float co2;
float voc;

void mqttHandler(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived: ");
  Serial.println(topic);
  if (strcmp(topic, beep_topic) == 0) {
    if ((char)payload[0] == '1') {
      gestureHello();
    }
  }
}

void gestureHello() {
  ledcAttachPin(buzzerPin, pwmChannel);
  ledcWriteNote(pwmChannel, NOTE_C, 6);
  delay(100);
  ledcWriteNote(pwmChannel, NOTE_D, 6);
  delay(100);
  ledcWriteNote(pwmChannel, NOTE_G, 6);
  delay(100);
  ledcWriteNote(pwmChannel, NOTE_E, 6);
  delay(100);
  ledcDetachPin(buzzerPin);
  client.publish(did_beep_topic, "1");
  Serial.println("Did beep.");
}

void setup()
{
  Serial.begin(115200);

  // Delay on startup
  delay(2000);

  // Initiate temperature/humidity sensor
  Serial.println("Initiating temperature & humidity sensor");
  if (!temp_sensor.begin()) {
    while(true);
  }

  // Initiate CO2/VOC sensor
  Serial.println("Initiating CO2 & VOC sensor");
  if (!air_sensor.begin()) {
    while(true);
  }

  // Connect to WiFi
  Serial.println("Connecting to WiFi.");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected: ");
  Serial.println(WiFi.localIP());

  // Connect to MQTT broker
  Serial.println("Connecting to MQTT broker.");
  if (client.connect(client_id, client_user, client_password)){
    Serial.println("Connected to MQTT broker.");
    client.publish(heartbeat_topic, "1");
    client.subscribe(beep_topic);
    gestureHello();
  }
}

void loop() {
  // Are we still connected to the MQTT broker?
  if (!client.connected()) {
    while (!client.connected()) {
      Serial.println("Reconnecting to MQTT broker.");
      if (client.connect(client_id, client_user, client_password)) {
        Serial.println("Connected to MQTT broker.");
        client.publish(heartbeat_topic, "1");
        client.subscribe(beep_topic);
      } else {
        Serial.println("Failed to reconnect to MQTT broker.");
        Serial.println("Trying again in 5 seconds");
        delay(5000);
      }
    }
  }

  client.loop();

  unsigned long now = millis();
  if (now - last_message_at > thirty_seconds) {
    temperature = temp_sensor.readTemperature();
    humidity = temp_sensor.readHumidity();
    if (air_sensor.available()) {
      air_sensor.setEnvironmentalData(humidity, temperature);
      if (!air_sensor.readData()) {
        last_message_at = now;

        co2 = air_sensor.geteCO2();
        voc = air_sensor.getTVOC();

        Serial.println();

        dtostrf(temperature, 6, 2, temperature_buffer);
        client.publish(temperature_topic, temperature_buffer);
        Serial.print("temperature: ");
        Serial.print(temperature_buffer);

        dtostrf(humidity, 6, 2, humidity_buffer);
        client.publish(humidity_topic, humidity_buffer);
        Serial.print(" humidity: ");
        Serial.print(humidity_buffer);

        dtostrf(co2, 6, 2, co2_buffer);
        client.publish(co2_topic, co2_buffer);
        Serial.print(" CO2: ");
        Serial.print(co2_buffer);

        dtostrf(voc, 6, 2, voc_buffer);
        client.publish(voc_topic, voc_buffer);

        Serial.print(" VOC: ");
        Serial.print(voc_buffer);
        Serial.println();
      }
    }
  }
}