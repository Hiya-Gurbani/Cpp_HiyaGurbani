#include <iostream>
#include <cstring>

class Student {
    char* name;
    int age;

public:
    Student(const char* currName, int currAge)
    : age {currAge} {
        name = new char[strlen(currName) + 1];
        strcpy(name, currName);
        std::cout << "Constructor: Allocated memory for " << name << "\n";
    }

    Student(const Student& student) {
        age = student.age;

        name = new char[strlen(student.name) + 1];
        strcpy(name, student.name);
    }

    void setName(const char* currName) {
        strcpy(name, currName);
    }
    
    void display() {
        std::cout << "Name: " << name << ", Age: " << age << "\n";
    }

    ~Student() {
        std::cout << "Destructor: Deleting " << name << "\n";
        delete[] name;
    }
};

int main() {
    Student s1 {"Hiya", 21};
    Student s2 = s1;

    s1.display();
    s2.display();

    s1.setName("Sakshi");

    s1.display();
    s2.display();
}
