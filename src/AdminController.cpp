#include "AdminController.h"
#include "Logger.h"
#include "InputHandler.h"
#include "Customer.h"
#include "Bank.h"
#include <iostream>
#include <iomanip>

void AdminController::registerCustomer() {
    std::cout << "===== REGISTER NEW CUSTOMER =====\n";

    std::string name, phone, email;
    
    std::cout << "Customer Name: ";
    InputHandler::inputString(name);

    std::cout << "Customer Email: ";
    InputHandler::inputString(email);
    
    std::cout << "Customer Phone Number: ";
    InputHandler::inputString(phone);
    
    Customer& newCustomer = bank->createCustomer(name, email, phone);
    
    std::cout << "\nCustomer registered successfully!\n";
    std::cout << "Account Number: " << newCustomer.getAccount().getAccountNumber() << "\n";
    // std::cout << "PIN: " << newCustomer.getAccount().getPin() << "\n";
}

void AdminController::viewAllCustomers() {
    std::vector<Customer>& customers = bank->getCustomers();
    
    if (customers.empty()) {
        std::cout << "\nNo customers found.\n";
        return;
    }
    
    std::cout << "\n===== LIST OF ALL CUSTOMERS =====\n";
    std::cout << "Total Customers: " << customers.size() << "\n\n";
    
    for (auto& customer : customers) {
        customer.displayInformation();
        std::cout << "----------------------------\n";
    }
}

void AdminController::viewAllAccounts() {
    std::vector<Customer>& customers = bank->getCustomers();
    
    if (customers.empty()) {
        std::cout << "\nNo accounts found.\n";
        return;
    }
    
    std::cout << "\n===== LIST OF ALL ACCOUNTS =====\n";
    std::cout << "Total Accounts: " << customers.size() << "\n\n";
    
    for (auto& customer : customers) {
        customer.displayAccountDetails();
        std::cout << "----------------------------\n";
    }
}

void AdminController::searchCustomerByAccountNumber() {
    std::cout << "\n===== SEARCH CUSTOMER BY ACCOUNT =====\n";
    
    std::string accountNumber;
    std::cout << "Enter Account Number: ";
    InputHandler::inputString(accountNumber);
    
    Customer* customer = bank->findCustomerByAccountNumber(accountNumber);
    
    if (customer) 
    {
        std::cout << "\nCustomer Found!\n";
        customer->displayInformation();
    } 
    else 
    {
        std::cout << "\nNo customer found with account number: " << accountNumber << "\n";
    }
}

void AdminController::searchAccountByNumber() {
    std::cout << "\n===== SEARCH ACCOUNT BY NUMBER =====\n";
    
    std::string accountNumber;
    std::cout << "Enter Account Number: ";
    InputHandler::inputString(accountNumber);
    
    Customer* customer = bank->findCustomerByAccountNumber(accountNumber);
    
    if (customer) 
    {
        std::cout << "\nAccount Found!\n";
        customer->displayAccountDetails();
    } 
    else 
    {
        std::cout << "\nNo account found with account number: " << accountNumber << "\n";
    }
}

//Break this function
void AdminController::editCustomerAccountDetails() {
    std::cout << "\n===== EDIT CUSTOMER DETAILS =====\n";
    
    std::string accountNumber;
    std::cout << "Enter Account Number: ";
    InputHandler::inputString(accountNumber);
    
    Customer* customer = bank->findCustomerByAccountNumber(accountNumber);
    
    if (!customer) 
    {
        std::cout << "\nCustomer not found!\n";
    }
    else
    {
        std::cout << "\nCurrent Details:\n";
        customer->displayInformation();

        std::cout << "\n--- What would you like to edit? ---\n";
        std::cout << "1. Name\n";
        std::cout << "2. Email\n";
        std::cout << "3. Phone\n";
        std::cout << "4. PIN\n";
        std::cout << "5. Cancel\n";
        std::cout << "Enter choice: ";

        int choice;
        InputHandler::inputValue(choice);
        
        std::string newValue;
        
        switch (choice) {
            case 1:
                std::cout << "Enter new name: ";
                InputHandler::inputString(newValue);
                customer->setName(newValue);
                std::cout << "Name updated!\n";
                break;
                
            case 2:
                std::cout << "Enter new email: ";
                InputHandler::inputString(newValue);
                customer->setEmail(newValue);
                std::cout << "Email updated!\n";
                break;
                
            case 3:
                std::cout << "Enter new phone: ";
                InputHandler::inputString(newValue);
                customer->setPhone(newValue);
                std::cout << "Phone updated!\n";
                break;
                
                //VALIDATION--------
            case 4:
                std::cout << "Enter new PIN (4 digits): ";
                InputHandler::inputString(newValue);
                customer->getAccount().setPin(newValue);
                std::cout << "PIN updated!\n";

                //Validate in validator
                // if (newValue.length() == 4 && std::all_of(newValue.begin(), newValue.end(), ::isdigit)) 
                // {
                //     customer->getAccount().setPin(newValue);
                //     std::cout << "PIN updated!\n";
                // } 
                // else 
                // {
                //     std::cout << "Invalid PIN! Must be 4 digits.\n";
                // }
                break;
                
            case 5:
                std::cout << "Edit cancelled.\n";
                break;
                
            default:
                std::cout << "Invalid choice!\n";
        }
    }
    
}

void AdminController::deleteCustomer() {
    std::cout << "\n===== DELETE CUSTOMER =====\n";
    
    std::string accountNumber;
    std::cout << "Enter Account Number of customer to delete: ";
    InputHandler::inputString(accountNumber);
    
    Customer* customer = bank->findCustomerByAccountNumber(accountNumber);
    
    if (!customer) 
    {
        std::cout << "\nCustomer not found!\n";
    }
    else
    {
        double balance = customer->getAccount().getBalance();
        if (balance > 0) 
        {
            std::cout << "\nCannot delete customer with remaining balance: " 
                    << std::setprecision(2) << balance << "\n";
            std::cout << "Please withdraw all funds before deletion.\n";
        }
        else
        {
            bank->deleteCustomerFromBank(accountNumber);
            std::cout << "Customer Deleted Successfully!\n";
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
        std::cout << "\n===== DELETE ACCOUNT =====\n";
        std::cout << "Note: Deleting an account will also remove the customer.\n";
        deleteCustomer(); 
        break;

        case 9:
        continueProgram = false;
        break;

        default:
        std::cout << Logger::MSG_INVALID_CHOICE;
    }
    
    return continueProgram;
}

void AdminController::handleMenu() {
    int choice;

    while (true)
    {
        std::cout << Logger::MSG_ADMIN_OPERATIONS_MENU;
        std::cout << Logger::MSG_INPUT_CHOICE;

        InputHandler::inputValue(choice);
        if (!handleChoice(choice))
        {
            std::cout << Logger::MSG_LOGOUT;
            return;
        }
    }
}
