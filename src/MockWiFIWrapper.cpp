#include <WiFi.h>
#include "InterfaceWifi.h"
#include <Arduino.h>

using namespace std;

class MockWiFiWrapper : public InterfaceWifi
{
  public:
    int CONNECTED = WL_CONNECTED;

    void begin(char* ssid, char* password){
    };

    int status(){
      return 1;
    };

    void applyDelay() {
    }

    void print(char* output) {
      Serial.println(output);
    }
};
