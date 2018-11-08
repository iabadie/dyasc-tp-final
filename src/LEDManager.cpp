#include <Arduino.h>
#include "LEDManager.h"

int GREEN = 14;
int YELLOW = 26;
int RED = 33;
int SHORT_DELAY = 500; // 0.5 seg
int LONG_DELAY = 1000; // 1 seg

LEDManager::LEDManager(){
  // Declare used pins on outputs to manage the leds
  pinMode (2, OUTPUT);
  pinMode (GREEN, OUTPUT);
  pinMode (YELLOW, OUTPUT);
  pinMode (RED, OUTPUT);
}

void LEDManager::encenderLED(String status)
{
    // Check the different status and react in each condition
    if (status.equals("passed"))
    {
      digitalWrite(GREEN, HIGH);
      delay(LONG_DELAY);
      Serial.println("Build Success");
    }
    if (status.equals("failed"))
    {
      digitalWrite(GREEN, LOW);
      digitalWrite(RED, HIGH);
      delay(LONG_DELAY);
      digitalWrite(RED, LOW);
      delay(LONG_DELAY);
      Serial.println("Build Failed");
    }
    if (status.equals("created"))
    {
      digitalWrite(GREEN, LOW);
      digitalWrite(YELLOW, HIGH);
      delay(SHORT_DELAY);
      digitalWrite(YELLOW, LOW);
      delay(SHORT_DELAY);
      Serial.println("Build Created and processing");
    }
}
