#include <thread>
#include <iostream>

class Worker
{
public:
    void run()
    {
        std::cout << "Member function thread\n";
    }
};

int main() {
    Worker worker;

    std::thread thread(&Worker::run, &worker);

    thread.join();
}
