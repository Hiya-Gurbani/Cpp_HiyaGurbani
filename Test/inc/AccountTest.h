#ifndef ACCOUNT_TEST_H
#define ACCOUNT_TEST_H


#include "Account.h"
#include <gtest/gtest.h>

class AccountTest : public ::testing::Test {
protected:
    Account account;

    void SetUp() override {
        std::string accountNumber = "12345678";
        account.setAccountNumber(accountNumber);
        account.setPin("4321");
        account.setBalance(1000.0);
    }
};

class AccountInvalidAmountTest : public AccountTest,
    public ::testing::WithParamInterface<double> {};

#endif
