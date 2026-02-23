#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "UserManager.h"

class MockLogger : public ILogger {
public:
    MOCK_METHOD(void, log, (const std::string& message), (override));
};

TEST(UserManagerTest, CreatesUserAndLogs) {
    MockLogger mockLogger;

    EXPECT_CALL(mockLogger, log("User created: Alice"))
        .Times(1);

    UserManager manager(&mockLogger);
    manager.createUser("Alice");
}

TEST(UserManagerTest, LogsCorrectMessageForDifferentUser) {
    MockLogger mockLogger;

    EXPECT_CALL(mockLogger, log("User created: Bob"))
        .Times(1);

    UserManager manager(&mockLogger);
    manager.createUser("Bob");
}
