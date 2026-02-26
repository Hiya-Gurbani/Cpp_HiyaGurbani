#include "Transaction.h"
#include "Constants.h"
#include <gtest/gtest.h>

class TransactionTest : public ::testing::Test {
protected:
    Transaction deposit{Constants::TransactionType::DEPOSIT, 500.0, 1500.0};
    Transaction withdrawal{Constants::TransactionType::WITHDRAWAL, 200.0, 800.0};
};

// Constructor Test
TEST_F(TransactionTest, Constructor_TypeSetCorrectly) {
    EXPECT_EQ(deposit.getType(), Constants::TransactionType::DEPOSIT);
}

TEST_F(TransactionTest, Constructor_AmountSetCorrectly) {
    EXPECT_EQ(deposit.getAmount(), 500.0);
}

TEST_F(TransactionTest, Constructor_PostBalanceSetCorrectly) {
    EXPECT_EQ(deposit.getPostBalance(), 1500.0);
}

// ID Counter
TEST_F(TransactionTest, TransactionId_IsAtLeastInitialValue) {
    EXPECT_GE(deposit.getId(), Constants::INITIAL_TRANSACTION_ID);
}

TEST_F(TransactionTest, ConsecutiveTransactionsId_IncrementByOne) {
    EXPECT_EQ(withdrawal.getId(), deposit.getId() + 1);
}

// PostBalance
TEST_F(TransactionTest, SetPostBalance_UpdatesPostBalance) {
    deposit.setPostBalance(2000.0);
    EXPECT_EQ(deposit.getPostBalance(), 2000.0);
}
