#include <gmock/gmock.h>
#include "IBank.h"

class MockBank : public IBank {
public:
    MOCK_METHOD(void, handleMenu, (), (override));
    MOCK_METHOD(bool, login, (Constants::UserRole), (override));
};