/*
Problem Statement
Write a function that takes an int** and modifies the pointer it points to so that it points to a new dynamically allocated integer.

Constraints:
    - Must demonstrate allocating memory inside the function.
    - Caller must receive the updated pointer.
    - Must check for null pointers.
    - Must free the allocated integer in main().
    - Must demonstrate the difference between modifying *p vs **p.
*/

#include <iostream>

// Function that accepts a pointer to a pointer
void allocateThroughDoublePtr(int **ptrToptr) noexcept
{
    // Check if ptrToptr is not null
    if(ptrToptr == nullptr)
    {
        return;
    }

    // If the caller accidentally passes a pointer that already points to allocated memory
    // the code may leak old memory, this fixes that.
    if(*ptrToptr != nullptr)
    {
        delete *ptrToptr;
    }

    // Dereference once to access pointer varaible in main
    // Assign it to a new address on the heap
    *ptrToptr = new int(42);

    //**ptrToptr accesses the actual int value 42
    std::cout << "Value set to: " << **ptrToptr << '\n';
}

//Upon calling the function, the memory is now owned by the caller.

int main()
{
    int *myPtr = nullptr;

    std::cout << "Initial address: " << myPtr << '\n';

    // Call function by passing the address of the pointer
    allocateThroughDoublePtr(&myPtr);

    // If the function worked, the pointer should no longer be a nullptr
    if(myPtr != nullptr)
    {
        std::cout << "Address of myPtr: " << myPtr << '\n';
        std::cout << "Value held: " << static_cast<void *>(myPtr) << '\n';

        //Cleanup
        delete myPtr;
        myPtr = nullptr;
    }
    else {
    std::cout << "Allocation failed.\n";
    }

    return 0;
}