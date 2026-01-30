/*
Problem Statement
Implement a class Person with fields name and age. 
Overload the stream insertion operator (operator<<) so that printing a Person to std::cout shows a readable string representation.

Constraints:
    - operator<< must be a non-member function.
    - Must take std::ostream& as first parameter and return it by reference.
    - Must not expose private data directly (use getters or friend declaration).
    - Output must be formatted cleanly.
*/

#include <iostream>
#include <ostream>
#include <string>

class Person
{
    private:
        std::string name;
        int age;

    public:

        //Constructor
        Person(std::string name_, int age_) : name(name_), age(age_) { }

        //Friend declaration
        friend std::ostream &operator<<(std::ostream &os, const Person &p);
};

//Defining the operator outside the class

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << "Name: " << p.name << ", Age: " << p.age << '\n';

    return os; //Returning the stream allows for chaining.
}

int main()
{
    Person p1("Alice", 45);
    Person p2("Bob", 35);

    std::cout << p1 << '\n' << p2 << '\n';

    return 0;
}