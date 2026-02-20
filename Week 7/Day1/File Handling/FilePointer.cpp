#include <fstream>
#include <iostream>
using namespace std;

int main() {
    fstream file("data.txt", ios::in | ios::out);

    // Move put pointer to end to append
    file.seekp(0, ios::end);
    file << "\nAppended line";

    // Move get pointer to start
    file.seekg(0, ios::beg);
    string content;
    while (getline(file, content)) {
        cout << content << endl;
    }

    file.tellg();

    file.close();
}
