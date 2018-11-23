#ifndef BRAIN_H_
#define BRAIN_H_

#include "WifiConnectorInterface.hpp"
#include "LEDManagerInterface.hpp"
#include "SensorInterface.hpp"
#include "AccessPointServerInterface.hpp"

class Brain
{
    private:
      LEDManagerInterface *ledManager;
      WifiConnectorInterface *wifi;
      SensorInterface *sensor;
      AccessPointServerInterface *ap;
      int status = -1;
      int cont = 0;

    public:
      Brain(LEDManagerInterface *ledManager, WifiConnectorInterface *wifi, SensorInterface *sensor, AccessPointServerInterface *ap);

      void setup();

      int runProgram();
};

#endif
