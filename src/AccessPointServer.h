#ifndef ACCESSPOINTSERVER_H_
#define ACCESSPOINTSERVER_H_

#include <WiFi.h>

class AccessPointServer
{
    public:
      AccessPointServer();

      void setup();

      void checkServer();
};

#endif
