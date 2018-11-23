#ifndef LEDMANAGERINTERFACE_H_
#define LEDMANAGERINTERFACE_H_

// Interfaz utilizada para el componente de SENSOR
class LEDManagerInterface
{
    public:
      virtual ~LEDManagerInterface() {}

      virtual void turnOnLED(int status) = 0;

      virtual void turnOffLEDS() = 0;
};

#endif
