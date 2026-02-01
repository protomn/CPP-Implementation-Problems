/*
Problem Statement
Implement a ShapeFactory that can produce objects of different shape types (Circle, Square).
The factory should return a Shape* based on a string or enum input.

Constraints:
    - Must define a base class Shape with a virtual draw() function.
    - Derived classes: Circle, Square.
    - Factory method createShape(type) returns a std::unique_ptr<Shape>.
    - Must not use raw pointers for returned objects.
    - Must demonstrate usage in main() (create and draw shapes).
*/

#include <iostream>
#include <memory>

//The Interface (Abstract Base Class)
class Shape
{
    public:
        
        //Pure virtual function - forces derived classes to implement it
        virtual void draw() const = 0;

        //Virtual destructor
        //Without this, deleting *Shape would fail to cleanup derived parts
        virtual ~Shape()
        {
            std::cout << "Shape destructor.\n";
        }
};

//Derived class
class Circle : public Shape
{
    public:

        void draw() const override
        {
            std::cout << "Drawing a circle O.\n";
        }

        ~Circle() { std::cout << "Circle destroyed.\n"; }
};

class Square : public Shape
{
    public:

        void draw() const override
        {
            std::cout << "Drawing a square [].\n";
        }

        ~Square() { std::cout << "Square destroyed.\n"; }
};

//The Factory -> decides which object to create
enum class ShapeType
{
    Circle,
    Square,
    Unknown
};

class ShapeFactory
{
    public:

        //Returns a unique_ptr to the base class
        static std::unique_ptr<Shape> createShape(ShapeType type)
        {
            switch(type)
            {
                case ShapeType::Circle: { return std::make_unique<Circle>(); }
                case ShapeType::Square: { return std::make_unique<Square>(); }
                default: { return nullptr; }
            }
        }
};

int main()
{
    std::unique_ptr<Shape> shape1 = ShapeFactory::createShape(ShapeType::Circle);

    if(shape1)
    {
        shape1 -> draw();
    }

    std::unique_ptr<Shape> shape2 = ShapeFactory::createShape(ShapeType::Square);

    if(shape2)
    {
        shape2 -> draw();
    }

    return 0;
}