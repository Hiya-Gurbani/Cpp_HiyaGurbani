#ifndef INPUT_H
#define INPUT_H

#include <climits>

bool isInputStreamValid();
int inputValue(int minValue = INT_MIN, int maxValue = INT_MAX);
void inputValue(double&);

#endif