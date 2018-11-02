#include "gtest/gtest.h"
#include "../src/Sensor.h"

TEST(Sensor, getStatus)
{


    String res = getStatus();

    ASSERT_TRUE(res.equals("passed"));
}

TEST(Sensor, getStatus)
{
    String res;
    res = getStatus();
    ASSERT_TRUE(res.equals("failed"));
}

TEST(Sensor, getStatus)
{
    String res;
    res = getStatus();
    ASSERT_TRUE(res.equals("created"));
}
