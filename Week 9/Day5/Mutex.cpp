#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mtx;
int counter = 0;

void increment(int id)
{
    for(int index = 0; index < 1000; index++)
    {
        std::lock_guard<std::mutex> lock(mtx);
        counter++;
    }

    std::cout << "Thread " << id << " finished\n";
}

int main()
{
    std::vector<std::thread> threads;

    for(int index = 0; index < 6; index++)
    {
        threads.emplace_back(increment, index);
    }

    for(auto &thread : threads)
    {
        thread.join();
    }

    std::cout << "Final counter value: " << counter << std::endl;
}
