#ifndef IBANK_H
#define IBANK_H

#include "Constants.h"
#include <string>
#include <vector>

class Customer; 

class IBank {
public:
    virtual ~IBank() = default;
    
    virtual void handleMenu() = 0;
    virtual bool handleChoice(int choice) = 0;
    virtual bool login(Constants::UserRole role) = 0;
    virtual void logout() = 0;
    
    virtual Customer* findCustomerByAccountNumber(const std::string& accountNumber) = 0;
    virtual bool deleteCustomerFromBank(const std::string& accountNumber) = 0;
    virtual Customer& createCustomer(const std::string& name, 
                                     const std::string& email, 
                                     const std::string& phone) = 0;
    virtual std::vector<Customer>& getCustomers() = 0;
};

#endif
