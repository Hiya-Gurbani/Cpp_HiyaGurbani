#ifndef INPUT_H
#define INPUT_H

enum InputType {
    CHOICE,
    MATRICES_NUMBER,
    ROWS,
    COLUMNS
};

bool isInputStreamValid();
bool isValidRange(InputType input, int value);
int inputValue(InputType input);
double inputValue();

#endif