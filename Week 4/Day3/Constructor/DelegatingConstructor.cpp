#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
    std::string name = "";
    int id = 0;

public:
    Employee(std::string_view name)
        : Employee{name, 0} 
    {
    }

    Employee(std::string_view employeeName, int employeeId)
        : name{employeeName}, id {employeeId} 
    {
        std::cout << "Employee " << name << " created\n";
    }
};

int main()
{
    Employee e1{"James"};
    Employee e2{"Dave", 42};
}