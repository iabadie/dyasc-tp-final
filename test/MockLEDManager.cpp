#include "gmock/gmock.h"
#include "LEDManagerInterface.hpp"

class MockLEDManager : public LEDManagerInterface {
    public:
    // Mockea las funciones de la interfaz SensorInterface
    MOCK_METHOD1(turnOnLED, void(int status));
    MOCK_METHOD0(turnOffLEDS, void());
};
