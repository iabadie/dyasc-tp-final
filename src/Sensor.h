#ifndef SENSOR_H_
#define SENSOR_H_

#include "SensorInterface.hpp"
#include "CiInterface.hpp"

class Sensor : public SensorInterface
{
    private:
      String _status;
      String _repoNumber;
      String _token;
      CiInterface* _http;
      int integerStatus = 3;

    public:
      Sensor();

      Sensor(CiInterface* httpClient);

      void setHeaders();

      String getStatus();

      //Tuve que meter este para que reciba el string. Solo implementado en Sensor.h
      void setIntegerStatus(String status);

      //Este lo hereda de la interfaz... Como no recibe ni devuelve String... PODEMOS MOCKEARLO!!
      int getIntegerStatus();
};

#endif
