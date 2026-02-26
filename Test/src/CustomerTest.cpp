#include "Customer.h"
#include <gtest/gtest.h>

class CustomerTest : public ::testing::Test {
protected:
    Customer customer{"Daksh Sharma", "daksh@gmail.com", "6789543210"};

    void SetUp() {
        std::string accountNumber = "12345678";
        customer.getAccount().setAccountNumber(accountNumber);
        customer.getAccount().setPin("4321");
    }
};

// Getters Test

TEST_F(CustomerTest, Constructor_NameSetCorrectly) {
    EXPECT_EQ(customer.getName(), "Daksh Sharma");
}

TEST_F(CustomerTest, Constructor_EmailSetCorrectly) {
    EXPECT_EQ(customer.getEmail(), "daksh@gmail.com");
}

TEST_F(CustomerTest, Constructor_PhoneSetCorrectly) {
    EXPECT_EQ(customer.getPhone(), "6789543210");
}

TEST_F(CustomerTest, Constructor_RoleSetToCustomer) {
    EXPECT_EQ(customer.getRole(), Constants::UserRole::CUSTOMER);
}

// Setters Test

TEST_F(CustomerTest, SetEmail_UpdatesEmail) {
    customer.setEmail("new@email.com");
    EXPECT_EQ(customer.getEmail(), "new@email.com");
}

TEST_F(CustomerTest, SetPhone_UpdatesPhone) {
    customer.setPhone("0987654321");
    EXPECT_EQ(customer.getPhone(), "0987654321");
}

TEST_F(CustomerTest, SetName_UpdatesName) {
    std::string newName = "Disha Sharma";
    customer.setName(newName);
    EXPECT_EQ(customer.getName(), newName);
}

TEST_F(CustomerTest, GetAccount_ReturnsReference) {
    customer.getAccount().deposit(500.0);
    EXPECT_EQ(customer.getAccount().getBalance(), 500.0);
}

// Authentication Test

TEST_F(CustomerTest, CorrectCredentials_AuthenticateReturnsTrue) {
    EXPECT_TRUE(customer.authenticate("12345678", "4321"));
}

TEST_F(CustomerTest, WrongAccountNumber_AuthenticateReturnsFalse) {
    EXPECT_FALSE(customer.authenticate("00000000", "4321"));
}

TEST_F(CustomerTest, WrongPin_AuthenticateReturnsFalse) {
    EXPECT_FALSE(customer.authenticate("12345678", "0000"));
}

TEST_F(CustomerTest, BothWrong_AuthenticateReturnsFalse) {
    EXPECT_FALSE(customer.authenticate("00000000", "0000"));
}

