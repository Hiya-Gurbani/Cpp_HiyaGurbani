#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>

std::counting_semaphore<1> semaphore(1); 

void worker(int id) {
    std::cout << "Worker " << id << " waiting to enter critical section...\n";
    semaphore.acquire();
    std::cout << "Worker " << id << " entered critical section.\n";

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "Worker " << id << " leaving critical section.\n";
    semaphore.release(); 
}

int main() {
    std::thread thread1(worker, 1);
    std::thread thread2(worker, 2);

    thread1.join();
    thread2.join();

    return 0;
}
