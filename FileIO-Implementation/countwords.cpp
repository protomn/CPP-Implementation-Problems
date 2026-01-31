/*
Problem Statement
Write a function that reads a text file, parses it into words, and counts how many words the file contains.

Constraints:
    - Must use std::ifstream.
    - Words are sequences of alphabetic characters (ignore punctuation).
    - Must handle file-open failure gracefully.
    - Must not load entire file into memory at once (read incrementally).
    - Must print final word count.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

// Counting words in a given filename

int countWords(const std::string &filename)
{
    std::ifstream file(filename); //Opens the file

    if(!file.is_open())
    {
        std::cerr << "[Error]: Could not open file " << filename << '\n';
        return -1;
    }

    int count{0};
    char c{};
    bool inWord{false};

    //Read char by char
    while(file.get(c))
    {
        if(std::isalpha(c))
        {
            if(!inWord)
            {
                count++;
                inWord = true;
            }
            else 
            {
            inWord = false; //encountered anything other than an alphabet
            }
        }
    }

    return count;
}

int main()
{
    int result = countWords("sample.txt");

    if(result >= 0)
    {
        std::cout << "Total word count: " << result << '\n';
    }

    return 0;
}