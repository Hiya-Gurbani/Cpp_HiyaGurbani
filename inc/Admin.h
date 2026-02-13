#ifndef ADMIN_H
#define ADMIN_H

#include "Constants.h"
#include <string.h>
#include <iostream>

class Admin : public User {
    std::string userName;
    std::string password;

public:
    Admin() : userName{Constants::ADMIN_USERNAME}, password{Constants::ADMIN_PASSWORD}
    {
        this->name = Constants::ADMIN_NAME;
        this->role = Constants::UserRole::ADMIN;
    }

    bool authenticate(const std::string& userName, const std::string& password)
    {
        return (this->userName == userName) && (this->password == password);
    }

    void displayInformation() {
        std::cout << "\nAdmin Name: " << name << "\n";
        std::cout << "Username: " << userName << "\n";
    }
};

#endif
