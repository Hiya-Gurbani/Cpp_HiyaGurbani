#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "BankingSystem.h"
#include "MockBank.h"

class BankingSystemTest : public ::testing::Test {
protected:
    MockBank mockBank;
    BankingSystem system{&mockBank};
};

TEST_F(BankingSystemTest, Execute_CallsHandleMenuOnce) {
    EXPECT_CALL(mockBank, handleMenu())
        .Times(1);

    system.execute();
}
