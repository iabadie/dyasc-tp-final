#include <Arduino.h>
#include "LEDManager.h"

LEDManager::LEDManager(){}

void LEDManager::encenderLED(String status)
{
    if (status.equals("passed"))
    {
      Serial.println(status);
    }
    if (status.equals("failed"))
    {
      Serial.println(status);
    }
}
