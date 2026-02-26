#include "BankTest.h"

// Admin Login

TEST_F(BankLoginTest, AdminLoginSuccessOnFirstAttempt_ReturnsTrue) {
    EXPECT_CALL(mockAdminLogin, login())
        .WillOnce(::testing::Return(Constants::LoginResult::SUCCESS));

    EXPECT_TRUE(bank.login(Constants::UserRole::ADMIN));
}

TEST_F(BankLoginTest, AdminLoginFailsThenSucceeds_ReturnsTrue) {
    EXPECT_CALL(mockAdminLogin, login())
        .WillOnce(::testing::Return(Constants::LoginResult::FAILED))
        .WillOnce(::testing::Return(Constants::LoginResult::SUCCESS));

    EXPECT_TRUE(bank.login(Constants::UserRole::ADMIN));
}

TEST_F(BankLoginTest, AdminLoginExhaustsAllAttempts_ReturnsFalse) {
    EXPECT_CALL(mockAdminLogin, login())
        .Times(Constants::MAX_LOGIN_ATTEMPTS)
        .WillRepeatedly(::testing::Return(Constants::LoginResult::FAILED));

    EXPECT_FALSE(bank.login(Constants::UserRole::ADMIN));
}

// Customer Login

TEST_F(BankLoginTest, CustomerLoginSuccessOnFirstAttempt_ReturnsTrue) {
    EXPECT_CALL(mockCustomerLogin, login())
        .WillOnce(::testing::Return(Constants::LoginResult::SUCCESS));

    EXPECT_TRUE(bank.login(Constants::UserRole::CUSTOMER));
}

TEST_F(BankLoginTest, CustomerLoginAccountNotFound_ReturnsTrueImmediately) {
    EXPECT_CALL(mockCustomerLogin, login())
        .Times(1)
        .WillOnce(::testing::Return(Constants::LoginResult::ACCOUNT_NOT_FOUND));

    EXPECT_TRUE(bank.login(Constants::UserRole::CUSTOMER));
}

TEST_F(BankLoginTest, CustomerLoginExhaustsAllAttempts_ReturnsFalse) {
    EXPECT_CALL(mockCustomerLogin, login())
        .Times(Constants::MAX_LOGIN_ATTEMPTS)
        .WillRepeatedly(::testing::Return(Constants::LoginResult::FAILED));

    EXPECT_FALSE(bank.login(Constants::UserRole::CUSTOMER));
}

// Role Setup

TEST_F(BankLoginTest, AdminRoleUsesAdminHandler_NotCustomerHandler) {
    EXPECT_CALL(mockAdminLogin, login())
        .WillOnce(::testing::Return(Constants::LoginResult::SUCCESS));
    EXPECT_CALL(mockCustomerLogin, login())
        .Times(0);

    bank.login(Constants::UserRole::ADMIN);
}

TEST_F(BankLoginTest, CustomerRoleUsesCustomerHandler_NotAdminHandler) {
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
