#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex1;
std::mutex mutex2;

void funcThread1() {
    mutex1.lock();
    std::cout << "Thread 1 locked mutex1\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    mutex2.lock();
    std::cout << "Thread 1 locked mutex2\n";

    mutex2.unlock();
    mutex1.unlock();
}

void funcThread2() {
    mutex2.lock();
    std::cout << "Thread 2 locked mutex2\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    mutex1.lock();
    std::cout << "Thread 2 locked mutex1\n";

    mutex1.unlock();
    mutex2.unlock();
}

int main() {
    std::thread thread1(funcThread1);
    std::thread thread2(funcThread2);

    thread1.join();
    thread2.join();
}
