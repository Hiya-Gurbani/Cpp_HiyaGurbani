#include "Bank.h"
#include "Logger.h"
#include "InputHandler.h"
#include "Constants.h"
#include "Display.h"
#include <iostream>
#include <random>
#include <string>

long Bank::accountNumberCounter = 10000000;
long Bank::transactionIdCounter = 1;

std::string Bank::generateRandomPin() {
    static std::random_device randomDevice;     
    static std::mt19937 gen(randomDevice());     
    static std::uniform_int_distribution<> distribution(1000, 9999);

    return std::to_string(distribution(gen));
}

std::string Bank::generateAccountNumber() {
    std::string accountNumber = std::to_string(accountNumberCounter);
    accountNumberCounter++;
    return accountNumber;
}

long Bank::generateTransactionId() {
    return transactionIdCounter++;
}

Customer* Bank::findCustomerByAccountNumber(const std::string& accountNumber) {
    for (auto& customer : customers) 
    {
        if (customer.getAccount().getAccountNumber() == accountNumber) 
        {
            return &customer;
        }
    }
    return nullptr;
}

Customer& Bank::createCustomer(const std::string& name, 
                               const std::string& email, 
                               const std::string& phone) {
    
    Customer newCustomer(name, email, phone);
    
    std::string accountNumber = generateAccountNumber();
    std::string pin = generateRandomPin();
    newCustomer.getAccount().setAccountNumber(accountNumber);
    newCustomer.getAccount().setPin(pin);
    newCustomer.getAccount().setBalance(0.0);
    
    customers.push_back(newCustomer);
    Display::printWithValue(Logger::MSG_ACCOUNT_NUMBER, accountNumber);
    Display::printWithValue(Logger::MSG_PIN, pin);
    
    return customers.back();
}

bool Bank::deleteCustomerFromBank(const std::string& accountNumber) {
    bool isCustomerDeleted = false;

    for (size_t index = 0; index < customers.size(); index++)
    {
        if (customers[index].getAccount().getAccountNumber() == accountNumber)
        {
            customers.erase(customers.begin() + index);
            isCustomerDeleted = true;
        }
    }
    
    return isCustomerDeleted;
}

bool Bank::adminLogin() {
    bool isLoginSuccessful = false;

    Display::printMessage(Logger::MSG_ADMIN_LOGIN);

    std::string userName;
    Display::printMessage(Logger::MSG_ENTER_USERNAME);
    InputHandler::inputString(userName, Constants::InputType::USERNAME);

    std::string password;
    Display::printMessage(Logger::MSG_ENTER_PASSWORD);
    InputHandler::inputString(password, Constants::InputType::PASSWORD);

    if (admin.authenticate(userName, password))
    {
        isLoginSuccessful = true;
        Display::printMessage(Logger::MSG_LOGIN_SUCCESS);
        adminController->handleMenu();
    } 
    
    return isLoginSuccessful;
}

bool Bank::customerLogin() {
    bool isLoginSuccessful = false;

    Display::printMessage(Logger::MSG_CUSTOMER_LOGIN);
    std::string accountNumber;
    Display::printMessage(Logger::MSG_ENTER_ACCOUNT_NUMBER);
    InputHandler::inputString(accountNumber, Constants::InputType::ACCOUNT_NUMBER);

    std::string pin;
    Display::printMessage(Logger::MSG_ENTER_ACCOUNT_PIN);
    InputHandler::inputString(pin, Constants::InputType::PIN);

    for (auto& customer: customers)
    {
        if (customer.authenticate(accountNumber, pin))
        {
            isLoginSuccessful = true;
            Display::printMessage(Logger::MSG_LOGIN_SUCCESS);
            customerController->handleMenu(customer);
            break;
        }
    }

    return isLoginSuccessful;
}

bool Bank::login(Constants::UserRole role) {
    int attempts = 0;
    bool isLoginSuccessful = false;

    while (!isLoginSuccessful && attempts < Constants::MAX_LOGIN_ATTEMPTS) 
    {
        isLoginSuccessful = 
        (role == Constants::UserRole::ADMIN) ? adminLogin() : customerLogin();

        attempts++;

        if (!isLoginSuccessful && attempts < Constants::MAX_LOGIN_ATTEMPTS) 
        {
            Display::printMessage(Logger::MSG_LOGIN_FAILED);
            Display::printAttemptsRemaining(Constants::MAX_LOGIN_ATTEMPTS - attempts);
        }
    }

    if (!isLoginSuccessful) 
    {
        Display::printMessage(Logger::MSG_ACCESS_DENIED);
    }

    return isLoginSuccessful;
}

void Bank::logout() {

}

bool Bank::handleChoice(int choice) {
    bool continueProgram = true;
    bool validChoice = true;
    Constants::UserRole role;

    switch (choice)
    {
        case 1:
            role = Constants::UserRole::ADMIN;
            break;

        case 2:
            role = Constants::UserRole::CUSTOMER;
            break;

        case 3:
            continueProgram = false;
            break;

        default:
            Display::printMessage(Logger::MSG_INVALID_CHOICE);
            validChoice = false;
    }

    if (continueProgram && validChoice)  
    {
        if (!login(role))
        {
            continueProgram = false;
        }
    }
    
    return continueProgram;
}

void Bank::handleMenu() {
    int choice;

    while (true) 
    {
        Display::printMessage(Logger::MSG_BANK_MENU);
        Display::printMessage(Logger::MSG_INPUT_CHOICE);

        InputHandler::inputValue(choice);
        if (!handleChoice(choice))
        {
            Display::printMessage(Logger::MSG_PROGRAM_EXIT);
            return;
        }
    }
}

