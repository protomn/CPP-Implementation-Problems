/*
Problem Statement
Implement a class InstanceCounter that tracks how many instances of the class have been created so far. 
Use a static integer to store the count and a static method to retrieve it.

Constraints:
    - Instance count must increment on every successful construction.
    - Count must not increment on destruction.
    - Static method must be callable without an object: InstanceCounter::getCount().
    - Demonstrate usage by creating multiple objects in main().
*/

#include <iostream>

class InstanceCounter
{
    private:
        static int totalCreated; //shared by all instances of the InstanceCounter

    public:

        //Constructor
        InstanceCounter() 
        {
            totalCreated++;
            std::cout << "Constructor called! Total created: " << totalCreated << '\n';
        }

        //Destructor
        ~InstanceCounter()
        {
            totalCreated--;
            std::cout << "Instance out of scope! Destructor called! Total currently alive: " << totalCreated << '\n';
        }

        //Static method that can be called without an object instance.
        static int getCount()
        {
            return totalCreated;
        }
};

//Static data members are initialized outside the class.
int InstanceCounter::totalCreated = 0;

int main()
{
    //Initial count
    std::cout << "Initial count: " << InstanceCounter::getCount() << '\n';

    InstanceCounter a;
    InstanceCounter *ptr = new InstanceCounter();

    {
        //Entering a new scope
        InstanceCounter c;

        std::cout << "Current count inside scope: " << InstanceCounter::getCount() << '\n';

    } // c goes out of scope here

    std::cout << "Current count: " << InstanceCounter::getCount() << '\n';

    delete ptr;
    ptr = nullptr;

    std::cout << "Final count before main goes out of scope: " << InstanceCounter::getCount() << '\n';

    return 0;
}