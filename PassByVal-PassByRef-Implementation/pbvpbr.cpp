/*
Problem Statement
Implement two functions:
    - One that takes an integer by value and modifies it internally.
    - One that takes an integer by reference and modifies it.
Call both functions from main() and show the difference in behavior.

Constraints:
    - Must clearly label which version is by value / by reference.
    - Must show that pass-by-value does not modify the caller’s variable.
    - Must show that pass-by-reference does modify the caller’s variable.
    - Must use int& for the reference version (not pointers).
*/

#include <iostream>

//1. Pass by value - receives a copy of the integer
void passByValue(int x)
{
    std::cout << "Received " << x << '\n';
    x = 100;
    std::cout << "Local x is now " << x << '\n';
}

//2. Pass by reference - receives a reference to the argument
void passByRef(int &x)
{
    std::cout << "Received " << x << '\n';
    x = 200;
    std::cout << "Received x now " << x << '\n';
}

int main()
{
    int num{10};

    // Calling passByValue
    passByValue(num);
    std::cout << num << '\n'; //num remains unchanged

    //Calling passByRef
    passByRef(num);
    std::cout << num << '\n'; //num is modified (change to reference changes the object being referred to)

    return 0;
}