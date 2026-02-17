#include <iostream>
#include <vector>
#include <string>

class Student {
public:
    std::string name;
    int age;
    double gpa;

    void promote() {
        gpa += 0.1;
        if (gpa > 4.0) 
        {
            gpa = 4.0;
        }
    }

    bool isPassing() { 
        return gpa >= 2.0; 
    }
};

class Classroom {
public:
    std::string subject;
    std::vector<Student> students;
    void promoteAll() {
        for (auto& student : students) 
        {
            student.promote();
        }
    }
};

int main() {
    Classroom room;
    room.subject = "Mathematics";

    room.students.push_back({"Alice", 20, 3.5});
    room.students.push_back({"Bob", 21, 1.8});
    room.students.push_back({"Carol", 19, 2.9});
    room.students.push_back({"Dave", 22, 3.95});

    std::cout << "Students added\n";   // Breakpoint

    room.promoteAll();

    return 0;
}
