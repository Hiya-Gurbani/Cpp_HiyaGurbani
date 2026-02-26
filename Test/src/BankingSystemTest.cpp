#include "BankingSystemTest.h"

TEST_F(BankingSystemTest, Execute_CallsHandleMenuOnce) {
    EXPECT_CALL(mockBank, handleMenu())
        .Times(1);

    system.execute();
}
