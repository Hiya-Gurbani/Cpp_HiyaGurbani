// g++ -std=c++20 sem_test.cpp -o sem_test
#include <iostream>
#include <semaphore>

int main() {
    std::counting_semaphore<10> s{3};  

    std::cout << "initial count = 3\n";

    s.acquire();
    std::cout << "after acquire()  -> count = 2\n";

    s.release();
    std::cout << "after release()  -> count = 3  (back to start)\n";

    s.release();  // extra! no matching acquire
    std::cout << "after release()  -> count = 4  (inflated!)\n\n";
}