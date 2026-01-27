int main()
{
    const int value1 = 5;
    // int* ptr1 = &value1; Error: int * can't point to const int

    const int value2 = 10;
    const int* ptr2 = &value2;

    int value3 = 15;
    const int* ptr3 = &value3; //Valid we can't update value3 by ptr
    // *ptr3 = 20;  Error : Pointer is read only
    value3 = 20;

    return 0;
}