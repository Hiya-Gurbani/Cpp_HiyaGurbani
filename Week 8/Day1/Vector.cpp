#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);

    // Display all elements 
    std::cout << "Elements in vector: ";
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Size of vector: " << numbers.size() << "\n";

    // First element
    std::cout << "First element: " << numbers.front() << "\n";

    // Last element
    std::cout << "Last element: " << numbers.back() << "\n";

    // a specific index (safe)
    std::cout << "Element at index 2: " << numbers.at(2) << "\n";

    // Remove the last element
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

    std::cout << "Is vector empty? " << (numbers.empty() ? "Yes" : "No") << "\n";

    numbers.clear();
    std::cout << "After clear(), size = " << numbers.size() << "\n";
    std::cout << "Is vector empty now? " << (numbers.empty() ? "Yes" : "No") << "\n";

    return 0;
}
