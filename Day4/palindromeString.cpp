#include <iostream>

bool isPalindromeString(std::string input) {
    int length = input.size();
    for (int index = 0; index < length; index++)
    {
        if (input[index] != input[length - index - 1])
        {
            return false;
        }
    }
    return true;
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    bool isPalindrome = isPalindromeString(input);

    std::cout << (isPalindrome ? "Palindrome String\n" : "Not a Palindrome String\n");
}