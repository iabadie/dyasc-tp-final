#ifndef BRAIN_H_
#define BRAIN_H_

#include "WifiConnector.h"
#include "LEDManager.h"
#include "Sensor.h"

class Brain
{
    private:
      LEDManager *ledManager;
      WifiConnector *wifi;
      Sensor *sensor;
      int status = -1;
      int cont = 0;

    public:
      Brain(LEDManager *ledManager, WifiConnector *wifi, Sensor *sensor);

      void setup(char* ssid, char* password);

      void runProgram();
};

#endif
