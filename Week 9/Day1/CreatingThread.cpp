#include <iostream>
#include <thread>

void sayHello() {
    std::cout << "Hello from thread\n";
}

int main() {
    std::thread thread(sayHello);
    thread.join(); //Waiting for the thread to finish
    std::cout << "Main thread finished.\n";
    return 0;
}

// If we don't use join
// Main thread finished.
// terminate called without an active exception
// Hello from thread
// Aborted (core dumped)
