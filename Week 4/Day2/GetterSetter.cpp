#include <iostream>

class Date {
    private:
    int day;
    int month;
    int year;

    public:
    void print() {
        std::cout << day << "/" << month << "/" << year << "\n";
    }

    int getDay() {
        return day;
    }
    void setDay(int currDay)
    {
        currDay = day;
    }

    int getMonth() {
        return month;
    }
    void setMonth(int currMonth)
    {
        currMonth = month;
    }

    int getYear() {
        return year;
    }
    void setYear(int currYear)
    {
        currYear = year;
    }
};

int main() {
    Date d{};
    d.setYear(2021);
    std::cout << "The year is: " << d.getYear() << '\n';
    
    return 0;
}