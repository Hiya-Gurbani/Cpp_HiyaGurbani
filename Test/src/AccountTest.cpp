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

// Constructor Test

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
    EXPECT_TRUE(account.verifyPin("4321"));
}

TEST_F(AccountTest, VerifyIncorrectPin_ReturnsFalse) {
    EXPECT_FALSE(account.verifyPin("0000"));
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

// Invalid Transaction Limits for Deposit and Withdraw

class AccountInvalidAmountTest : public AccountTest, 
    public ::testing::WithParamInterface<double> {};

INSTANTIATE_TEST_SUITE_P(InvalidAmounts, AccountInvalidAmountTest,
    ::testing::Values(
        Constants::MIN_TRANSACTION_AMOUNT - 1,
        Constants::MAX_TRANSACTION_AMOUNT + 1
    )
);

TEST_P(AccountInvalidAmountTest, Deposit_InvalidAmount_ReturnsFalse) {
    EXPECT_FALSE(account.deposit(GetParam()));
}

TEST_P(AccountInvalidAmountTest, Deposit_InvalidAmount_BalanceUnchanged) {
    account.deposit(GetParam());
    EXPECT_EQ(account.getBalance(), 1000.0);
}

TEST_P(AccountInvalidAmountTest, Deposit_InvalidAmount_NoTransactionRecorded) {
    account.deposit(GetParam());
    EXPECT_TRUE(account.getTransactions().empty());
}

TEST_P(AccountInvalidAmountTest, Withdrawal_InvalidAmount_ReturnsFalse) {
    EXPECT_FALSE(account.withdrawal(GetParam()));
}

TEST_P(AccountInvalidAmountTest, Withdrawal_InvalidAmount_BalanceUnchanged) {
    account.withdrawal(GetParam());
    EXPECT_EQ(account.getBalance(), 1000.0);
}

TEST_P(AccountInvalidAmountTest, Withdrawal_InvalidAmount_NoTransactionRecorded) {
    account.withdrawal(GetParam());
    EXPECT_TRUE(account.getTransactions().empty());
}

// Get Last Transactions

TEST_F(AccountTest, EmptyAccountTransactions_ReturnsEmptyVector) {
    EXPECT_TRUE(account.getLastTransactions(5).empty());
}

TEST_F(AccountTest, FewerThanCountTransactions_ReturnsAll) {
    account.deposit(100.0);
    account.deposit(200.0);
    EXPECT_EQ(account.getLastTransactions(5).size(), 2);
}

TEST_F(AccountTest, EqualToCountTransactions_ReturnsAll) {
    account.deposit(100.0);
    account.withdrawal(500.0);
    account.deposit(200.0);
    EXPECT_EQ(account.getLastTransactions(3).size(), 3);
}

TEST_F(AccountTest, MoreThanCountTransactions_ReturnLastTransactions) {
    account.deposit(100.0);
    account.withdrawal(500.0);
    account.deposit(200.0);

    std::vector<Transaction> result = account.getLastTransactions(2);
    ASSERT_EQ(result.size(), 2);
    EXPECT_EQ(result[0].getAmount(), 500.0);
    EXPECT_EQ(result[1].getAmount(), 200.0);
}
