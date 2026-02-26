#include "CustomerServiceTest.h"

// Create Customer Test

TEST_F(CustomerServiceTest, CreateCustomer_NameSetCorrectly) {
    EXPECT_EQ(customer->getName(), "Daksh Sharma");
}

TEST_F(CustomerServiceTest, CreateCustomer_EmailSetCorrectly) {
    EXPECT_EQ(customer->getEmail(), "daksh@gmail.com");
}

TEST_F(CustomerServiceTest, CreateCustomer_PhoneSetCorrectly) {
    EXPECT_EQ(customer->getPhone(), "1234567890");
}

TEST_F(CustomerServiceTest, CreateCustomer_InitialBalanceZero) {
    EXPECT_EQ(customer->getAccount().getBalance(), 0.0);
}

TEST_F(CustomerServiceTest, CreateCustomer_AddsToCustomers) {
    EXPECT_THAT(service.getCustomers(), ::testing::SizeIs(1));
}

TEST_F(CustomerServiceTest, CreateMultipleCustomers_AllAdded) {
    service.createCustomer("Disha Jain", "jain@email.com", "0987654321");
    EXPECT_THAT(service.getCustomers(), ::testing::SizeIs(2));
}

TEST_F(CustomerServiceTest, CreateMultipleCustomers_AccountNumbersIncrement) {
    std::string accountNumber = customer->getAccount().getAccountNumber();
    Customer& nextCustomer = service.createCustomer("Disha Jain", "jain@email.com", "0987654321");
    long accountNumber1 = std::stol(accountNumber);
    long accountNumber2 = std::stol(nextCustomer.getAccount().getAccountNumber());
    EXPECT_EQ(accountNumber2, accountNumber1 + 1);
}

// Find Customer Test

TEST_F(CustomerServiceTest, FindExistingAccountNumber_ReturnsNonNullptr) {
    std::string accountNumber = customer->getAccount().getAccountNumber();
    EXPECT_NE(service.findCustomerByAccountNumber(accountNumber), nullptr);
}

TEST_F(CustomerServiceTest, FindExistingAccountNumber_ReturnsCorrectCustomer) {
    std::string accountNumber = customer->getAccount().getAccountNumber();
    Customer* found = service.findCustomerByAccountNumber(accountNumber);
    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->getName(), "Daksh Sharma");
}

TEST_F(CustomerServiceTest, FindNonExistingAccountNumber_ReturnsNullptr) {
    EXPECT_EQ(service.findCustomerByAccountNumber("0000000"), nullptr);
}

TEST_F(CustomerServiceTest, FindAmongMultipleCustomers_FindsCorrectOne) {
    std::string accountNumber = customer->getAccount().getAccountNumber();
    service.createCustomer("Disha Jain", "jain@email.com", "0987654321");
    Customer* found = service.findCustomerByAccountNumber(accountNumber);
    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->getName(), "Daksh Sharma");
}

// Delete Customer

TEST_F(CustomerServiceTest, DeleteExistingCustomer_ReturnsTrue) {
    std::string accountNumber = customer->getAccount().getAccountNumber();
    EXPECT_TRUE(service.deleteCustomerFromBank(accountNumber));
}

TEST_F(CustomerServiceTest, DeleteExistingCustomer_RemovesFromList) {
    std::string accountNumber = customer->getAccount().getAccountNumber();
    service.deleteCustomerFromBank(accountNumber);
    EXPECT_THAT(service.getCustomers(), ::testing::IsEmpty());
}

TEST_F(CustomerServiceTest, DeleteExistingCustomer_CanNoLongerBeFound) {
    std::string accountNumber = customer->getAccount().getAccountNumber();
    service.deleteCustomerFromBank(accountNumber);
    EXPECT_EQ(service.findCustomerByAccountNumber(accountNumber), nullptr);
}

TEST_F(CustomerServiceTest, DeleteNonExistingCustomer_ReturnsFalse) {
    EXPECT_FALSE(service.deleteCustomerFromBank("0000000"));
}

TEST_F(CustomerServiceTest, DeleteAmongMultipleCustomers_OnlyTargetRemoved) {
    std::string accountNumber = customer->getAccount().getAccountNumber();
    service.createCustomer("Disha Jain", "jain@email.com", "0987654321");
    service.deleteCustomerFromBank(accountNumber);
    EXPECT_THAT(service.getCustomers(), ::testing::SizeIs(1));
    EXPECT_EQ(service.getCustomers()[0].getName(), "Disha Jain");
}

TEST_F(CustomerServiceTest, DeleteCustomerWithPositiveBalance_ReturnsFalse) {
    std::string accountNumber = customer->getAccount().getAccountNumber();
    customer->getAccount().setBalance(500.0);
    EXPECT_FALSE(service.deleteCustomerFromBank(accountNumber));
}

TEST_F(CustomerServiceTest, DeleteCustomerWithPositiveBalance_CustomerStillExists) {
    std::string accountNumber = customer->getAccount().getAccountNumber();
    customer->getAccount().setBalance(500.0);
    service.deleteCustomerFromBank(accountNumber);
    EXPECT_NE(service.findCustomerByAccountNumber(accountNumber), nullptr);
}

TEST_F(CustomerServiceTest, DeleteCustomerWithZeroBalance_ReturnsTrue) {
    std::string accountNumber = customer->getAccount().getAccountNumber();
    EXPECT_TRUE(service.deleteCustomerFromBank(accountNumber));
}
