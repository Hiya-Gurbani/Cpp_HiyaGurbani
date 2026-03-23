#ifndef CUSTOMER_LOGIN_HANDLER_H
#define CUSTOMER_LOGIN_HANDLER_H

#include "ILoginHandler.h"
#include "CustomerService.h"
#include "CustomerController.h"

class CustomerLoginHandler : public ILoginHandler {
    CustomerService& customerService;
    CustomerController* customerController;

    Customer* getCustomer();           
    bool verifyPin(Customer* customer);

public:
    CustomerLoginHandler(CustomerService& service, CustomerController* controller)
        : customerService{service}, customerController{controller} {}

    Constants::LoginResult login() override;

    virtual void logout() override;
};

#endif
