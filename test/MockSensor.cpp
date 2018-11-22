#include "gmock/gmock.h"
#include <SensorInterface.hpp>

class MockSensor : public SensorInterface {
    public:
    // Mockea las funciones de la interfaz SensorInterface
    MOCK_METHOD0(setHeaders, void());
    MOCK_METHOD0(getStatus, int());
};
