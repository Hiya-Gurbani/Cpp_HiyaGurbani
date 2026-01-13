#include <iostream>

void traversalWay1(std::string input) {
    for (int index = 0; index < input.size(); index++)
    {
        std::cout << input[index] << " ";
    }
    std::cout << "\n";
}

void traversalWay2(std::string input) {
    for (char character : input) 
    {
        std::cout << character << " ";
    }
    std::cout << "\n";
}

void traversalWay3(std::string input) {
    for (auto it = input.begin(); it != input.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

int main() {
    std::string input;
    std::cin >> input; //Stops at first space

    traversalWay1(input);
    traversalWay2(input);
    traversalWay3(input);
}