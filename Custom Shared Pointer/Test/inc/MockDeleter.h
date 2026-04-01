#ifndef MOCK_DELETER_H
#define MOCK_DELETER_H

#include "../inc/SharedPointerTest.h"
#include <gmock/gmock.h>

class MockDeleter {
public:
    MOCK_METHOD(void, Call, (int*), ());
    void operator()(int* ptr) { Call(ptr); }
};

#endif
