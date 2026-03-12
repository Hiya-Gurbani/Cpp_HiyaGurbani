#include <thread>
#include <iostream>

class Task {
public:
    void operator()() {
        std::cout << "Functor thread\n";
    }
};

int main() {
    Task task;

    std::thread thread(task);

    thread.join();
}
