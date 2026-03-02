#include <iostream>
#include <list>

int main() {
    std::list<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    numbers.push_front(5);

    std::cout << "Elements in list: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << "\n";

    std::cout << "Size of list: " << numbers.size() << "\n";

    std::cout << "First element: " << numbers.front() << "\n";

    std::cout << "Last element: " << numbers.back() << "\n";

    numbers.pop_front();
    std::cout << "After pop_front(), first element is now: " << numbers.front() << "\n";

    numbers.pop_back();
    std::cout << "After pop_back(), last element is now: " << numbers.back() << "\n";

    auto it = numbers.begin();
    ++it; // move to index 1
    numbers.insert(it, 99);
    std::cout << "After inserting 99 at index 1: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << "\n";

    it = numbers.begin();
    numbers.erase(it);
    std::cout << "After erasing index 1: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << "\n";

    numbers.push_back(10);
    numbers.push_back(10);
    std::cout << "Before remove(10): ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << "\n";
    numbers.remove(10);
    std::cout << "After remove(10): ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << "\n";

    // Sort
    numbers.push_back(50);
    numbers.push_back(15);
    numbers.push_back(35);
    std::cout << "Before sort: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << "\n";
    numbers.sort();
    std::cout << "After sort:  ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << "\n";

    // Reverse
    numbers.reverse();
    std::cout << "After reverse: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << "\n";

    std::cout << "Is list empty? " << (numbers.empty() ? "Yes" : "No") << "\n";

    numbers.clear();
    std::cout << "After clear(), size = " << numbers.size() << "\n";
    std::cout << "Is list empty now? " << (numbers.empty() ? "Yes" : "No") << "\n";

    return 0;
}
