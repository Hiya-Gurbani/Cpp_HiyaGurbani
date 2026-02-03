#include <iostream>

struct Date
{
    int day;
    int month;
    int year;

    // void print() {
    //     std::cout << day << "/" << month << "/" << year << "\n";
    // }

    void print() const {
        std::cout << day << "/" << month << "/" << year << "\n";
        // ++day; Error const function can't modify 
    }

    void update(int currDay) {
        day = currDay;
    }
};

int main()
{
    //Needs to be initialised at the time of declaration
    const Date today = {12, 12, 2026};

    // today.day += 1; error: assignment of member ‘Date::day’ in read-only object

    //error: passing ‘const Date’ as ‘this’ argument discards qualifiers
    //i.e update is a non-const member function, can't call it
    // today.update(20);

    // today.print(); can't call until its const
    today.print();

    return 0;
}