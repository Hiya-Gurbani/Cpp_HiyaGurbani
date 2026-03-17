#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex mutex;

void increment() {
    for (int index = 0; index < 1000; index++)
    {
        mutex.lock();
        mutex.unlock();
        counter++;
        mutex.unlock();
    }
}

int main() {
    std::thread thread1(increment);
    std::thread thread2(increment);

    thread1.join();
    thread2.join();

    std::cout << "Counter: " << counter << "\n";
}


