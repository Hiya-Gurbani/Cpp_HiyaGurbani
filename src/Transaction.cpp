#include "Transaction.h"
#include "Bank.h"  

Transaction::Transaction(Constants::TransactionType transactionType, 
                        double amount, double postBalance)
    : type(transactionType), amount(amount), 
      postTransactionBalance(postBalance) {
    id = Bank::generateTransactionId(); 
}
