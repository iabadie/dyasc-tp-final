#include "Sensor.h"
#include "LEDManager.h"
#include <WiFi.h>

Sensor sensor;
LEDManager ledManager;

const char* ssid = "AP";
const char* password = "Passw0rd";
String status = "";
int cont = 0;

void setup() {
  Serial.begin(115200);
  delay(4000);   //Delay needed before calling the WiFi.begin

  // DECLARA EL PIN
  pinMode (2, OUTPUT);
  
  WiFi.begin(ssid, password);

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
