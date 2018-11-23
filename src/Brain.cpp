#include "Brain.h"
#include "WifiConnectorInterface.hpp"
#include "LEDManagerInterface.hpp"
#include "SensorInterface.hpp"
#include "AccessPointServerInterface.hpp"

#include <Arduino.h>

bool wifiConnected = false;
bool ciConnected = false;

Brain::Brain(LEDManagerInterface *ledManager, WifiConnectorInterface *wifi, SensorInterface *sensor, AccessPointServerInterface *ap) {
  this->ledManager = ledManager;
  this->wifi = wifi;
  this->sensor = sensor;
  this->ap = ap;
}

void Brain::setup(){
    this->ledManager->turnOnLED(-1);
  // ---------------

  // Start wifi connection
  ap->setup();
  while (!wifiConnected) {
    ap->checkServer();
    char* netName = NULL;
    ap->getNetName(netName);
    char* pass = NULL;
    ap->getPass(pass);
    Serial.println("NET");
    Serial.println(netName);
    Serial.println("PASS");
    Serial.println(pass);
    Serial.println(sizeof(netName)/sizeof(char));
    Serial.println("--------");
    if (sizeof(netName)/sizeof(char) > 4 && sizeof(pass)/sizeof(char) > 4) {
      this->wifi->connectToWifi(netName, pass);
      wifiConnected = true;
    }
  }

  while (!ciConnected) {
    ap->checkServer();
    char* repoNumber = NULL;
    ap->getNetName(repoNumber);
    char* token = NULL;
    ap->getPass(token);
    if (!ciConnected && sizeof(repoNumber)/sizeof(char) > 0 && sizeof(token)/sizeof(char) > 0) {
      sensor->setHeaders(repoNumber, token);
      ciConnected = true;
    }
  }



  // ---------------
}

int Brain::runProgram() {
  if (this->cont == 0) {
    this->status = this->sensor->getStatus();
    this->cont = 15;
  }
  this->ledManager->turnOnLED(this->status);
  this->cont--;
  return this->status;
}
