#include <WiFi.h>
#include "InterfaceWifi.h"
#include <Arduino.h>

using namespace std;

class WifiWrapper : public InterfaceWifi
{
  public:
    int CONNECTED = WL_CONNECTED;

    void begin(char* ssid, char* password){
      WiFi.begin(ssid, password);
    };

    int status(){
      return WiFi.status();
    };

    void applyDelay() {
      delay(500);
    }

    void print(char* output) {
      Serial.println(output);
    }
};
