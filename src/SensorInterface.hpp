#ifndef SENSORINTERFACE_H_
#define SENSORINTERFACE_H_

// Interfaz utilizada para el componente de SENSOR
class SensorInterface
{
    public:
      virtual ~SensorInterface() {}
      virtual void setHeaders(char* repoNumber, char* token) = 0;
      virtual int getStatus() = 0;
};

#endif
