#ifndef MOCK_LOGIN_HANDLER_H
#define MOCK_LOGIN_HANDLER_H

#include <gmock/gmock.h>
#include "ILoginHandler.h"

class MockLoginHandler : public ILoginHandler {
public:
    MOCK_METHOD(Constants::LoginResult, login, (), (override));
    MOCK_METHOD(void, logout, (), (override));
};

#endif
