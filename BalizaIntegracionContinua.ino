#include "Sensor.h"
#include "LEDManager.h"
#include <WiFi.h>

Sensor sensor;
LEDManager ledManager;

const char* ssid = "Mariano";
const char* password = "mgmarianobk@gmail.com";
String status = "";


void setup() {
  Serial.begin(115200);
  delay(4000);   //Delay needed before calling the WiFi.begin

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  sensor.setHeaders();
}

void loop() {
  
  status = sensor.getStatus();
  
  ledManager.encenderLED(status);
}
