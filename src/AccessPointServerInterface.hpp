#ifndef ACCESSPOINTSERVERINTERFACE_H_
#define ACCESSPOINTSERVERINTERFACE_H_

class AccessPointServerInterface
{
    public:

      virtual ~AccessPointServerInterface() {}

      virtual void setup() = 0;

      virtual void checkServer() = 0;

      virtual void getNetName(char* text) = 0;

      virtual void getPass(char* text) = 0;

      virtual void getRepoNumber(char* text) = 0;

      virtual void getToken(char* text) = 0;
};

#endif
