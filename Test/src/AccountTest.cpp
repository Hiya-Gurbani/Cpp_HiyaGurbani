#include "Account.h"
#include <gtest/gtest.h>

class AccountTest : public ::testing::Test {
protected:
    Account account;

    void SetUp() override {
        account.setAccountNumber(std::string("12345678"));
        account.setPin("4321");
        account.setBalance(1000.0);
    }
}

// Constructor Test
//See if we have to use fixture
TEST_F(AccountTest, Constructor_BalanceInitializedToZero) {
    Account freshAccount;
    EXPECT_EQ(freshAccount.getBalance(), 0.0);
}

// Setter/Getter Test

TEST_F(AccountTest, SetAccountNumber_UpdatesAccountNumber) {
    std::string newNumber = "99999999";
    account.setAccountNumber(newNumber);
    EXPECT_EQ(account.getAccountNumber(), "99999999");
}

TEST_F(AccountTest, SetValidBalance_UpdatesBalance) {
    account.setBalance(500.0);
    EXPECT_EQ(account.getBalance(), 500.0);
}

TEST_F(AccountTest, SetInvalidBalance_BalanceUnchanged) {
    account.setBalance(-100.0);
    EXPECT_EQ(account.getBalance(), 1000.0);
}

// Verify Pin
TEST_F(AccountTest, VerifyCorrectPin_ReturnsTrue) {
    EXPECT_TRUE(verifyPin("4321"));
}

TEST_F(AccountTest, VerifyIncorrectPin_ReturnsFalse) {
    EXPECT_FALSE(verifyPin("0000"));
}

// Deposit Test
TEST_F(AccountTest, DepositValidAmount_BalanceIncreases) {
    account.deposit(500.0);
    EXPECT_EQ(account.getBalance(), 1500.0);
}

TEST_F(AccountTest, DepositValidAmount_TransactionRecorded) {
    account.deposit(500.0);
    ASSERT_EQ(account.getTransactions().size(), 1);
    EXPECT_EQ(account.getTransactions().back().getType(), Constants::TransactionType::DEPOSIT);
    EXPECT_EQ(account.getTransactions().back().getAmount(), 500.0);
    EXPECT_EQ(account.getTransactions().back().getPostBalance(), 1500.0);
}

// Withdrawal Test
TEST_F(AccountTest, WithdrawalValidAmount_BalanceDecreases) {
    account.withdrawal(200.0);
    EXPECT_EQ(account.getBalance(), 800.0);
}

TEST_F(AccountTest, Withdrawal_ValidAmount_TransactionRecorded) {
    account.withdrawal(200.0);
    ASSERT_EQ(account.getTransactions().size(), 1);
    EXPECT_EQ(account.getTransactions().back().getType(), Constants::TransactionType::WITHDRAWAL);
    EXPECT_EQ(account.getTransactions().back().getAmount(), 200.0);
    EXPECT_EQ(account.getTransactions().back().getPostBalance(), 800.0);
}

TEST_F(AccountTest, WithdrawalExactBalance_BalanceBecomesZero) {
    account.withdrawal(1000.0);
    EXPECT_EQ(account.getBalance(), 0.0);
}

TEST_F(AccountTest, WithdrawalInsufficientBalance_ReturnsFalse) {
    EXPECT_FALSE(account.withdrawal(1500.0));
}

TEST_F(AccountTest, WithdrawalInsufficientBalance_BalanceUnchanged) {
    account.withdrawal(1500.0);
    EXPECT_EQ(account.getBalance(), 1000.0);
}

TEST_F(AccountTest, WithdrawalInsufficientBalance_NoTransactionRecorded) {
    account.withdrawal(1500.0);
    EXPECT_TRUE(account.getTransactions().empty());
}
