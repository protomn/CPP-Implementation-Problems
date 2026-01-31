/*
Problem Statement
Write a function that takes a vector of integers and prints all duplicate values using std::unordered_set.

Constraints:
    - Must detect duplicates with O(n) expected complexity.
    - Must print each duplicate only once.
    - Must not sort the input.
    - Must not modify the original vector.
*/

#include <iostream>
#include <unordered_set>
#include <vector>

void printDups(const std::vector<int> &nums)
{
    std::unordered_set<int> seen;
    std::unordered_set<int> duplicates;

    bool found{false};

    for(const auto &num : nums)
    {
        if(seen.count(num))
        {
            if(duplicates.find(num) == duplicates.end())
            {
                std::cout << num << " ";
                duplicates.insert(num);
                found = true;
            }
        }
        else
        {
            seen.insert(num);
        }
    }

    if(!found) { std::cout << "None found"; }
    std::cout << '\n';
}

int main()
{
    std::vector<int> data = {10, 50, 10, 20, 30, 50, 50, 99};

    printDups(data);

    return 0;
}