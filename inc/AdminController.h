#ifndef ADMIN_CONTROLLER_H
#define ADMIN_CONTROLLER_H

#include "Customer.h"
class Bank; 

class AdminController {
    Bank* bank;

    bool handleMenuChoice(int choice);
    bool handleEditMenuChoice(int choice, Customer* customer);
    
    void registerCustomer();
    void editCustomerDetails();
    void deleteCustomer();

    void displayCustomersInformation();
    void displayAccountsInformation();

    void searchCustomerByAccountNumber();
    void searchAccountByNumber();

public:
    AdminController(Bank* currentBank) : bank{currentBank} {}

    bool handleMenu();
};

#endif
