#ifndef BANK_H
#define BANK_H

#include "Customer.h"
#include "Admin.h"
#include "AdminController.h"
#include "CustomerController.h"
#include "IBank.h"
#include "IUser.h"
#include "Constants.h"
#include <vector>
#include <string>

class Bank : public IBank {
    std::vector<Customer> customers;
    Admin admin;
    AdminController* adminController;
    CustomerController* customerController;

    static long accountNumberCounter;
    static long transactionIdCounter;

    bool adminLogin();
    bool customerLogin();

public:
    Bank() {
        adminController = new AdminController(this);
        customerController = new CustomerController(this);
    }

    ~Bank() {
        delete adminController;
        delete customerController;
        //delete vector clean
    }

    Customer& createCustomer(const std::string& name, 
                            const std::string& email, 
                            const std::string& phone);

    void handleMenu() override;
    bool handleChoice(int choice) override;
    bool login(Constants::UserRole role) override;
    void logout() override;

    std::vector<Customer>& getCustomers() {
        return customers;
    }

    Customer* findCustomerByAccountNumber(const std::string& accountNumber);
    bool deleteCustomerFromBank(const std::string& accountNumber);

    static std::string generateAccountNumber();
    static std::string generateRandomPin();
    static long generateTransactionId();

};

#endif
