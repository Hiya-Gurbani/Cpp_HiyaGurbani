#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include <iostream>
#include <limits>
#include <optional>

void printMenu() {
    std::cout << "\nOperations: \n";
    std::cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n";
}

bool isInputStreamValid() {
    if (std::cin.fail() || std::cin.peek() != '\n') 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

unsigned int getChoice() {
    unsigned int choice;

    while (true)
    {
        std::cin >> choice;
        if (isInputStreamValid()) 
        {
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
        if (isInputStreamValid()) 
        {
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

std::optional<double> performOperation(unsigned int choice, double operand1, double operand2) {
    std::optional<double> result = std::nullopt;

    switch (choice) 
    {
        case 1:
        result = addOperands(operand1, operand2);
        break;

        case 2:
        result = subtractOperands(operand1, operand2);
        break;

        case 3:
        result = multiplyOperands(operand1, operand2);
        break;

        case 4:
        if (operand2 == 0)
        {
            std::cout << "Error: Division by zero is not allowed.\n";
        }
        else
        {
            result = divideOperands(operand1, operand2);
        }
        break;
    }

    return result;
}

bool handleChoice(unsigned int choice) {
    if (choice == 5)
    {
        return false;
    }

    double operand1, operand2;
    getInputOperands(operand1, operand2);

    std::optional<double> result = performOperation(choice, operand1, operand2);
    if (result.has_value())
    {
        std::cout << "Result: " << result.value() << "\n";
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