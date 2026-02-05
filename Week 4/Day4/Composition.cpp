#include <iostream>

class Heart {
public:
    Heart() {
        std::cout << "Heart is working!\n";
    }

    void printRate() {
        std::cout << "Your heart rate is 72 bpm\n";
    }

    ~Heart() {
        std::cout << "Heart has stopped!\n";
    }
};

class Human {
    Heart heart1;
    Heart* heart2; //It persists after the Human too but need to be deleted

public:
    Human() {
        std::cout << "Human is alive\n";
        heart2 = new Heart();
    }
    ~Human() {
        std::cout << "Human has died!\n";
    }
};

int main() {
    Human human;

    //If we want heart to outlive make a ptr to it
}