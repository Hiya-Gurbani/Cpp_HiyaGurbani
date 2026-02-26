#include "AdminTest.h"
#include "Constants.h"

// Constructor Tests

TEST_F(AdminTest, Constructor_NameSetCorrectly) {
    EXPECT_EQ(admin.getName(), Constants::ADMIN_NAME);
}

TEST_F(AdminTest, Constructor_RoleSetCorrectly) {
    EXPECT_EQ(admin.getRole(), Constants::UserRole::ADMIN);
}

// Authenticate Admin

TEST_F(AdminTest, CorrectCredentials_AuthenticateReturnsTrue) {
    EXPECT_TRUE(admin.authenticate(Constants::ADMIN_USERNAME, Constants::ADMIN_PASSWORD));
}

TEST_F(AdminTest, WrongUsername_AuthenticateReturnsFalse) {
    std::string input = "wrong";
    EXPECT_FALSE(admin.authenticate(input, Constants::ADMIN_PASSWORD));
}

TEST_F(AdminTest, WrongPassword_AuthenticateReturnsFalse) {
    std::string input = "wrong";
    EXPECT_FALSE(admin.authenticate(Constants::ADMIN_USERNAME, input));
}

TEST_F(AdminTest, BothWrong_AuthenticateReturnsFalse) {
    std::string username = "wrong";
    std::string password = "wrong";
    EXPECT_FALSE(admin.authenticate(username, password));
}

// Getters/Setters

TEST_F(AdminTest, SetName_UpdatesName) {
    std::string newName = "New Admin";
    admin.setName(newName);
    EXPECT_EQ(admin.getName(), newName);
}
