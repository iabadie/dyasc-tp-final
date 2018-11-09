#include <HTTPClient.h>
#include "gmock/gmock.h"

class MockHttpClient : public HTTPClient {
    public:
    MOCK_METHOD0(GET, int());
    MOCK_METHOD0(getString, String());
    MOCK_METHOD0(end, void());
};
