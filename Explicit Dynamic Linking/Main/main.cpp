#include <iostream>
#include <dlfcn.h>
#include <optional>
#include <limits>
#include <string>

namespace operation
{
    using arithmeticFunction = double(*)(double, double);
}

enum class ExitStatus {
    CONTINUE,
    USER_EXIT,
    ERROR_EXIT
};

void printMenu() {
    std::cout << "\nOperations: \n";
    std::cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n";
}

unsigned int getChoice() {
    unsigned int choice;

    while (true)
    {
        std::cin >> choice;
        if (std::cin.fail() || std::cin.peek() != '\n') 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
        if (std::cin.fail() || std::cin.peek() != '\n') 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

void* loadLibrary() {
    void* handle = dlopen("./liboperations.so", RTLD_LAZY);
    if (!handle)
    {
        std::cerr << "Cannot Load Library: " << dlerror() << "\n";
    }

    return handle;
}

operation::arithmeticFunction loadFunction(void* handle, const std::string& functionName) {
    dlerror();
    operation::arithmeticFunction operationFunction = 
                            (operation::arithmeticFunction)dlsym(handle, functionName.c_str());

    char* error = dlerror();
    if (error)
    {
        std::cerr << "Cannot Find Function: " << error << "\n";
        operationFunction = nullptr;
    }

    return operationFunction;
}

std::optional<double> performOperation(void* handle, const std::string& functionName, 
    double operand1, double operand2) {
    std::optional<double> result = std::nullopt;
    
    if (handle)
    {
        operation::arithmeticFunction operationFunction = 
                                        loadFunction(handle, functionName);
        if (operationFunction)
        {
            result = operationFunction(operand1, operand2);
        }
    }

    return result;
}

bool handleOperation(void* handle, const std::string& functionName) {
    double operand1, operand2;
    bool shouldContinue = false;

    getInputOperands(operand1, operand2);
    if (functionName == "divideOperands" && operand2 == 0)
    {
        std::cout << "Error: Division by zero is not allowed.\n";
        shouldContinue = true;
    }
    else
    {
        std::optional<double> result = performOperation(handle, functionName, operand1, operand2);
        if (result.has_value())
        {
            std::cout << "Result: " << result.value() << "\n";
            shouldContinue = true;
        }
    }
    
    return shouldContinue;
}

ExitStatus handleChoice(void* handle, unsigned int choice) {
    ExitStatus status = ExitStatus::CONTINUE;

    switch (choice) 
    {
        case 1:
        if (!handleOperation(handle, "addOperands"))
        {
            status = ExitStatus::ERROR_EXIT;
        }
        break;

        case 2:
        if (!handleOperation(handle, "subtractOperands"))
        {
            status = ExitStatus::ERROR_EXIT;
        }
        break;

        case 3:
        if (!handleOperation(handle, "multiplyOperands"))
        {
            status = ExitStatus::ERROR_EXIT;
        }
        break;

        case 4:
        if (!handleOperation(handle, "divideOperands"))
        {
            status = ExitStatus::ERROR_EXIT;
        }
        break;
        
        case 5:
        status = ExitStatus::USER_EXIT;
        break;

        default:
        std::cout << "Invalid Choice! Choice must be in range of 1 to 5.\n";
    }

    return status;
}

int main() {
    unsigned int choice;
    ExitStatus status;

    void* handle = loadLibrary();
    if (!handle)
    {
        return 1;
    }

    while (true) 
    {
        printMenu();

        std::cout << "\nEnter your choice: ";
        choice = getChoice();

        status = handleChoice(handle, choice);

        if (status != ExitStatus::CONTINUE)
        {
            dlclose(handle);
            std::cout << "Exiting Program...\n";
            break;
        }
    }

    return (status == ExitStatus::ERROR_EXIT) ? 1 : 0;
}