#include <iostream>

struct Notes {
    int number;

    void getNotes() {
        std::cout << "Editing Mode: Moving to next note\n";
        number++;
    }

    void getNotes() const {
        std::cout << "Reading Mode: Only read current notes\n";
    }
};

int main() {
    Notes notes1;
    notes1.number = 5;
    notes1.getNotes();
    
    const Notes notes2 = {5};
    notes2.getNotes(); //Calls const function

    //We can overload normal functions with 
}