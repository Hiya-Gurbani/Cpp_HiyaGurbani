#include <iostream>
#include <string>

struct Cat {
    std::string name = "cat";
    int numLegs = 4;
};

struct Dog {
    std::string name = "dog";
    int numLegs = 4;
};

struct Rabbit {
    std::string name = "rabbit";
    int numLegs = 2;
};

struct Snake {
    std::string name = "snake";
    int numLegs = 0;
};

int main() {
    Rabbit animal;
    std::cout << "A " << animal.name << " has " << animal.numLegs << " legs\n";

    Snake snake;
    std::cout << "A " << snake.name << " has " << snake.numLegs << " legs\n";

    return 0;
}