#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace Constants {
    inline constexpr char WHITESPACE = ' ';
    inline const std::string NEW_LINE = "\n";
    inline const std::string LAMBDA = "Lambda";
    // Unique
    inline const std::string YES = "yes";
    inline const std::string NO = "no";

    // Null check
    inline const std::string NOT_NULL = "not null";
    inline const std::string IS_NULL = "null";

    // Lambda
    inline const std::string LAMBDA_POINTER = "\nLambda pointer : ";
    inline const std::string AFTER_LAMBDA_SCOPE = "After lambda scope : lambda deleter fired above\n";
    inline const std::string LAMBDA_DELETER_CALLED = "Lambda deleter called for: ";

    // Section headers
    inline const std::string DOUBLE_SECTION = "\nDOUBLE SECTION\n";
    inline const std::string INT_ARRAY_SECTION = "\nINT ARRAY SECTION\n";
    inline const std::string STRING_SECTION = "\nSTRING SECTION\n";

    // Operations
    inline const std::string AFTER_CREATE = "After Create          >> ";
    inline const std::string AFTER_COPY = "After Copy            >> useCount: ";
    inline const std::string AFTER_MOVE = "After Move            >> useCount: ";
    inline const std::string AFTER_RESET = "After Reset           >> ";
    inline const std::string AFTER_COPY_ASSIGN = "After Copy Assignment >> useCount: ";
    inline const std::string AFTER_MOVE_ASSIGN = "After Move Assignment >> useCount: ";

    // Labels 
    inline const std::string LABEL_VALUE = "value: ";
    inline const std::string LABEL_LENGTH = "  length: ";
    inline const std::string LABEL_USE_COUNT = "  useCount: ";
    inline const std::string LABEL_UNIQUE = "  unique: ";
    inline const std::string LABEL_VALUES = "values: ";

    // Pointer labels
    inline const std::string DOUBLE_PTR2 = "doublePointer2 after move >> ";
    inline const std::string STRING_PTR2 = "stringPointer2 after move >> ";
}

#endif
