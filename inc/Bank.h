#ifndef BANK_H
#define BANK_H

#include "Customer.h"
#include "Admin.h"
#include "AdminController.h"
#include "CustomerController.h"
#include "AdminLoginHandler.h"
#include "CustomerLoginHandler.h"
#include "IBank.h"
#include "IUser.h"
#include "ILoginHandler.h"
#include "Constants.h"
#include <vector>
#include <string>

class Bank : public IBank {
    CustomerService customerService;
    Admin admin;
    AdminController* adminController;
    CustomerController* customerController;
    ILoginHandler* adminLoginHandler;
    ILoginHandler* customerLoginHandler;
    bool ownsHandlers;

    bool handleChoice(int choice);

public:
    Bank() : ownsHandlers{true}{
        customerController = new CustomerController();
        adminController = new AdminController(&customerService, customerController);
        adminLoginHandler = new AdminLoginHandler(admin, adminController);
        customerLoginHandler = new CustomerLoginHandler(customerService, customerController);
    }

    Bank(ILoginHandler* adminHandler, ILoginHandler* customerHandler)
        : adminLoginHandler{adminHandler},
          customerLoginHandler{customerHandler},
          adminController{nullptr},
          customerController{nullptr},
          ownsHandlers{false} {}

    ~Bank() {
        delete adminController;
        delete customerController;
        if (ownsHandlers)
        {
            delete adminLoginHandler;
            delete customerLoginHandler;
        }
    }

    void handleMenu() override;
    bool login(Constants::UserRole role) override;
};

#endif
