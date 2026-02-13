#ifndef ADMIN_CONTROLLER_H
#define ADMIN_CONTROLLER_H

class Bank; 

class AdminController {
    Bank* bank;

public:
    AdminController(Bank* currentBank) {
        bank = currentBank;
    }

    void handleMenu();
    bool handleChoice(int choice);
    
    void registerCustomer();
    void viewAllCustomers();
    void viewAllAccounts();
    void searchCustomerByAccountNumber();
    void searchAccountByNumber();
    void editCustomerAccountDetails();
    void deleteCustomer();
    void deleteAccount();
};

#endif
