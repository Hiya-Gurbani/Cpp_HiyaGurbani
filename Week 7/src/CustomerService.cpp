#include "CustomerService.h"
#include "Display.h"
#include "Logger.h"
#include <random>
#include <string>

long CustomerService::accountNumberCounter = Constants::INITIAL_ACCOUNT_NUMBER;

std::string CustomerService::generateRandomPin() {
    static std::random_device randomDevice;     
    static std::mt19937 gen(randomDevice());     
    static std::uniform_int_distribution<> distribution(Constants::MIN_PIN_VALUE, Constants::MAX_PIN_VALUE);

    return std::to_string(distribution(gen));
}

Customer* CustomerService::findCustomerByAccountNumber(const std::string& accountNumber) {
    for (auto& customer : customers) 
    {
        if (customer.getAccount().getAccountNumber() == accountNumber) 
        {
            return &customer;
        }
    }
    return nullptr;
}

Customer& CustomerService::createCustomer(const std::string& name, 
                               const std::string& email, 
                               const std::string& phone) {
    
    Customer newCustomer(name, email, phone);
    
    std::string accountNumber = std::to_string(accountNumberCounter);
    accountNumberCounter++;
    std::string pin = generateRandomPin();
    newCustomer.getAccount().setAccountNumber(accountNumber);
    newCustomer.getAccount().setPin(pin);
    
    customers.push_back(newCustomer);
    Display::printWithValue(Logger::MSG_ACCOUNT_NUMBER, accountNumber);
    Display::printWithValue(Logger::MSG_PIN, pin);
    
    return customers.back();
}

bool CustomerService::deleteCustomerFromBank(const std::string& accountNumber) {
    bool isCustomerDeleted = false;

    for (size_t index = 0; index < customers.size(); index++)
    {
        if (customers[index].getAccount().getAccountNumber() == accountNumber)
        {
            if (customers[index].getAccount().getBalance() == 0)
            {
                customers.erase(customers.begin() + index);
                isCustomerDeleted = true;
            }
            break;
        }
    }
    
    return isCustomerDeleted;
}
