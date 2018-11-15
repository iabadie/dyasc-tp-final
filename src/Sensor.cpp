#include <HTTPClient.h>
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
