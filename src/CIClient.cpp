#include <HTTPClient.h>
#include "CiInterface.hpp"

class CIClient : public CiInterface {

	private:
		HTTPClient _http;

	public:
	CIClient(){};

	void begin(String repoNumber)
	{
		String str = String("https://api.travis-ci.org/repo/" + repoNumber + "/builds?limit=1");
		_http.begin(str);
	}

	void addHeaders(String token)
	{
		_http.addHeader(String("Travis-API-Version"), String("3"));
    	_http.addHeader(String("Authorization"), String("token ") + token);
	}

	int GET()
	{
		return _http.GET();
	}

	String getString()
	{
		return _http.getString();
	}

	void end()
	{
		_http.end(); //Free the resources
	}
};
