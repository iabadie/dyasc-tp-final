#ifndef SENSOR_H_
#define SENSOR_H_

#include "SensorInterface.hpp"
#include "CiInterface.hpp"

class Sensor : public SensorInterface
{
    private:
      int _status = -1;  // -1 representa casos que no matchea con los status deseados
      String _repoNumber;
      String _token;
      CiInterface* _http;
      int integerStatus = 3;

    public:
      Sensor();

      Sensor(CiInterface* httpClient);

      void setHeaders();

      int getStatus();

      //Tuve que meter este para que reciba el string. Solo implementado en Sensor.h
      int setIntegerStatus(String status);
};

#endif
