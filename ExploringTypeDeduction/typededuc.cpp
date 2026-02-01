/*
Problem Statement
Write code that demonstrates C++ type deduction using auto, including:
    - Deducing types from literals
    - Deducing types from expressions
    - Demonstrating difference between auto, auto&, and const auto&
    - Using decltype to print or inspect deduced types

Constraints:
    - Must include at least 4 different cases of deduction.
    - Must use typeid(...).name() or a helper template to print deduced types.
    - Must demonstrate that auto drops references and cv-qualifiers.
    - Must avoid relying on compiler extensions.
*/

#include <iostream>
#include <string>

void myFunc() { }

template <typename T>
void printType(const std::string &name)
{
    std::cout << name << " is: ";
    
#if defined (__GNUC__) || defined (__clang__)
    { std::cout << __PRETTY_FUNCTION__ << '\n'; }
#elif defined (_MSC_VER)
    { std::cout << __FUNCSIG__ << '\n'; }
#else
    { std::cout << typeid(T).name() << " (Raw name)\n"; }
#endif
}

#define INSPECT(var) printType<decltype(var)>(#var)

const int globalVal = 100;
const int &getRef() { return globalVal; }

/*
auto as a function return type
*/
int glob_x = 10;

// Standard auto return (returns a copy of glob_x)
auto getVal() { return glob_x; }

//auto & -> return a reference
auto &getRefer() { return glob_x; }

//decltype(auto) -> returns exactly what glob_x is
decltype(auto) getExact() { return glob_x; }

int main()
{
    //Basic value decay
    /*
    Auto alone creates a new object
    It drops top level const and volatile
    It drops references.
    */
    const int c{5};
    const int &cr = c;

    auto x = c; // const is dropped, x is an int
    auto y = cr; // const and '&' are dropped, y is an int

    INSPECT(x);
    INSPECT(y);

    x = 10; // proof x is mutable
    std::cout << "Modified x: " << x << " (Original c is " << c << ")\n\n";

    //Pointers
    /*
    auto deduces pointers automatically
    but auto* enforces it
    */

    int i{42};
    int *ptr = &i;

    auto p1 = ptr; //p1 is int *
    auto *p2 = ptr; //p2 is also int * (explicit pointer syntax)

    //auto *p3 = i; gives error as i is not a pointer

    const int *cptr = &i; // Pointer to a const int
    auto p4 = cptr; // p4 is a cont int * (low level const is kept)

    INSPECT(p1);
    INSPECT(p2);
    INSPECT(p4);
    std::cout << '\n';

    //References
    auto &r1 = i; //r1 is int&
    auto &r2 = c; //r2 is const int& (const is preserved)

    const auto &r3 = i; //r3 is const int& (const added explicitly)

    INSPECT(r1);
    INSPECT(r2);
    INSPECT(r3);

    std::cout << '\n';

    /*
    Arrays decay to pointers unless you use auto&
    */

    int arr[3] = {1, 5, 7};

    auto a1 = arr; //Decays to int* (pointer to the first element)
    auto &a2 = arr; // No decay, type is int(&)[3] - reference to an array of 3 ints

    INSPECT(a1);
    INSPECT(a2);
    std::cout << '\n';

    /*
    Universal References (auto&&)
    auto&& is not an r-value reference here. It's a forwarding reference
    it accepts anything, l-value or r-value
    */

    auto &&u1 = i; // i is an l-value, u1 becomes int&
    auto &&u2 = 10; // 10 is an r-value, u2 becomes int&&

    INSPECT(u1);
    INSPECT(u2);
    std::cout << '\n';

    //Initlializer lists
    //C++17 rules changed here

    auto list1 = {1}; //std::initializer_list<int>
    auto list2 = {1, 4}; //std::initializer_list<int>

    //C++17 direct initialization
    auto direct(1); //type is int
    //auto bad{1, 2}; //throws error in C++17 (direct initialization must be single element)

    INSPECT(list1);
    INSPECT(direct);
    std::cout << '\n';

    /*
    decltype(auto) - give me exactly what the expression is, no decay
    useful for return types of wrpaper functions
    */

    decltype(auto) d1 = i; // gives int
    decltype(auto) d2 = getRef(); // gives const int&
    auto d3 = getRef(); // gives int (decays to value)

    INSPECT(d1);
    INSPECT(d2);
    INSPECT(d3);

    std::cout << '\n';

    /*
    Function decay
    */
    auto f1 = myFunc; // decays to void(*)() -> function pointer
    auto &f2 = myFunc; // becomes void(&)() -> reference to function

    INSPECT(f1);
    INSPECT(f2);
    std::cout << '\n';

    /*
    decltype(auto) parantheses
    */

    decltype(auto) e1 = x; // deduces to int
    decltype(auto) e2 = (x); // deduces to int &

    /*
    Why?
    x is the variable name (identifier)
    (x) is an expression that evaluates to an l-value
    decltype differentiates between identifiers and l-values expressions
    */

    INSPECT(e1);
    INSPECT(e2);
    std::cout << '\n';

    /*
    Multi-variable definition
    */
    auto u = 1, v = 2; //OK, both are ints
    //auto l = 1, m = 3.1415; //throws an ERROR, inconsistent type deduction for auto

    /*
    Comma operator trick
    */
    auto m1 = (1, 2.5);
    /*
    Left operand of the comma operator has no effect.
    Evaluates to return double
    */
    INSPECT(m1);
    std::cout << '\n';

    /*
    C++20 (Abreviated Templates)
    */
    /*
    void foo(auto val) { ... }
    This is valid in C++20, it's a literal shorthand for
    template <typename T> void foo (T val) { ... }
    All of the standard auto deduction rules apply to T
    */

    return 0;
}