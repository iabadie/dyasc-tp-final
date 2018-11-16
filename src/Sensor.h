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

      Sensor(HTTPClient httpClient);

      void setHeaders(String repoNumber, String token);

      String getStatus();
};

#endif
