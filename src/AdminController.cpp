#include "AdminController.h"
#include "Logger.h"
#include "InputHandler.h"
#include "Customer.h"
#include "Bank.h"
#include "Display.h"
#include "Constants.h"
#include <iostream>
#include <iomanip>

void AdminController::registerCustomer() {
    Display::printMessage(Logger::MSG_REGISTER_CUSTOMER);

    std::string name, phone, email;
    
    Display::printMessage(Logger::MSG_CUSTOMER_NAME);
    InputHandler::inputString(name, Constants::InputType::NAME);

    Display::printMessage(Logger::MSG_CUSTOMER_EMAIL);
    InputHandler::inputString(email, Constants::InputType::EMAIL);
    
    Display::printMessage(Logger::MSG_CUSTOMER_PHONE);
    InputHandler::inputString(phone, Constants::InputType::PHONE);
    
    Customer& newCustomer = bank->createCustomer(name, email, phone);
    
    Display::printMessage(Logger::MSG_CUSTOMER_REGISTERED_SUCCESS);
}

void AdminController::viewAllCustomers() {
    std::vector<Customer>& customers = bank->getCustomers();
    
    if (customers.empty()) 
    {
        Display::printMessage(Logger::MSG_NO_CUSTOMERS_FOUND);
        return;
    }
    
    Display::printMessage(Logger::MSG_LIST_ALL_CUSTOMERS);
    Display::printWithNumber(Logger::MSG_TOTAL_CUSTOMERS, customers.size());
    
    for (auto& customer : customers) {
        customer.displayInformation();
        Display::printMessage(Logger::MSG_SEPARATOR);
    }
}

void AdminController::viewAllAccounts() {
    std::vector<Customer>& customers = bank->getCustomers();
    
    if (customers.empty()) {
        Display::printMessage(Logger::MSG_NO_ACCOUNTS_FOUND);
        return;
    }
    
    Display::printMessage(Logger::MSG_LIST_ALL_ACCOUNTS);
    Display::printWithNumber(Logger::MSG_TOTAL_ACCOUNTS, customers.size());
    
    for (auto& customer : customers) {
        customer.displayAccountDetails();
        Display::printMessage(Logger::MSG_SEPARATOR);
    }
}

void AdminController::searchCustomerByAccountNumber() {
    Display::printMessage(Logger::MSG_SEARCH_CUSTOMER_HEADER);
    
    std::string accountNumber;
    Display::printMessage(Logger::MSG_ENTER_ACCOUNT_NUMBER);
    InputHandler::inputString(accountNumber, Constants::InputType::ACCOUNT_NUMBER);
    
    Customer* customer = bank->findCustomerByAccountNumber(accountNumber);
    
    if (customer) 
    {
        Display::printMessage(Logger::MSG_CUSTOMER_FOUND);
        customer->displayInformation();
    } 
    else 
    {
        Display::printWithValue(Logger::MSG_CUSTOMER_NOT_FOUND_WITH_ACCOUNT, accountNumber);
    }
}

void AdminController::searchAccountByNumber() {
    Display::printMessage(Logger::MSG_SEARCH_ACCOUNT_HEADER);
    
    std::string accountNumber;
    Display::printMessage(Logger::MSG_ENTER_ACCOUNT_NUMBER);
    InputHandler::inputString(accountNumber, Constants::InputType::ACCOUNT_NUMBER);
    
    Customer* customer = bank->findCustomerByAccountNumber(accountNumber);
    
    if (customer) 
    {
        Display::printMessage(Logger::MSG_ACCOUNT_FOUND);
        customer->displayAccountDetails();
    } 
    else 
    {
        Display::printWithValue(Logger::MSG_ACCOUNT_NOT_FOUND_WITH_NUMBER, accountNumber);
    }
}

void AdminController::editCustomerAccountDetails() {
    Display::printMessage(Logger::MSG_EDIT_CUSTOMER);
    
    std::string accountNumber;
    Display::printMessage(Logger::MSG_ENTER_ACCOUNT_NUMBER);
    InputHandler::inputString(accountNumber, Constants::InputType::ACCOUNT_NUMBER);
    
    Customer* customer = bank->findCustomerByAccountNumber(accountNumber);
    
    if (!customer) 
    {
        Display::printMessage(Logger::MSG_CUSTOMER_NOT_FOUND);
    }
    else
    {
        Display::printMessage(Logger::MSG_CURRENT_DETAILS);
        customer->displayInformation();

        Display::printMessage(Logger::MSG_EDIT_MENU);

        int choice;
        InputHandler::inputValue(choice);
        
        std::string newValue;
        
        switch (choice) {
            case 1:
                Display::printMessage(Logger::MSG_ENTER_NEW_NAME);
                InputHandler::inputString(newValue, Constants::InputType::NAME);
                customer->setName(newValue);
                Display::printMessage(Logger::MSG_NAME_UPDATED);
                break;
                
            case 2:
                Display::printMessage(Logger::MSG_ENTER_NEW_EMAIL);
                InputHandler::inputString(newValue, Constants::InputType::EMAIL);
                customer->setEmail(newValue);
                Display::printMessage(Logger::MSG_EMAIL_UPDATED);
                break;
                
            case 3:
                Display::printMessage(Logger::MSG_ENTER_NEW_PHONE);
                InputHandler::inputString(newValue, Constants::InputType::PHONE);
                customer->setPhone(newValue);
                Display::printMessage(Logger::MSG_PHONE_UPDATED);
                break;
                
            case 4:
                Display::printMessage(Logger::MSG_ENTER_NEW_PIN);
                InputHandler::inputString(newValue, Constants::InputType::PIN);
                customer->getAccount().setPin(newValue);
                Display::printMessage(Logger::MSG_PIN_UPDATED);
                break;
                
            case 5:
                Display::printMessage(Logger::MSG_INVALID_CHOICE);
                break;
                
            default:
                std::cout << "Invalid choice!\n";
        }
    }  
}

void AdminController::deleteCustomer() {
    Display::printMessage(Logger::MSG_DELETE_CUSTOMER_HEADER);
    
    std::string accountNumber;
    Display::printMessage(Logger::MSG_ENTER_ACCOUNT_TO_DELETE);
    InputHandler::inputString(accountNumber, Constants::InputType::ACCOUNT_NUMBER);
    
    Customer* customer = bank->findCustomerByAccountNumber(accountNumber);
    
    if (!customer) 
    {
        Display::printMessage(Logger::MSG_CUSTOMER_NOT_FOUND);
    }
    else
    {
        double balance = customer->getAccount().getBalance();
        if (balance > 0) 
        {
            Display::printWithAmount(Logger::MSG_CANNOT_DELETE_WITH_BALANCE, balance);
            Display::printMessage(Logger::MSG_WITHDRAW_FUNDS_FIRST);
        }
        else
        {
            bank->deleteCustomerFromBank(accountNumber);
            Display::printMessage(Logger::MSG_CUSTOMER_DELETED_SUCCESS);
        }
    }
}

bool AdminController::handleChoice(int choice) {
    bool continueProgram = true;

    switch (choice)
    {
        case 1:
        registerCustomer();
        break;

        case 2:
        viewAllCustomers();
        break;

        case 3:
        viewAllAccounts();
        break;

        case 4:
        searchCustomerByAccountNumber();
        break;

        case 5:
        searchAccountByNumber();
        break;

        case 6:
        editCustomerAccountDetails();
        break;

        case 7:
        deleteCustomer();
        break;

        case 8:
        Display::printMessage(Logger::MSG_DELETE_ACCOUNT_HEADER);
        Display::printMessage(Logger::MSG_DELETE_ACCOUNT_NOTE);
        deleteCustomer(); 
        break;

        case 9:
        continueProgram = false;
        break;

        default:
        Display::printMessage(Logger::MSG_INVALID_CHOICE);
    }
    
    return continueProgram;
}

void AdminController::handleMenu() {
    int choice;

    while (true)
    {
        Display::printMessage(Logger::MSG_ADMIN_OPERATIONS_MENU);
        Display::printMessage(Logger::MSG_INPUT_CHOICE);

        InputHandler::inputValue(choice);
        if (!handleChoice(choice))
        {
            std::cout << Logger::MSG_LOGOUT;
            return;
        }
    }
}
