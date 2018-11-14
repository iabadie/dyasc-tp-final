#include "WifiConnector.h"

WifiConnector::WifiConnector(InterfaceWifi *_wifi) {
	this->_wifi = _wifi;
}

void WifiConnector::connectToWifi(char* netName, char* password) {
	// Start wifi connection
	this->_wifi->begin(netName, password);
	// Check wifi status and when its connected continue with the program
	while (this->_wifi->status() != this->_wifi->CONNECTED) {
		this->_wifi->applyDelay();
		this->_wifi->print("Connecting to WiFi..");
	}
	this->_wifi->print("Connected to the WiFi network");
}
