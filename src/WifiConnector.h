#ifndef WIFICONNECTOR_H_
#define WIFICONNECTOR_H_

#include "InterfaceWifi.h"

using namespace std;

class WifiConnector
{
    private:
      InterfaceWifi *_wifi;

    public:
      WifiConnector(InterfaceWifi *_wifi);

      void connectToWifi(char* netName, char* password);
};

#endif
