/*
Problem Statement
Write a constexpr function factorial(int n) that computes the factorial of a number at compile time.
Demonstrate compile-time evaluation by using the function in a constexpr variable and a static_assert.

Constraints:
    - Function must be constexpr and fully evaluatable at compile time.
    - Must not use loops — implement recursion or constexpr-loop logic.
    - Must verify correctness via static_assert(factorial(5) == 120);.
    - Must also demonstrate runtime usage.
    - Must not cause undefined behavior for invalid input (e.g., negative numbers).
*/

#include <iostream>

// The constexpr function

constexpr long long factorial(int n)
{
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

int main()
{
    constexpr long long val = factorial(5);

    static_assert(val == 120, "Math is broken!");
    static_assert(factorial(6) == 720, "Factorial 6 calculation failed.");

    //Runtime evaluation

    int num{};

    std::cout << "Enter a number: ";

    if (std::cin >> num)
    {
        std::cout << num << "! = " << factorial(num) << '\n';
    }

    return 0;
}