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

void LEDManager::turnOffLEDS() {
  digitalWrite(GREEN, LOW);
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
}

void LEDManager::turnOnLED(int status)
{
    turnOffLEDS();
    // Check the different status and react in each condition
    if (status == 1)
    {
      digitalWrite(GREEN, HIGH);
      delay(LONG_DELAY);
      Serial.println("Build Success");
    } else if (status == 0)
    {
      digitalWrite(RED, HIGH);
      delay(SHORT_DELAY);
      digitalWrite(RED, LOW);
      delay(SHORT_DELAY);
      digitalWrite(RED, HIGH);
      Serial.println("Build Failed");
    } else if (status == 2)
    {
      digitalWrite(GREEN, HIGH);
      delay(LONG_DELAY);
      digitalWrite(GREEN, LOW);
      delay(LONG_DELAY);
      digitalWrite(GREEN, HIGH);
      Serial.println("Build Created and processing");
    } else {
      digitalWrite(YELLOW, HIGH);
      delay(SHORT_DELAY);
      digitalWrite(YELLOW, LOW);
      delay(SHORT_DELAY);
      digitalWrite(YELLOW, HIGH);
      Serial.println("Connection failed");
    }
}
