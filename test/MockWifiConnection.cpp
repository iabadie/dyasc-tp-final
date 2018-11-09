#include <WifiConnector.h>
#include "gmock/gmock.h"

class MockWifiConnection : public WifiConnector {
    public:
    MOCK_METHOD2(connectToWifi, void (String netName, String password));
};
