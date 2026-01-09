#include <iostream>

//Decides the choice
enum RemoteMode {
    TV,
    AC,
    Speaker
};

//Only one of these would be used at a time
union RemoteAction {
    int channel;
    int temperature;
    int volume;
};


int main() {
    std::cout << sizeof(RemoteMode) << "\n";
    std::cout << sizeof(RemoteAction) << "\n";
}