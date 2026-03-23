#ifndef CUSTOMER_SERVICE_TEST_H
#define CUSTOMER_SERVICE_TEST_h

#include "CustomerService.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class GivenCustomerServiceTest : public ::testing::Test {
protected:
    CustomerService service;
    Customer* customer;
    
    void SetUp() override {
        customer = &service.createCustomer("Daksh Sharma", "daksh@gmail.com", "1234567890");
    }
};

#endif
