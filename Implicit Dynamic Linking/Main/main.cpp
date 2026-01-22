#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include <iostream>

void printMenu() {
    std::cout << "\nOperations: \n";
    std::cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n";
}

unsigned int getChoice() {
    unsigned int choice;

    while (true)
    {
        std::cin >> choice;
        if (std::cin.fail()) 
        {
            std::cin.clear();
            while (getchar() != '\n');
            std::cout << "Invalid Input. Kindly enter a number: ";
        }
        else if (choice < 1 || choice > 5) 
        {
            std::cout << "Choice must be between 1 and 5. Enter again: ";
        }
        else
        {
            break;
        }   
    }

    return choice;
}

double getOperand() {
    double operand;

    while (true)
    {
        std::cin >> operand;
        if (std::cin.fail()) 
        {
            std::cin.clear();
            while (getchar() != '\n');
            std::cout << "Invalid Input. Kindly enter a number: ";
        }
        else
        {
            break;
        }   
    }

    return operand;
}

void getInputOperands(double& operand1, double& operand2) {
    std::cout << "Enter first operand: ";
    operand1 = getOperand();

    std::cout << "Enter second operand: ";
    operand2 = getOperand();
}

void printResult(double result) {
    std::cout << "Result: " << result << "\n";
}

void handleDivision() {
    double operand1, operand2;
    getInputOperands(operand1, operand2);

    if (operand2 == 0)
    {
        std::cout << "Error: Division by zero is not allowed.\n";
    }
    else
    {
        double result = divideOperands(operand1, operand2);
        printResult(result);
    }
}

bool handleChoice(unsigned int choice) {
    double operand1, operand2;
    double result;

    switch (choice) 
    {
        case 1:
        getInputOperands(operand1, operand2);
        result = addOperands(operand1, operand2);
        printResult(result);
        break;

        case 2:
        getInputOperands(operand1, operand2);
        result = subtractOperands(operand1, operand2);
        printResult(result);
        break;

        case 3:
        getInputOperands(operand1, operand2);
        result = multiplyOperands(operand1, operand2);
        printResult(result);
        break;

        case 4:
        handleDivision();
        break;
        
        case 5:
        return false;

        default:
        std::cout << "Invalid Choice! Choice must be in range of 1 to 5.\n";
    }

    return true;
}

int main() {
    unsigned int choice;

    while (true) 
    {
        printMenu();

        std::cout << "\nEnter your choice: ";
        choice = getChoice();

        if (!handleChoice(choice))
        {
            std::cout << "Exiting Program...\n";
            return 0;
        }
    }

    return 0;
}