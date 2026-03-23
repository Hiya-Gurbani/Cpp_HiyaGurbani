#ifndef BANKING_SYSTEM_H
#define BANKING_SYSTEM_H

#include "IBank.h"
#include "Bank.h"

class BankingSystem {
    IBank* bank;

public:
    BankingSystem(IBank* currentBank) : bank(currentBank) {}

    void execute() {
        bank->handleMenu();
    }
};

#endif
