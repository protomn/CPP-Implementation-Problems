/*
Problem Statement
Implement a custom swap function for integers:
    void swap(int &a, int &b)

It should swap the values using references.

Constraints:
    - Must not use std::swap.
    - Must not use pointers.
    - Function must be noexcept.
    - Must correctly handle aliasing (e.g., swap(x, x)).
*/

#include <iostream>

void swapInts(int &a, int &b)
{
    if (&a == &b) //Checking for self-aliasing
    {
        return;
    }

    //Standard swap algo
    int temp = a;
    a = b;
    b = temp;

}

int main()
{
    int x {2}, y{3};

    std::cout << "Numbers before swap: " << x << " " << y << '\n';

    swapInts(x, y);

    std::cout << "Numbers after swap: " << x << " " << y << '\n';

    return 0;
}