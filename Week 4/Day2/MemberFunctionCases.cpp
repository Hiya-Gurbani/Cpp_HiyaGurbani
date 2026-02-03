#include <iostream>
#include <string>

class Yogurt {
    std::string flavor = "Vanilla";

    public:
    void setFlavor(std::string& newFlavor) {
        flavor = newFlavor;
    }

    const std::string& getFlavor() {
        return flavor;
    }

    //Worst: Member function accesses flavor directly even when getter exists
    void print()
    {
        std::cout << "The yogurt has flavor " << flavor << '\n';
    }

    //Better: Member function doesn't access flavor directly
    //Still if we update this class we'll need to check this function
    void print()
    {
        std::cout << "The yogurt has flavor " << getFlavor() << '\n';
    }
};

//Not a part of class interface anymore
void print(Yogurt& y)
{
    std::cout << "The yogurt has flavor " << y.getFlavor() << '\n';
}

int main() {
    Yogurt y;
    y.print();
}