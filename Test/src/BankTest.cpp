#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Bank.h"
#include "MockLoginHandler.h"

class BankLoginTest : public ::testing::Test {
protected:
    MockLoginHandler mockAdminLogin;
    MockLoginHandler mockCustomerLogin;
    Bank bank{&mockAdminLogin, &mockCustomerLogin};
};

// Admin Login

TEST_F(BankLoginTest, AdminLogin_SuccessOnFirstAttempt_ReturnsTrue) {
    EXPECT_CALL(mockAdminLogin, login())
        .WillOnce(::testing::Return(Constants::LoginResult::SUCCESS));

    EXPECT_TRUE(bank.login(Constants::UserRole::ADMIN));
}

TEST_F(BankLoginTest, AdminLogin_FailsThenSucceeds_ReturnsTrue) {
    EXPECT_CALL(mockAdminLogin, login())
        .WillOnce(::testing::Return(Constants::LoginResult::FAILED))
        .WillOnce(::testing::Return(Constants::LoginResult::SUCCESS));

    EXPECT_TRUE(bank.login(Constants::UserRole::ADMIN));
}

TEST_F(BankLoginTest, AdminLogin_ExhaustsAllAttempts_ReturnsFalse) {
    EXPECT_CALL(mockAdminLogin, login())
        .Times(Constants::MAX_LOGIN_ATTEMPTS)
        .WillRepeatedly(::testing::Return(Constants::LoginResult::FAILED));

    EXPECT_FALSE(bank.login(Constants::UserRole::ADMIN));
}

// Customer Login

TEST_F(BankLoginTest, CustomerLogin_SuccessOnFirstAttempt_ReturnsTrue) {
    EXPECT_CALL(mockCustomerLogin, login())
        .WillOnce(::testing::Return(Constants::LoginResult::SUCCESS));

    EXPECT_TRUE(bank.login(Constants::UserRole::CUSTOMER));
}

TEST_F(BankLoginTest, CustomerLogin_AccountNotFound_ReturnsTrueImmediately) {
    EXPECT_CALL(mockCustomerLogin, login())
        .Times(1)
        .WillOnce(::testing::Return(Constants::LoginResult::ACCOUNT_NOT_FOUND));

    EXPECT_TRUE(bank.login(Constants::UserRole::CUSTOMER));
}

TEST_F(BankLoginTest, CustomerLogin_ExhaustsAllAttempts_ReturnsFalse) {
    EXPECT_CALL(mockCustomerLogin, login())
        .Times(Constants::MAX_LOGIN_ATTEMPTS)
        .WillRepeatedly(::testing::Return(Constants::LoginResult::FAILED));

    EXPECT_FALSE(bank.login(Constants::UserRole::CUSTOMER));
}

// Role Setup

TEST_F(BankLoginTest, AdminRole_UsesAdminHandler_NotCustomerHandler) {
    EXPECT_CALL(mockAdminLogin, login())
        .WillOnce(::testing::Return(Constants::LoginResult::SUCCESS));
    EXPECT_CALL(mockCustomerLogin, login())
        .Times(0);

    bank.login(Constants::UserRole::ADMIN);
}

TEST_F(BankLoginTest, CustomerRole_UsesCustomerHandler_NotAdminHandler) {
    EXPECT_CALL(mockCustomerLogin, login())
        .WillOnce(::testing::Return(Constants::LoginResult::SUCCESS));
    EXPECT_CALL(mockAdminLogin, login())
        .Times(0);

    bank.login(Constants::UserRole::CUSTOMER);
}

// Account Not Found

TEST_F(BankLoginTest, AccountNotFound_DoesNotCountAsFailedAttempt) {
    EXPECT_CALL(mockCustomerLogin, login())
        .Times(1)
        .WillOnce(::testing::Return(Constants::LoginResult::ACCOUNT_NOT_FOUND));

    bank.login(Constants::UserRole::CUSTOMER);
}
