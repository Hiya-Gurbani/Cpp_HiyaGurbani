#include <iostream>
#include <thread>
#include <vector>
#include <semaphore.h>  

sem_t sem;

int counter = 0;

void increment(int id)
{
    for(int index = 0; index < 1000; index++)
    {
        sem_wait(&sem);    
        counter++;        
        sem_post(&sem);     
    }

    std::cout << "Thread " << id << " finished\n";
}

int main()
{
    sem_init(&sem, 0, 2);
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
