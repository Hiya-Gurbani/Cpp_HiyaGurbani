#include "CustomerController.h"
#include "Bank.h"
#include "Logger.h"
#include "Constants.h"
#include "InputHandler.h"
#include <iostream>
#include <iomanip>

void CustomerController::performDeposit(Customer& customer) {
    double amount;
    std::cout << "Enter the amount you want to deposit: ";
    InputHandler::inputValue(amount);
    customer.getAccount().setBalance(customer.getAccount().getBalance() + amount);

    //Create and add transaction
    Transaction transaction(Constants::TransactionType::DEPOSIT, amount, customer.getAccount().getBalance());
    customer.getAccount().addTransaction(transaction);

    std::cout << "Deposited Money! Balance after transaction: " 
    << customer.getAccount().getBalance() << "\n";
}

void CustomerController::performWithdrawal(Customer& customer) {
    double amount;
    std::cout << "Enter the amount you want to withdraw: ";
    InputHandler::inputValue(amount);

    if (customer.getAccount().getBalance() >= amount)
    {
        customer.getAccount().setBalance(customer.getAccount().getBalance() - amount);
        //Create and add transaction
        Transaction transaction(Constants::TransactionType::WITHDRAWAL, amount, customer.getAccount().getBalance());
        customer.getAccount().addTransaction(transaction);

        std::cout << "Withdrawed Money! Balance after transaction: " 
        << customer.getAccount().getBalance();
    }
    else
    {
        std::cout << "You do not have enough balance for this!\n";
    }
}

void CustomerController::displayMiniStatement(Customer& customer) {
    auto& transactions = customer.getAccount().getTransactions();
    int size = transactions.size();

    std::cout << "\n========== Mini Statement (Last 5 Transactions) ==========\n";
    std::cout << std::setw(5) << "ID" 
            << std::setw(12) << "Type" 
            << std::setw(10) << "Amount" 
            << std::setw(15) << "Post Balance" << "\n";

    int start = (size > 5) ? size - 5 : 0;

    for (int index = start; index < size; index++) 
    {
        Transaction& transaction = transactions[index];
        std::cout << std::setw(5) << transaction.getId()
             << std::setw(12) << (transaction.getType() == 
             Constants::TransactionType::DEPOSIT ? "Deposit" : "Withdrawal")
             << std::setw(10) << transaction.getAmount()
             << std::setw(15) << transaction.getPostBalance() << "\n";
    }
    std::cout << "===========================================================\n";
}

void CustomerController::displayBankStatement(Customer& customer) {
    auto& transactions = customer.getAccount().getTransactions();

    std::cout << "\n=============== Full Bank Statement ===============\n";
    std::cout << std::setw(5) << "ID" 
         << std::setw(12) << "Type" 
         << std::setw(10) << "Amount" 
         << std::setw(15) << "Post Balance" 
         << std::setw(15) << "Date" << "\n";

    for (Transaction& transaction : transactions) 
    {
        std::cout << std::setw(5) << transaction.getId()
             << std::setw(12) << (transaction.getType() == 
             Constants::TransactionType::DEPOSIT ? "Deposit" : "Withdrawal")
             << std::setw(10) << transaction.getAmount()
             << std::setw(15) << transaction.getPostBalance() << "\n";
    }
    std::cout << "==================================================\n";
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
        std::cout << "Your current balance is: " << customer.getAccount().getBalance();
        break;

        case 4:
        displayMiniStatement(customer);
        break;

        case 5:
        displayBankStatement(customer);
        break;

        case 6:
        continueProgram = false;
    }
    
    return continueProgram;
}

void CustomerController::handleMenu(Customer& customer) {
    int choice;

    while (true)
    {
        std::cout << Logger::MSG_CUSTOMER_OPERATIONS_MENU;
        std::cout << Logger::MSG_INPUT_CHOICE;

        InputHandler::inputValue(choice);
        if (!handleChoice(choice, customer))
        {
            std::cout << Logger::MSG_LOGOUT;
            return;
        }
    }
}
