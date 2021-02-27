#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

void callback(char* topic, byte* payload, unsigned int length);
const char* ssid = "REDACTED";
const char* password = "REDACTED";
const char* mqtt_server = "REDACTED";
const char* client_name = "REDACTED";
const char* client_user = "REDACTED";
const char* client_pass = "REDACTED";

WiFiClient espClient;
PubSubClient client(mqtt_server, 1883, callback, espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (50)
char msg[MSG_BUFFER_SIZE];
long int value = 0;

void setup_wifi() {
  delay(1000);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect(client_name, client_user, client_pass)) {
    Serial.println("Connected to broker.");
      client.publish("outTopic", "hello world");
      client.subscribe("inTopic");
    }
    else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  if ((char)payload[0] == '1') {
    digitalWrite(BUILTIN_LED, HIGH); 
  } else {
    digitalWrite(BUILTIN_LED, LOW);
  }
}

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);
  Serial.begin(115200);
  setup_wifi();

  if (client.connect(client_name, client_user, client_pass)) {
    Serial.println("Connected to broker.");
    client.publish("outTopic", "hello world");
    client.subscribe("inTopic");
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 60000) {
    lastMsg = now;
    ++value;
    snprintf (msg, MSG_BUFFER_SIZE, "hello world #%ld", value);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("outTopic", msg);
  }
}