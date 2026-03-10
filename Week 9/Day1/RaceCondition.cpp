#include <iostream>
#include <thread>

int counter = 0;

void increment() {
    for (int index = 0; index < 10000; index++)
    {
        counter++;
    }
}

int main() {
    std::thread thread1(increment);
    std::thread thread2(increment);

    thread1.join();
    thread2.join();

    // Counter: 15284 because race condition happens (can get any random number)
    std::cout << "Counter: " << counter << "\n";
    return 0;
}
