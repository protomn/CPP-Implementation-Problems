/*
Problem Statement
Implement a class Point with:
    - Default constructor (0,0)
    - Parameterized constructor (x, y)
    - Copy constructor
    - A print() function

Constraints:
    - Use initialization lists for all constructors.
    - No code duplication — call one constructor from another if needed.
    - Ensure copy constructor performs deep or correct copying (no raw pointers).
    - Demonstrate all constructors in main().
*/

#include <iostream>

class Point
{
    private:
        double x, y;

    public:

        //Parameterized constructor
        Point(double x_, double y_) : x(x_), y(y_)
        {
            std::cout << "Parameterized constructor called for: (" << x_ << ", " << y_ << ")" << '\n';
        }

        //Default constructor
        Point() : Point(0, 0)
        {
            std::cout << "Default constructor called." << '\n';
        }

        //Copy constructor
        Point(const Point &copy) : x(copy.x), y(copy.y)
        {
            std::cout << "Copy constructor called.\n";
        }

        void print() const
        {
            std::cout << "Point: (" << x << ", " << y << ")\n";
        }
};

int main()
{
    //Default construction
    Point p1;
    p1.print();

    //Parameterized construction
    Point p2(3.0, 4.0);
    p2.print();

    //Copy constructor
    Point p3 = p2;
    p3.print();

    return 0;
}