#include "src/Sensor.h"
#include "src/LEDManager.h"
#include <WiFi.h>

Sensor sensor;
LEDManager ledManager;

const char* ssid = "Mariano";
const char* password = "mgmarianobk@gmail.com";
String status = "";
int cont = 0;

void setup() {
  Serial.begin(115200);
  delay(4000);   //Delay needed before calling the WiFi.begin
  // Start wifi connection
  WiFi.begin(ssid, password);
  // Check wifi status and when its connected continue with the program
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  sensor.setHeaders();
}

void loop() {
  if (cont == 0) {
    status = sensor.getStatus();
    cont = 15;
  }
  ledManager.encenderLED(status);
  cont--;
}
