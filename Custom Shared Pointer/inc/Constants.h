#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace Constants {
    inline constexpr char WHITESPACE = ' ';

    // Section headers
    inline const std::string DOUBLE_SECTION = "\nDOUBLE Section\n";
    inline const std::string INT_ARRAY_SECTION = "\nINT ARRAY Section\n";
    inline const std::string STRING_SECTION = "\nSTRING Section\n";

    // Double section
    inline const std::string AFTER_CREATE = "After Create  : ";
    inline const std::string AFTER_COPY = "After Copy    : ";
    inline const std::string AFTER_MOVE = "After Move    : ";
    inline const std::string AFTER_RESET = "After Reset   : ";
    inline const std::string AFTER_COPY_ASSIGN = "After Copy Assignment : ";
    inline const std::string AFTER_MOVE_ASSIGN = "After Move Assignment : ";

    // Labels
    inline const std::string LABEL_VALUE = "value: ";
    inline const std::string LABEL_LENGTH = " | length: ";
    inline const std::string LABEL_USE_COUNT = " | useCount: ";
    inline const std::string LABEL_UNIQUE = " | unique: ";
    inline const std::string LABEL_VALUES = "values: ";

    // Unique
    inline const std::string YES = "yes";
    inline const std::string NO = "no";

    // Null check
    inline const std::string NOT_NULL = "not null";
    inline const std::string IS_NULL = "null";

    // Pointer labels
    inline const std::string DOUBLE_PTR2 = "doublePointer2   : ";
    inline const std::string STRING_PTR2 = "stringPointer2 after move : ";

    // Lambda
    inline const std::string LAMBDA_POINTER = "Lambda pointer : ";
    inline const std::string AFTER_LAMBDA_SCOPE = "After lambda scope : lambda deleter fired above\n";
    inline const std::string LAMBDA_DELETER_CALLED = "Lambda deleter called for: ";
}

#endif
