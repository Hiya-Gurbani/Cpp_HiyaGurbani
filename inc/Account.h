#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Transaction.h"
#include <string>
#include <vector>

class Account {
    std::string accountNumber;
    std::string pin;
    double balance;
    std::vector<Transaction> transactions;

public:
    Account() : balance{0.0} {}

    const std::string& getAccountNumber() {  
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    std::vector<Transaction>& getTransactions() { 
        return transactions;
    }


    void setPin(const std::string& pin) { 
        this->pin = pin;
    }

    void setAccountNumber(std::string& accountNumber) {
        this->accountNumber = accountNumber;
    }
    
    void setBalance(double balance) {
        if (balance >= 0.0)
        {
            this->balance = balance;
        }
    }

    void addTransaction(const Transaction& transaction) { 
        transactions.push_back(transaction); 
    }

    bool verifyPin(const std::string& inputPin) {
        return (pin == inputPin);
    }

    bool deposit(double amount);
    bool withdrawal(double amount);
};

#endif
