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
    CustomerService customerService;
    Admin admin;
    AdminController* adminController;
    CustomerController* customerController;

    Constants::LoginResult adminLogin();
    Constants::LoginResult customerLogin();
    bool handleChoice(int choice);

public:
    Bank() {
        adminController = new AdminController(&customerService);
        customerController = new CustomerController();
    }

    ~Bank() {
        delete adminController;
        delete customerController;
    }

    void handleMenu() override;
    bool login(Constants::UserRole role) override;
    void logout() override;
};

#endif
