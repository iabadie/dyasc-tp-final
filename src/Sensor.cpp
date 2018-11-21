#include <HTTPClient.h>
#include "SensorInterface.hpp"
#include "Sensor.h"

Sensor::Sensor(CiInterface* httpClient)
{
    this->_http = httpClient;
}

void Sensor::setHeaders()
{
    String repoNumber = "21899657"; //repoNumber;
    String token = "493t8B9EqYnLeuRYjwJ5YQ"; //token;
    //21286906
    //493t8B9EqYnLeuRYjwJ5YQ

    this->_http->begin(repoNumber);
    this->_http->addHeaders(token);
}

String Sensor::getStatus()
{
    int httpCode = this->_http->GET();
    if (httpCode > 0)
    {
        String payload = this->_http->getString();
        int start = payload.indexOf("state") + 9;
        int end = payload.indexOf(",", start) - 1;
        _status = payload.substring(start, end);
    }
    else {
        Serial.println("Error on HTTP request");
    }
    this->_http->end(); //Free the resources
    return _status;
}

void Sensor::setIntegerStatus(String status)
{
    if (status.equals("passed"))
    {
      integerStatus = 1;
    } else if (status.equals("failed"))
    {
      integerStatus = 0;
    } else if (status.equals("created"))
    {
      integerStatus = 2;
    }else{
        integerStatus = 3;
    }

    return integerStatus;
}

int Sensor::getIntegerStatus()
{
    return integerStatus;
}