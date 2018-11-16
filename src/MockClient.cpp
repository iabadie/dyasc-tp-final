#include <HTTPClient.h>
#include "CiInterface.hpp"

class MockClient : public CiInterface {

	public:
	MockClient(){};

	void begin(String repoNumber)
	{
	}

	void addHeaders(String token)
	{
	}

	int GET()
	{
		return 200;
	}

	String getString()
	{
		return "status:passed";
	}

	void end()
	{
	}

};