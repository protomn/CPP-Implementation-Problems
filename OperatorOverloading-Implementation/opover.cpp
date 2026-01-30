/*
Problem Statement
Implement a class Point with two integer members (x and y). 
Overload the comparison operators:
    - operator==
    - operator!=
    - operator< (lexicographic comparison: first compare x, then y)

Constraints:
    - All operators must be const.
    - Must use const Point& parameters.
    - Must not use memcmp or any hackish comparison tricks.
    - Must demonstrate comparisons in main().
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Point
{
    private: 
        int x, y;

    public:

        //Constructor
        Point(int x_, int y_) : x(x_), y(y_) { }

        //Equality operator
        bool operator==(const Point &other) const
        {
            return (x == other.x) && (y == other.y);
        }

        //Inequality operator
        bool operator!=(const Point &other) const
        {
            return !(*this == other);
        }

        //Lexicographic comparison operator
        bool operator<(const Point &other) const
        {
            if (x != other.x)
            {
                return x < other.x;
            }
            
            return y < other.y;
        }

        //Helper function
        void print() const
        {
            std::cout << "(" << x << ", " << y << ")\n";
        }
};

int main()
{
    Point p1(1, 5);
    Point p2(1, 5);
    Point p3(2, 2);
    Point p4(1, 10);

    //Test equality
    std::cout << "p1 == p2? " << (p1 == p2 ? "True" : "False") << '\n';
    std::cout << "p1 != p3? " << (p1 != p3 ? "True" : "False") << '\n'; 

    //Test less than logic
    std::cout << "p1 < p3?  " << (p1 < p3 ? "True" : "False") << '\n';

    std::cout << "p1 < p4?  " << (p1 < p4 ? "True" : "False") << '\n';

    std::vector<Point> points = {p3, p4, p1, Point(0, 0)};
    std::sort(points.begin(), points.end());
    
    for(const auto &p : points)
    {
        p.print();
    }
    std::cout << '\n';

    return 0;
}