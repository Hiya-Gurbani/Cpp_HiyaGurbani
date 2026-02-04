#include <iostream>
#include <string>
#include <string_view>

class Fruit {
    std::string name;
    std::string color;

public:
    Fruit(std::string_view fruitName, std::string_view fruitColor) 
    : name {fruitName}, color {fruitColor} 
    {
    }
};

class Apple : public Fruit {
    double fiber;

public:
    Apple(std::string_view fruitName, std::string_view fruitColor, double fruitFiber)
    : Fruit {fruitName, fruitColor}, fiber {fruitFiber} 
    {
    }
};

class Banana : public Fruit {
public:
    Banana(std::string_view fruitName, std::string_view fruitColor)
    : Fruit {fruitName, fruitColor} 
    {
    }
};


int main()
{
	const Apple a{ "Red delicious", "red", 4.2 };
	// std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	// std::cout << b << '\n';

	return 0;
}