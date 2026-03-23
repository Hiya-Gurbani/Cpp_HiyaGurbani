#ifndef CUSTOMER_SERVICE_H
#define CUSTOMER_SERVICE_H

#include "Customer.h"

class CustomerService {
    std::vector<Customer> customers;
    static long accountNumberCounter;

    static std::string generateRandomPin();

public:
    Customer& createCustomer(const std::string& name, 
                            const std::string& email, 
                            const std::string& phone);
    
    std::vector<Customer>& getCustomers() { 
        return customers; 
    }
    
    Customer* findCustomerByAccountNumber(const std::string& accountNumber);

    bool deleteCustomerFromBank(const std::string& accountNumber);
};

#endif