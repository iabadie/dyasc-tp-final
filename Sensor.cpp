#include <HTTPClient.h>

class Sensor
{
    private:
    String status;
    String repoNumber;
    String token;
    HTTPClient http;  

    public:

    Sensor()
    {
        this.http = HTTPClient();
    }
    
    void setHeaders()
    {
        this.repoNumber = repoNumber;
        this.token = token;
        //21286906
        //493t8B9EqYnLeuRYjwJ5YQ

        http.begin("https://api.travis-ci.org/repo/" + this.repoNumber + "/builds");
        http.addHeader("Travis-API-Version", "3");
        http.addHeader("Authorization", "token " + this.token);
        Serial.println("Setee el header");
        Serial.println(http.getHeader());
    }

    String getStatus()
    {
        int httpCode = http.GET();
        Serial.println(httpCode);
        if (httpCode > 0) 
        {
            String payload = http.getString();
            Serial.println(payload);
            int start = payload.indexOf("state") + 9;
            int end = payload.indexOf(",", start) - 1;
            this.status = payload.substring(start, end));
        }
        else {
            Serial.println("Error on HTTP request");
        }

        http.end(); //Free the resources

    }
}