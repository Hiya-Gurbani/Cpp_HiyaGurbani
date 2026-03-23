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

public:
    Bank();
    Bank(ILoginHandler* adminHandler, ILoginHandler* customerHandler);

    ~Bank();

    bool handleChoice(int choice);
    void handleMenu() override;
    bool login(Constants::UserRole role) override;
};

#endif
