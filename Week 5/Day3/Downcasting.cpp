#include<iostream>

class Base {
    int value;
};

class Derived {

};

int main() {
    //Not allowed as derived is-a base but base is-not-a derived
    Derived* derived = new Base();
}