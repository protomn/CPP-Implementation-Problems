/*
Problem Statement
Use std::transform to take a vector of integers and produce a new vector where each element is doubled (x → 2×x).

Constraints:
    - Must use std::transform, not manual loops.
    - Output vector must have correct size.
    - Use a lambda for the transform operation.
    - Must not mutate the original vector.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void printVec(const std::vector<int> &vec)
{
    for(const auto &num : vec)
    {
        std::cout << num << " ";
    }

    std::cout << '\n';
}

int main()
{
    std::vector<int> input = {1, 2, 3, 4, 5};

    std::vector<int> output;

    output.reserve(input.size());

    std::transform(input.begin(), input.end(), 
                    std::back_inserter(output), 
                [](int x)
            {
                return x * 2;
            });

    std::cout << "Original: ";
    printVec(input);

    std::cout << "Transformed: ";
    printVec(output);
}