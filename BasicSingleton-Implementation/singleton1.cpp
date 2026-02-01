/*
Problem Statement
Implement a Singleton class that ensures only one instance of the class can exist at any time. 
Provide a static method getInstance() that returns a reference to the single instance.

Constraints:
    - Constructor must be private.
    - Copy and move operations must be deleted.
    - getInstance() must create the instance on first use (lazy initialization).
    - Do not make it thread-safe (explicitly single-threaded requirement).
    - Demonstrate that Singleton::getInstance() always returns the same object.
*/

#include <iostream>

/*
Singleton guarantees that a class has only one instance and has a global point of access to it.
Used for config managers, db connections or loggeres.

Properties:
    - Private constructor: prevents anyone else from saying "new Singleton()"
    - Static instance: The single instance is stored inside the class itself
    - Deleted copying/moving: Can't clone the Singleton (Singleton a = b; fails)
*/

class Singleton
{
    private:
        //Static pointer to hold the single instance
        static Singleton *instancePtr;

        //Constructor
        Singleton() 
        {
            std::cout << "Singleton constructor called.\n";
        }

    public:
        
        //Deleting the copy constructor and copy assignment operator
        Singleton(const Singleton &) = delete;
        Singleton &operator=(const Singleton &) = delete;

        //Global access point
        static Singleton &getInstance()
        {
            //Lazy initialization
            //Only create an instance if the object doesn't exist yet
            if(instancePtr == nullptr)
            {
                instancePtr = new Singleton();
            }
            
            return *instancePtr;
        }

        void doSomething()
        {
            std::cout << "Singleton is doing work.\n";
        }
};

//Initializing static member to nullptr
Singleton *Singleton::instancePtr = nullptr;

int main()
{
    //First call
    Singleton &s1 = Singleton::getInstance();

    //Second call -> instancePtr is not null so it just returns the existing ptr
    Singleton &s2 = Singleton::getInstance();

    //Address check
    std::cout << "Address of s1: " << &s1 << '\n';
    std::cout << "Address of s2: " << &s2 << '\n';

    if(&s1 == &s2)
    {
        std::cout << "Both variables refer to the exact same object.\n";
    }

    s1.doSomething();

    return 0;
}