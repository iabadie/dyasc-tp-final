#ifndef BRAIN_H_
#define BRAIN_H_

#include "WifiConnectorInterface.hpp"
#include "LEDManagerInterface.hpp"
#include "SensorInterface.hpp"

class Brain
{
    private:
      LEDManagerInterface *ledManager;
      WifiConnectorInterface *wifi;
      SensorInterface *sensor;
      int status = -1;
      int cont = 0;

    public:
      Brain(LEDManagerInterface *ledManager, WifiConnectorInterface *wifi, SensorInterface *sensor);

      void setup(char* ssid, char* password);

      int runProgram();
};

#endif
