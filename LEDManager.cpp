#include <Arduino.h>
#include "LEDManager.h"

LEDManager::LEDManager(){}

void LEDManager::encenderLED(String status)
{
    if (status.equals("passed"))
    {
      digitalWrite(2, HIGH);   // Enciende el LED.
      Serial.println("Build Success");
    }
    if (status.equals("failed"))
    {
      digitalWrite(2, HIGH);   // Enciende el LED.
      delay(1000);                          // Espera un segundo.
      digitalWrite(2, LOW);    // Apaga el LED.
      delay(1000);
      Serial.println("Build Failed");
    }
    if (status.equals("created")) // || status.equals("started"))
    {
      digitalWrite(2, HIGH);   // Enciende el LED.
      delay(500);                          // Espera un segundo.
      digitalWrite(2, LOW);    // Apaga el LED.
      delay(500);
      Serial.println("Build Created and processing");
    }
}
