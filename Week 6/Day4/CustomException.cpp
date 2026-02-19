#include <iostream>
#include <exception>  
#include <string>

class MyException : public std::exception {
private:
    std::string message;  
public:
    MyException(const std::string& msg) : message(msg) {}

    //Override what() of exception class 
    const char* what() const noexcept override {
        return message.c_str();
    }
};

int main() {
    try 
    {
        throw MyException("Something went wrong!");
    } 
    catch (const MyException& e) 
    {
        std::cout << "Caught MyException: " << e.what() << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cout << "Caught std::exception: " << e.what() << std::endl;
    }
}
