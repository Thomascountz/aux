#include <Arduino.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <Secrets.h>
#include <OTA.h>

const char* ssid = SECRET_SSID;
const char* password = SECRET_PASS;

unsigned long previousChangeAt = 0;
const long interval = 1000;
int ledState = LOW;

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);

  Serial.begin(115200);
  Serial.println("Booting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  OTABegin();

  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  OTAHandle();

  unsigned long now = millis();
  if (now - previousChangeAt >= interval) {
    previousChangeAt = now;
    ledState = not(ledState);
    digitalWrite(BUILTIN_LED, ledState);
  }
}