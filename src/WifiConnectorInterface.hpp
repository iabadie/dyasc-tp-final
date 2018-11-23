#ifndef WIFICONNECTORINTERFACE_H_
#define WIFICONNECTORINTERFACE_H_

// Interfaz utilizada para el componente de WifiConnector
class WifiConnectorInterface
{
    public:
      virtual ~WifiConnectorInterface() {}
      virtual void connectToWifi(char* netName, char* password) = 0;
};

#endif
