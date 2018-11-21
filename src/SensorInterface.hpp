#ifndef SensorInterface_H_
#define SensorInterface_H_

#include "CiInterface.hpp"

class SensorInterface
{
    public:
      virtual void setHeaders();
      virtual int getIntegerStatus();
};

#endif
