class Calculator {
    bool isValidInput(int a, int b) {
        return b != 0;
    }

public:
    int divide(int a, int b) {
        if (!isValidInput(a, b))  
        {
            return -1;
        }
            
        return a / b;
    }
};