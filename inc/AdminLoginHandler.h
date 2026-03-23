#ifndef ADMIN_LOGIN_HANDLER_H
#define ADMIN_LOGIN_HANDLER_H

#include "ILoginHandler.h"
#include "Admin.h"
#include "CustomerService.h"
#include "AdminController.h"

class AdminLoginHandler : public ILoginHandler {
    Admin& admin;
    AdminController* adminController;

    bool getAndVerifyCredentials();

public:
    AdminLoginHandler(Admin& admin, AdminController* controller)
        : admin{admin}, adminController{controller} {}

    Constants::LoginResult login() override;

    virtual void logout() override;
};

#endif
