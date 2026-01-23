#include <iostream>

bool isVowel(char character) {
    character = std::tolower(static_cast<unsigned char>(character));
    if (character == 'a' || character == 'e' || character == 'i' 
        || character == 'o' || character == 'u')
    {
        return true;
    }
    return false;
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    int count = 0;

    for (char character : input)
    {
        if (isVowel(character))
        {
            count++;
        }
    }

    std::cout << "Total Vowels are: " << count << "\n";
}