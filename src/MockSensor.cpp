#include "SensorInterface.hpp"

class MockSensor : public SensorInterface
{
	public:
		void setHeaders();
		{
		}

		int getIntegerStatus()
		{
			return 1;
		}
}