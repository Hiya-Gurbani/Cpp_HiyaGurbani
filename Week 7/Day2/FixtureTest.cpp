TEST(BankTest, Deposit) {
    //Same above two lines
    BankAccount account("Alice");  
    account.deposit(1000);         
    account.deposit(500);
    EXPECT_EQ(account.balance(), 1500);
}

TEST(BankTest, Withdraw) {
    //Same above two lines
    BankAccount account("Alice");  
    account.deposit(1000);         
    account.withdraw(200);
    EXPECT_EQ(account.balance(), 800);
}

class BankAccountTest : public ::testing::Test {
protected:
    void SetUp() override {
        account = new BankAccount("Alice");
        account->deposit(1000);   
    }

    void TearDown() override {
        delete account;           
    }

    BankAccount* account;
};

TEST_F(BankAccountTest, Deposit) {
    account->deposit(500);
    EXPECT_EQ(account->balance(), 1500);
}

TEST_F(BankAccountTest, Withdraw) {
    account->withdraw(200);
    EXPECT_EQ(account->balance(), 800);
}

TEST_F(BankAccountTest, MultipleOperations) {
    account->deposit(500);
    account->withdraw(300);
    EXPECT_EQ(account->balance(), 1200);
}
