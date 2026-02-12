#include <iostream>

class Bank {
private:
    //We made constructor private
    Bank() {
        std::cout << "Bank created\n";
    }

    //Also delete copy constructor and assignment operator
    Bank(const Bank&) = delete;
    Bank& operator=(const Bank&) = delete;

public:
    //Creates one instance
    static Bank& getInstance() {
        static Bank instance;  
        return instance;
    }

    void display() {
        std::cout << "Welcome to Singleton Bank\n";
    }
};

int main() {
    Bank& bank1 = Bank::getInstance();
    Bank& bank2 = Bank::getInstance();

    bank1.display();

    std::cout << &bank1 << "\n";
    std::cout << &bank2 << "\n";
}

