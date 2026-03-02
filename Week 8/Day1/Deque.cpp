#include <iostream>
#include <deque>

int main() {
    std::deque<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    numbers.push_front(5);

    std::cout << "Elements in deque: ";
    for (int i = 0; i < numbers.size(); i++) std::cout << numbers[i] << " ";
    std::cout << "\n";

    std::cout << "Size of deque: " << numbers.size() << "\n";

    std::cout << "First element: " << numbers.front() << "\n";

    std::cout << "Last element: " << numbers.back() << "\n";

    std::cout << "Element at index 2: " << numbers.at(2) << "\n";

    std::cout << "Element at index 1 using []: " << numbers[1] << "\n";

    numbers.pop_front();
    std::cout << "After pop_front(), first element is now: " << numbers.front() << "\n";

    numbers.pop_back();
    std::cout << "After pop_back(), last element is now: " << numbers.back() << "\n";

    numbers.insert(numbers.begin() + 1, 99);
    std::cout << "After inserting 99 at index 1: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << "\n";

    numbers.erase(numbers.begin() + 1);
    std::cout << "After erasing index 1: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << "\n";

    std::cout << "Is deque empty? " << (numbers.empty() ? "Yes" : "No") << "\n";

    numbers.clear();
    std::cout << "After clear(), size = " << numbers.size() << "\n";
    std::cout << "Is deque empty now? " << (numbers.empty() ? "Yes" : "No") << "\n";

    return 0;
}
