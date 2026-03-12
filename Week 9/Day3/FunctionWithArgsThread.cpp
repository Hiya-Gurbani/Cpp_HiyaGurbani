#include <iostream>
#include <thread>

void print(int x, int y) {
    std::cout << x << " " << y << "\n";
}

int main() {
    std::thread thread(print, 10, 20);

    thread.join();
}
