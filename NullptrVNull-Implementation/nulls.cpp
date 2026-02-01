/*
Problem Statement
Demonstrate the difference between nullptr and NULL in C++. 
Create overloaded functions that take:
    - void func(int);
    - void func(char*);
and call them using:
    - NULL
    - nullptr
Show which overload gets selected in each case.

Constraints:
    - Must use two clearly ambiguous overloads.
    - Show that nullptr calls the pointer overload while NULL may call the integer overload.
    - Must print which overload is selected.
    - Must not use 0 literal — only NULL and nullptr.
    - Must explain behavior through printed output.
*/

#include <iostream>
#include <cstddef>

// Overload 1: Accepts an integer
void func(int x)
{
    std::cout << "[func(int)] - Value: " << x << '\n';
}

// Overload 2: Accepts a pointer
void func(char *c)
{
    if(c)
    {
        std::cout << "[func(char *)] - Not NULL" << '\n';
    }
    else
    {
        std::cout << "[func(char *)] - nullptr" << '\n';
    }
}

int main()
{
    //Calling with NULL
    /* 
    NULL is technically 0, the compiler sees 0 as an integer first.
    this picks func(int)
    generates an error
    */
    func(NULL); // -> call to func becomes ambiguous, doesn't compile.

    //calling with nullptr
    /*
    nullptr is type safe, it cannot be an int
    forces the compiler to look for a pointer overload
    calls func(char *)
    */

    func(nullptr);

    return 0;
}