#ifndef LEDMANAGER_H_
#define LEDMANAGER_H_

#include <Arduino.h>

class LEDManager
{
    public:
      LEDManager();

      void turnOnLED(int status);

      void turnOffLEDS();
};

#endif
