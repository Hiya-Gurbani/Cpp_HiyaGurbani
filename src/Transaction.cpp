#include "Transaction.h"
#include "Bank.h"  

Transaction::Transaction(Constants::TransactionType transactionType, 
                        double amt, double postBalance)
    : type(transactionType), amount(amt), 
      postTransactionBalance(postBalance) {
    id = Bank::generateTransactionId(); 
}