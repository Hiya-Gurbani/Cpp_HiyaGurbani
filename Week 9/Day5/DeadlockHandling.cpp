#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex1;
std::mutex mutex2;

void safeThread()
{
    std::lock(mutex1, mutex2);

    std::lock_guard<std::mutex> lock1(mutex1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(mutex2, std::adopt_lock);

    std::cout << "Thread safely locked both mutexes\n";
}

std::mutex m1, m2, m3;

void task()
{
    std::scoped_lock lock(m1, m2, m3);
    std::cout << "All mutexes locked safely\n";
}

int main()
{
    std::thread thread1(safeThread);
    std::thread thread2(safeThread);

    thread1.join();
    thread2.join();
}
