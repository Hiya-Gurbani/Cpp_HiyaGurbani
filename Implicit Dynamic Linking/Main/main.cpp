#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include <iostream>

void printMenu() {
    std::cout << "\nOperations: \n";
    std::cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n";
}

void getInputoperands(double& operand1, double& operand2) {
    std::cout << "Enter first operand: ";
    //getValidDouble();
    std::cin >> operand1;

    std::cout << "Enter second operand: ";
    //getValidDouble();
    std::cin >> operand2;
}

void printResult(double result) {
    std::cout << "Result: " << result << "\n";
}

bool handleChoice(unsigned int choice) {
    double result;
    bool isDivideByZero = false;

    switch (choice) 
    {
        double operand1, operand2;

        case 1:
        getInputoperands(operand1, operand2);
        result = addOperands(operand1, operand2);
        break;

        case 2:
        getInputoperands(operand1, operand2);
        result = subtractOperands(operand1, operand2);
        break;

        case 3:
        getInputoperands(operand1, operand2);
        result = multiplyOperands(operand1, operand2);
        break;

        case 4:
        getInputoperands(operand1, operand2);

        if (operand2 == 0)
        {
            isDivideByZero = true;
        }
        else
        {
            result = divideOperands(operand1, operand2);
        }
        break;
        
        case 5:
        return false;

        // default:
        // std::cout << "Choice must be between 1 to 5. Enter again: ";
    }

    if (isDivideByZero)
    {
        std::cout << "Error: Division by zero is not allowed."
    }
    else
    {
        printResult(result);
    }

    return true;
}

int main() {
    unsigned int choice;

    while (true) 
    {
        unsigned int choice;
        std::string input;
        printMenu();
        std::cout << "\nEnter your choice: ";
        //std::getline(std::cin, input);
        //if (isValidChoice(input))
        //{
            // break;
        //}
        std::cin >> choice;

        if (!handleChoice(choice))
        {
            std::cout << "Exiting Program...\n";
            return 0;
        }
    }

}