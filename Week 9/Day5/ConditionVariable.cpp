#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
#include <iostream>

std::mutex mutex;
std::condition_variable cv;
std::queue<int> q;

void produce() {
    for (int index = 0; index < 5; index++)
    {
        {
            std::lock_guard<std::mutex> lock(mutex);
            q.push(index);
            std::cout << "Produced: " << 5 - index << "\n";
        }
        cv.notify_one();
    }
}

void consume() {
    for (int index = 0; index < 5; index++)
    {
        std::unique_lock<std::mutex> lock(mutex);
        cv.wait(lock, []() { return !q.empty(); });
        int item = q.front();
        q.pop();
        std::cout << "Consumed: " << item << "\n";
    }
}


int main() {
    std::thread producer(produce);
    std::thread consumer(consume);
    producer.join();
    consumer.join();
}