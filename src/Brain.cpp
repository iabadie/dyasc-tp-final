#include "Brain.h"
#include "WifiConnector.h"
#include "LEDManager.h"
#include "Sensor.h"

Brain::Brain(LEDManager *ledManager, WifiConnector *wifi, Sensor *sensor) {
  this->ledManager = ledManager;
  this->wifi = wifi;
  this->sensor = sensor;
}

void Brain::setup(char* ssid, char* password){
  this->ledManager->turnOnLED(-1);
  // Start wifi connection
  this->wifi->connectToWifi(ssid, password);
  this->sensor->setHeaders();
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
