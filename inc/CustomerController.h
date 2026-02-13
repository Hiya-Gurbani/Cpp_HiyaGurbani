#ifndef Customer_CONTROLLER_H
#define Customer_CONTROLLER_H

#include "Customer.h"
class Bank;

class CustomerController {
    Bank* bank;

public:
    CustomerController() {}

    CustomerController(Bank* currentBank) : bank{currentBank} {
    }

    void performDeposit(Customer& customer);
    void performWithdrawal(Customer& customer);

    bool changePin(Customer& customer);

    void displayMiniStatement(Customer& customer);
    void displayBankStatement(Customer& customer);
    
    void handleMenu(Customer& customer);
    bool handleChoice(int choice, Customer& customer);
};

#endif
