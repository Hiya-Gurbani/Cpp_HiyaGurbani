#include "Bank.h"
#include "Logger.h"
#include "InputHandler.h"
#include "Constants.h"
#include "Display.h"
#include <random>
#include <string>

bool Bank::login(Constants::UserRole role) {
    int attempts = 0;
    bool isSuccessful = false;

    ILoginHandler* handler = (role == Constants::UserRole::ADMIN) 
                            ? adminLoginHandler 
                            : customerLoginHandler;

    while (!isSuccessful && attempts < Constants::MAX_LOGIN_ATTEMPTS) 
    {
        Constants::LoginResult loginResult = handler->login();

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
