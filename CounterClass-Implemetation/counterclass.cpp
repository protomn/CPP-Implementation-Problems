/*
Problem Statement:
Implement a Counter class that tracks how many objects of this type have been created so far. 
Use a static data member to count constructions.

Constraints:
    - Count only successful constructions (not destructions).
    - Counter must increase on copy and move constructions as well.
    - Declare and define the static member correctly.
    - Provide a static getCount() method.
*/

#include <iostream>

class Counter
{
    private:
        static int totalCount; // Declaration only

    public:

        // Default Constructor
        Counter() 
        {
            std::cout << "Default constructor.\n";
            totalCount++;
        }

        //Copy constructor
        Counter(const Counter &other)
        {
            std::cout << "Copy constructor.\n";
            totalCount++;
        }

        // Move constructor
        Counter(Counter &&other)
        {
            std::cout << "Move constructor.\n";
            totalCount++;
        }

        //Static Accessor
        static int getCount()
        {
            return totalCount;
        }    
};

int Counter::totalCount = 0;

//Function that creates a counter object
Counter createCounter()
{
    Counter temp;
    return temp;
}

int main()
{
    std::cout << "Initial count: " << Counter::getCount() << '\n';

    Counter c1;

    std::cout << "Count after c1: " << Counter::getCount() << '\n';

    Counter c2 = c1;

    std::cout << "Count after copy: " << Counter::getCount() << '\n';

    Counter c3 = createCounter(); //Move construction;
    
    std::cout << "Count after c3: " << Counter::getCount() << '\n';

    return 0;

}

