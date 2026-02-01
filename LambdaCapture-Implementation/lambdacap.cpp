/*
Problem Statement
Write code that demonstrates lambda captures:
    - A lambda that captures an external variable by copy and modifies its internal copy.
    - A lambda that captures the same variable by reference and modifies the original.

Constraints:
    - Must use explicit capture lists: [x] and [&x].
    - Must show before/after effects on the variable.
    - Must demonstrate that the copy-capture does not modify the original.
    - Must use C++14 or later lambda syntax.
    - Must print output to show behavior clearly.
*/

#include <iostream>

int main()
{
    int value{10};

    std::cout << "Initial value in main(): " << value << '\n';

    //Capture by copy
    //We we want to change the captured value, we use the mutable keyword since lambdas are const by default
    auto copyLambda = [value]() mutable {
        value += 5; //Modifies the local value copy only
        std::cout << "[Inside Copy Lambda] value: " << value << '\n';
    };

    //Capture by reference
    auto refLambda = [&value](){
        value += 20; //Modifies the original variable
        std::cout << "[Inside Ref Lambda] value: " << value << '\n';
    };

    //copy lambda
    copyLambda();

    //ref lambda
    refLambda();
    
    return 0;
}