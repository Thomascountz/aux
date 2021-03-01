#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <Adafruit_Si7021.h>
#include <secrets.h>
#include <OTA.h>

// consts
const long thirty_seconds = 30000;
unsigned long last_message_at = 0;

// Beep
const int pwmChannel = 0;
const int buzzerPin = 26;

// WIFI
const char *ssid = SECRET_SSID;
const char *password = SECRET_PASS;

// MQTT Settings
void mqttHandler(char *topic, byte *payload, unsigned int length);
void gestureHello();
const char *mqtt_broker_address = SECRET_MQTT_BROKER_ADDRESS;
const char *client_id = SECRET_MQTT_CLIENT_ID;
const char *client_user = SECRET_MQTT_CLIENT_USER;
const char *client_password = SECRET_MQTT_CLIENT_PASSWORD;
const int port = 1883;
WiFiClient wifi_client = WiFiClient();
PubSubClient client(mqtt_broker_address, port, mqttHandler, wifi_client);

const char *temperature_topic = "thomascountz/feeds/proto-1.temperature";
const char *humidity_topic = "thomascountz/feeds/proto-1.humidity";
const char *beep_topic = "thomascountz/feeds/proto-1.beep";
const char *did_beep_topic = "thomascountz/feeds/proto-1.did-beep";
const char *heartbeat_topic = "thomascountz/feeds/proto-1.heartbeat";
const char *diagnostics_topic = "thomascountz/feeds/proto-1.diagnostics";

char temperature_buffer[8];
char humidity_buffer[8];

// Temp & Humidity
Adafruit_Si7021 temp_sensor = Adafruit_Si7021();
float temperature;
float humidity;

void mqttHandler(char *topic, byte *payload, unsigned int length) {
#ifdef DEBUG
  Serial.print("Message arrived: ");
  Serial.println(topic);
#endif
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
#ifdef DEBUG
  Serial.println("Did beep.");
#endif
}

void setup() {
#ifdef DEBUG
  Serial.begin(115200);
#endif

  // Delay on startup
  delay(2000);

// Initiate temperature/humidity sensor
#ifdef DEBUG
  Serial.println("Initiating temperature & humidity sensor");
#endif
  if (!temp_sensor.begin()) {
    while (true)
      ;
  }

// Connect to WiFi
#ifdef DEBUG
  Serial.println("Connecting to WiFi.");
#endif
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
#ifdef DEBUG
    Serial.print(".");
#endif
  }
#ifdef DEBUG
  Serial.println();
  Serial.println("Connected: ");
  Serial.println(WiFi.localIP());
#endif

// Connect to MQTT broker
#ifdef DEBUG
  Serial.println("Connecting to MQTT broker.");
#endif
  if (client.connect(client_id, client_user, client_password)) {
#ifdef DEBUG
    Serial.println("Connected to MQTT broker.");
#endif
    client.publish(heartbeat_topic, "1");
    client.subscribe(beep_topic);
    gestureHello();
  }
  
  // OTA
  OTABegin();
}

void loop() {
  //OTA
  OTAHandle();

  // Are we still connected to the MQTT broker?
  if (!client.connected()) {
    while (!client.connected()) {
#ifdef DEBUG
      Serial.println("Reconnecting to MQTT broker.");
#endif
      if (client.connect(client_id, client_user, client_password)) {
#ifdef DEBUG
        Serial.println("Connected to MQTT broker.");
#endif
        client.publish(heartbeat_topic, "1");
        client.subscribe(beep_topic);
      } else {
#ifdef DEBUG
        Serial.println("Failed to reconnect to MQTT broker.");
        Serial.println("Trying again in 5 seconds");
#endif
        delay(5000);
      }
    }
  }

  client.loop();

  unsigned long now = millis();
  if (now - last_message_at > thirty_seconds) {
    last_message_at = now;
    temperature = temp_sensor.readTemperature();
    humidity = temp_sensor.readHumidity();

#ifdef DEBUG
    Serial.println();
#endif

    dtostrf(temperature, 6, 2, temperature_buffer);
    client.publish(temperature_topic, temperature_buffer);
#ifdef DEBUG
    Serial.print("temperature: ");
    Serial.print(temperature_buffer);
#endif

    dtostrf(humidity, 6, 2, humidity_buffer);
    client.publish(humidity_topic, humidity_buffer);
#ifdef DEBUG
    Serial.print(" humidity: ");
    Serial.print(humidity_buffer);
#endif
  }
}