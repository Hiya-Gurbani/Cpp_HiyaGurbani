#include "../inc/SharedPointer.h"
#include "../inc/Constants.h"
#include "../inc/Logger.h"

void demonstrateDouble() {
    Logger::printMessage(Constants::DOUBLE_SECTION);

    SharedPointer<double> doublePointer1(new double(21.3));
    Logger::printMessage(Constants::AFTER_CREATE + Constants::LABEL_VALUE + std::to_string(*doublePointer1) + Constants::LABEL_USE_COUNT + std::to_string(doublePointer1.useCount()) + Constants::LABEL_UNIQUE + (doublePointer1.unique() ? Constants::YES : Constants::NO) + Constants::NEW_LINE);

    SharedPointer<double> doublePointer2(doublePointer1);
    Logger::printMessage(Constants::AFTER_COPY + Constants::LABEL_USE_COUNT + std::to_string(doublePointer1.useCount()) + Constants::LABEL_UNIQUE + (doublePointer1.unique() ? Constants::YES : Constants::NO) + Constants::NEW_LINE);

    SharedPointer<double> doublePointer3(std::move(doublePointer2));
    Logger::printMessage(Constants::AFTER_MOVE + Constants::LABEL_USE_COUNT + std::to_string(doublePointer1.useCount()) + Constants::LABEL_UNIQUE + (doublePointer1.unique() ? Constants::YES : Constants::NO) + Constants::NEW_LINE);
    Logger::printMessage(Constants::DOUBLE_PTR2 + (doublePointer2 ? Constants::NOT_NULL : Constants::IS_NULL) + Constants::NEW_LINE);
}

void demonstrateIntArray() {
    Logger::printMessage(Constants::INT_ARRAY_SECTION);

    SharedPointer<int, ArrayDeleter<int>> arrayPointer(new int[3]);
    arrayPointer.get()[0] = 10;
    arrayPointer.get()[1] = 20;
    arrayPointer.get()[2] = 30;

    Logger::printMessage(Constants::AFTER_CREATE + Constants::LABEL_VALUES +
        std::to_string(arrayPointer.get()[0]) + Constants::WHITESPACE +
        std::to_string(arrayPointer.get()[1]) + Constants::WHITESPACE +
        std::to_string(arrayPointer.get()[2]) +
        Constants::LABEL_USE_COUNT + std::to_string(arrayPointer.useCount()) + Constants::NEW_LINE);

    arrayPointer.reset();
    Logger::printMessage(Constants::AFTER_RESET + (arrayPointer ? Constants::NOT_NULL : Constants::IS_NULL) + Constants::LABEL_USE_COUNT + std::to_string(arrayPointer.useCount()) + Constants::NEW_LINE);
}

void demonstrateString() {
    Logger::printMessage(Constants::STRING_SECTION);

    SharedPointer<std::string> stringPointer1(new std::string("Hello"));
    Logger::printMessage(Constants::AFTER_CREATE + Constants::LABEL_VALUE + *stringPointer1 + Constants::LABEL_LENGTH + std::to_string(stringPointer1->size()) + Constants::LABEL_USE_COUNT + std::to_string(stringPointer1.useCount()) + Constants::NEW_LINE);

    SharedPointer<std::string> stringPointer2;
    stringPointer2 = stringPointer1;
    Logger::printMessage(Constants::AFTER_COPY_ASSIGN + Constants::LABEL_USE_COUNT + std::to_string(stringPointer1.useCount()) + Constants::NEW_LINE);

    SharedPointer<std::string> stringPointer3;
    stringPointer3 = std::move(stringPointer2);
    Logger::printMessage(Constants::AFTER_MOVE_ASSIGN + Constants::LABEL_USE_COUNT + std::to_string(stringPointer1.useCount()) + Constants::NEW_LINE);
    Logger::printMessage(Constants::STRING_PTR2 + (stringPointer2 ? Constants::NOT_NULL : Constants::IS_NULL) + Constants::NEW_LINE);

    {
        SharedPointer<std::string> lambdaPointer(new std::string(Constants::LAMBDA), [](std::string* p) {
            Logger::printMessage(Constants::LAMBDA_DELETER_CALLED + *p + Constants::NEW_LINE);
            delete p;
        });
        Logger::printMessage(Constants::LAMBDA_POINTER + Constants::LABEL_VALUE + *lambdaPointer + Constants::LABEL_USE_COUNT + std::to_string(lambdaPointer.useCount()) + Constants::NEW_LINE);
    }
    Logger::printMessage(Constants::AFTER_LAMBDA_SCOPE);
}

int main()
{
    demonstrateDouble();
    demonstrateIntArray();
    demonstrateString();

    return 0;
}
