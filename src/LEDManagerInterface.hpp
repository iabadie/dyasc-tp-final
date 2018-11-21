#ifndef LEDMANAGERINTERFACE_H_
#define LEDMANAGERINTERFACE_H_

// Interfaz utilizada para el componente de SENSOR
class LEDManagerInterface
{
    public:
      virtual void turnOnLED(int status);

      virtual void turnOffLEDS();
};

#endif
