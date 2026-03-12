#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello from thread\n";
}

int main() {
    std::thread thread(hello);

    thread.join();
}
