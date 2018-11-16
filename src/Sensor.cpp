
#include <HTTPClient.h>
#include "Sensor.h"

Sensor::Sensor()
{
    HTTPClient _http;
}

// TODO fix this commented code to support mocked http client for test
// Sensor::Sensor(HTTPClient httpClient)
// {
//     _http = httpClient;
// }

void Sensor::setHeaders(String repoNumber, String token)
{
    // String repoNumber = "21899657"; //repoNumber;
    // String token = "493t8B9EqYnLeuRYjwJ5YQ"; //token;
    //21286906
    //493t8B9EqYnLeuRYjwJ5YQ

    _http.begin("https://api.travis-ci.org/repo/" + repoNumber + "/builds?limit=1");
    _http.addHeader("Travis-API-Version", "3");
    _http.addHeader("Authorization", "token " + token);
    Serial.println("Setee el header");
}

String Sensor::getStatus()
{
    int httpCode = _http.GET();
    if (httpCode > 0)
    {
        String payload = _http.getString();
        int start = payload.indexOf("state") + 9;
        int end = payload.indexOf(",", start) - 1;
        _status = payload.substring(start, end);
    }
    else {
        Serial.println("Error on HTTP request");
    }
    _http.end(); //Free the resources
    return _status;
}
