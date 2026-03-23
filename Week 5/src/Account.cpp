#include "Account.h"
#include "Bank.h"

bool Account::deposit(double amount) {
    bool isSuccessful = true;

    if (amount <= 0) 
    {
        isSuccessful = false;
    }
    else
    {
        balance += amount;
        
        Transaction transaction(Constants::TransactionType::DEPOSIT, amount, balance);
        transactions.push_back(transaction); 
    }
    
    return isSuccessful;
}

bool Account::withdrawal(double amount) {
    bool isSuccessful = true;

    if (amount <= 0 || balance < amount) 
    {
        isSuccessful = false;
    }
    else
    {
        balance -= amount;
    
        Transaction transaction(Constants::TransactionType::WITHDRAWAL, amount, balance);
        transactions.push_back(transaction); 
    }
    
    return isSuccessful;
}
