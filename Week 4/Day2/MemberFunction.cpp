#include <iostream>

struct Date {
    int day;
    int month;
    int year;

    void print() {
        std::cout << day << "/" << month << "/" << year << "\n";
    }
};

void print(Date& date) {
    std::cout << date.day << "/" << date.month << "/" << date.year << "\n";
}

int main() {
    Date date = {12, 10, 2004}; //Aggregate Initialization
    date.print();

    date.day = 1;
    date.print();
}