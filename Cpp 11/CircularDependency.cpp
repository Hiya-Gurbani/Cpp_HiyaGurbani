#include <iostream>
#include <memory>
#include <string>

class Person {
    std::string name;
    std::shared_ptr<Person> partner;

public:
    Person(const std::string& name) : name(name) {
        std::cout << "Person " << name << " created!\n";
    }

    ~Person() {
        std::cout << "Person " << name << " destroyed!\n";
    }

    friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2) {
        if (!p1 || !p2) 
        {
            return false;
        }

        p1->partner = p2;
        p2->partner = p1;

        std::cout << p1->name << " is partnered with " << p2->name << "\n";

        return true;
    }
};

int main() {
    auto lucy = std::make_shared<Person>("Lucy");
    auto ricky = std::make_shared<Person>("Ricky");

    partnerUp(lucy, ricky);

    // Never Destroyed
}