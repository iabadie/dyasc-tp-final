#include "gmock/gmock.h"
#include "WifiConnectorInterface.hpp"

class MockWifiConnector : public WifiConnectorInterface {
    public:
    // Mockea las funciones de la interfaz SensorInterface
    MOCK_METHOD2(connectToWifi, void(char* netName, char* password));
};
