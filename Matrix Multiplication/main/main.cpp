#include "../inc/InputHandler.h"
#include "../inc/MatrixProcessor.h"

int main() {
    InputHandler inputHandler;
    MatrixProcessor matrixProcessor(inputHandler);
    matrixProcessor.executeProgram();
}
