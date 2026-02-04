#include <iostream>

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int currNumerator = 0, int currDenominator = 1)
        : numerator{currNumerator}, denominator{currDenominator}
    {
    }

    Fraction(const Fraction& fraction)
        : numerator{ fraction.numerator }
        , denominator{ fraction.denominator }
    {
        std::cout << "Copy constructor called\n"; 
    }

    void print()
    {
        std::cout << "Fraction(" << numerator << ", " << denominator << ")\n";
    }
};

int main()
{
    Fraction fraction {5, 3};
    Fraction fCopy {fraction}; 

    fraction.print();

    //Explicit Copy Constructor
    fCopy.print();

    return 0;
}