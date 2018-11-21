#include "src/InterfaceWifi.h"
#include "src/WifiWrapper.cpp"
#include "src/WifiConnector.h"
#include "src/Sensor.h"
#include "src/LEDManager.h"
#include <WiFi.h>
#include "src/CIClient.cpp"
#include "src/Brain.h"
// Instance Client and Sensor
CIClient* client = new CIClient();
Sensor* sensor = new Sensor(client);
// Instance Wifi
WifiWrapper* wifi = new WifiWrapper();
WifiConnector* wifiConnector = new WifiConnector(wifi);
// LEd instance
LEDManager* ledManager = new LEDManager();
// Brain instance
Brain* brain = new Brain(ledManager, wifiConnector, sensor);

char* ssid = "Mariano";
char* password = "mgmarianobk@gmail.com";

void setup() {
  brain->setup(ssid, password);
}

void loop() {
  brain->runProgram();
}
