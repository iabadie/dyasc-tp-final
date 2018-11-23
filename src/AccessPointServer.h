#ifndef ACCESSPOINTSERVER_H_
#define ACCESSPOINTSERVER_H_

#include "AccessPointServerInterface.hpp"
#include <WiFi.h>

class AccessPointServer : public AccessPointServerInterface
{
    public:
      AccessPointServer();

      void setup();

      void checkServer();

      void getNetName(char* text);

      void getPass(char* text);

      void getRepoNumber(char* text);

      void getToken(char* text);
};

#endif
