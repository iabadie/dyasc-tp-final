#ifndef LEDMANAGER_H_
#define LEDMANAGER_H_

#include <Arduino.h>

class LEDManager
{
    public:
      LEDManager();

      void encenderLED(String status);
};

#endif
