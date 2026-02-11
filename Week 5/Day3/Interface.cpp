#include <iostream>

class PaymentMethod {
public:
    virtual void pay(double amount) = 0;     
    virtual void refund(double amount) = 0; 
    
    virtual ~PaymentMethod() {}  
};

class CreditCard : public PaymentMethod {
public:
    void pay(double amount) override {
        std::cout << "Paid " << amount << " using Credit Card\n";
    }

    void refund(double amount) override {
        std::cout << "Refunded " << amount << " to Credit Card\n";
    }

    ~CreditCard() {
        std::cout << "CreditCard destroyed\n";
    }
};

int main() {
    PaymentMethod* payment1 = new CreditCard();

    payment1->pay(500);

    delete payment1;

    return 0;
}

