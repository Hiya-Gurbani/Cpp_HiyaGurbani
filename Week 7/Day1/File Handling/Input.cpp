#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream inFile("Result.txt");
    std::string line;

    while (getline(inFile, line)) //read line by line
    {
        std::cout << line << "\n";
    }

    // inFile >> variable (reads word by word skipping space)
    inFile.close();
}