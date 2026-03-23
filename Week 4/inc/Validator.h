#ifndef VALIDATOR_H
#define VALIDATOR_H

enum InputType {
    CHOICE,
    MATRICES_NUMBER,
    ROWS,
    COLUMNS
};

class Validator {
public:
    static bool isInputStreamValid();
    static bool isValueInValidRange(InputType input, int value);
};

#endif
