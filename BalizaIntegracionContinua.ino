#include "src/InterfaceWifi.h"
#include "src/WifiWrapper.cpp"
#include "src/WifiConnector.h"
#include "src/Sensor.h"
#include "src/LEDManager.h"
#include <WiFi.h>

WifiWrapper *wifi;
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
  WifiConnector wifiConnector(wifi);
  wifiConnector.connectToWifi(ssid, password);
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
