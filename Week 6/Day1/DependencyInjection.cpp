#include <iostream>
#include <string>

class INotifier {
public:
    virtual void notify(std::string message) = 0;
};

class EmailNotifier : public INotifier {
public:
    void notify(std::string message) {
        std::cout << "Email: " << message << std::endl;
    }
};

class SMSNotifier : public INotifier {
public:
    void notify(std::string message) {
        std::cout << "SMS: " << message << std::endl;
    }
};

class Bank {
private:
    INotifier* notifier;  
    
public:
    Bank(INotifier* n) : notifier(n) {}  //Dependency injection!
    
    void withdraw(int amount) {
        std::cout << "Withdrawing $" << amount << std::endl;
        notifier->notify("You withdrew $" + std::to_string(amount));
    }
};

int main() {
    EmailNotifier email;
    Bank bank1(&email);
    bank1.withdraw(100);
    
    std::cout << std::endl;
    
    SMSNotifier sms;
    Bank bank2(&sms);
    bank2.withdraw(200);
    
    return 0;
}
