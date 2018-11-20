#include "Brain.h"
#include "WifiConnector.h"
#include "LEDManager.h"
#include "Sensor.h"

#include <Arduino.h>

Brain::Brain(LEDManager *ledManager, WifiConnector *wifi, Sensor *sensor) {
  this->ledManager = ledManager;
  this->wifi = wifi;
  this->sensor = sensor;
}

void Brain::setup(char* ssid, char* password){
  Serial.begin(115200);
  this->ledManager->turnOnLED("");
  delay(4000);   //Delay needed before calling the WiFi.begin
  // Start wifi connection
  this->wifi->connectToWifi(ssid, password);
  this->sensor->setHeaders();
}

void Brain::runProgram() {
  if (this->cont == 0) {
    this->status = this->sensor->getStatus();
    this->cont = 15;
  }
  this->ledManager->turnOnLED(this->status);
  this->cont--;
}
