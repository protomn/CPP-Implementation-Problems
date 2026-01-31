/*
Problem Statement
Write a function that takes a vector of strings and returns a std::map<std::string,int> counting how many times each unique string appears.

Constraints:
    - Must use std::map (not unordered_map).
    - Must return the map, not print it inside the function.
    - Must demonstrate use in main() by printing counts.
    - Must handle empty and repeated strings.
*/

#include <map>
#include <iostream>
#include <vector>
#include <string>

std::map<std::string, int> countFreqs(const std::vector<std::string> &words)
{
    std::map<std::string, int> counts;

    for(const auto &str : words)
    {
        counts[str]++;
    }

    return counts;
}

int main()
{
    std::vector<std::string> fruits = {
        "apple", "banana", "orange", "apple", "banana", "apple", "date"
    };

    std::map<std::string, int> count = countFreqs(fruits);

    for(const auto &pair : count)
    {
        std::cout << pair.first << ": " << pair.second << '\n';
    }

    return 0;
}