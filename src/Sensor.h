#ifndef SENSOR_H_
#define SENSOR_H_

#include <HTTPClient.h>

class Sensor
{
    private:
      String _status;
      String _repoNumber;
      String _token;
      HTTPClient _http;

    public:
      Sensor();

      void setHeaders();

      String getStatus();
};

#endif
