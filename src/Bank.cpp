#include "Bank.h"
#include "Logger.h"
#include "InputHandler.h"
#include "Constants.h"
#include "Display.h"
#include <random>
#include <string>

Constants::LoginResult Bank::adminLogin() {
    Constants::LoginResult result = Constants::LoginResult::FAILED;

    Display::printMessage(Logger::MSG_ADMIN_LOGIN);

    std::string userName;
    Display::printMessage(Logger::MSG_ENTER_USERNAME);
    InputHandler::inputString(userName, Constants::InputType::USERNAME);

    std::string password;
    Display::printMessage(Logger::MSG_ENTER_PASSWORD);
    InputHandler::inputString(password, Constants::InputType::PASSWORD);

    if (admin.authenticate(userName, password))
    {
        result = Constants::LoginResult::SUCCESS;
        Display::printMessage(Logger::MSG_LOGIN_SUCCESS);
        if (!adminController->handleMenu())
        {
            logout();
        }
    } 
    
    return result;
}

Constants::LoginResult Bank::customerLogin() {
    Constants::LoginResult result = Constants::LoginResult::FAILED;

    Display::printMessage(Logger::MSG_CUSTOMER_LOGIN);
    std::string accountNumber;
    Display::printMessage(Logger::MSG_ENTER_ACCOUNT_NUMBER);
    InputHandler::inputString(accountNumber, Constants::InputType::ACCOUNT_NUMBER);

    Customer* customer = customerService.findCustomerByAccountNumber(accountNumber);
    if (!customer)
    {
        Display::printMessage(Logger::MSG_ACCOUNT_DOES_NOT_EXIST);
        result = Constants::LoginResult::ACCOUNT_NOT_FOUND;
    }
    else
    {
        std::string pin;
        Display::printMessage(Logger::MSG_ENTER_ACCOUNT_PIN);
        InputHandler::inputString(pin, Constants::InputType::PIN);

        if (customer->authenticate(accountNumber, pin))
        {
            result = Constants::LoginResult::SUCCESS;
            Display::printMessage(Logger::MSG_LOGIN_SUCCESS);
            if (!customerController->handleMenu(*customer))
            {
                logout();
            }
        }
    }

    return result;
}

bool Bank::login(Constants::UserRole role) {
    int attempts = 0;
    bool isSuccessful = false;

    while (!isSuccessful && attempts < Constants::MAX_LOGIN_ATTEMPTS) 
    {
        Constants::LoginResult loginResult = 
        (role == Constants::UserRole::ADMIN) ? adminLogin() : customerLogin();

        if (loginResult == Constants::LoginResult::ACCOUNT_NOT_FOUND) 
        {
            isSuccessful = true;
            break; 
        }

        if (loginResult == Constants::LoginResult::SUCCESS)
        {
            isSuccessful = true;
        }
        else
        {
            attempts++;
            if (attempts < Constants::MAX_LOGIN_ATTEMPTS) 
            {
                Display::printMessage(Logger::MSG_LOGIN_FAILED);
                Display::printWithNumber(Logger::MSG_LEFT_ATTEMPTS, Constants::MAX_LOGIN_ATTEMPTS - attempts);
            }
        }
    }

    if (!isSuccessful && attempts >= Constants::MAX_LOGIN_ATTEMPTS) 
    {
        Display::printMessage(Logger::MSG_ACCESS_DENIED);
    }

    return isSuccessful;
}

void Bank::logout() {
    Display::clearScreen();
    Display::printMessage(Logger::MSG_LOGOUT);
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
