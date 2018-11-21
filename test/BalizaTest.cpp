// Libs
#include "gtest/gtest.h"

// Classes
#include "Brain.h"

// Mocks
#include "MockLEDManager.cpp"
#include "MockSensor.cpp"
#include "MockWifiConnector.cpp"

// get status test from sensor class mocking http response
TEST(Test, getBuildStatusResultIsOKAndBrainDoLedManagerTurnGreenStateOn)
{
	// Instancing
	MockHttpClient mockLEDManager = new MockLEDManager();
	MockSensor mockSensor = new MockSensor();
	MockWifiConnector mockWifiConnector = new MockWifiConnector();
	Brain brain = new Brain(mockLEDManager, mockSensor, mockWifiConnector);
	char* net = "net";
	char* pass = "pass";
	// Mocked expected actions
	EXPECT_CALL(mockWifiConnector, connectToWifi(net, pass))
		.Times(1);
		.WillOnce(Return());

	EXPECT_CALL(mockSensor, setHeader())
		.Times(1);
		.WillOnce(Return());

	EXPECT_CALL(mockSensor, getStatus())
		.Times(1)
		.WillOnce(Return(1));


	EXPECT_CALL(mockLEDManager, turnOnLED(1))
		.Times(1)
		.WillOnce(Return());

		// Program actions
		brain.setup("net", "pass");
		int resultStatus = brain.runProgram();

    // Assertion
    ASSERT_EQ(resultStatus, 1);

    delete mockLEDManager;
    delete mockSensor;
		delete mockWifiConnector;
    delete brain;
}

// TEST(Test, getBuildStatusResultIsCreated)
// {
// 	// Instancing
// 	MockHttpClient mockHttpClient = new MockHttpClient();
// 	Sensor sensor = new Sensor(mockHttpClient);
//
// 	// Mocked expected actions
// 	EXPECT_CALL(mockResponse, GET())
// 	.Times(1)
// 	.WillOnce(Return(1));
//
// 	EXPECT_CALL(mockResponse, getString())
// 		.Times(1)
// 		.WillOnce(Return("\"status\": \"created\","));
//
// 	EXPECT_CALL(mockResponse, end())
// 		.Times(1)
// 		.WillOnce(Return());
//
// 	// Sensor action to get build status
//     String res = sensor.getStatus();
//
//     // Assertion
//     ASSERT_EQ(res, "created");
//
//     delete mockHttpClient;
//     delete sensor;
// }
//
// TEST(Test, getBuildStatusResultIsFailed)
// {
// 	// Instancing
// 	MockHttpClient mockHttpClient = new MockHttpClient();
// 	Sensor sensor = new Sensor(mockHttpClient);
//
// 	// Mocked expected actions
// 	EXPECT_CALL(mockResponse, GET())
// 	.Times(1)
// 	.WillOnce(Return(1));
//
// 	EXPECT_CALL(mockResponse, getString())
// 		.Times(1)
// 		.WillOnce(Return("\"status\": \"failed\","));
//
// 	EXPECT_CALL(mockResponse, end())
// 		.Times(1)
// 		.WillOnce(Return());
//
// 	// Sensor action to get build status
//     String res = sensor.getStatus();
//
//     // Assertion
//     ASSERT_EQ(res, "failed");
//
//     delete mockHttpClient;
//     delete sensor;
// }
