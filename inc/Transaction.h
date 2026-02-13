#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Constants.h"
class Bank;

class Transaction {
    long id;
    Constants::TransactionType type;
    double postTransactionBalance;
    double amount;

public:
    Transaction(Constants::TransactionType transactionType, 
        double amount, double postBalance);

    long getId(){ 
        return id; 
    }

    Constants::TransactionType getType() { 
        return type; 
    }

    double getPostBalance() { 
        return postTransactionBalance; 
    }

    double getAmount() { 
        return amount; 
    }

    void setPostBalance(double balance) { 
        postTransactionBalance = balance; 
    }
};

#endif
