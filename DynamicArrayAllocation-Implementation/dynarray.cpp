/*
Problem Statement
Write code that dynamically allocates an array of integers using new[], 
initializes it with values, prints the contents, and then frees the memory using delete[].

Constraints:
    - Must use raw new[] and delete[] (no std::vector).
    - Must prevent memory leaks.
    - Must handle dynamic size determined at runtime.
    - Must show both allocation + deallocation clearly.
    - Access must stay within bounds.
*/

#include <iostream>

int main()
{
    int size{0};

    std::cout << "Enter the size of the array: ";

    if (!(std::cin >> size) || size <= 0)
    {
        std::cerr << "Invalid size!\n";
        return 1;
    }

    //Allocate heap memory
    int *myArray = new int[size];

    std::cout << "Allocated " << size << " integers at address " << myArray << '\n';

    //Initialize and read
    for(int i{0}; i < size; i++)
    {
        myArray[i] = i * 10;
    }

    std::cout << "Contents\n";
    for(int j{0}; j < size; ++j)
    {
        std::cout << myArray[j] << " ";
    }

    std::cout << '\n';

    delete[] myArray; //Deallocate

    myArray = nullptr; //Get rid of any dangling pointer.

    return 0;
}