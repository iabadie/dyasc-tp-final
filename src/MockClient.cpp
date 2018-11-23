#include "CiInterface.hpp"
#include <String>

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