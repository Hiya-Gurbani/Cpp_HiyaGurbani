#include <iostream>
#include <string>

enum AnimalType {
    cat,
    dog,
    rabbit,
};

std::string animalName(AnimalType type) {
    switch (type)
    {
        case cat: 
        return "cat";

        case dog: 
        return "dog";

        case rabbit: 
        return "rabbit";
        
        default:  return "";
    }
}

int numLegs(AnimalType type) {
    switch (type)
    {
        case cat: return 4;
        case dog: return 4;
        case rabbit: return 2;
        default:  return 0;
    }
}

int main() {
    AnimalType animal = dog;
    std::cout << "A " << animalName(animal) << " has " << numLegs(animal) << " legs\n";

    return 0;
}