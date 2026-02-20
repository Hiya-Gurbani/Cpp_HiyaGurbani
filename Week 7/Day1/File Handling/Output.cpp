#include <fstream>

int main() {
    std::ofstream outFile("Result.txt");
    outFile << "Line 1\n";
    outFile << "Line 2\n";
    outFile.close();

    //Without append overwrite the file every time program runs

    ofstream outFile("example.txt", ios::app); // append mode -> avoid overwrite

}