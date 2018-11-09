
#include <WiFi.h>
#include "WifiConnector.h"

WifiConnector::WifiConnector(){}

void WifiConnector::connectToWifi(String netName, String password) {
	// Start wifi connection
	WiFi.begin(ssid, password);
	// Check wifi status and when its connected continue with the program
	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.println("Connecting to WiFi..");
	}
	Serial.println("Connected to the WiFi network");
}
