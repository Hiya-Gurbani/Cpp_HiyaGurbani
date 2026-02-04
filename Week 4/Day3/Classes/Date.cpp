#include "Date.h"
#include <iostream>

Date::Date(int currDay, int currMonth, int currYear) 
    : day{currDay}, month{currMonth}, year{currYear}
{
}

void Date::print() 
{
    std::cout << "Date(" << day << ", " << month << ", " << day << ")\n";
};