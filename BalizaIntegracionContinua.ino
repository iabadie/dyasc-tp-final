#include "src/WifiConnector.h"
#include "src/Sensor.h"
#include "src/LEDManager.h"
#include "src/AccessPointServer.h"
#include <WiFi.h>

AccessPointServer ap;
WifiConnector wifiConnector;
Sensor sensor;
LEDManager ledManager;

String status = "";
int cont = 0;
bool wifiConnected = false;
bool ciConnected = false;

void setup() {
  Serial.begin(115200);
  delay(4000);   //Delay needed before calling the WiFi.begin
  // Start wifi connection
  ap.setup();
  String netName = "";
  String pass = "";
  while (!wifiConnected) {
    ap.checkServer();
    netName = ap.getNetName();
    pass = ap.getPass();
    if (netName.length() > 0 && pass.length() > 0) {
      char auxName[netName.length()+1];
      strcpy(auxName, netName.c_str());
      char auxPass[pass.length()+1];
      strcpy(auxPass, pass.c_str());
      wifiConnector.connectToWifi(auxName, auxPass);
      wifiConnected = true;
    }
  }
  String repoNumber;
  String token;
  while (!ciConnected) {
    ap.checkServer();
    repoNumber = ap.getNetName();
    token = ap.getPass();
    if (!ciConnected && repoNumber.length() > 0 && token.length() > 0) {
      sensor.setHeaders(repoNumber, token);
      ciConnected = true;
    }
  }
}

void loop() {
  if (cont == 0) {
    status = sensor.getStatus();
    cont = 15;
  }
  ledManager.encenderLED(status);
  cont--;
}  
