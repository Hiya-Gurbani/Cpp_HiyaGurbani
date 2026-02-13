#include "CustomerController.h"
#include "Bank.h"
#include "Logger.h"
#include "Constants.h"
#include "Display.h"
#include "InputHandler.h"
#include <iostream>
#include <iomanip>

void CustomerController::performDeposit(Customer& customer) {
    double amount;
    Display::printMessage(Logger::MSG_ENTER_DEPOSIT_AMOUNT);
    InputHandler::inputValue(amount);
    customer.getAccount().setBalance(customer.getAccount().getBalance() + amount);

    Transaction transaction(Constants::TransactionType::DEPOSIT, amount, customer.getAccount().getBalance());
    customer.getAccount().addTransaction(transaction);

    Display::printWithAmount(Logger::MSG_DEPOSIT_SUCCESS, customer.getAccount().getBalance());
}

void CustomerController::performWithdrawal(Customer& customer) {
    double amount;
    Display::printMessage(Logger::MSG_ENTER_WITHDRAWAL_AMOUNT);
    InputHandler::inputValue(amount);

    if (customer.getAccount().getBalance() >= amount)
    {
        customer.getAccount().setBalance(customer.getAccount().getBalance() - amount);
        
        Transaction transaction(Constants::TransactionType::WITHDRAWAL, amount, customer.getAccount().getBalance());
        customer.getAccount().addTransaction(transaction);

        Display::printWithAmount(Logger::MSG_WITHDRAWAL_SUCCESS, customer.getAccount().getBalance());
    }
    else
    {
        Display::printMessage(Logger::MSG_INSUFFICIENT_BALANCE);
    }
}

bool CustomerController::changePin(Customer& customer) {
    bool continueProgram = true;

    std::string pin;
    Display::printMessage(Logger::MSG_ENTER_OLD_PIN);
    InputHandler::inputString(pin, Constants::InputType::PIN);
    if (customer.getAccount().verifyPin(pin))
    {
        std::string confirmPin;
        Display::printMessage(Logger::MSG_ENTER_NEW_PIN_CHANGE);
        InputHandler::inputString(pin, Constants::InputType::PIN);

        Display::printMessage(Logger::MSG_REENTER_PIN);
        InputHandler::inputString(confirmPin, Constants::InputType::PIN);

        if (pin == confirmPin)
        {
            customer.getAccount().setPin(pin);
            Display::printMessage(Logger::MSG_PIN_UPDATED_SUCCESS);
            Display::printMessage(Logger::MSG_LOGGING_OUT);
            continueProgram = false;
        }
        else
        {
            Display::printMessage(Logger::MSG_PINS_DO_NOT_MATCH);
        } 
    }
    else
    {
        Display::printMessage(Logger::MSG_INCORRECT_PIN);
        Display::printMessage(Logger::MSG_FORGOT_PIN_CONTACT);
    }

    return continueProgram;
}

void CustomerController::displayMiniStatement(Customer& customer) {
    std::vector<Transaction>& transactions = customer.getAccount().getTransactions();
    int size = transactions.size();

    if (size == 0) {
        Display::printMessage(Logger::MSG_NO_TRANSACTIONS);
        return;
    }

    Display::printMessage(Logger::MSG_MINI_STATEMENT_HEADER);
    Display::printTransactionHeader();

    int start = (size > 5) ? size - 5 : 0;

    for (int index = start; index < size; index++) 
    {
        Transaction& transaction = transactions[index];
        std::string type = (transaction.getType() == Constants::TransactionType::DEPOSIT) 
                          ? Logger::MSG_TRANSACTION_TYPE_DEPOSIT 
                          : Logger::MSG_TRANSACTION_TYPE_WITHDRAWAL;
        
        Display::printTransactionRow(transaction.getId(), type, 
                                     transaction.getAmount(), 
                                     transaction.getPostBalance());
    }

    Display::printMessage(Logger::MSG_STATEMENT_FOOTER);
}

void CustomerController::displayBankStatement(Customer& customer) {
    std::vector<Transaction>& transactions = customer.getAccount().getTransactions();

    if (transactions.empty()) {
        Display::printMessage(Logger::MSG_NO_TRANSACTIONS);
        return;
    }

    Display::printMessage(Logger::MSG_BANK_STATEMENT_HEADER);
    Display::printTransactionHeader();

    for (Transaction& transaction : transactions) 
    {
        std::string type = (transaction.getType() == Constants::TransactionType::DEPOSIT) 
                          ? Logger::MSG_TRANSACTION_TYPE_DEPOSIT 
                          : Logger::MSG_TRANSACTION_TYPE_WITHDRAWAL;
        
        Display::printTransactionRow(transaction.getId(), type, 
                                     transaction.getAmount(), 
                                     transaction.getPostBalance());
    }

    Display::printMessage(Logger::MSG_STATEMENT_FOOTER);
}

bool CustomerController::handleChoice(int choice, Customer& customer) {
    bool continueProgram = true;

    switch (choice)
    {
        case 1:
            performDeposit(customer);
            break;

        case 2:
            performWithdrawal(customer);
            break;

        case 3:
            Display::printWithAmount(Logger::MSG_CURRENT_BALANCE, customer.getAccount().getBalance());
            break;

        case 4:
        {
            continueProgram = changePin(customer);
            break;
        }    

        case 5:
            displayMiniStatement(customer);
            break;

        case 6:
            displayBankStatement(customer);
            break;

        case 7:
            continueProgram = false;
            break;

        default:
            Display::printMessage(Logger::MSG_INVALID_CHOICE);
    }
    
    return continueProgram;
}

void CustomerController::handleMenu(Customer& customer) {
    int choice;

    while (true)
    {
        Display::printMessage(Logger::MSG_CUSTOMER_OPERATIONS_MENU);
        Display::printMessage(Logger::MSG_INPUT_CHOICE);

        InputHandler::inputValue(choice);
        if (!handleChoice(choice, customer))
        {
            Display::printMessage(Logger::MSG_LOGOUT);
            return;
        }
    }
}
