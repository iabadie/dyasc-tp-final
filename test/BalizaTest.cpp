// Libs
#include "gtest/gtest.h"

// Classes
#include "../src/Sensor.h"

// Mocks
#include "MockHttpClient.h"

// get status test from sensor class mocking http response
TEST(Sensor, getBuildStatusResultIsOK)
{
	// Instancing
	MockHttpClient mockHttpClient = new MockHttpClient();
	Sensor sensor = new Sensor(mockHttpClient);

	// Mocked expected actions
	EXPECT_CALL(mockResponse, GET())
	.Times(1)
	.WillOnce(Return(1));

	EXPECT_CALL(mockResponse, getString())
		.Times(1)
		.WillOnce(Return("\"status\": \"passed\","));

	EXPECT_CALL(mockResponse, end())
		.Times(1)
		.WillOnce(Return());

	// Sensor action to get build status
    String res = sensor.getStatus();

    // Assertion
    ASSERT_EQ(res, "passed");

    delete mockHttpClient;
    delete sensor;
}

TEST(Sensor, getBuildStatusResultIsCreated)
{
	// Instancing
	MockHttpClient mockHttpClient = new MockHttpClient();
	Sensor sensor = new Sensor(mockHttpClient);

	// Mocked expected actions
	EXPECT_CALL(mockResponse, GET())
	.Times(1)
	.WillOnce(Return(1));

	EXPECT_CALL(mockResponse, getString())
		.Times(1)
		.WillOnce(Return("\"status\": \"created\","));

	EXPECT_CALL(mockResponse, end())
		.Times(1)
		.WillOnce(Return());

	// Sensor action to get build status
    String res = sensor.getStatus();

    // Assertion
    ASSERT_EQ(res, "created");

    delete mockHttpClient;
    delete sensor;
}

TEST(Sensor, getBuildStatusResultIsFailed)
{
	// Instancing
	MockHttpClient mockHttpClient = new MockHttpClient();
	Sensor sensor = new Sensor(mockHttpClient);

	// Mocked expected actions
	EXPECT_CALL(mockResponse, GET())
	.Times(1)
	.WillOnce(Return(1));

	EXPECT_CALL(mockResponse, getString())
		.Times(1)
		.WillOnce(Return("\"status\": \"failed\","));

	EXPECT_CALL(mockResponse, end())
		.Times(1)
		.WillOnce(Return());

	// Sensor action to get build status
    String res = sensor.getStatus();

    // Assertion
    ASSERT_EQ(res, "failed");

    delete mockHttpClient;
    delete sensor;
}

