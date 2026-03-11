#include <iostream>
#include <thread>
#include <shared_mutex>

std::shared_mutex mutex; 
int data = 0;

void reader() {
    std::shared_lock lock(mutex);
    std::cout << "Reader sees data = " << data << "\n";
}

void writer() {
    std::unique_lock lock(mutex); 
    data += 1;
    std::cout << "Writer updated data to " << data << "\n";
}

int main() {
    std::thread thread1(reader);
    std::thread thread2(writer);

    thread1.join();
    thread2.join();

    return 0;
}
