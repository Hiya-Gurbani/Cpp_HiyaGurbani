#include <iostream>

class Date {
    int day;
    int month;
    int year;

    void print() {
        std::cout << day << "/" << month << "/" << year << "\n";
    }
};

int main() {
    //Compiler Error: error: could not convert ‘{12, 12, 2004}’ to Date
    // Date date = {12, 12, 2004}; 

    // today.day = 16; // compile error: the day member is private
    // today.print();    // compile error: the print() member function is private

    return 0;

}