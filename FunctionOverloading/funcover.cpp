/*
Problem Statement
Implement three overloaded print() free functions:
    - print(int)
    - print(double)
    - print(const std::string&)
Each should output the value to std::cout along with the type printed.

Constraints:
    - No templates.
    - No implicit conversions (ensure proper type selection).
    - Output format must be clear and consistent.
*/

#include <iostream>
#include <string>

//Overload for int
void print(int value)
{
    std::cout << "[Integer] " << value << '\n';
}

//Overload for double
void print(double value)
{
    std::cout << "[Double] " << value << '\n';
}

//Overload for string
void print(const std::string &str)
{
    std::cout << "[String] " << str << '\n';
}

int main()
{
    int i = 42;
    double d = 3.14159;
    std::string s = "hello";

    print(i);
    print(d);
    print(s);
    print(1);
    print(1.1);
    print("hello?");
}