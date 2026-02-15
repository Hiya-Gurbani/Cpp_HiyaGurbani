#ifndef Customer_CONTROLLER_H
#define Customer_CONTROLLER_H

#include "Customer.h"
class Bank;

class CustomerController {
    Bank* bank;

    void performDeposit(Customer& customer);
    void performWithdrawal(Customer& customer);

    bool changePin(Customer& customer);
    bool isOldPinCorrect(Account& account);

    void displayMiniStatement(Customer& customer);
    void displayBankStatement(Customer& customer);

    bool handleChoice(int choice, Customer& customer);

public:
    CustomerController() {}

    CustomerController(Bank* currentBank) : bank{currentBank} {}

    bool handleMenu(Customer& customer);
};

#endif
