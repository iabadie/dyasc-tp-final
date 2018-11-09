#ifndef WIFICONNECTOR_H_
#define WIFICONNECTOR_H_

#include <WiFi.h>

class WifiConnector
{
    public:
      WifiConnector();

      void connectToWifi(String netName, String password);
};

#endif
