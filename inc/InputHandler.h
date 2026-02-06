#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "Matrix.h"

class InputHandler {
public:
    static double inputValue();
    static int inputValue(InputType input);
    static void inputMatrix(Matrix& matrix);
    static void inputDimensionsForMultiplication(int numberOfMatrices, 
                                                int*& rowsArray, int*& colsArray);
                                                
};

#endif