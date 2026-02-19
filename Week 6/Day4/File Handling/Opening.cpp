#include <fstream>
#include <iostream>

int main() {
    std::cout << "Opening a file!\n";
    std::ifstream inFile("file.txt");
    bool status = inFile.is_open();
    if (status)
    {
        std::cout << "Successful!\n";
    }
    else
    {
        std::cout << "Failed!\n";
    }

    std::cout << "\nUsing Getline\n";
    std::string string;
    std::getline(inFile, string);
    std::cout << string << "\n";

    std::cout << "\nNot using Getline\n";
    std::string string2;
    file >> string2;
    std::cout << string2 << "\n";
}