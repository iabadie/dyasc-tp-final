#ifndef LEDMANAGER_H_
#define LEDMANAGER_H_

#include "LEDManagerInterface.hpp"

class LEDManager : public LEDManagerInterface
{
    public:
      LEDManager();

      void turnOnLED(int status);

      void turnOffLEDS();
};

#endif
