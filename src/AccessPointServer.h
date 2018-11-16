#ifndef ACCESSPOINTSERVER_H_
#define ACCESSPOINTSERVER_H_

#include <WiFi.h>

class AccessPointServer
{
    public:
      AccessPointServer();

      void setup();

      void checkServer();

      String getNetName();

      String getPass();

      String getRepoNumber();

      String getToken();
};

#endif
