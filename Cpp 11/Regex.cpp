#include <iostream>
#include <regex>

int main() {
    std::regex pattern("abc");
    std::string text = "abcxyz";

    if (std::regex_search(text, pattern))
    {
        std::cout << "Pattern Found!\n";
    }
}

