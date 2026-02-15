#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    //InputHandler
    inline static const std::string MSG_INVALID_NUMBER = "Invalid Input. Please enter a number: ";
    inline static const std::string MSG_INVALID_INTEGER = "Invalid Input. Please enter an integer: ";
    inline static const std::string MSG_OUT_OF_RANGE = "Invalid Value. Please enter an integer in range: ";
    inline static const std::string MSG_EMPTY_INPUT = "Input cannot be empty! Enter again: ";
    inline static const std::string MSG_ENTER_AGAIN = "Enter again: ";

    //Validator 
    inline static const std::string MSG_INVALID_DIGITS = "Invalid Input. Only digits expected!\n";
    inline static const std::string MSG_INVALID_LENGTH = "Invalid Input. Input should be exactly ";
    inline static const std::string MSG_DIGITS_SUFFIX = " digits!\n";
    inline static const std::string MSG_INVALID_NAME_LENGTH = "Invalid Input. Name should be at least ";
    inline static const std::string MSG_CHARACTERS_SUFFIX = " characters!\n";
    inline static const std::string MSG_INVALID_NAME_CHARS = "Invalid Input. Only alphabets and spaces expected!\nEnter again: ";
    inline static const std::string MSG_EMAIL_NO_AT = "Email must contain '@'.\n";
    inline static const std::string MSG_EMAIL_NO_DOMAIN = "Email must have a domain (e.g., @gmail.com).\n";
    inline static const std::string MSG_INVALID_PASSWORD_LENGTH = "Invalid Input. Password should be at least ";
    
    //Bank
    inline static const std::string MSG_BANK_MENU = 
    "\n=============== WELCOME ===============\n"
    "1. Login as an Admin\n"
    "2. Login as a Customer\n"
    "3. Exit\n"
    "========================================\n";
    inline static const std::string MSG_ADMIN_LOGIN = "\n===== ADMIN LOGIN =====\n";
    inline static const std::string MSG_CUSTOMER_LOGIN = "\n===== CUSTOMER LOGIN =====\n";
    inline static const std::string MSG_ENTER_USERNAME = "Enter username: ";
    inline static const std::string MSG_ENTER_PASSWORD = "Enter password: ";
    inline static const std::string MSG_ENTER_ACCOUNT_NUMBER = "Enter account number: ";
    inline static const std::string MSG_ENTER_ACCOUNT_PIN = "Enter PIN: ";
    inline static const std::string MSG_LOGIN_SUCCESS = "\nLogin successful!\n";
    inline static const std::string MSG_LOGIN_FAILED = "\nLogin failed! Incorrect credentials.";
    inline static const std::string MSG_ACCESS_DENIED = "\nAccess denied! Maximum login attempts exceeded.\n";
    inline static const std::string MSG_LEFT_ATTEMPTS = "\nAttempts remaining: ";
    inline static const std::string MSG_ACCOUNT_NUMBER = "\nAccount Number: ";
    inline static const std::string MSG_PIN = "PIN: ";

    //AdminController
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
    
    inline static const std::string MSG_REGISTER_CUSTOMER = "===== REGISTER NEW CUSTOMER =====\n";
    inline static const std::string MSG_CUSTOMER_NAME = "Customer Name: ";
    inline static const std::string MSG_CUSTOMER_EMAIL = "Customer Email: ";
    inline static const std::string MSG_CUSTOMER_PHONE = "Customer Phone Number: ";
    inline static const std::string MSG_CUSTOMER_REGISTERED_SUCCESS = "\nCustomer registered successfully!\n";

    inline static const std::string MSG_NO_CUSTOMERS_FOUND = "\nNo customers found.\n";
    inline static const std::string MSG_LIST_ALL_CUSTOMERS = "\n===== LIST OF ALL CUSTOMERS =====\n";
    inline static const std::string MSG_TOTAL_CUSTOMERS = "Total Customers: ";
    inline static const std::string MSG_NO_ACCOUNTS_FOUND = "\nNo accounts found.\n";
    inline static const std::string MSG_LIST_ALL_ACCOUNTS = "\n===== LIST OF ALL ACCOUNTS =====\n";
    inline static const std::string MSG_TOTAL_ACCOUNTS = "Total Accounts: ";
    inline static const std::string MSG_SEPARATOR = "----------------------------\n";

    inline static const std::string MSG_SEARCH_CUSTOMER_HEADER = "\n===== SEARCH CUSTOMER BY ACCOUNT =====\n";
    inline static const std::string MSG_CUSTOMER_FOUND = "\nCustomer Found!\n";
    inline static const std::string MSG_CUSTOMER_NOT_FOUND_WITH_ACCOUNT = "\nNo customer found with account number: ";

    inline static const std::string MSG_SEARCH_ACCOUNT_HEADER = "\n===== SEARCH ACCOUNT BY NUMBER =====\n";
    inline static const std::string MSG_ACCOUNT_FOUND = "\nAccount Found!\n";
    inline static const std::string MSG_ACCOUNT_NOT_FOUND_WITH_NUMBER = "\nNo account found with account number: ";

    inline static const std::string MSG_EDIT_CUSTOMER = "\n===== EDIT CUSTOMER DETAILS =====\n";
    inline static const std::string MSG_CURRENT_DETAILS = "\nCurrent Details:\n";
    inline static const std::string MSG_EDIT_MENU = 
        "\n--- What would you like to edit? ---\n"
        "1. Name\n"
        "2. Email\n"
        "3. Phone\n"
        "4. PIN\n"
        "5. Cancel\n"
        "Enter choice: ";

    inline static const std::string MSG_ENTER_NEW_NAME = "Enter new name: ";
    inline static const std::string MSG_ENTER_NEW_EMAIL = "Enter new email: ";
    inline static const std::string MSG_ENTER_NEW_PHONE = "Enter new phone: ";
    inline static const std::string MSG_ENTER_NEW_PIN = "Enter new PIN (4 digits): ";
    inline static const std::string MSG_NAME_UPDATED = "Name updated!\n";
    inline static const std::string MSG_EMAIL_UPDATED = "Email updated!\n";
    inline static const std::string MSG_PHONE_UPDATED = "Phone updated!\n";
    inline static const std::string MSG_PIN_UPDATED = "PIN updated!\n";
    inline static const std::string MSG_EDIT_CANCELLED = "Edit cancelled.\n";
    inline static const std::string MSG_CUSTOMER_NOT_FOUND = "\nCustomer not found!\n";

    inline static const std::string MSG_DELETE_CUSTOMER_HEADER = "\n===== DELETE CUSTOMER =====\n";
    inline static const std::string MSG_ENTER_ACCOUNT_TO_DELETE = "Enter Account Number of customer to delete: ";
    inline static const std::string MSG_CANNOT_DELETE_WITH_BALANCE = "\nCannot delete customer with remaining balance: ";
    inline static const std::string MSG_WITHDRAW_FUNDS_FIRST = "Please withdraw all funds before deletion.\n";
    inline static const std::string MSG_CUSTOMER_DELETED_SUCCESS = "Customer Deleted Successfully!\n";

    inline static const std::string MSG_DELETE_ACCOUNT_HEADER = "\n===== DELETE ACCOUNT =====\n";
    inline static const std::string MSG_DELETE_ACCOUNT_NOTE = "Note: Deleting an account will also remove the customer.\n";

    inline static const std::string MSG_LOGOUT = "\nLogged out successfully!\n";

    //Customer Controller
    inline static const std::string MSG_CUSTOMER_OPERATIONS_MENU = 
    "\n=============== CUSTOMER OPERATIONS ===============\n"
    "1. Deposit\n"
    "2. Withdraw\n"
    "3. Check Balance\n"
    "4. Change Pin\n"
    "5. Mini Statement\n"
    "6. Bank Statement\n"
    "7. Logout\n"
    "====================================================\n";
    inline static const std::string MSG_TRANSACTION_RANGE = "Transaction amount must be between ";
    inline static const std::string MSG_ENTER_DEPOSIT_AMOUNT = "Enter the amount you want to deposit: ";
    inline static const std::string MSG_DEPOSIT_SUCCESS = "\nDeposited Money! Balance after transaction: ";
    inline static const std::string MSG_ENTER_WITHDRAWAL_AMOUNT = "Enter the amount you want to withdraw: ";
    inline static const std::string MSG_WITHDRAWAL_SUCCESS = "\nWithdrawed Money! Balance after transaction: ";
    inline static const std::string MSG_INSUFFICIENT_BALANCE = "You do not have enough balance for this!\n";

    inline static const std::string MSG_CURRENT_BALANCE = "Your current balance is: ";

    inline static const std::string MSG_MINI_STATEMENT_HEADER = "\n========== Mini Statement (Last 5 Transactions) ==========\n";
    inline static const std::string MSG_BANK_STATEMENT_HEADER = "\n================== Full Bank Statement ===================\n";
    inline static const std::string MSG_STATEMENT_FOOTER = "===========================================================\n";
    inline static const std::string MSG_TRANSACTION_TYPE_DEPOSIT = "Deposit";
    inline static const std::string MSG_TRANSACTION_TYPE_WITHDRAWAL = "Withdrawal";

    inline static const std::string MSG_ENTER_OLD_PIN = "Enter old PIN: ";
    inline static const std::string MSG_ENTER_NEW_PIN_CHANGE = "Enter new PIN (4 digits): ";
    inline static const std::string MSG_REENTER_PIN = "Re-enter your PIN: ";
    inline static const std::string MSG_PIN_UPDATED_SUCCESS = "PIN updated!.\n";
    inline static const std::string MSG_LOGGING_OUT = "You are getting logged out. Kindly login again!";
    inline static const std::string MSG_PINS_DO_NOT_MATCH = "PINS do not match. Try again!\n";
    inline static const std::string MSG_INCORRECT_PIN = "Entered PIN is incorrect.\n";
    inline static const std::string MSG_FORGOT_PIN_CONTACT = "If you have forgot the pin, kindly contact your bank\n";

    inline static const std::string MSG_NO_TRANSACTIONS = "\nNo transactions found.\n";

    inline static const std::string MSG_INPUT_CHOICE = "\nEnter your choice: ";
    inline static const std::string MSG_INVALID_CHOICE = "Invalid Choice! Please choose an option from menu.\n";
    inline static const std::string MSG_PROGRAM_EXIT = "\nThank you for banking with us!\n";

    inline static const std::string CLEAR_SCREEN = "clear";

    //Customer
    inline static const std::string MSG_DISPLAY_CUSTOMER_NAME = "Customer Name: ";
    inline static const std::string MSG_DISPLAY_EMAIL = "Email: ";
    inline static const std::string MSG_DISPLAY_PHONE = "Phone: ";
    inline static const std::string MSG_DISPLAY_ACCOUNT_NUMBER = "Account Number: ";
    inline static const std::string MSG_DISPLAY_BALANCE = "Balance: ";

    //Admin
    inline static const std::string MSG_DISPLAY_ADMIN_NAME = "\nAdmin Name: ";
    inline static const std::string MSG_DISPLAY_USERNAME = "Username: ";

    // Transaction headers
    inline static const std::string MSG_TRANSACTION_HEADER_ID = "ID";
    inline static const std::string MSG_TRANSACTION_HEADER_TYPE = "Type";
    inline static const std::string MSG_TRANSACTION_HEADER_AMOUNT = "Amount";
    inline static const std::string MSG_TRANSACTION_HEADER_POSTBAL = "Post Balance";

};

#endif
