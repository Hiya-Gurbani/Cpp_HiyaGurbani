#ifndef Customer_CONTROLLER_H
#define Customer_CONTROLLER_H

#include "Customer.h"
#include "CustomerService.h"

class CustomerController {
    bool changePin(Customer& customer);
    bool isOldPinCorrect(Account& account);

    void displayMiniStatement(Customer& customer);
    void displayBankStatement(Customer& customer);

    bool handleChoice(int choice, Customer& customer);

public:

    void performDeposit(Customer& customer);
    void performWithdrawal(Customer& customer);

    bool handleMenu(Customer& customer);
};

#endif
