#include <thread>
#include <iostream>

int main() {
    std::thread thread([](){
        std::cout << "Thread using lambda\n";
    });

    thread.join();
}
