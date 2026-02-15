#ifndef ADMIN_CONTROLLER_H
#define ADMIN_CONTROLLER_H

#include "Customer.h"
#include "CustomerController.h"
class IBank; 

class AdminController {
    IBank* bank;
    CustomerController* customerController;

    bool handleMenuChoice(int choice);
    bool handleEditMenuChoice(int choice, Customer* customer);
    
    void registerCustomer();

    void updateCustomerName(Customer* customer);
    void updateCustomerEmail(Customer* customer);
    void updateCustomerPhone(Customer* customer);
    void updateCustomerPin(Customer* customer);
    void editCustomerDetails();
    void handleCustomerDeletion();

    void displayCustomersInformation();
    void displayAccountsInformation();

    void displayCustomerByAccountNumber();
    void displayAccountByNumber();

    void manageCustomerAccount();
    void performAccountOperation(Customer* customer);

public:
    AdminController(IBank* currentBank) : bank{currentBank} {}

    bool handleMenu();
};

#endif
