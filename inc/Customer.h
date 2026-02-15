#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "Account.h"
#include "Constants.h"
#include <iostream>
#include <iomanip>

class Customer : public User {
    std::string phone;
    std::string email;
    Account account;

public:
    Customer(const std::string& name, const std::string& email, const std::string& phone)
        : email{email}, phone{phone} {
        this->name = name;
        this->role = Constants::UserRole::CUSTOMER;
    }

    Account& getAccount() { 
        return account; 
    }

    std::string getPhone() { 
        return phone; 
    }
    std::string getEmail() { 
        return email; 
    }

    void setEmail(const std::string& email) { 
        this->email = email; 
    }
    void setPhone(const std::string& phone) { 
        this->phone = phone; 
    }

    bool authenticate(const std::string& accountNumber, const std::string& accountPin) {
        return (this->account.getAccountNumber() == accountNumber)
         && this->account.verifyPin(accountPin);
    }
    
    void displayInformation();
    
    void displayAccountDetails();
};

#endif
