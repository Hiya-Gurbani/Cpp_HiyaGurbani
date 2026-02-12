#include <iostream>
#include <string>

class User {
private:
    std::string name;
    int age;

public:
    User(const std::string& name, int age) {
        //name and name can be differentiated 
        this->name = name;   
        this->age = age;
    }

    void display() {
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
    }

    User& setName(const std::string& name) {
        this->name = name;
        return *this;   
    }
};

int main() {
    User user("Hiya", 20);

    //Allows Method Chaining
    user.setName("Gurbani").setName("Hiya");
    user.display();
}
