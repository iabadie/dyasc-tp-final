#ifndef INTERFACEWIFI_H_
#define INTERFACEWIFI_H_

using namespace std;

class InterfaceWifi
{
	public:
    int CONNECTED;
    virtual ~InterfaceWifi();
    virtual void begin(char* ssid, char* password) = 0;
    virtual int status() = 0;
    virtual void applyDelay() = 0;
    virtual void print(char* output) = 0;
};

#endif
