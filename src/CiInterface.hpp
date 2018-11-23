#ifndef CiInterface_H_
#define CiInterface_H_

#include <Arduino.h>

using namespace std;

class CiInterface
{
	public:
	 virtual void begin(String repoNumber) = 0;
	 virtual void addHeaders(String token) = 0;
	 virtual int GET() = 0;
	 virtual String getString() = 0;
	 virtual void end() = 0;
};

#endif
