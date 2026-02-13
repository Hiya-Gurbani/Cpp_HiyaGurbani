#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    inline static const std::string MSG_BANK_MENU = 
    "\n=============== WELCOME ===============\n"
    "1. Login as an Admin\n"
    "2. Login as a Customer\n"
    "3. Exit\n"
    "========================================\n";
    
    inline static const std::string MSG_ADMIN_OPERATIONS_MENU = 
    "\n=============== ADMIN OPERATIONS ===============\n"
    "1. Register Customer\n"
    "2. View All Customers\n"
    "3. View All Accounts\n"
    "4. Search Customer via Account\n"
    "5. Search Account via Number\n"
    "6. Edit User Details\n"
    "7. Delete Customer\n"
    "8. Delete Account\n"
    "9. Logout\n"
    "================================================\n";

    inline static const std::string MSG_CUSTOMER_OPERATIONS_MENU = 
    "\n=============== CUSTOMER OPERATIONS ===============\n"
    "1. Deposit\n"
    "2. Withdraw\n"
    "3. Check Balance\n"
    "4. Mini Statement\n"
    "5. Bank Statement\n"
    "6. Exit\n"
    "====================================================\n";

    inline static const std::string MSG_INPUT_CHOICE = "\nEnter your choice: ";
    inline static const std::string MSG_PROGRAM_EXIT = "\nThank you for banking with us!\n";
    inline static const std::string MSG_ADMIN_LOGIN = "\n===== ADMIN LOGIN =====\n";
    inline static const std::string MSG_ENTER_USERNAME = "Enter username: ";
    inline static const std::string MSG_ENTER_PASSWORD = "Enter password: ";
    inline static const std::string MSG_CUSTOMER_LOGIN = "\n===== CUSTOMER LOGIN =====\n";
    inline static const std::string MSG_ENTER_ACCOUNT_NUMBER = "Enter account number: ";
    inline static const std::string MSG_ENTER_ACCOUNT_PIN = "Enter account pin: ";

    inline static const std::string MSG_LOGIN_SUCCESS = "Login Successful!\n";
    inline static const std::string MSG_LOGIN_FAILED = "Login Failed! Invalid Credentials.\n";
    inline static const std::string MSG_LEFT_ATTEMPTS = "Attempts Left: ";
    inline static const std::string MSG_ACCESS_DENIED = "Maximum login attempts reached. Access denied.\n";
    
    inline static const std::string MSG_INVALID_NUMBER = "Invalid Input. Please enter a number: ";
    inline static const std::string MSG_INVALID_INTEGER = "Invalid Input. Please enter an integer: ";
    inline static const std::string MSG_OUT_OF_RANGE = "Invalid Value. Please enter an integer in range: ";
    inline static const std::string MSG_LOGOUT = "\nYou have successfully logged out!\n";

    inline static const std::string MSG_INVALID_CHOICE = "Invalid Choice! Please choose an option from menu.\n";
    


};

#endif
