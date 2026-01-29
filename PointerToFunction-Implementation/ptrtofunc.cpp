/*
Problem Statement
Implement two simple arithmetic functions, e.g. add(int,int) and mul(int,int). 
Then create a pointer-to-function variable that can point to either of them and invoke the selected function.

Constraints:
    - Must define a function pointer variable, not a typedef.
    - Must show switching the pointer between functions.
    - Must call the function through the pointer.
    - Must print output for verification.
*/

#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int mul(int a, int b)
{
    return a * b;
}

int main()
{
    //Declaring the function pointer
    //Returns int, takes (int, int)
    int (*mathOp)(int, int);

    mathOp = add;

    int sum = mathOp(10, 5);

    std::cout << "Pointer points to add, sum = " << sum << '\n';

    mathOp = mul;

    int prod = mathOp(5, 6);

    std::cout << "Pointer points to mul, prod = " << prod << '\n';

    return 0;
}