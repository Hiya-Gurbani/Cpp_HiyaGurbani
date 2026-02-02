#include <iostream>

class Date {
    public:
    int mDay;
    int mMonth;
    int mYear;
};

void printDate(Date& date) {
    std::cout << date.mDay << '/' << date.mMonth << "/" << date.mYear << "\n";
}

int main() {
    Date date;
    printDate(date);

    date.mDay = 12;
    date.mMonth = 07;
    date.mYear = 2009;

    printDate(date);
}