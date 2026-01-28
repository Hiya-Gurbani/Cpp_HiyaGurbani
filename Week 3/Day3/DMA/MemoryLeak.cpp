#include <iostream>

int main() {
    //Some ways:

    //First
    {
        int* ptr = new int ();
    } //Ptr goes out of scope here and memory sin't freed

    //Second
    int* ptr1 = new int();
    int* ptr2 = new int();

    ptr2 = ptr1; //No ptr is holding address of ptr2 block

    //Thirs
    int* ptr3 = new int (2);
    ptr3 = new int (4); //Old allocated block is leaked
}