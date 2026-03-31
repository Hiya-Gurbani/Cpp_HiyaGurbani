#include "../inc/SharedPointerTest.h"
#include <gmock/gmock.h>

class MockDeleter {
public:
    MOCK_METHOD(void, Call, (int*), ());
    void operator()(int* ptr) { Call(ptr); }
};
