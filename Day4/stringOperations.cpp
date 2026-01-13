#include <iostream>

int lengthOfString(std::string input) {
    return input.size(); //or input.length()
}

void concatenate(std::string& string1, std::string& string2) {
    //Doesn't modify string, we need to reassign 
    std::cout << string1 + string2 << "\n"; 

    //Modifies string 
    string1.append(string2);
    std::cout << string1 << "\n";
}

void modify(std::string string1) {
    std::cout << "\n\nModifying string: \n";
    std::cout << "Original String: " << string1 << "\n";

    string1.push_back('a');
    // string1.push_back("b"); Error: only char
    // string1.push_back("cd"); Error
    std::cout << string1 << "\n";

    string1.pop_back();
    std::cout << string1 << "\n";

    string1.insert(2, "ab");
    // string1.insert(2, 'a'); Only string
    std::cout << string1 << "\n";
    
    string1.erase(2, 2); //Starting index, and length of substring
    // string1.erase(10, 2); Throwing Out of Range Exception
    std::cout << string1 << "\n";
}

int main() {
    std::string str = "Hello Hiya!";
    std::string str1 {"Hello!"};

    std::cout << lengthOfString(str) << "\n";
    std::cout << lengthOfString(str1) << "\n";

    concatenate(str, str1);
    std::cout << str;

    modify(str1);
}