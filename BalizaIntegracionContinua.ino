#include "src/WifiConnector.h"
#include "src/Sensor.h"
#include "src/LEDManager.h"
#include "src/AccessPointServer.h"
#include <WiFi.h>

AccessPointServer ap;
WifiConnector wifiConnector;
Sensor sensor;
LEDManager ledManager;

char* ssid = "Mariano";
char* password = "mgmarianobk@gmail.com";
String status = "";
int cont = 0;

void setup() {
  Serial.begin(115200);
  delay(4000);   //Delay needed before calling the WiFi.begin
  // Start wifi connection
  ap.setup();
  // wifiConnector.connectToWifi(ssid, password);
  // sensor.setHeaders();
}

void loop() {
  ap.checkServer();
  if (cont == 0) {
    // status = sensor.getStatus();
    cont = 15;
  }
  ledManager.encenderLED(status);
  cont--;
}
