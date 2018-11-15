#include "src/WifiConnector.h"
#include "src/Sensor.h"
#include "src/LEDManager.h"
#include <WiFi.h>
#include "src/CIClient.cpp"

WifiConnector wifiConnector;
CIClient* client = new CIClient();
Sensor sensor(client);
LEDManager ledManager;

char* ssid = "AP";
char* password = "Passw0rd";
String status = "";
int cont = 0;

void setup() {
  Serial.begin(115200);
  delay(4000);   //Delay needed before calling the WiFi.begin
  // Start wifi connection
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
