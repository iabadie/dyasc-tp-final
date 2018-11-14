#ifndef SENSOR_H_
#define SENSOR_H_

#include "CiInterface.hpp"

class Sensor
{
    private:
      String _status;
      String _repoNumber;
      String _token;
      CiInterface* _http;

    public:
      Sensor();

      Sensor(CiInterface& httpClient);

      void setHeaders();

      String getStatus();
};

#endif
