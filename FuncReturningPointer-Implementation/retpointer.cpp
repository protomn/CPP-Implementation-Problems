/*
Poblem Statement
Implement a function that takes an int* as input and modifies the integer value it points to. 
Demonstrate that the caller sees the updated value.

Constraints:
    - Must not use references; pointer parameter required.
    - Must check for nullptr before dereferencing.
    - Must modify the original variable in the caller’s scope.
*/

#include <iostream>

int *createValue(int value)
{
    //Allocate heap memory
    int *ptr = new int;

    //Assign value
    *ptr = value;

    return ptr; //Pass address back to the caller
    //ptr dies here but the memory still lives on the heap
}

int main()
{

    int *myptr = createValue(42);

    if (myptr == nullptr)
    {
        std::cerr << "Memory allocation failed.\n";
        return 1;
    }

    std::cout << "Value inside the pointer: " << *myptr << '\n';

    //Cleanup
    delete myptr;
    myptr = nullptr;

    std::cout << "Memory deallocated.\n";
    return 0;
}