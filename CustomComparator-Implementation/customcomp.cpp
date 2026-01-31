/*
Problem Statement
Given a vector of std::string, sort the vector by string length using std::sort with a custom comparator.

Constraints:
    - Comparator must be a lambda or a named functor.
    - If two strings have the same length, preserve lexicographic order.
    - Must not use stable_sort (implement ordering manually).
    - Must print before/after results.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

//Helper function to print the vector
void printVector(const std::vector<std::string> &vec)
{
    for(const auto &s : vec)
    {
        std::cout << s << " ";
    }

    std::cout << '\n';
}

int main()
{
    std::vector<std::string> words = {
        "banana", "kiwi", "apple", "orange", "strawberry", "fig", "date", "cucumber"
    };

    //Before sorting
    printVector(words);

    //Sorting with lambda
    std::sort(words.begin(), words.end(), 
                [](const std::string &a, const std::string &b)
            {
                if(a.length() != b.length())
                {
                    return a.length() < b.length();
                }

                return a < b;
            });

    //Post sorting
    printVector(words);

    return 0;
}