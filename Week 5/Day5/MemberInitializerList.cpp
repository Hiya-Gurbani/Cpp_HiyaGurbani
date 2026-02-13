#include <iostream>
#include <vector>
#include <initializer_list>

class MyClass {
public:
    MyClass(int size, int value) {
        std::cout << "Size-value constructor called\n";
        data.resize(size, value);
    }

    MyClass(std::initializer_list<int> list) {
        std::cout << "Initializer_list constructor called\n";

        for (const int& element : list) { //Const is necessary
            std::cout << element << " ";
            // element = 10;   //Error: All elements are const
        }
        std::cout << "\n";

        data = list;
    }

    void print() {
        for (int v : data)
        {
            std::cout << v << " ";
        }  
        std::cout << "\n";
    }

private:
    std::vector<int> data;
};

int main() {

    MyClass a(3, 7); //Calls (int, int)
    a.print();

    MyClass b{3, 7}; //Calls initializer_list version!
    b.print();

    return 0;
}
