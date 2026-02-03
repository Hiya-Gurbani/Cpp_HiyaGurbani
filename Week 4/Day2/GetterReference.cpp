#include <iostream>
#include <string>

class Employee {
    private:
    std::string name;

    public:
    std::string& getName() {
        return name;
    }

    void setName(std::string employeeName) {
        name = employeeName;
    }
};

int main() {
    Employee e1;
    e1.setName("Hiya");

    std::cout << e1.getName() << "\n";

    return 0;
}