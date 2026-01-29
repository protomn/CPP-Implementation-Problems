/*
Problem Statement
Implement a Vector2D struct representing a 2-dimensional vector with x and y coordinates. Provide member functions for:
    - add(const Vector2D&)
    - sub(const Vector2D&)
    - dot(const Vector2D&) const
All operations must return a new Vector2D or a scalar (in the case of dot product).

Constraints:
    - Must be a struct, not a class.
    - No dynamic allocation.
    - Implement all functions as const where appropriate.
    - All operations must be pure (no mutation of inputs).
*/

#include <iostream>

struct Vector2D
{
    double x; // X coordinate
    double y; // Y coordinate

    Vector2D(double x_, double y_) : x(x_), y(y_) { } // Constructor for initialization.

    // Add method, return a new Vector2D, does not modify input vectors.
    Vector2D add(const Vector2D &other) const
    {
        return Vector2D(x + other.x, y + other.y); // Creates a new Vector2D object on the stack and returns it to the caller.
    }

    // Sub method, follows same constraints and rules and Add method.
    Vector2D sub(const Vector2D &other) const
    {
        return Vector2D(x - other.x, y - other.y);
    }

    // dot method, returns a scalar
    double dot(const Vector2D &other) const
    {
        return (x * other.x) + (y * other.y);
    }

    // print() helper method.
    void print() const
    {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main()
{
    Vector2D v1(3.0, 4.0);
    Vector2D v2(1.0, 2.0);

    Vector2D sum1 = v1.add(v2);
    std::cout << "Sum: ";
    sum1.print();

    Vector2D diff1 = v1.sub(v2);
    std::cout << "Difference: ";
    diff1.print();

    double scalarProd = v1.dot(v2);
    std::cout << "Dot Product: " << scalarProd << '\n';

    return 0;
}